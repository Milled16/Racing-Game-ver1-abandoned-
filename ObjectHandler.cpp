#include "stdafx.h"
#include "ObjectHandler.h"


ObjectHandler::ObjectHandler()
{
	spriteSheet.loadFromFile("res/textures/spriteSheet.png");

	rObjectsLeft = 50;
	for (int i = 0; i < rObjectsLeft; i++)
	{
		rObjects.push_back(new RoadSideObject);
	}

	ridersLeft = 6;
	for (int i = 0; i < ridersLeft; i++)
	{
		riders.push_back(new Rider);
	}

	for (int i = 0; i < rObjectsLeft; i++)
	{
		rObjects[i]->setTex(spriteSheet);
		rObjects[i]->setSprite(sf::IntRect(0, 0, 90, 150));
		rObjects[i]->setZ(float(i) / 4.f);
		if (i % 2 == 1)
			rObjects[i]->setDistanceFromCenter(330);
		else
			rObjects[i]->setDistanceFromCenter(-330);
	}

	for (int i = 0; i < ridersLeft; i++)
	{
		riders[i]->setTex(spriteSheet);
		riders[i]->setSprite(sf::IntRect(90, 0, 50, 142));
		riders[i]->setZ(float(i + 1) / 2.f);
		if (i % 2 == 1)
			riders[i]->setDistanceFromCenter(90);
		else
			riders[i]->setDistanceFromCenter(-90);
	}
}


void ObjectHandler::setScanlines()
{
	for (int i = 0; i < MAXROADPIECES; i++)
	{
		for (int j = 0; j < rObjectsLeft; j++)
		{
			if (rObjects[j]->getZ() <= roadPieces[i].zPos)
			{
				rObjects[j]->setScanline(i);
				rObjects[j]->setScale(roadPieces[i].zScaling);
			}
		}
	}
	for (int i = 0; i < MAXROADPIECES - 1; i++)
	{
		for (int j = 0; j < ridersLeft; j++)
		{
			if (riders[j]->getZ() <= roadPieces[i].zPos && riders[j]->getZ() >= roadPieces[i + 1].zPos)
			{
				riders[j]->setScanline(i);
				riders[j]->setScale(roadPieces[i].zScaling);
			}
		}
	}
}

void ObjectHandler::setXs()
{
	for (int i = 0; i < rObjectsLeft; i++)
	{
		rObjects[i]->setX(roadPieces[rObjects[i]->getScanline()].xPos);
	}
	for (int i = 0; i < ridersLeft; i++)
	{
		riders[i]->setX(roadPieces[riders[i]->getScanline()].xPos);
	}
}

void ObjectHandler::setYs()
{
	for (int i = 0; i < rObjectsLeft; i++)
	{
		rObjects[i]->setY(roadPieces[rObjects[i]->getScanline()].yPos);
	}
	for (int i = 0; i < ridersLeft; i++)
	{
		riders[i]->setY(roadPieces[riders[i]->getScanline()].yPos);
	}
}

void ObjectHandler::process()
{

}

void ObjectHandler::update(float time, float speed, RoadPiece roadPieces[])
{
	for (int i = 0; i < MAXROADPIECES; i++)
	{
		this->roadPieces[i] = roadPieces[i];
	}

	process();
	float adjustedSpeed = speed * time;
	float adjustedForwardSpeed = RIDERSPEED * time;

	setScanlines();
	setXs();
	setYs();

	for (int i = 0; i < rObjectsLeft; i++)
	{
		rObjects[i]->update(adjustedSpeed);
	}

	for (int i = 0; i < ridersLeft; i++)
	{
		riders[i]->setForwardSpeed(adjustedForwardSpeed);
		riders[i]->update(adjustedSpeed);
	}
}

void ObjectHandler::render(sf::RenderWindow &window, int line)
{
	for (int i = 0; i < rObjectsLeft; i++)
	{
		if (rObjects[i]->getZ() <= roadPieces[0].zPos && rObjects[i]->getZ() >= roadPieces[MAXROADPIECES - 1].zPos && rObjects[i]->getScanline() == line)
			rObjects[i]->render(window);
	}
	for (int i = 0; i < ridersLeft; i++)
	{
		if (riders[i]->getZ() <= roadPieces[0].zPos && riders[i]->getZ() >= roadPieces[MAXROADPIECES - 1].zPos && riders[i]->getScanline() == line)
			riders[i]->render(window);
	}
}