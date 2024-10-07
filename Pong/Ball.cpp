#include "Ball.hpp"

Ball::Ball(Score* scoreRef, Paddle* left_paddleRef, Paddle* right_paddleRef) : score(scoreRef), left_paddle(left_paddleRef), right_paddle(right_paddleRef)
{

}

sf::CircleShape& Ball::GetBall()
{
	return ball;
}

void Ball::SetBall()
{
	ball.setRadius(5.f);
	ball.setFillColor(sf::Color::White);
	ball.setPosition(429.f, 262.5f);
	ball_velocity = sf::Vector2f(4.f, 0);
}

void Ball::SwitchServe(bool side)
{
	if (side)
	{
		ball.setPosition(429.f, 262.5f);
		ball_velocity = sf::Vector2f(4.f, 0);
	}
	else
	{
		ball.setPosition(429.f, 262.5f);
		ball_velocity = sf::Vector2f(-4.f, 0);
	}
}

void Ball::UpdateMovement(float delta_time)
{
	ball.move(ball_velocity.x * delta_time, ball_velocity.y * delta_time);
}

void Ball::InputHandling(float& speed, sf::Keyboard::Key const& Up, sf::Keyboard::Key const& Down)
{
	std::cout << "I dont need any input handling..." << std::endl;
}

void Ball::PositionUpdate()
{
	std::cout << "I dont need any position update..." << std::endl;
}

void Ball::Drawing(sf::RenderWindow& window)
{
	window.draw(ball);
	CollisionDetection();
}

void Ball::CollisionDetection()
{
	// Check collision with the top and bottom of the screen
	if (ball.getPosition().y < 0.f || ball.getPosition().y + ball.getRadius() * 2.f > 525.f) {
		ball_velocity.y *= -1;
	}

	sf::FloatRect ballBounds = ball.getGlobalBounds();
	sf::FloatRect leftPaddleBounds = left_paddle->GetPaddle().getGlobalBounds();
	sf::FloatRect rightPaddleBounds = right_paddle->GetPaddle().getGlobalBounds();

	// Left paddle collision
	if (ballBounds.intersects(leftPaddleBounds)) 
	{
		ball.setPosition(leftPaddleBounds.left + leftPaddleBounds.width, ball.getPosition().y); // Adjust position to prevent sticking

		// Calculate the offset where the ball has hit the paddle
		float paddleCenter = leftPaddleBounds.top + (leftPaddleBounds.height / 2.f);
		float ballCenter = ball.getPosition().y + (ball.getRadius());
		float distanceFromCenter = ballCenter - paddleCenter;

		ball_velocity.y += distanceFromCenter * 0.05f;
		ball_velocity.x *= -1;
		ball_velocity = sf::Vector2f(ball_velocity.x * 1.2f, ball_velocity.y * 1.2f);
	}

	// Right paddle collision
	if (ballBounds.intersects(rightPaddleBounds)) {
		ball.setPosition(rightPaddleBounds.left - ballBounds.width, ball.getPosition().y);

		float paddleCenter = rightPaddleBounds.top + (rightPaddleBounds.height / 2.f);
		float ballCenter = ball.getPosition().y + (ball.getRadius());
		float distanceFromCenter = ballCenter - paddleCenter;

		ball_velocity.y += distanceFromCenter * 0.05f;
		ball_velocity.x *= -1; 
		ball_velocity = sf::Vector2f(ball_velocity.x * 1.2f, ball_velocity.y * 1.2f);
	}

	// Check collision with left or right walls
	if (ball.getPosition().x <= -2.5f)
	{
		score->UpdateRightScore();
		SwitchServe(true);
	}

	if (ball.getPosition().x >= 858.f)
	{
		score->UpdateLeftScore();
		SwitchServe(false);
	}
}