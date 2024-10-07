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
	Score();
	void SetScore();
	void LoadFont();

	void UpdateLeftScore();
	void UpdateRightScore();

	void InputHandling(float& speed) override;
	void PositionUpdate() override;
	void Drawing(sf::RenderWindow& window) override;
	void CollisionDetection() override;
};