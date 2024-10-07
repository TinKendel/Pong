#pragma once

#include <iostream>
#include "SFML/Audio.hpp"

class Sound
{
private:
	sf::SoundBuffer score_buffer;
	sf::SoundBuffer bounce_buffer;
	sf::Sound score_sound;
	sf::Sound bounce_sound;

public:
	/// \brief Constructor.
	Sound();

	/// \brief Loads the sound file.
	void LoadSound();

	/// \brief Sets the sound files to the sound object.
	void SetSounds();

	/// \brief Playes score sound.
	void PlayScoreSound();

	/// \brief Playes bounce sound.
	void PlayBounceSound();
};