#include "stdafx.h"
#include "MusicPlayer.h"


MusicPlayer::MusicPlayer()
{
	song0.openFromFile("res/music/loop0.ogg");
	song0.setLoop(true);
}


MusicPlayer::~MusicPlayer()
{
}

void MusicPlayer::playSong()
{
	if (song0.getStatus() == sf::Music::Stopped || song0.getStatus() == sf::Music::Paused)
	{
		song0.play();
	}
}