#pragma once
#include "SFML\Graphics.hpp"
#include <iostream>

enum Type
{
	playerType,
	riderType,
	roadSideType
};
class RoadObject
{
public:
	RoadObject();

	virtual void					setDistanceFromCenter(float distance) = 0;					//Sets the distance from the center
	virtual void					setScale(float scale) = 0;
	virtual void					setZ(float z) = 0;
	virtual void					setY(float y) = 0;
	virtual void					setX(float roadX) = 0;
	virtual void					setScanline(int line) = 0;
	virtual void					move(float speed) = 0;
	virtual void					setTex(sf::Texture &texture) = 0;
	virtual void					setSprite(sf::IntRect rect) = 0;

	virtual void					update(float speed) = 0;
	virtual void					render(sf::RenderWindow &window) = 0;

	virtual int						getScanline() = 0;

	virtual float					getZ() = 0;

	virtual sf::IntRect				getRect() = 0;
protected:
	int						scanLine;

	float					y;
	float					z;
	float					x;
	float					distanceFromCenter;								//A road object's distance from the center of the road
	float					scale;											//The scale value for object values

	sf::Sprite				sprite;
};

