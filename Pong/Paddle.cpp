#include "Paddle.hpp"

Paddle::Paddle(float& position)
{
	//left_paddle.setSize(sf::Vector2f(10.f, 100.f));
	//left_paddle.setFillColor(sf::Color::White);
	//left_paddle.setPosition(10.f, 212.5);

	/*right_paddle.setSize(sf::Vector2f(10.f, 100.f));
	right_paddle.setFillColor(sf::Color::White);
	right_paddle.setPosition(838.f, 212.5);*/
	paddle.setSize(sf::Vector2f(10.f, 100.f));
	paddle.setFillColor(sf::Color::White);
	paddle.setPosition(position, 212.5);
}

sf::RectangleShape& Paddle::GetLeftPaddle()
{
	return left_paddle;
}

sf::RectangleShape& Paddle::GetRightPaddle()
{
	return right_paddle;
}

sf::RectangleShape& Paddle::GetPaddle()
{
	return paddle;
}

void Paddle::InputHandling(float& speed, sf::Keyboard::Key const& Up, sf::Keyboard::Key const& Down)
{
	//Left Paddle Movement
	if (sf::Keyboard::isKeyPressed(Up))
	{
		paddle_velocity.y = -4.f * speed;
		PositionUpdate();
	}

	if (sf::Keyboard::isKeyPressed(Down))
	{
		paddle_velocity.y = 4.f * speed;
		PositionUpdate();
	}
}

void Paddle::PositionUpdate()
{
	paddle.move(paddle_velocity.x, paddle_velocity.y);
}

void Paddle::Drawing(sf::RenderWindow& window)
{
	window.draw(paddle);
	//window.draw(right_paddle);
}

void Paddle::CollisionDetection()
{
	//Collision detection for the left paddle
	if (paddle.getPosition().y < 0.f)
	{
		paddle.setPosition(paddle.getPosition().x, 0.f);
	}
	if (paddle.getPosition().y > 425.f)
	{
		paddle.setPosition(paddle.getPosition().x, 425.f);
	}

	//Collision detection for the right paddle
	/*if (right_paddle.getPosition().y < 0.f)
	{
		right_paddle.setPosition(right_paddle.getPosition().x, 0.f);
	}
	if (right_paddle.getPosition().y > 425.f)
	{
		right_paddle.setPosition(right_paddle.getPosition().x, 425.f);
	}*/
}