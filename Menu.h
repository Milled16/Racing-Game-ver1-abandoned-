#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>

const float MENUMOVESPEED = 320.f / 0.5f;
const float TEXTBOXWIDTH = 316.f;
const float TEXTBOXHEIGHT = 71.f;

const float TEXTBOXXPOS = 2.f;													//Textbox moves on and off screen depending on the menu, so this is its final x position
const float TEXTBOXYPOS = 224.f - TEXTBOXHEIGHT - 2.f;							//Textbox y pos is the height of the screen minus the height of the textbox minus 2 pixels

const float TOPBOXYPOS = 3.f;													//The y position the top boxes sit on

const float BOXDIMENSIONS = 71.f;												//The width and height of each box

const float BOTTOMBOXYPOS = TOPBOXYPOS + BOXDIMENSIONS + 4.f;					//The y position the bottom boxes sit on

const float STARTBOXXPOS = 26.f;												//The X position of the start box

const float OPTIONSBOXXPOS = STARTBOXXPOS + BOXDIMENSIONS + 27.f;				//THe x position of the options box

const float QUITBOXXPOS = OPTIONSBOXXPOS + BOXDIMENSIONS + 27.f;				//The x position of the quit box

const float COURSE1BOXXPOS = STARTBOXXPOS + 320.f;

const float COURSE2BOXXPOS = OPTIONSBOXXPOS + 320.f;

const float COURSE3BOXXPOS = QUITBOXXPOS + 320.f;

const float COURSE4BOXXPOS = 320.f + 59.f;

const float COURSE5BOXXPOS = COURSE4BOXXPOS +  BOXDIMENSIONS + 59.f;

const float LEFTSONGBOXXPOS = 640.f + 59.f;

const float RIGHTSONGBOXXPOS = LEFTSONGBOXXPOS + BOXDIMENSIONS + 59.f;

enum SubMenuState
{
	start,				//The part of the menu that allows the play to start the game, go to options, or quit
	selectRoad,			//The part of the menu where the player can select which track to drive on
	selectSong,			//The part of the menu where the player can select which song to play on the road
	options			//The menu that give the play access to the different 
};

class Menu
{
public:
	Menu();

	void					downPressed();
	void					upPressed();
	void					leftPressed();
	void					rightPressed();

	void					selectPressed();
	void					backPressed();

	void					flashSelector(sf::Time timeSinceLastUpdate);		//Flashes the box that surrounds the selectable boxes
	void					moveMenu(sf::Time timeSinceLastUpdate);				//Moves all menu items left or right
	void					update(sf::Time timeSinceLastUpdate);
	void					render(sf::RenderWindow &window);
	void					restart();											//Restarts all conditions of the menu

	bool					goToRace();											//Returns true if the game should go to the road
private:

	unsigned int startSelection;			//0 = startgame; 1 = options; 2 = quit

	unsigned int roadSelection;				//0 = very easy course; 1 = easy course; 2 = medium course; 3 = hard course; 4 = course

	unsigned int songselection;				//0 = first song; 1 = second song; 2 = third track; 3 = fourth track

	sf::Texture menuTexture;				//The texture for all menu sprites

	sf::Sprite textBox;						//The textbox on the menu screens

	sf::Sprite boxOutline;					//The outline shows which box the player is about to select
	sf::Sprite startBox;					//The selection box that gets the player into the road selection screen
	sf::Sprite optionBox;					//The selection box that gets the player into the options menu
	sf::Sprite quitBox;						//The selection box that quits that game

	sf::Sprite course1Box;
	sf::Sprite course2Box;
	sf::Sprite course3Box;
	sf::Sprite course4Box;
	sf::Sprite course5Box;

	sf::Sprite song1Box;
	sf::Sprite song2Box;
	sf::Sprite song3Box;
	sf::Sprite song4Box;

	sf::Time		flashTime;				//The amount of time the selector has been flashing
	float			flashSwitchTime;		

	bool			flashingOver;			//Returns true when the flashTime is greater than or equal to 2;
	bool			shouldFlash;			//Is true when the selector box should flash after selecting a song
	bool			isOpaque;				//Is true when the selector should be opaque;

	float			globalXOffset;			//This variable is added to the value of every sprite (except the box outline) to 
	float			newXOffset;				//This variable is used to determine what new x value the new offset should be set to

	SubMenuState	menuState;					//Determines which menu to be in

	bool			transitioning;			//bool is true if menu is sliding over to a different section
	bool			shouldRace;				//bool is true when the race should start
};

