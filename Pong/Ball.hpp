#pragma once

#include "BaseGameClass.hpp"
#include "Score.hpp"
#include "Paddle.hpp"

class Paddle;

class Ball : public BaseGame
{
private:
	sf::CircleShape ball;
	sf::Vector2f ball_velocity;
	Score* score;
	Paddle* left_paddle;
	Paddle* right_paddle;

public:
	/// \brief Constructor.
	/// \param scoreRef Type pointer. It points to Score object. 
	/// \param left_paddleRef Type pointer. It points to Paddle object.
	/// \param right_paddleRef Type pointer. It points to Paddle object.
	Ball(Score* scoreRef, Paddle* left_paddleRef, Paddle* right_paddleRef);

	/// \brief Returns Ball address.
	/// \return Address of ball.
	sf::CircleShape& GetBall();

	/// \brief Sets the balls size, color, position and velocity.
	void SetBall();

	/// \brief Serve the ball to the player who scores.
	/// \param side Type bool. Left to serve the ball to the left side and vice versa.
	void SwitchServe(bool side);

	/// \brief Moves the ball. 
	/// \param delta_time Type float. Needed in case we have more or less frames.
	void UpdateMovement(float delta_time);

	/// \brief This function is not used.
	void InputHandling(float& speed, sf::Keyboard::Key const& Up, sf::Keyboard::Key const& Down) override;

	/// \brief This function is not used.
	void PositionUpdate() override;

	/// \brief Draws the ball on the window.
	/// \param window Type sf::RenderWindow. Window is used for drawing 2D shapes.
	void Drawing(sf::RenderWindow& window) override;

	/// \brief Detects if the ball hits the walls or the paddles.
	void CollisionDetection() override;
};