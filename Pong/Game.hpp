#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Paddle.hpp"
#include "Ball.hpp"
#include "Wall.hpp"
#include "Score.hpp"


class Game
{
private:
	Paddle* paddle;
	Ball* ball;
	Wall* wall;
	Score* score;

public:
	Game();
	~Game();

	void StartGame();
	void GameLoop(sf::RenderWindow& window);
	void ExitGame(sf::RenderWindow& window);
};