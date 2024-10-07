#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"

//Base Class for all game objects
class BaseGame
{
public:
	virtual ~BaseGame() {}

	virtual void InputHandling(float& speed) = 0;
	virtual void PositionUpdate() = 0;
	virtual void Drawing(sf::RenderWindow& window) = 0;
	virtual void CollisionDetection() = 0;
};