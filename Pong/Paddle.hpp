#pragma once

#include <iostream>

#include "BaseGameClass.hpp"
#include "Ball.hpp"

class Paddle : public BaseGame
{
private:
	sf::RectangleShape paddle;
	sf::Vector2f paddle_velocity;

public:
	Paddle(float& position);

	sf::RectangleShape& GetPaddle();

	void InputHandling(float& speed, sf::Keyboard::Key const& Up, sf::Keyboard::Key const& Down) override;
	void PositionUpdate() override;
	void Drawing(sf::RenderWindow& window) override;
	void CollisionDetection() override;
};