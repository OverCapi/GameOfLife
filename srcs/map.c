#include "../includes/Map.h"

void	draw_map(Map map)
{
	int	i;
	int	j;

	i = 0;
	while (i < MAP_SIZE)
	{
		j = 0;
		while (j < MAP_SIZE)
		{
			if (map.map[i][j] == 1)
			{
				DrawRectangle(i * SQUARE_SIZE, j * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE, BLACK);
			}
			j++;
		}
		i++;
	}
}

int	nb_neighboring_living_cells(Map map, int x, int y)
{
	int nb;
	int i;
	int j;

	nb = 0;
	i = -1;
	while (i <= 1)
	{
		j = -1;
		while (j <= 1)
		{
			if (!(i == 0 && j == 0))
			{
				int nx = x + i;
				int ny = y + j;
				if (nx >= 0 && nx < MAP_SIZE && ny >= 0 && ny < MAP_SIZE)
				{
					if (map.map[nx][ny] == 1)
						nb++;
				}
			}
			j++;
		}
		i++;
	}
	return (nb);
}

void	create_new_map(Map current, Map *new_map)
{
	int	i;
	int	j;
	int	nb_neighbor;

	init_map(new_map);
	i = 0;
	while (i < MAP_SIZE)
	{
		j = 0;
		while (j < MAP_SIZE)
		{
			nb_neighbor = nb_neighboring_living_cells(current, i, j);
			if (nb_neighbor == 3)
				new_map->map[i][j] = 1;
			else if (nb_neighbor == 2)
				new_map->map[i][j] = current.map[i][j];
			else
				new_map->map[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	init_map(Map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < MAP_SIZE)
	{
		j = 0;
		while (j < MAP_SIZE)
		{
			map->map[i][j] = 0;
			j++;
		}
		i++;
	}
}
