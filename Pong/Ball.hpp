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
	Ball(Score* scoreRef, Paddle* left_paddleRef, Paddle* right_paddleRef);

	sf::CircleShape& GetBall();

	void SetBall();

	void SwitchServe(bool side);
	void UpdateMovement(float delta_time);

	void InputHandling(float& speed, sf::Keyboard::Key const& Up, sf::Keyboard::Key const& Down) override;
	void PositionUpdate() override;
	void Drawing(sf::RenderWindow& window) override;
	void CollisionDetection() override;
};