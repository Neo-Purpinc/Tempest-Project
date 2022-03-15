#include <SDL.h>
#include <assert.h>
#include <iostream>
#include "Game.hpp"

Game *game = nullptr;

int main(int argc, char** argv)
{
	game = new Game();
	game->init("Tempest", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, true);
	while (game->running())
	{
		game->handleEvents();
		game->update();
		game->render();
	}
	game->clean();
	delete game;
	return 0;
}