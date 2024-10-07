#include "Sound.hpp"

Sound::Sound()
{
	LoadSound();
	SetSounds();
}

void Sound::LoadSound()
{
	if (!score_buffer.loadFromFile("assets\\Sounds\\score.wav"))
	{
		std::cout << "Couldnt load a scoure sound file!" << std::endl;
	}
	if (!bounce_buffer.loadFromFile("assets\\Sounds\\bounce.wav"))
	{
		std::cout << "Couldnt load a bounce sound file!" << std::endl;
	}
}

void Sound::SetSounds()
{
	score_sound.setBuffer(score_buffer);
	bounce_sound.setBuffer(bounce_buffer);
}

void Sound::PlayScoreSound()
{
	score_sound.play();
}

void Sound::PlayBounceSound()
{
	bounce_sound.play();
}