#include <iostream>
#include "Game.hpp"

int main()
{
	try
	{
		Game game;
		game.StartGame();
	}
	catch (...) 
	{
		// This will catch any exception and print an error message
		std::cerr << "An error occurred during the game." << std::endl;
		return 1; 
	}
	return 0;
}