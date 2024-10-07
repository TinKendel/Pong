#pragma once

#include <iostream>

#include "BaseGameClass.hpp"
#include "Ball.hpp"

class Paddle : public BaseGame
{
private:
	sf::RectangleShape left_paddle;
	sf::RectangleShape right_paddle;
	sf::Vector2f left_paddle_velocity;
	sf::Vector2f right_paddle_velocity;

public:
	Paddle();

	sf::RectangleShape& GetLeftPaddle();
	sf::RectangleShape& GetRightPaddle();

	void InputHandling(float& speed) override;
	void PositionUpdate() override;
	void Drawing(sf::RenderWindow& window) override;
	void CollisionDetection() override;
};