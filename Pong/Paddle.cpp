#include "Paddle.hpp"

Paddle::Paddle()
{
	left_paddle.setSize(sf::Vector2f(10.f, 100.f));
	left_paddle.setFillColor(sf::Color::White);
	left_paddle.setPosition(10.f, 212.5);

	right_paddle.setSize(sf::Vector2f(10.f, 100.f));
	right_paddle.setFillColor(sf::Color::White);
	right_paddle.setPosition(838.f, 212.5);
}

sf::RectangleShape& Paddle::GetLeftPaddle()
{
	return left_paddle;
}

sf::RectangleShape& Paddle::GetRightPaddle()
{
	return right_paddle;
}

void Paddle::InputHandling(float& speed) 
{
	//Left Paddle Movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		left_paddle_velocity.y = -4.f * speed;
		PositionUpdate();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		left_paddle_velocity.y = 4.f * speed;
		PositionUpdate();
	}

	//Right Paddle Movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		right_paddle_velocity.y = -4.f * speed;
		right_paddle.move(right_paddle_velocity.x, right_paddle_velocity.y);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		right_paddle_velocity.y = 4.f * speed;
		right_paddle.move(right_paddle_velocity.x, right_paddle_velocity.y);
	}
}

void Paddle::PositionUpdate()
{
	left_paddle.move(left_paddle_velocity.x, left_paddle_velocity.y);
}

void Paddle::Drawing(sf::RenderWindow& window)
{
	window.draw(left_paddle);
	window.draw(right_paddle);
}

void Paddle::CollisionDetection()
{
	//Collision detection for the left paddle
	if (left_paddle.getPosition().y < 0.f)
	{
		left_paddle.setPosition(left_paddle.getPosition().x, 0.f);
	}
	if (left_paddle.getPosition().y > 425.f)
	{
		left_paddle.setPosition(left_paddle.getPosition().x, 425.f);
	}

	//Collision detection for the right paddle
	if (right_paddle.getPosition().y < 0.f)
	{
		right_paddle.setPosition(right_paddle.getPosition().x, 0.f);
	}
	if (right_paddle.getPosition().y > 425.f)
	{
		right_paddle.setPosition(right_paddle.getPosition().x, 425.f);
	}
}