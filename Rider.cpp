#include "stdafx.h"
#include "Rider.h"


Rider::Rider()
{
	scanLine = 0;

	y = 0;
	z = 0;
	x = 0;
	distanceFromCenter = 0;
	scale = 0;
}

void Rider::setDistanceFromCenter(float distance)
{
	distanceFromCenter = distance;
}

void Rider::setScale(float scale)
{
	this->scale = (1 / z) * .00869565;
}

void Rider::setZ(float z)
{
	this->z = z;
}

void Rider::setY(float y)
{
	this->y = y - sprite.getTextureRect().height * scale;
}

void Rider::setX(float roadX)
{
	x = (roadX + 320.f - (distanceFromCenter * scale)) - sprite.getTextureRect().width * scale;
}

void Rider::setScanline(int line)
{
	scanLine = line;
}

void Rider::move(float speed)
{
	z -= speed;
	z += forwardSpeed;
}

void Rider::setTex(sf::Texture &texture)
{
	sprite.setTexture(texture);
}

void Rider::setSprite(sf::IntRect rect)
{
	sprite.setTextureRect(rect);
}

void Rider::setForwardSpeed(float forwardSpeed)
{
	this->forwardSpeed = forwardSpeed;
}

void Rider::update(float speed)
{
	move(speed);
	sprite.setPosition(sf::Vector2f(x, y));
	sprite.setScale(sf::Vector2f(scale, scale));
}

void Rider::render(sf::RenderWindow &window)
{
	window.draw(sprite);
}

int Rider::getScanline()
{
	return scanLine;
}

float Rider::getZ()
{
	return z;
}

sf::IntRect	Rider::getRect()
{
	return sprite.getTextureRect();
}