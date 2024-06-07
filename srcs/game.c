#include "../includes/game.h"

struct Game	game 
{
	.window = NULL;
	.renderer = NULL;
	.state = 0;
}

int	init_game(void)
{
    if (SDL_INIT(SDL_INIT_EVERYTHING) != 0)
	return (0);
    game.window = SDL_CreateWindow(GAME_TITLE,
		    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		    WINDOW_WIDTH, WINDOW_HEIGHT,
		    SDL_WINDOW_SHOWN);
    if (game.window == NULL)
	    return (0);
    game.renderer = SDL_CreateRenderer(window, -1, 0);
    if (game.renderer == NULL)
	    return (0);
    return (1);
}

void	gameloop(void)
{

}

void	start(void)
{
	game.state = init_game();
	if (game.state == 1)
	{
		gameloop();
	}
}
