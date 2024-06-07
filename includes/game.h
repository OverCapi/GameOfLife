#ifndef GAME_H
# define GAME_H

#include "SDL2/SDL.h"
#include "Constant.h"

struct	Game 
{
	SDL_Window	*window;
	SDL_Renderer	*renderer;
	int		state;
}

int	init_game(void);
void	start(void);
void	gameloop(void);

#endif
