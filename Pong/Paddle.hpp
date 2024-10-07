#pragma once

#include <iostream>

#include "BaseGameClass.hpp"
#include "Ball.hpp"

class Paddle : public BaseGame
{
private:
	sf::RectangleShape paddle;
	sf::RectangleShape left_paddle;
	sf::RectangleShape right_paddle;
	sf::Vector2f paddle_velocity;
	sf::Vector2f left_paddle_velocity;
	sf::Vector2f right_paddle_velocity;

public:
	Paddle(float& position);

	sf::RectangleShape& GetLeftPaddle();
	sf::RectangleShape& GetRightPaddle();

	sf::RectangleShape& GetPaddle();

	void InputHandling(float& speed, sf::Keyboard::Key const& Up, sf::Keyboard::Key const& Down) override;
	void PositionUpdate() override;
	void Drawing(sf::RenderWindow& window) override;
	void CollisionDetection() override;
};