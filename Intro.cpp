#include "stdafx.h"
#include <iostream>
#include "Intro.h"


Intro::Intro()
{
	introTextures.loadFromFile("res/textures/introSprites.png");
	logo.setTexture(introTextures);
	logo.setTextureRect(sf::IntRect(2, 2, LOGOWIDTH, LOGOHEIGHT));
	logo.setPosition(sf::Vector2f(LOGOX, LOGOY));

	state = showLogo;
	lState = fadeIn;
	logoAlpha = 0.f;
	holdTime = sf::Time::Zero;

	animationState = enlarge;
	baboonScale = 0.f;

	baboonIntro.setTexture(introTextures);
	baboonIntro.setTextureRect(sf::IntRect(0, 222, BABOONSCALEWIDTH, BABOONSCALEHEIGHT));
	baboonIntro.setScale(sf::Vector2f(0, 0));
	baboonIntro.setPosition(sf::Vector2f(XMIDDLE - XMIDDLE * baboonScale, XMIDDLE - XMIDDLE * baboonScale));

	title.setTexture(introTextures);
	title.setTextureRect(sf::IntRect(0, 671, TITLEWIDTH, TITLEHEIGHT));
	title.setPosition(sf::Vector2f(TITLEXPOS, -1 * TITLEHEIGHT));
	titleHeight = -1.f * TITLEHEIGHT;

	baboonTitle.setTexture(introTextures);
	baboonTitle.setTextureRect(sf::IntRect(0, 894, TITLEBABOONWIDTH, TITLEBABOONHEIGHT));
	baboonTitle.setPosition(sf::Vector2f(-1 * TITLEBABOONWIDTH, TITLEHEIGHT));
	baboonXPos = -1 * TITLEBABOONWIDTH;

	pressStart.setTexture(introTextures);
	pressStart.setTextureRect(sf::IntRect(0, 1006, PRESSSTARTWIDTH, PRESSSTARTHEIGHT));
	pressStart.setPosition(sf::Vector2f(PRESSSTARTXPOS, PRESSSTARTYPOS));

	tState = dropTitle;
	waitingToStart = false;
	readyToStart = false;
}


Intro::~Intro()
{
}

void Intro::skip()
{
	if (state == showLogo)
	{
		logoAlpha = 0.f;
		lState = fadeIn;
		holdTime = sf::Time::Zero;
		state = showIntroAnimation;
	}
	else if (state == showIntroAnimation)
	{
		baboonScale = 0.f;
		animationState = enlarge;
		state = showTitle;
	}
	else if (state == showTitle)
	{
		titleHeight = 0.f;
		title.setPosition(sf::Vector2f(TITLEXPOS, titleHeight));
		baboonXPos = BABOONFINALXPOS;
		baboonTitle.setPosition(sf::Vector2f(baboonXPos, TITLEHEIGHT));
		tState = showPressStart;
	}
}

void Intro::gameStart()
{
	tState = flashPressStart;
}

void Intro::update(sf::Time timeSinceLastUpdate)
{
	if (state == showLogo)
	{
		if (lState == fadeIn)
		{
			logoAlpha += LOGOFADERATE * timeSinceLastUpdate.asSeconds();
			if (logoAlpha >= 255.f)
			{
				logoAlpha = 255.f;
				lState = hold;
			}
			logo.setColor(sf::Color(255, 255, 255, logoAlpha));
		}
		else if (lState == hold)
		{
			holdTime += timeSinceLastUpdate;
			if (holdTime.asSeconds() > 2.f)
			{
				lState = fadeOut;
			}
		}
		else if (lState == fadeOut)
		{
			logoAlpha -= LOGOFADERATE * timeSinceLastUpdate.asSeconds();
			if (logoAlpha <= 0.f)
			{
				logoAlpha = 0.f;
				lState = fadeIn;
				holdTime = sf::Time::Zero;
				state = showIntroAnimation;
			}
			logo.setColor(sf::Color(255, 255, 255, logoAlpha));
		}
	}
	else if (state == showIntroAnimation)
	{
		if (animationState == enlarge)
		{
			baboonScale += SCALERATE* timeSinceLastUpdate.asSeconds();
			if (baboonScale > 1.f)
			{
				baboonScale = 1.f;
				baboonIntro.setTextureRect(sf::IntRect(0, 446, BABOONSCALEWIDTH, BABOONSCALEHEIGHT));
				animationState = shrink;
			}
		}
		else if (animationState == shrink)
		{
			baboonScale -= SCALERATE* timeSinceLastUpdate.asSeconds();
			if (baboonScale < 0.f)
			{
				baboonScale = 0.f;
				animationState = enlarge;
				state = showTitle;
			}
		}
		baboonIntro.setScale(sf::Vector2f(baboonScale, baboonScale));
		baboonIntro.setPosition(sf::Vector2f(XMIDDLE - XMIDDLE * baboonScale, YMIDDLE - YMIDDLE * baboonScale));
	}
	else if (state == showTitle)
	{
		if (tState == dropTitle)
		{
			titleHeight += TITLEDROPSPEED * timeSinceLastUpdate.asSeconds();
			if (titleHeight > 0.f)
			{
				titleHeight = 0.f;
				tState = moveBaboon;
			}
			title.setPosition(sf::Vector2f(TITLEXPOS, titleHeight));
		}
		else if (tState == moveBaboon)
		{
			baboonXPos += BABOONMOVESPEED * timeSinceLastUpdate.asSeconds();
			if (baboonXPos > BABOONFINALXPOS)
			{
				baboonXPos = BABOONFINALXPOS;
				tState = showPressStart;
			}
			baboonTitle.setPosition(sf::Vector2f(baboonXPos, TITLEHEIGHT));
		}
		else if (tState == showPressStart)
		{
			waitingToStart = true;
		}
		else if (tState == flashPressStart)
		{
			waitingToStart = false;
			readyToStart = true;
		}
	}
}

void Intro::render(sf::RenderWindow &window)
{
	if (state == showLogo)
	{
		window.draw(logo);
	}
	else if (state == showIntroAnimation)
	{
		window.draw(baboonIntro);
	}
	else if (state == showTitle)
	{
		window.draw(title);
		window.draw(baboonTitle);
		if (tState == showPressStart)
		{
			window.draw(pressStart);
		}
	}
}

bool Intro::getReadyToStart()
{
	return readyToStart;
}

bool Intro::getWaitingToStart()
{
	return waitingToStart;
}