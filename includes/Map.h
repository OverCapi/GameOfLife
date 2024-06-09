#ifndef MAP_H
# define MAP_H

#include "Const.h"
#include "../../../library/raylib/src/raylib.h"

typedef struct
{
	int	map[MAP_SIZE][MAP_SIZE];
} Map;

void	init_map(Map *map);
void	create_new_map(Map current, Map *new_map);
void	draw_map(Map map);

#endif