#pragma once

#include "BaseGameClass.hpp"

class Wall : public BaseGame
{
private:
	sf::RectangleShape line;

public:
	/// \brief Constructor.
	/// Sets up the size and color of the wall.
	Wall();

	/// \brief Returns wall address.
	/// \returns Wall address.
	sf::RectangleShape& GetLine();

	/// \brief This function is not used.
	void InputHandling(float& speed, sf::Keyboard::Key const& Up, sf::Keyboard::Key const& Down) override;

	/// \brief This function is not used.
	void PositionUpdate() override;

	/// \brief Draws the wall on the window.
	/// \param window Type sf::RenderWindow. Window is used for drawing 2D shapes.
	void Drawing(sf::RenderWindow& window) override;

	/// \brief This function is not used.
	void CollisionDetection() override;
};