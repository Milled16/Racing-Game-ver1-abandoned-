#pragma once
#include "SFML\Graphics.hpp"
#include "Intro.h"
#include "Menu.h"
#include "Road.h"

const int XRES = 320; //Width of the screen in pixels
const int YRES = 224; //Height of the screen in pixels

enum GameState
{
	inIntro,
	inMenu,
	inRoad,
	inGameOver,
	inVictory
};


class Game
{
public:
	Game();
	~Game();

	void	run();

	void	process();
	void	keyPress(sf::Keyboard::Key key, bool isPressed);
	void	buttonProcess(unsigned int button, bool isPressed);
	void	joyStickMoved(float x, float y);
	void	update();
	void	render();

private:

	GameState gState;

	sf::RenderWindow			window;
	sf::Event					event;
	sf::Clock					clock;
	sf::Time					timeSinceLastUpdate;
	sf::Joystick				joystick;
	unsigned int				joyButtons;
	unsigned int				gasButton;
	unsigned int				brakeButton;
	unsigned int				pauseButton;

	bool						gasPressed;					//Bool is true if gas is pressed and false if released
	bool						takeGasInput;				//Bool is used in instances where holding down gas should only register one action
	bool						brakePressed;				//Bool is true if brake is pressed and false if released
	bool						takeBrakeInput;				//Bool is used in instances where holding down brake should only register one action
	bool						pausePressed;				//Bool is true if pause is pressed and false if released
	bool						takePauseInput;				//Bool is used in instances where holding down pause should only register one action
	bool						joyStickConnected;			//Bool is true if joystick is connected

	bool						spacePressed;				//Bool is true if space is pressed and false if released
	bool						takeSpaceInput;				//Bool is used in instances where holding down space should only register one action

	bool						enterPressed;
	bool						takeEnterInput;

	bool						escPressed;
	bool						takeEscInput;

	//Booleans for directional buttons pressed
	bool						joyLeftPressed;
	bool						takeJoyLeft;

	bool						joyRightPressed;
	bool						takeJoyRight;

	bool						joyUpPressed;
	bool						takeJoyUp;

	bool						joyDownPressed;
	bool						takeJoyDown;

	bool						leftPressed;
	bool						takeLeftInput;
	bool						rightPressed;
	bool						takeRightInput;
	bool						upPressed;
	bool						takeUpInput;
	bool						downPressed;
	bool						takeDownInput;

	Intro						intro;						//The intro of the game
	Menu						menu;						//The menus of the game
	Road						road;						//The road of the game
};

