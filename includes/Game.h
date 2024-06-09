#ifndef GAME_H
# define GAME_H

#include "Const.h"
#include "Map.h"
#include "../../../library/raylib/src/raylib.h"

struct Game
{
	int	state;
	int nb_gen;
	int	tick;
	int	want_update;
	Map	current_map;
	Map	new_map;
};

int	init_game(void);
int	clean_game(void);

void	game_loop(void);
void	handleEvents(void);
void	update(void);
void	render(void);

#endif