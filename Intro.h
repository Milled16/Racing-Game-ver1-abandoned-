#pragma once
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"

const float LOGOFADERATE = 255.f / 2.f;										//The speed at which the logo fades in and out
const float SCALERATE = 1.f / 3.f;											//The speed at which the baboon in the intro scales

const float LOGOWIDTH = 205.f;												//The width of the logo
const float LOGOHEIGHT = 218.f;												//The height of the logo

const float LOGOX = (320.f / 2.f) - (LOGOWIDTH / 2.f);						//The x position of the logo
const float LOGOY = (224.f / 2.f) - (LOGOHEIGHT / 2.f);						//The y position of the logo

const float BABOONSCALEWIDTH = 320.f;										//The width of the baboon scaled in the intro
const float BABOONSCALEHEIGHT = 224.f;										//The height of the baboon scaled in the intro
const float YMIDDLE = 112.f;												//The middle y position of the screen
const float XMIDDLE = 160.f;												//The middle x position of the screen

const float TITLEHEIGHT = 120.f;													//The height of the title
const float TITLEWIDTH = 320.f * (3.f / 4.f);										//The width of the title
const float TITLEXPOS = (320.f / 2.f) - (TITLEWIDTH / 2.f);							//The X position of the title, which is constant
const float TITLEDROPSPEED = TITLEHEIGHT / .5f;										//The speed at which the title drops

const float TITLEBABOONWIDTH = 320.f;												//The height of the baboon shown on the title screen
const float TITLEBABOONHEIGHT = 320.f - TITLEHEIGHT;								//The width of the baboon shown on the title screen

const float BABOONMOVESPEED = 235.f / .5f;											//The speed at which the baboon slides onto the screen;
const float BABOONYPOS = TITLEHEIGHT + 1.f;											//The y position of the baboon that slides onto the screen, which is just below the titlecard
const float BABOONFINALXPOS = (320 / 2.f) - (TITLEBABOONWIDTH / 2.f);				//The final x position of the baboon

const float PRESSSTARTWIDTH = 160.f;
const float PRESSSTARTHEIGHT = 224.f / 8.f;
const float PRESSSTARTXPOS = (320.f / 2.f) - (PRESSSTARTWIDTH / 2.f);
const float PRESSSTARTYPOS = (224.f / 2.f) - (PRESSSTARTHEIGHT / 2.f);

enum State
{
	showLogo,					//In this state the title shows the logo
	showIntroAnimation,			//In this state the title shows the intro animation
	showTitle					//In this state the title screen is shown
};

enum LogoState
{
	fadeIn,						//This state for when the logo should fade in
	hold,						//This state for when the logo should hold
	fadeOut						//This state for when the logo should fade out
};

enum IntroAnimationState
{
	enlarge,
	shrink
};

enum TitleState
{
	dropTitle,
	moveBaboon,
	showPressStart,
	flashPressStart
};

class Intro
{
public:
	Intro();
	~Intro();

	void				skip();												//Skips parts of the intro when a button is pressed
	void				gameStart();										//Gets the player into the first menu of the game
	void				update(sf::Time timeSinceLastUpdate);				//Updates the intro animations
	void				render(sf::RenderWindow &window);					//Renders everything to the window
	void				restart();											//Restarts all conditions of the intro

	bool				getWaitingToStart();								//returns waitingToStart bool
	bool				getReadyToStart();									//returns readyToStart bool
private:
	bool							waitingToStart;			//Bool is true if "press start" is displayed on screen and the player can press a button to start the game
	bool							readyToStart;			//Bool is true if player pressed start or any button on the "Press Start" screen

	sf::Texture introTextures;

	sf::Sprite						logo;					//The "company" logo
	sf::Sprite						baboonIntro;			//The baboon that flies to the player and then away
	sf::Sprite						baboonTitle;			//The baboon that appears on the title screen
	sf::Sprite						title;					//The title of the game
	sf::Sprite						pressStart;				//The press start sprite

	sf::Time holdTime;

	State							state;					//State of the intro
	LogoState						lState;					//State of the logo animation
	float							logoAlpha;				//The alpha for the logo fade in

	IntroAnimationState				animationState;			//The state of the baboon riding at the viewer animation
	float							baboonScale;			//The scaling factor for the baboon in the intro


	TitleState						tState;					//The current state of the title screen
	float							titleHeight;			//Height of the title as it drops

	float							baboonXPos;				//X position of the baboon as it slides across the screen
};

