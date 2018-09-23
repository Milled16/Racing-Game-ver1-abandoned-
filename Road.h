#pragma once
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"
#include <fstream>
#include <iostream>
#include <vector>

#include "ObjectHandler.h"

const int XRESOLUTION = 320;
const int YRESOLUTION = 224;
const int ZTEXTUREMAX = 2; //Number of values in each stripe. The 0th value is the bottom of the stripe, and the 1st value is the top of the stripe.
const int MAXSTRIPES = 50; //Max number of stripes on the road
//const int MAXZVALUES = YRESOLUTION + YRESOLUTION / 30;
//const int MAXROADPIECES = 256 / 2; //Max number of RoadPieces
const int FOV = 60; //Angle of the field of view

const float VELOCITY = 0.05f; //Amount by which the speed increases per second if the player is on the gas, or by which the player slows down if the player steps off the gas
const float BRAKESPEED = VELOCITY + VELOCITY / 2.f; //Amount of speed the player loses while braking. Added on top of decceleration speed if player is braking

const float SPEED_LIMIT = .2f; //Highest amount the player's bike goes
const float THRESHCALCULATOR = ((SPEED_LIMIT / float(3)) - SPEED_LIMIT) / -3; //This number is multiplied by the ddx to determine the threshold for when the player starts to drift
const float MAXTURNSPEED = 3000.f; //Turning speed of the player's bike

const float LEANVELOCITY = MAXTURNSPEED / .25f; //The speed at which the player leans
const float MAXDRIFTSPEED = MAXTURNSPEED * .75f; //Max amount the players bike will drift
const float DRIFTSPEED = MAXTURNSPEED * SPEED_LIMIT / (SPEED_LIMIT - (SPEED_LIMIT - THRESHCALCULATOR * .7f)) * 5;
const float SEGMENTSPEED = (YRESOLUTION / 4) / SPEED_LIMIT;
const float STARTINGYPOS = YRESOLUTION + (MAXROADPIECES - (YRESOLUTION / 2));
const float STARTINGXPOS = (-1 * XRESOLUTION) / 2;
const float STRIPEWIDTH = (1.f / float(MAXSTRIPES)) * .5f; //Width of each stripe, which is the inverse of MAXSTRIPES divided in half

/*struct RoadPiece //struct for a scanline of the road
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
};*/

struct roadSegmentX //a segment of the road that determines the curve any piece of road in front of it on the z-plane
{
	float	yLoc; //The z location of the beginning of the segment
	float	ddx; //The curve offset of the segment
};

struct roadSegmentY
{
	float	yLoc; //The z location of the beginning of the segment
	float	ddy; //The hill offset of the segment
};

enum LeanDirection
{
	straight,
	left,
	right
};

class Road
{
public:
	Road();

	void					processRoadPiecePosition();//Processes position of the road pieces and determine which scan line it appears in.
	void					processRoadDimensions(); //Sets up the road and scanlines as well as comes up with a z table and scaling value for scanlines;
	void					processRoadXPositions(); //Processes the screen X positions of the road segments
	void					processRoadYPositions(); //Processes the screen Y positions of the road segments
	void					handleSegments(); //Removes segments from the road as they leave the screen
	void					steer(float speed); //Keeps the road in perspective while steering: distance is the distance between the center of the screen and the center of the bottom of the road

	void					leanLeft();
	void					leanRight();
	void					standStraight();

	void					hitGas();
	void					offGas();				//I know its not a real word
	void					hitBrake();
	void					offBrake();

	void					moveSegments(float speed);
	void					moveStripes(float speed);
	void					drift(float updateTime);

	void					accelerate(float updateTime);
	void					lean(float updateTime);
	void					update(sf::Time timeSinceLastUpdate);
	void					render(sf::RenderWindow &window); //Render loop for the road graphic

private:
	int					maxStripes; //Max number of stripes on the road
	int					xSegsLeft;
	int					ySegsLeft;

	float				roadGraphicHeight; //Screen height of the road graphic
	float				stripeWidth; //Width of the stripes on the road
	float				returnZ1; //Z value that the top of a stripe returns to after exiting the screen
	float				returnZ2; //Z value that the bottom of a stripe returns to after exiting the screen
	float				xDistance; //distance of the x position of the bottom of the road to the x position of the screen
	float				driftAmount; //How much the screen drifts left or right depending on the curve of the road
	float				driftThreshold; //How fast the player must be going to start drifting

	float				textureZ[MAXSTRIPES][ZTEXTUREMAX]; //2-dimensional array of stripe Z-values. First subscript indicates which stripe, and second subscript indicates the z values for the bottom and top stripe

	float				currentSpeed;
	float				turnSpeed;

	float				ddx;
	float				dx;
	float				x;

	float				ddy;
	float				dy;
	float				y;

	bool				onGas;
	bool				onBrakes;

	RoadPiece			roadPieces[MAXROADPIECES];
	LeanDirection		lDirection;

	std::vector<roadSegmentX*> xSegs;
	std::vector<roadSegmentY*> ySegs;

	sf::Texture			road1T; //First alternating road texture
	sf::Texture			road2T; //Second alternating road texture
	sf::Texture			driverTextures;
	sf::Texture			environmentTextures;

	sf::Texture			line1;	//First alternating background line
	sf::Texture			line2;	//Second alternating baground line

	ObjectHandler		handler;

	sf::RectangleShape	rekt;
};

