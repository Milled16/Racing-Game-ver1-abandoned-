#include "stdafx.h"
#include "Menu.h"


Menu::Menu()
{
	menuTexture.loadFromFile("res/textures/menuSprites.png");

	textBox.setTexture(menuTexture);
	textBox.setTextureRect(sf::IntRect(0, 0, TEXTBOXWIDTH, TEXTBOXHEIGHT));
	textBox.setPosition(sf::Vector2f(TEXTBOXXPOS, TEXTBOXYPOS));

	boxOutline.setTexture(menuTexture);
	boxOutline.setTextureRect(sf::IntRect(0, 321, BOXDIMENSIONS + 4.f, BOXDIMENSIONS + 4.f));
	boxOutline.setPosition(sf::Vector2f(STARTBOXXPOS - 2.f, TOPBOXYPOS - 2.f));

	startBox.setTexture(menuTexture);
	startBox.setTextureRect(sf::IntRect(0, 108, BOXDIMENSIONS, BOXDIMENSIONS));
	startBox.setPosition(sf::Vector2f(STARTBOXXPOS, TOPBOXYPOS));
	
	optionBox.setTexture(menuTexture);
	optionBox.setTextureRect(sf::IntRect(71, 108, BOXDIMENSIONS, BOXDIMENSIONS));
	optionBox.setPosition(sf::Vector2f(OPTIONSBOXXPOS, TOPBOXYPOS));

	quitBox.setTexture(menuTexture);
	quitBox.setTextureRect(sf::IntRect(142, 108, BOXDIMENSIONS, BOXDIMENSIONS));
	quitBox.setPosition(sf::Vector2f(QUITBOXXPOS, TOPBOXYPOS));

	course1Box.setTexture(menuTexture);
	course1Box.setTextureRect(sf::IntRect(213, 108, BOXDIMENSIONS, BOXDIMENSIONS));
	course1Box.setPosition(sf::Vector2f(COURSE1BOXXPOS, TOPBOXYPOS));

	course2Box.setTexture(menuTexture);
	course2Box.setTextureRect(sf::IntRect(0, 179, BOXDIMENSIONS, BOXDIMENSIONS));
	course2Box.setPosition(sf::Vector2f(COURSE2BOXXPOS, TOPBOXYPOS));
	
	course3Box.setTexture(menuTexture);
	course3Box.setTextureRect(sf::IntRect(71, 179, BOXDIMENSIONS, BOXDIMENSIONS));
	course3Box.setPosition(sf::Vector2f(COURSE3BOXXPOS, TOPBOXYPOS));

	course4Box.setTexture(menuTexture);
	course4Box.setTextureRect(sf::IntRect(142, 179, BOXDIMENSIONS, BOXDIMENSIONS));
	course4Box.setPosition(sf::Vector2f(COURSE4BOXXPOS, BOTTOMBOXYPOS));

	course5Box.setTexture(menuTexture);
	course5Box.setTextureRect(sf::IntRect(213, 179, BOXDIMENSIONS, BOXDIMENSIONS));
	course5Box.setPosition(sf::Vector2f(COURSE5BOXXPOS, BOTTOMBOXYPOS));

	song1Box.setTexture(menuTexture);
	song1Box.setTextureRect(sf::IntRect(0, 250, BOXDIMENSIONS, BOXDIMENSIONS));
	song1Box.setPosition(sf::Vector2f(LEFTSONGBOXXPOS, TOPBOXYPOS));

	song2Box.setTexture(menuTexture);
	song2Box.setTextureRect(sf::IntRect(71, 250, BOXDIMENSIONS, BOXDIMENSIONS));
	song2Box.setPosition(sf::Vector2f(RIGHTSONGBOXXPOS, TOPBOXYPOS));

	song3Box.setTexture(menuTexture);
	song3Box.setTextureRect(sf::IntRect(142, 250, BOXDIMENSIONS, BOXDIMENSIONS));
	song3Box.setPosition(sf::Vector2f(LEFTSONGBOXXPOS, BOTTOMBOXYPOS));

	song4Box.setTexture(menuTexture);
	song4Box.setTextureRect(sf::IntRect(213, 250, BOXDIMENSIONS, BOXDIMENSIONS));
	song4Box.setPosition(sf::Vector2f(RIGHTSONGBOXXPOS, BOTTOMBOXYPOS));

	menuState = start;
	globalXOffset = 0.f;
	newXOffset = 0.f;
	menuState = start;
	shouldFlash = false;
	flashingOver = false;
	flashTime = sf::Time::Zero;
	isOpaque = true;
	flashSwitchTime = 0.f;
	shouldRace = false;
}

void Menu::upPressed()
{
	if (!transitioning && !shouldFlash)
	{
		if (menuState == start)
		{

		}
		else if (menuState == selectRoad)
		{
			switch (roadSelection)
			{
			case 0:
			case 1:
				roadSelection = 3;
				break;
			case 2:
				roadSelection = 4;
				break;
			case 3:
				roadSelection = 1;
				break;
			case 4:
				roadSelection = 2;
				break;
			}
		}
		else if (menuState == selectSong)
		{
			switch (songselection)
			{
			case 0:
				songselection = 2;
				break;
			case 1:
				songselection = 3;
				break;
			case 2:
				songselection = 0;
				break;
			case 3:
				songselection = 1;
				break;
			}
		}
		else if (menuState == options)
		{

		}
	}
}

void Menu::downPressed()
{
	if (!transitioning && !shouldFlash)
	{
		if (menuState == start)
		{

		}
		else if (menuState == selectRoad)
		{
			switch (roadSelection)
			{
			case 0:
			case 1:
				roadSelection = 3;
				break;
			case 2:
				roadSelection = 4;
				break;
			case 3:
				roadSelection = 0;
				break;
			case 4:
				roadSelection = 2;
				break;
			}
		}
		else if (menuState == selectSong)
		{
			switch (songselection)
			{
			case 0:
				songselection = 2;
				break;
			case 1:
				songselection = 3;
				break;
			case 2:
				songselection = 0;
				break;
			case 3:
				songselection = 1;
				break;
			}
		}
		else if (menuState == options)
		{

		}
	}
}

void Menu::leftPressed()
{
	if (!transitioning && !shouldFlash)
	{
		if (menuState == start)
		{
			switch (startSelection)
			{
			case 0:
				startSelection = 2;
				break;
			case 1:
				startSelection = 0;
				break;
			case 2:
				startSelection = 1;
				break;
			}
		}
		else if (menuState == selectRoad)
		{
			switch (roadSelection)
			{
			case 0:
				roadSelection = 2;
				break;
			case 1:
				roadSelection = 0;
				break;
			case 2:
				roadSelection = 1;
				break;
			case 3:
				roadSelection = 4;
				break;
			case 4:
				roadSelection = 3;
				break;
			}
		}
		else if (menuState == selectSong)
		{
			switch (songselection)
			{
			case 0:
				songselection = 1;
				break;
			case 1:
				songselection = 0;
				break;
			case 2:
				songselection = 3;
				break;
			case 3:
				songselection = 2;
				break;
			}
		}
		else if (menuState == options)
		{

		}
	}
}

void Menu::rightPressed()
{
	if (!transitioning && !shouldFlash)
	{
		if (menuState == start)
		{
			switch (startSelection)
			{
			case 0:
				startSelection = 1;
				break;
			case 1:
				startSelection = 2;
				break;
			case 2:
				startSelection = 0;
				break;
			}
		}
		else if (menuState == selectRoad)
		{
			switch (roadSelection)
			{
			case 0:
				roadSelection = 1;
				break;
			case 1:
				roadSelection = 2;
				break;
			case 2:
				roadSelection = 0;
				break;
			case 3:
				roadSelection = 4;
				break;
			case 4:
				roadSelection = 3;
				break;
			}
		}
		else if (menuState == selectSong)
		{
			switch (songselection)
			{
			case 0:
				songselection = 1;
				break;
			case 1:
				songselection = 0;
				break;
			case 2:
				songselection = 3;
				break;
			case 3:
				songselection = 2;
				break;
			}
		}
		else if (menuState == options)
		{

		}
	}
}

void Menu::selectPressed()
{
	if (!transitioning && !shouldFlash)
	{
		if (menuState == start)
		{
			switch (startSelection)
			{
			case 0:
				menuState = selectRoad;
				transitioning = true;
				newXOffset = -320;
				break;
			case 1:
				menuState = options;
				transitioning = true;
				newXOffset = 320;
				break;
			case 2:
				break;
			}
		}
		else if (menuState == selectRoad)
		{
			switch (roadSelection)
			{
			case 0:
				break;
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			}

			menuState = selectSong;
			transitioning = true;
			newXOffset = -640;
		}
		else if (menuState == selectSong)
		{
			switch (songselection)
			{
			case 0:
				break;
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			}
			shouldFlash = true;
		}
		else if (menuState == options)
		{

		}
	}
}

void Menu::backPressed()
{
	if (!transitioning && !shouldFlash)
	{
		if (menuState == start)
		{

		}
		else if (menuState == options)
		{
			menuState = start;
			newXOffset = 0;
			transitioning = true;
		}
		else if (menuState == selectRoad)
		{
			menuState = start;
			newXOffset = 0;
			transitioning = true;
		}
		else if (menuState == selectSong)
		{
			menuState = selectRoad;
			newXOffset = -320;
			transitioning = true;
		}
	}
}

void Menu::flashSelector(sf::Time timeSinceLastUpdate)
{
	flashTime += timeSinceLastUpdate;
	flashSwitchTime += timeSinceLastUpdate.asSeconds();
	if (flashTime.asSeconds() >= 1.f)
	{
		flashingOver = true;
	}
	if (flashSwitchTime >= 0.075f)
	{
		if (isOpaque)
		{
			isOpaque = false;
		}
		else if (!isOpaque)
		{
			isOpaque = true;
		}
		flashSwitchTime = 0.f;
	}

	if (isOpaque)
	{
		boxOutline.setColor(sf::Color(255, 255, 255, 255));
	}
	else if (!isOpaque)
	{
		boxOutline.setColor(sf::Color(255, 255, 255, 0));
	}

}

void Menu::moveMenu(sf::Time timeSinceLastUpdate)
{
	if (globalXOffset >= newXOffset)
	{
		globalXOffset -= MENUMOVESPEED * timeSinceLastUpdate.asSeconds();
	}
	else if (globalXOffset <= newXOffset)
	{
		globalXOffset += MENUMOVESPEED * timeSinceLastUpdate.asSeconds();
	}

	if (globalXOffset < newXOffset + 0.01f && globalXOffset > newXOffset - 0.01f)
	{
		transitioning = false;
	}

	startBox.setPosition(sf::Vector2f(STARTBOXXPOS + globalXOffset, TOPBOXYPOS));

	optionBox.setPosition(sf::Vector2f(OPTIONSBOXXPOS + globalXOffset, TOPBOXYPOS));

	quitBox.setPosition(sf::Vector2f(QUITBOXXPOS + globalXOffset, TOPBOXYPOS));

	course1Box.setPosition(sf::Vector2f(COURSE1BOXXPOS + globalXOffset, TOPBOXYPOS));

	course2Box.setPosition(sf::Vector2f(COURSE2BOXXPOS + globalXOffset, TOPBOXYPOS));

	course3Box.setPosition(sf::Vector2f(COURSE3BOXXPOS + globalXOffset, TOPBOXYPOS));

	course4Box.setPosition(sf::Vector2f(COURSE4BOXXPOS + globalXOffset, BOTTOMBOXYPOS));

	course5Box.setPosition(sf::Vector2f(COURSE5BOXXPOS + globalXOffset, BOTTOMBOXYPOS));

	song1Box.setPosition(sf::Vector2f(LEFTSONGBOXXPOS + globalXOffset, TOPBOXYPOS));

	song2Box.setPosition(sf::Vector2f(RIGHTSONGBOXXPOS + globalXOffset, TOPBOXYPOS));

	song3Box.setPosition(sf::Vector2f(LEFTSONGBOXXPOS + globalXOffset, BOTTOMBOXYPOS));

	song4Box.setPosition(sf::Vector2f(RIGHTSONGBOXXPOS + globalXOffset, BOTTOMBOXYPOS));
}

void Menu::update(sf::Time timeSinceLastUpdate)
{
	if (menuState == start)
	{
		switch (startSelection)
		{
		case 0:
			boxOutline.setPosition(sf::Vector2f(STARTBOXXPOS - 2.f, TOPBOXYPOS - 2.f));
			break;
		case 1:
			boxOutline.setPosition(sf::Vector2f(OPTIONSBOXXPOS - 2.f, TOPBOXYPOS - 2.f));
			break;
		case 2:
			boxOutline.setPosition(sf::Vector2f(QUITBOXXPOS - 2.f, TOPBOXYPOS - 2.f));
			break;
		}
	}
	else if (menuState == selectRoad)
	{
		switch (roadSelection)
		{
		case 0:
			boxOutline.setPosition(sf::Vector2f(course1Box.getPosition().x - 2.f, TOPBOXYPOS - 2.f));
			break;
		case 1:
			boxOutline.setPosition(sf::Vector2f(course2Box.getPosition().x - 2.f, TOPBOXYPOS - 2.f));
			break;
		case 2:
			boxOutline.setPosition(sf::Vector2f(course3Box.getPosition().x - 2.f, TOPBOXYPOS - 2.f));
			break;
		case 3:
			boxOutline.setPosition(sf::Vector2f(course4Box.getPosition().x - 2.f, BOTTOMBOXYPOS - 2.f));
			break;
		case 4:
			boxOutline.setPosition(sf::Vector2f(course5Box.getPosition().x - 2.f, BOTTOMBOXYPOS - 2.f));
			break;
		}
	}
	else if (menuState == selectSong)
	{
		switch (songselection)
		{
		case 0:
			boxOutline.setPosition(sf::Vector2f(song1Box.getPosition().x - 2.f, TOPBOXYPOS - 2.f));
			break;
		case 1:
			boxOutline.setPosition(sf::Vector2f(song2Box.getPosition().x - 2.f, TOPBOXYPOS - 2.f));
			break;
		case 2:
			boxOutline.setPosition(sf::Vector2f(song3Box.getPosition().x - 2.f, BOTTOMBOXYPOS - 2.f));
			break;
		case 3:
			boxOutline.setPosition(sf::Vector2f(song4Box.getPosition().x - 2.f, BOTTOMBOXYPOS - 2.f));
			break;
		}
	}
	else if (menuState == options)
	{

	}

	if (transitioning)
		moveMenu(timeSinceLastUpdate);

	if (shouldFlash)
		flashSelector(timeSinceLastUpdate);

	if (flashingOver)
	{
		shouldFlash = false;
		shouldRace = true;
	}
}

void Menu::render(sf::RenderWindow &window)
{
	window.draw(startBox);
	window.draw(optionBox);
	window.draw(quitBox);

	window.draw(course1Box);
	window.draw(course2Box);
	window.draw(course3Box);
	window.draw(course4Box);
	window.draw(course5Box);

	window.draw(song1Box);
	window.draw(song2Box);
	window.draw(song3Box);
	window.draw(song4Box);

	window.draw(textBox);

	if (!transitioning && menuState != options)
	{
		window.draw(boxOutline);
	}
}

bool Menu::goToRace()
{
	return shouldRace;
}