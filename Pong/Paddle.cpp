#include "Paddle.hpp"

Paddle::Paddle(float& position)
{
	paddle.setSize(sf::Vector2f(10.f, 100.f));
	paddle.setFillColor(sf::Color::White);
	paddle.setPosition(position, 212.5);
}

sf::RectangleShape& Paddle::GetPaddle()
{
	return paddle;
}

void Paddle::InputHandling(float& speed, sf::Keyboard::Key const& Up, sf::Keyboard::Key const& Down)
{
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
}

void Paddle::CollisionDetection()
{
	if (paddle.getPosition().y < 0.f)
	{
		paddle.setPosition(paddle.getPosition().x, 0.f);
	}
	if (paddle.getPosition().y > 425.f)
	{
		paddle.setPosition(paddle.getPosition().x, 425.f);
	}
}