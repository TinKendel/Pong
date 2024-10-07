#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Paddle.hpp"
#include "Ball.hpp"
#include "Wall.hpp"
#include "Score.hpp"
#include "Sound.hpp"


class Game
{
private:
	Paddle* left_paddle;
	Paddle* right_paddle;
	Ball* ball;
	Wall* wall;
	Score* score;
	Sound* sound;

public:
	/// \brief Constructor. 
	Game();

	/// \brief Destructor. 
	~Game();

	/// \brief Creates all objects for the game to function.
	void StartGame();

	/// \brief Main game loop, keeps the game alive. 
	void GameLoop(sf::RenderWindow& window);

	/// \brief Closes the game.
	void ExitGame(sf::RenderWindow& window);
};