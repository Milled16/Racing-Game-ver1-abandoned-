/*
	Class used to play music
*/
#pragma once
#include "SFML\Audio.hpp"

class MusicPlayer
{
public:
	MusicPlayer();
	~MusicPlayer();

	void playSong(); //Plays the selected song
	void playSample(int num); //Plays samples of the songs: num argument determines which sample to play
private:
	sf::Music song0; //First song in the list
};

