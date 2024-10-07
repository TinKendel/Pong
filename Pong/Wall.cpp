#include "Wall.hpp"

Wall::Wall()
{
	line.setSize(sf::Vector2f(2.5f, 15.f));
	line.setFillColor(sf::Color::White);
}

sf::RectangleShape& Wall::GetLine()
{
	return line;
}

void Wall::InputHandling(float& speed, sf::Keyboard::Key const& Up, sf::Keyboard::Key const& Down)
{
	std::cout << "I dont need any inputs..." << std::endl;
}

void Wall::PositionUpdate()
{
	std::cout << "I dont need any position updates..." << std::endl;
}

void Wall::Drawing(sf::RenderWindow& window)
{
	for (float i = 0; i < 525.f; i += 35.f)
	{
		line.setPosition(427.25f, 10.f + i);
		window.draw(line);
	}
}

void Wall::CollisionDetection()
{
	std::cout << "I dont need any collision..." << std::endl;
}