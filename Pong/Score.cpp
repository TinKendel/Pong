#include "Score.hpp"

Score::Score()
{
	LoadFont();
	SetScore();
}

void Score::SetScore()
{
	left_text.setFont(font);
	left_text.setPosition(214.5f, 50.f);
	left_text.setFillColor(sf::Color::White);
	left_text.setCharacterSize(80);
	left_text.setString("0");

	right_text.setFont(font);
	right_text.setPosition(643.5f, 50.f);
	right_text.setFillColor(sf::Color::White);
	right_text.setCharacterSize(80);
	right_text.setString("0");
}

void Score::LoadFont()
{
	if (!font.loadFromFile("assets\\Fonts\\Dosis-Light.ttf"))
	{
		std::cout << "Couldnt load file!" << std::endl;
	}
}

void Score::UpdateLeftScore()
{
	left_score++;
	left_text.setString(std::to_string(left_score));
}

void Score::UpdateRightScore()
{
	right_score++;
	right_text.setString(std::to_string(right_score));
}

void Score::InputHandling(float& speed)
{
	std::cout << "I dont need any inputs..." << std::endl;
}

void Score::PositionUpdate()
{
	std::cout << "I dont need any position update..." << std::endl;
}

void Score::Drawing(sf::RenderWindow& window)
{
	window.draw(left_text);
	window.draw(right_text);
}

void Score::CollisionDetection()
{
	std::cout << "I dont need any collision detection..." << std::endl;
}