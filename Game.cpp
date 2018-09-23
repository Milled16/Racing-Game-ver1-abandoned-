#include "stdafx.h"
#include <iostream>
#include "Game.h"


Game::Game()
{
	gState = inIntro;
	window.create(sf::VideoMode(XRES, YRES), "Baboon on a Bike");
	window.setSize(sf::Vector2u(XRES * 3, YRES * 3));
	window.setPosition(sf::Vector2i(800, 200));

	gasButton = 0;
	brakeButton = 1;
	pauseButton = 2;
	if (joystick.isConnected(0))
	{
		joyStickConnected = true;
		joyButtons = joystick.getButtonCount(0);
	}
	else
	{
		joyStickConnected = false;
	}

	gasPressed = false;
	takeGasInput = true;
	brakePressed = false;
	takeBrakeInput = true;
	pausePressed = false;
	takePauseInput = true;

	spacePressed = false;
	takeSpaceInput = true;		

	enterPressed = false;
	takeEnterInput = true;

	escPressed = false;
	takeEscInput = true;

	joyLeftPressed = false;
	takeJoyLeft = true;

	joyRightPressed = false;
	takeJoyRight = true;

	joyUpPressed = false;
	takeJoyUp = true;

	joyDownPressed = false;
	takeJoyDown = true;

	leftPressed = false;
	takeLeftInput = true;
	rightPressed = false;
	takeRightInput = true;
	upPressed = false;
	takeUpInput = true;
	downPressed = false;
	takeDownInput = true;
}


Game::~Game()
{
}

void Game::run()
{
	clock.restart();
	timeSinceLastUpdate = sf::Time::Zero;
	while (window.isOpen())
	{
		process();
		update();
		render();
	}
}

void Game::process()
{
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}

		if (event.type == sf::Event::JoystickButtonPressed)
		{
			buttonProcess(event.joystickButton.button, true);
		}
		if (event.type == sf::Event::JoystickButtonReleased)
		{
			buttonProcess(event.joystickButton.button, false);
		}
		if (event.type == sf::Event::KeyPressed)
		{
			keyPress(event.key.code, true);
		}
		if (event.type == sf::Event::KeyReleased)
		{
			keyPress(event.key.code, false);
		}
		if (event.type == sf::Event::JoystickMoved)
		{
			joyStickMoved(sf::Joystick::getAxisPosition(0, sf::Joystick::X), sf::Joystick::getAxisPosition(0, sf::Joystick::Y));
		}
	}
}

void Game::joyStickMoved(float x, float y)
{
	if (y < -10)
	{
		joyUpPressed = true;
	}
	else if (y > -10)
	{
		joyUpPressed = false;
		takeUpInput = true;
	}
	
	if (y > 10)
	{
		joyDownPressed = true;
	}
	else if (y < 10)
	{
		joyDownPressed = false;
		takeDownInput = true;
	}

	if (x < -10)
	{
		joyLeftPressed = true;
	}
	else if (x > -10)
	{
		joyLeftPressed = false;
		takeLeftInput = true;
	}
	
	if (x > 10)
	{
		joyRightPressed = true;
	}
	else if (x < 10)
	{
		joyRightPressed = false;
		takeRightInput = true;
	}

	if (gState == inMenu)
	{
		if (joyRightPressed && takeRightInput)
		{
			menu.rightPressed();
			takeRightInput = false;
		}
		else if (joyLeftPressed && takeLeftInput)
		{
			menu.leftPressed();
			takeLeftInput = false;
		}

		if (joyUpPressed && takeUpInput)
		{
			menu.upPressed();
			takeUpInput = false;
		}
		else if (joyDownPressed && takeDownInput)
		{
			menu.downPressed();
			takeDownInput = false;
		}
	}
	else if (gState == inRoad)
	{
		if (joyLeftPressed)
		{
			road.leanLeft();
		}
		else if (joyRightPressed)
		{
			road.leanRight();
		}
		else if (!joyLeftPressed && !joyRightPressed)
		{
			road.standStraight();
		}
	}
}

void Game::keyPress(sf::Keyboard::Key key, bool isPressed)
{
	switch (key)
	{
	case sf::Keyboard::Space:
		spacePressed = isPressed;
		if (!isPressed)
			takeSpaceInput = true;
		break;
	case sf::Keyboard::Return:
		enterPressed = isPressed;
		if (!isPressed)
			takeEnterInput = true;
		break;
	case sf::Keyboard::Escape:
		escPressed = isPressed;
		if (!isPressed)
			takeEscInput = true;
		break;

	case sf::Keyboard::W:
	case sf::Keyboard::Up:
		upPressed = isPressed;
		if (!isPressed && !joyUpPressed)
			takeUpInput = true;
		break;
	case sf::Keyboard::S:
	case sf::Keyboard::Down:
		downPressed = isPressed;
		if (!isPressed && !joyDownPressed)
			takeDownInput = true;
		break;
	case sf::Keyboard::A:
	case sf::Keyboard::Left:
		leftPressed = isPressed;
		if (!isPressed && !joyLeftPressed)
			takeLeftInput = true;
		break;
	case sf::Keyboard::D:
	case sf::Keyboard::Right:
		rightPressed = isPressed;
		if (!isPressed && !joyRightPressed)
			takeRightInput = true;
		break;
	}

	if (gState == inIntro)
	{
		if (takeSpaceInput && spacePressed || takeEnterInput && enterPressed)
		{
			intro.skip();

			if (intro.getWaitingToStart())
			{
				intro.gameStart();
			}

			if (enterPressed)
				takeEnterInput = false;
			if (spacePressed)
				takeSpaceInput = false;
		}
	}
	else if (gState == inMenu)
	{
		if (rightPressed && takeRightInput)
		{
			menu.rightPressed();
			takeRightInput = false;
		}
		else if (leftPressed && takeLeftInput)
		{
			menu.leftPressed();
			takeLeftInput = false;
		}
		else if (upPressed && takeUpInput)
		{
			menu.upPressed();
			takeUpInput = false;
		}
		else if (downPressed && takeDownInput)
		{
			menu.downPressed();
			takeDownInput = false;
		}
		else if (spacePressed && takeSpaceInput || enterPressed && takeEnterInput)
		{
			menu.selectPressed();
			takeSpaceInput = false;
			takeEnterInput = false;
		}
		else if (escPressed && takeEscInput)
		{
			menu.backPressed();
			takeEscInput = false;
		}
	}
	else if (gState == inRoad)
	{
		if (upPressed)
		{
			road.hitGas();
		}
		else if (!upPressed && !gasPressed)
		{
			road.offGas();
		}

		if (spacePressed)
		{
			road.hitBrake();
		}
		else if (!spacePressed && !brakePressed)
		{
			road.offBrake();
		}

		if (rightPressed)
		{
			road.leanRight();
		}
		else if (leftPressed)
		{
			road.leanLeft();
		}
		else if (!rightPressed && !leftPressed)
		{
			road.standStraight();
		}
	}
	else if (gState == inGameOver)
	{

	}
}

void Game::buttonProcess(unsigned int button, bool isPressed)
{
	if (button == gasButton && isPressed)
	{
		gasPressed = true;
	}
	else if (button == gasButton && !isPressed)
	{
		gasPressed = false;
		takeGasInput = true;
	}
	else if (button == brakeButton && isPressed)
	{
		brakePressed = true;
	}
	else if (button == brakeButton && !isPressed)
	{
		brakePressed = false;
		takeBrakeInput = true;
	}
	else if (button == pauseButton && isPressed)
	{
		pausePressed = true;
	}
	else if (button == pauseButton && !isPressed)
	{
		pausePressed = false;
		takePauseInput = true;
	}

	if (gState == inIntro)
	{
		if (pausePressed && takePauseInput || gasPressed && takeGasInput || brakePressed && takeBrakeInput)
		{
			intro.skip();
			if (intro.getWaitingToStart())
			{
				intro.gameStart();
			}
			if (pausePressed)
				takePauseInput = false;
			else if (brakePressed)
				takeBrakeInput = false;
			else if (gasPressed)
				takeGasInput = false;
		}
	}
	else if (gState == inMenu)
	{
		if (gasPressed && takeGasInput || pausePressed && takePauseInput)
		{
			menu.selectPressed();
			takePauseInput = false;
			takeGasInput = false;
		}

		if (brakePressed && takeBrakeInput)
		{
			menu.backPressed();
			takeBrakeInput = false;
		}
	}
	else if (gState == inRoad)
	{
		if (gasPressed)
		{
			road.hitGas();
		}
		else if (!gasPressed && !upPressed)
		{
			road.offGas();
		}

		if (brakePressed)
		{
			road.hitBrake();
		}
		else if (!brakePressed && !spacePressed)
		{
			road.offBrake();
		}
	}
	else if (gState == inGameOver)
	{

	}
}

void Game::update()
{
	timeSinceLastUpdate = clock.restart();
	if (gState == inIntro)
	{
		intro.update(timeSinceLastUpdate);
		if (intro.getReadyToStart())
		{
			gState = inMenu;
		}
	}
	else if (gState == inMenu)
	{
		menu.update(timeSinceLastUpdate);
		if (menu.goToRace())
		{
			gState = inRoad;
		}
	}
	else if (gState == inRoad)
	{
		road.update(timeSinceLastUpdate);
	}
	else if (gState == inGameOver)
	{

	}
}

void Game::render()
{
	window.clear();
	if (gState == inIntro)
	{
		intro.render(window);
	}
	else if (gState == inMenu)
	{
		menu.render(window);
	}
	else if (gState == inRoad)
	{
		road.render(window);
	}
	else if (gState == inGameOver)
	{

	}
	window.display();
}