#pragma once
#include "RoadObject.h"

class RoadSideObject : public RoadObject
{
public:
	RoadSideObject();
	
	void					setDistanceFromCenter(float distance) override;					//Sets the distance from the center
	void					setScale(float scale) override;
	void					setZ(float z) override;
	void					setY(float y) override;
	void					setX(float roadX)override;
	void					setScanline(int line) override;
	void					move(float speed) override;
	void					setTex(sf::Texture &texture) override;
	void					setSprite(sf::IntRect rect) override;

	void					update(float speed) override;
	void					render(sf::RenderWindow &window) override;

	int						getScanline() override;

	float					getZ() override;

	sf::IntRect				getRect() override;
};