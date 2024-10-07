#include "Game.hpp"

Game::Game() : paddle(nullptr), ball(nullptr), wall(nullptr), score(nullptr)
{

}

Game::~Game()
{
	delete paddle;
	delete ball;
	delete wall;
	delete score;
}

void Game::StartGame()
{
	sf::RenderWindow window(sf::VideoMode(858, 525), "PONG");

	//Create Wall
	wall = new Wall();

	//Create Paddles
	paddle = new Paddle();

	//Create Score
	score = new Score();
	score->LoadFont();
	score->SetScore();

	//Create Ball
	ball = new Ball(score, paddle);
	ball->SetBall();

	//Setting Frames
	window.setFramerateLimit(60);

	//Start the game
	GameLoop(window);
}

void Game::GameLoop(sf::RenderWindow& window)
{
	sf::Clock clock;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
			{
				ExitGame(window);
			}
		}
		
		//Makes the game Framerate independent
		float delta_time = clock.restart().asSeconds();
		float frame_rate = delta_time * 60.f;
		
		ball->UpdateMovement(frame_rate);
		paddle->InputHandling(frame_rate);
		paddle->CollisionDetection();

		window.clear();

		//Drawing all the elements
		paddle->Drawing(window);
		ball->Drawing(window);
		wall->Drawing(window);
		score->Drawing(window);
		
		window.display();
	}
}

void Game::ExitGame(sf::RenderWindow& window)
{
	window.close();
}