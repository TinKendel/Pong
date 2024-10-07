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
	/// \brief Constructor.
	/// Sets paddle size, color and position.
	/// \param position Type float. Position tells which paddle is created.
	Paddle(float& position);

	/// \brief Gets the paddle address.
	/// \returns Address of paddle.
	sf::RectangleShape& GetPaddle();

	/// \brief Handles the input for paddle movement.
	///
	/// \param speed Type float. Defines the speed at witch the paddle is moving.
	/// \param Up Type sf::Keyboard::Key. The key that moves the paddle upwards.
	/// \param Down Type sf::Keyboard::Key. The key that moves the paddle downwards.
	void InputHandling(float& speed, sf::Keyboard::Key const& Up, sf::Keyboard::Key const& Down) override;

	/// \brief Moves the paddle.
	void PositionUpdate() override;

	/// \brief Draws the paddle on the window.
	/// \param window Type sf::RenderWindow. Window is used for drawing 2D shapes.
	void Drawing(sf::RenderWindow& window) override;

	/// \brief Detects if the paddle is touching the top or bottom of the window.
	void CollisionDetection() override;
};