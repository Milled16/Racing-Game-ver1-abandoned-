#pragma once
#include <iostream>
#include "RoadObject.h"
#include "RoadSideObject.h"
#include "Rider.h"

//const int MAXROADPIECES = 256 / 2;
const int MAXROADPIECES = 112;

const float RIDERSPEED = .1f;

struct RoadPiece //struct for a scanline of the road
{
	float xPos; //screen x position of the road piece
	float yPos; //screen y position of the road piece
	float zPos; //world z position of the road piece
	float zScaling; //Scaling value for sprites on the road

	bool textureChange; //bool that determines if the texture of the road should flip
	sf::Sprite roadTop1; //top line of the road
	sf::Sprite roadBottom1; //bottom line of the road
	sf::Sprite offRoadTop1; //top background line of the road
	sf::Sprite offRoadBottom1; //bottom background line of the road

	sf::Sprite roadTop2; //top line of the road
	sf::Sprite roadBottom2; //bottom line of the road
	sf::Sprite offRoadTop2; //top background line of the road
	sf::Sprite offRoadBottom2; //bottom background line of the road
};

class ObjectHandler
{
public:
	ObjectHandler();

	void							setScanlines();
	void							setXs();
	void							setYs();
	void							process();
	void							update(float time, float speed,RoadPiece roadPieces[]);
	void							render(sf::RenderWindow &window, int line);

private:
	unsigned int									rObjectsLeft;
	unsigned int									ridersLeft;

	std::vector<RoadSideObject*>					rObjects;
	std::vector<Rider*>								riders;

	RoadPiece										roadPieces[MAXROADPIECES];

	sf::Texture										spriteSheet;
};