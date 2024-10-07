#pragma once

#include "BaseGameClass.hpp"

class Wall : public BaseGame
{
private:
	sf::RectangleShape line;

public:

	Wall();
	sf::RectangleShape& GetLine();

	void InputHandling(float& speed, sf::Keyboard::Key const& Up, sf::Keyboard::Key const& Down) override;
	void PositionUpdate() override;
	void Drawing(sf::RenderWindow& window) override;
	void CollisionDetection() override;
};