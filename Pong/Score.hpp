#pragma once

#include "BaseGameClass.hpp"

class Score : public BaseGame
{
private:
	sf::Font font;
	sf::Text left_text;
	sf::Text right_text;
	int left_score = 0;
	int right_score = 0;

public:
	/// \brief Constructor.
	Score();

	/// \brief Sets font, position, color, size and string for the text.
	void SetScore();

	/// \brief Loads a font.
	void LoadFont();

	/// \brief Increments the left score and sets it to the text.
	void UpdateLeftScore();

	/// \brief Increments the right score and sets it to the text.
	void UpdateRightScore();

	/// \brief This function is not used.
	void InputHandling(float& speed, sf::Keyboard::Key const& Up, sf::Keyboard::Key const& Down) override;

	/// \brief This function is not used.
	void PositionUpdate() override;

	/// \brief Draws the score on the window.
	/// \param window Type sf::RenderWindow. Window is used for drawing 2D shapes.
	void Drawing(sf::RenderWindow& window) override;

	/// \brief This function is not used.
	void CollisionDetection() override;
};