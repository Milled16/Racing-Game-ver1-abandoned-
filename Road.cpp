#include "stdafx.h"
#include "Road.h"

Road::Road()
{
	rekt.setFillColor(sf::Color(sf::Color::Blue));
	rekt.setPosition(sf::Vector2f(0, 0));
	rekt.setSize(sf::Vector2f(320, 224));
	onGas = false;
	onBrakes = false;
	driftAmount = 0.f;

	lDirection = straight;
	road1T.loadFromFile("res/textures/roadwork1.png");

	road2T.loadFromFile("res/textures/roadwork2.png");

	line1.loadFromFile("res/textures/line1.png");
	line2.loadFromFile("res/textures/line2.png");

	roadPieces[0].xPos = STARTINGXPOS;
	roadPieces[0].yPos = YRESOLUTION / 2;

	xSegsLeft = 16;
	xSegs.push_back(new roadSegmentX);
	xSegs.push_back(new roadSegmentX);
	xSegs.push_back(new roadSegmentX);
	xSegs.push_back(new roadSegmentX);
	xSegs.push_back(new roadSegmentX);
	xSegs.push_back(new roadSegmentX);
	xSegs.push_back(new roadSegmentX);
	xSegs.push_back(new roadSegmentX);
	xSegs.push_back(new roadSegmentX);
	xSegs.push_back(new roadSegmentX);
	xSegs.push_back(new roadSegmentX);
	xSegs.push_back(new roadSegmentX);
	xSegs.push_back(new roadSegmentX);
	xSegs.push_back(new roadSegmentX);
	xSegs.push_back(new roadSegmentX);
	xSegs.push_back(new roadSegmentX);

	xSegs[0]->yLoc = 127.f;
	xSegs[0]->ddx = 0.0f;

	xSegs[1]->yLoc = -100.f;
	xSegs[1]->ddx = 1.0f;

	xSegs[2]->yLoc = -227.f;
	xSegs[2]->ddx = -1.0f;

	xSegs[3]->yLoc = -354.f;
	xSegs[3]->ddx = .6f;

	xSegs[4]->yLoc = -581.f;
	xSegs[4]->ddx = 2.f;

	xSegs[5]->yLoc = -658.f;
	xSegs[5]->ddx = 0.1f;

	xSegs[6]->yLoc = -700.f;
	xSegs[6]->ddx = 0.0f;

	xSegs[7]->yLoc = -860.f;
	xSegs[7]->ddx = -.6f;

	xSegs[8]->yLoc = -1027.f;
	xSegs[8]->ddx = .8f;

	xSegs[9]->yLoc = -1100.f;
	xSegs[9]->ddx = -.6f;

	xSegs[10]->yLoc = -1250.f;
	xSegs[10]->ddx = 0.7f;

	xSegs[11]->yLoc = -1340.f;
	xSegs[11]->ddx = -.6f;

	xSegs[12]->yLoc = -1400.f;
	xSegs[12]->ddx = .5f;

	xSegs[13]->yLoc = -1500.f;
	xSegs[13]->ddx = .6f;

	xSegs[14]->yLoc = -1600.f;
	xSegs[14]->ddx = -.9f;

	xSegs[15]->yLoc = -1700.f;
	xSegs[15]->ddx = 0.0f;

	ySegsLeft = 20;
	ySegs.push_back(new roadSegmentY);
	ySegs.push_back(new roadSegmentY);
	ySegs.push_back(new roadSegmentY);
	ySegs.push_back(new roadSegmentY);
	ySegs.push_back(new roadSegmentY);
	ySegs.push_back(new roadSegmentY);
	ySegs.push_back(new roadSegmentY);
	ySegs.push_back(new roadSegmentY);
	ySegs.push_back(new roadSegmentY);
	ySegs.push_back(new roadSegmentY);
	ySegs.push_back(new roadSegmentY);
	ySegs.push_back(new roadSegmentY);
	ySegs.push_back(new roadSegmentY);
	ySegs.push_back(new roadSegmentY);
	ySegs.push_back(new roadSegmentY);
	ySegs.push_back(new roadSegmentY);
	ySegs.push_back(new roadSegmentY);
	ySegs.push_back(new roadSegmentY);
	ySegs.push_back(new roadSegmentY);
	ySegs.push_back(new roadSegmentY);

	ySegs[0]->yLoc = 127.f;
	ySegs[0]->ddy = 0.0f;

	ySegs[1]->yLoc = 0.f;
	ySegs[1]->ddy = 1.0f;

	ySegs[2]->yLoc = -50.f;
	ySegs[2]->ddy = -1.0f;

	ySegs[3]->yLoc = -200.f;
	ySegs[3]->ddy = 0.0f;

	ySegs[4]->yLoc = -250.f;
	ySegs[4]->ddy = 0.5f;

	ySegs[5]->yLoc = -350.f;
	ySegs[5]->ddy = -1.2f;

	ySegs[6]->yLoc = -420.f;
	ySegs[6]->ddy = 0.0f;

	ySegs[7]->yLoc = -500.f;
	ySegs[7]->ddy = .1f;

	ySegs[8]->yLoc = -600.f;
	ySegs[8]->ddy = -1.0f;

	ySegs[9]->yLoc = -700.f;
	ySegs[9]->ddy = 0.0f;

	ySegs[10]->yLoc = -800.f;
	ySegs[10]->ddy = 0.8f;

	ySegs[11]->yLoc = -870.f;
	ySegs[11]->ddy = -1.0f;

	ySegs[12]->yLoc = -960.f;
	ySegs[12]->ddy = 0.0f;

	ySegs[13]->yLoc = -1300.f;
	ySegs[13]->ddy = -1.0f;

	ySegs[14]->yLoc = -1400.f;
	ySegs[14]->ddy = 1.0f;

	ySegs[15]->yLoc = -1500.f;
	ySegs[15]->ddy = -1.f;

	ySegs[16]->yLoc = -1600.f;
	ySegs[16]->ddy = 1.0f;

	ySegs[17]->yLoc = -1700.f;
	ySegs[17]->ddy = -1.0f;

	ySegs[18]->yLoc = -1800.f;
	ySegs[18]->ddy = 1.0f;

	ySegs[19]->yLoc = -1820.f;
	ySegs[19]->ddy = 0.0f;

	for (int i = 1; i < MAXROADPIECES; i++)
	{
		roadPieces[i].xPos = STARTINGXPOS;
		roadPieces[i].yPos = roadPieces[i - 1].yPos + 1;
	}

	currentSpeed = 0.f;
	turnSpeed = 0.f;

	xDistance = 0;

	processRoadDimensions();

	for (int i = 0; i < ZTEXTUREMAX; i++)
	{
		textureZ[0][i] = 0 + STRIPEWIDTH * i;
	}

	for (int i = 1; i < MAXSTRIPES; i++)
	{
		for (int j = 0; j < ZTEXTUREMAX; j++)
		{
			textureZ[i][j] = STRIPEWIDTH + textureZ[i - 1][ZTEXTUREMAX - 1] + STRIPEWIDTH * j;
		}
	}

	returnZ1 = textureZ[MAXSTRIPES - 1][0]  - STRIPEWIDTH;
	returnZ2 = textureZ[MAXSTRIPES - 1][ZTEXTUREMAX - 1] - STRIPEWIDTH;
}

void Road::processRoadPiecePosition()
{
	float xDistance = 0.f;
	for (int i = 0; i < MAXROADPIECES; i++)
	{
		roadPieces[i].roadTop1.setPosition(sf::Vector2f(roadPieces[i].xPos, roadPieces[i].yPos));
		roadPieces[i].roadTop2.setPosition(sf::Vector2f(roadPieces[i].xPos, roadPieces[i].yPos + 1.f));
		if (i < MAXROADPIECES - 1)
		{
			xDistance = (roadPieces[i + 1].xPos - roadPieces[i].xPos) / (roadPieces[i + 1].yPos - roadPieces[i].yPos);
			roadPieces[i].roadBottom1.setPosition(sf::Vector2f(roadPieces[i].roadTop1.getPosition().x + xDistance, roadPieces[i].yPos + 2.f));
			roadPieces[i].roadBottom2.setPosition(sf::Vector2f(roadPieces[i].roadTop1.getPosition().x + xDistance, roadPieces[i].yPos + 3.f));
		}
		else
		{
			roadPieces[i].roadBottom1.setPosition(sf::Vector2f(roadPieces[i].roadTop1.getPosition().x + xDistance, roadPieces[i].yPos + 2.f));
			roadPieces[i].roadBottom2.setPosition(sf::Vector2f(roadPieces[i].roadTop1.getPosition().x + xDistance, roadPieces[i].yPos + 3.f));
		}
		roadPieces[i].offRoadTop1.setPosition(sf::Vector2f(STARTINGXPOS, roadPieces[i].yPos));
		roadPieces[i].offRoadTop2.setPosition(sf::Vector2f(STARTINGXPOS, roadPieces[i].yPos + 1.f));
		roadPieces[i].offRoadBottom1.setPosition(sf::Vector2f(STARTINGXPOS, roadPieces[i].yPos + 2.f));
		roadPieces[i].offRoadBottom2.setPosition(sf::Vector2f(STARTINGXPOS, roadPieces[i].yPos + 3.f));
	}
}

void Road::processRoadDimensions()
{
	for (int i = 0; i < MAXROADPIECES; i++)
	{
		roadPieces[i].xPos = STARTINGXPOS;
		roadPieces[i].yPos = YRESOLUTION / 2 + i;

		roadPieces[i].zPos = 1 / (roadPieces[i].yPos + 3 - (YRESOLUTION / 2));
		roadPieces[i].textureChange = false;

		roadPieces[i].roadTop1.setTexture(road1T);
		roadPieces[i].roadTop1.setTextureRect(sf::IntRect(0, i * 2, XRESOLUTION * 2, 1));
		roadPieces[i].roadTop1.setPosition(sf::Vector2f(roadPieces[i].xPos, roadPieces[i].yPos));
		roadPieces[i].offRoadTop1.setTexture(line1);
		roadPieces[i].offRoadTop1.setTextureRect(sf::IntRect(0, 0, XRESOLUTION * 2, 1));
		roadPieces[i].offRoadTop1.setPosition(sf::Vector2f(roadPieces[i].xPos, roadPieces[i].yPos));
		roadPieces[i].roadTop2.setTexture(road1T);
		roadPieces[i].roadTop2.setTextureRect(sf::IntRect(0, i * 2, XRESOLUTION * 2, 1));
		roadPieces[i].roadTop2.setPosition(sf::Vector2f(roadPieces[i].xPos, roadPieces[i].yPos));
		roadPieces[i].offRoadTop2.setTexture(line1);
		roadPieces[i].offRoadTop2.setTextureRect(sf::IntRect(0, 0, XRESOLUTION * 2, 1));
		roadPieces[i].offRoadTop2.setPosition(sf::Vector2f(roadPieces[i].xPos, roadPieces[i].yPos));

		roadPieces[i].roadBottom1.setTexture(road1T);
		roadPieces[i].roadBottom1.setTextureRect(sf::IntRect(0, i * 2 + 1, XRESOLUTION * 2, 1));
		roadPieces[i].roadBottom1.setPosition(sf::Vector2f(roadPieces[i].xPos, roadPieces[i].yPos - 1.f));
		roadPieces[i].offRoadBottom1.setTexture(line1);
		roadPieces[i].offRoadBottom1.setTextureRect(sf::IntRect(0, 0, XRESOLUTION * 2, 1));
		roadPieces[i].offRoadBottom1.setPosition(sf::Vector2f(roadPieces[i].xPos, roadPieces[i].yPos - 1.f));
		roadPieces[i].roadBottom2.setTexture(road1T);
		roadPieces[i].roadBottom2.setTextureRect(sf::IntRect(0, i * 2 + 1, XRESOLUTION * 2, 1));
		roadPieces[i].roadBottom2.setPosition(sf::Vector2f(roadPieces[i].xPos, roadPieces[i].yPos - 1.f));
		roadPieces[i].offRoadBottom2.setTexture(line1);
		roadPieces[i].offRoadBottom2.setTextureRect(sf::IntRect(0, 0, XRESOLUTION * 2, 1));
		roadPieces[i].offRoadBottom2.setPosition(sf::Vector2f(roadPieces[i].xPos, roadPieces[i].yPos - 1.f));
	}

	for (int i = 0; i < MAXROADPIECES; i++)
	{
		roadPieces[i].zScaling = (1.f / roadPieces[i].zPos) * roadPieces[YRESOLUTION / 2].zPos;
	}
	std::cout << roadPieces[0].zPos << std::endl;
}

void Road::processRoadXPositions()
{
	int i = 0;
	x = STARTINGXPOS;
	dx = 0;
	while (i < MAXROADPIECES)
	{

		for (int j = 0; j < xSegsLeft; j++)
		{
			if (xSegs[j]->yLoc >= 0 && roadPieces[MAXROADPIECES - 1 - i].zPos >= roadPieces[int(xSegs[j]->yLoc)].zPos)
			{
				ddx = xSegs[j]->ddx;
			}
		}
		dx += ddx * roadPieces[MAXROADPIECES - 1 - i].zPos;
		x += dx;
		roadPieces[MAXROADPIECES - 1 - i].xPos = x + xDistance * float(MAXROADPIECES - 1 - i) / YRESOLUTION * -1;
		i++;
	}
}

void Road::processRoadYPositions()
{
	int i = 0;
	y = STARTINGYPOS;
	dy = 0;
	while (i < MAXROADPIECES)
	{
		for (int j = 0; j < ySegsLeft; j++)
		{
			if (ySegs[j]->yLoc >= 0 && roadPieces[MAXROADPIECES - 1 - i].zPos >= roadPieces[int(ySegs[j]->yLoc)].zPos)
			{
				ddy = ySegs[j]->ddy;
			}
		}
		dy += ddy * roadPieces[MAXROADPIECES - 1 - i].zPos;
		y -= dy + 1;
		roadPieces[MAXROADPIECES - 1 - i].yPos = y;
		if (i > 0)
		{
			if (roadPieces[MAXROADPIECES - 1 - i].yPos - roadPieces[MAXROADPIECES - i].yPos < -4)
			{
				roadPieces[MAXROADPIECES - 1 - i].yPos = roadPieces[MAXROADPIECES - i].yPos - 4;
			}
			else if (roadPieces[MAXROADPIECES - 1 - i].yPos - roadPieces[MAXROADPIECES - i].yPos > 4)
			{
				roadPieces[MAXROADPIECES - 1 - i].yPos = roadPieces[MAXROADPIECES - i].yPos + 4;
			}
		}
		i++;
	}
}

void Road::handleSegments()
{
	if (xSegsLeft > 1)
	{
		if (xSegs[1]->yLoc > 90.f)
		{
			driftThreshold = SPEED_LIMIT - abs(xSegs[1]->ddx) * THRESHCALCULATOR;
		}
		if (xSegs[1]->yLoc > MAXROADPIECES - 2)
		{
			xSegs.erase(xSegs.begin());
			xSegsLeft--;
			std::cout << xSegsLeft << std::endl;
		}
	}
	//driftThreshold = SPEED_LIMIT - abs(xSegs[0]->ddx) * THRESHCALCULATOR;
}

void Road::steer(float speed)
{
	xDistance += (turnSpeed * speed) - driftAmount;

	if (xDistance > XRESOLUTION * 2)
	{
		xDistance = XRESOLUTION * 2;
	}
	else if (xDistance < XRESOLUTION * -2)
	{
		xDistance = XRESOLUTION * -2;
	}
}

void Road::leanLeft()
{
	lDirection = left;
}

void Road::leanRight()
{
	lDirection = right;
}

void Road::standStraight()
{
	lDirection = straight;
}

void Road::hitGas()
{
	onGas = true;
}

void Road::offGas()
{
	onGas = false;
}

void Road::hitBrake()
{
	onBrakes = true;
}

void Road::offBrake()
{
	onBrakes = false;
}

void Road::moveSegments(float speed)
{
	for (int i = 0; i < xSegsLeft; i++)
	{
		if (xSegs[i]->yLoc < MAXROADPIECES - 1)
		{
			xSegs[i]->yLoc += SEGMENTSPEED * speed;
			if (xSegs[i]->yLoc > MAXROADPIECES - 1)
			{
				xSegs[i]->yLoc = MAXROADPIECES - 1;
			}
		}
	}

	for (int i = 0; i < ySegsLeft; i++)
	{
		if (ySegs[i]->yLoc < MAXROADPIECES - 1)
		{
			ySegs[i]->yLoc += SEGMENTSPEED * speed;
			if (ySegs[i]->yLoc > MAXROADPIECES - 1)
			{
				ySegs[i]->yLoc = MAXROADPIECES - 1;
			}
		}
	}
}

void Road::moveStripes(float speed)
{
	for (int i = 0; i < MAXSTRIPES; i++)
	{
		if (textureZ[i][ZTEXTUREMAX - 1] < 0)
		{
			textureZ[i][0] = returnZ1;
			textureZ[i][1] = returnZ2;
		}
		else
		{
			textureZ[i][0] -= speed;
			textureZ[i][1] -= speed;
		}

	}

	for (int i = 0; i < MAXROADPIECES; i++)
	{
		roadPieces[i].textureChange = false;
		for (int j = 0; j < MAXSTRIPES; j++)
		{
			if (roadPieces[i].zPos <= textureZ[j][ZTEXTUREMAX - 1] && roadPieces[i].zPos >= textureZ[j][0])
			{
				roadPieces[i].textureChange = true;
			}
		}
		if (roadPieces[i].textureChange)
		{
			roadPieces[i].roadTop1.setTexture(road2T);
			roadPieces[i].roadTop1.setTextureRect(sf::IntRect(0, i * 2, XRESOLUTION * 2, 1));
			roadPieces[i].roadBottom1.setTexture(road2T);
			roadPieces[i].roadBottom1.setTextureRect(sf::IntRect(0, i * 2 + 1, XRESOLUTION * 2, 1));

			roadPieces[i].offRoadTop1.setTexture(line2);
			roadPieces[i].offRoadTop1.setTextureRect(sf::IntRect(0, 0, XRESOLUTION * 2, 1));
			roadPieces[i].offRoadBottom1.setTexture(line2);
			roadPieces[i].offRoadBottom1.setTextureRect(sf::IntRect(0, 0, XRESOLUTION * 2, 1));

			roadPieces[i].roadTop2.setTexture(road2T);
			roadPieces[i].roadTop2.setTextureRect(sf::IntRect(0, i * 2, XRESOLUTION * 2, 1));
			roadPieces[i].roadBottom2.setTexture(road2T);
			roadPieces[i].roadBottom2.setTextureRect(sf::IntRect(0, i * 2 + 1, XRESOLUTION * 2, 1));

			roadPieces[i].offRoadTop2.setTexture(line2);
			roadPieces[i].offRoadTop2.setTextureRect(sf::IntRect(0, 0, XRESOLUTION * 2, 1));
			roadPieces[i].offRoadBottom2.setTexture(line2);
			roadPieces[i].offRoadBottom2.setTextureRect(sf::IntRect(0, 0, XRESOLUTION * 2, 1));
		}
		else
		{

			roadPieces[i].roadTop1.setTexture(road1T);
			roadPieces[i].roadTop1.setTextureRect(sf::IntRect(0, i * 2, XRESOLUTION * 2, 1));
			roadPieces[i].roadBottom1.setTexture(road1T);
			roadPieces[i].roadBottom1.setTextureRect(sf::IntRect(0, i * 2 + 1, XRESOLUTION * 2, 1));

			roadPieces[i].offRoadTop1.setTexture(line1);
			roadPieces[i].offRoadTop1.setTextureRect(sf::IntRect(0, 0, XRESOLUTION * 2, 1));
			roadPieces[i].offRoadBottom1.setTexture(line1);
			roadPieces[i].offRoadBottom1.setTextureRect(sf::IntRect(0, 0, XRESOLUTION * 2, 1));

			roadPieces[i].roadTop2.setTexture(road1T);
			roadPieces[i].roadTop2.setTextureRect(sf::IntRect(0, i * 2, XRESOLUTION * 2, 1));
			roadPieces[i].roadBottom2.setTexture(road1T);
			roadPieces[i].roadBottom2.setTextureRect(sf::IntRect(0, i * 2 + 1, XRESOLUTION * 2, 1));

			roadPieces[i].offRoadTop2.setTexture(line1);
			roadPieces[i].offRoadTop2.setTextureRect(sf::IntRect(0, 0, XRESOLUTION * 2, 1));
			roadPieces[i].offRoadBottom2.setTexture(line1);
			roadPieces[i].offRoadBottom2.setTextureRect(sf::IntRect(0, 0, XRESOLUTION * 2, 1));
		}
	}
}

void Road::drift(float updateTime)
{
	if (currentSpeed > driftThreshold)
	{
		if (xSegs[0]->ddx > 0.f)
		{
			driftAmount = DRIFTSPEED * (currentSpeed - driftThreshold) * updateTime;
		}
		else if (xSegs[0]->ddx < 0.f)
		{
			driftAmount = -1 * DRIFTSPEED * (currentSpeed - driftThreshold) * updateTime;
		}
	}
	else
	{
		driftAmount = 0.f;
	}

	if (driftAmount > MAXDRIFTSPEED)
	{
		driftAmount = MAXDRIFTSPEED;
	}
	if (driftAmount < -1 * MAXDRIFTSPEED)
	{
		driftAmount = -1 * MAXDRIFTSPEED;
	}
}

void Road::accelerate(float updateTime)
{
	if (onGas)
	{
		currentSpeed += VELOCITY * updateTime;
	}
	else
	{
		currentSpeed -= VELOCITY * updateTime;
	}

	if (onBrakes)
	{
		currentSpeed -= BRAKESPEED * updateTime;
	}

	if (currentSpeed < 0.f)
		currentSpeed = 0.f;
	if (currentSpeed > SPEED_LIMIT)
		currentSpeed = SPEED_LIMIT;
}

void Road::lean(float updateTime)
{
	if (lDirection == straight)
	{
		if (turnSpeed > 0.f)
		{
			turnSpeed -= LEANVELOCITY * updateTime;
		}
		else if (turnSpeed < 0.f)
		{
			turnSpeed += LEANVELOCITY * updateTime;
		}

		if (turnSpeed > -0.01f && turnSpeed < 0.01f)
		{
			turnSpeed = 0.f;
		}
	}
	else if (lDirection == left)
	{
		turnSpeed -= LEANVELOCITY * updateTime;

		if (turnSpeed < -1 * MAXTURNSPEED)
			turnSpeed = -1 * MAXTURNSPEED;
	}
	else if (lDirection == right)
	{
		turnSpeed += LEANVELOCITY * updateTime;
		
		if (turnSpeed > MAXTURNSPEED)
			turnSpeed = MAXTURNSPEED;
	}
}

void Road::update(sf::Time timeSinceLastUpdate)
{
	accelerate(timeSinceLastUpdate.asSeconds());
	float speed = currentSpeed * timeSinceLastUpdate.asSeconds();
	
	moveSegments(speed);
	moveStripes(speed);
	lean(timeSinceLastUpdate.asSeconds());
	steer(speed);
	drift(speed);

	handleSegments();
	processRoadXPositions();
	processRoadYPositions();
	processRoadPiecePosition();

	handler.update(timeSinceLastUpdate.asSeconds(), currentSpeed, roadPieces);
}

void Road::render(sf::RenderWindow &window)
{
	window.draw(rekt);
	for (int i = 0; i < MAXROADPIECES; i++)
	{
		window.draw(roadPieces[i].offRoadTop1);
		window.draw(roadPieces[i].offRoadTop2);
		window.draw(roadPieces[i].offRoadBottom1);
		window.draw(roadPieces[i].offRoadBottom2);
		window.draw(roadPieces[i].roadTop1);
		window.draw(roadPieces[i].roadTop2);
		window.draw(roadPieces[i].roadBottom1);
		window.draw(roadPieces[i].roadBottom2);

		handler.render(window, i);
	}
}