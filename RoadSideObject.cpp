#include "stdafx.h"
#include "RoadSideObject.h"


RoadSideObject::RoadSideObject()
{
	scanLine = 0;

	y = 0;
	z = 0;
	x = 0;
	distanceFromCenter = 0;
	scale = 0;
}

void RoadSideObject::setDistanceFromCenter(float distance)
{
	distanceFromCenter = distance;
}

void RoadSideObject::setScale(float scale)
{
	this->scale = (1 / z) * .00869565;
}

void RoadSideObject::setZ(float z)
{
	this->z = z;
}

void RoadSideObject::setY(float y)
{
	this->y = y - sprite.getTextureRect().height * scale;
}

void RoadSideObject::setX(float roadX)
{
	x = (roadX + 320.f - (distanceFromCenter * scale)) - (sprite.getTextureRect().width * .5f) * scale;
}

void RoadSideObject::setScanline(int line)
{
	scanLine = line;
}

void RoadSideObject::move(float speed)
{
	z -= speed;
}

void RoadSideObject::setTex(sf::Texture &texture)
{
	sprite.setTexture(texture);
}

void RoadSideObject::setSprite(sf::IntRect rect)
{
	sprite.setTextureRect(rect);
}

void RoadSideObject::update(float speed)
{
	move(speed);
	sprite.setPosition(sf::Vector2f(x, y));
	sprite.setScale(sf::Vector2f(scale, scale));
}

void RoadSideObject::render(sf::RenderWindow &window)
{
	window.draw(sprite);
}

int RoadSideObject::getScanline()
{
	return scanLine;
}

float RoadSideObject::getZ()
{
	return z;
}

sf::IntRect RoadSideObject::getRect()
{
	return sprite.getTextureRect();
}