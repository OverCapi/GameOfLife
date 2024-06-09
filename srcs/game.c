#include "../includes/Game.h"
#include <stdio.h>

struct Game game = 
{
	.state = 0,
	.nb_gen = 0,
	.want_update = 0,
	.tick = 0
};

int	init_game(void)
{
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, GAME_TITLE);
	init_map(&game.current_map);
	game.current_map.map[10][10] = 1;
	game.current_map.map[11][10] = 1;
	game.current_map.map[12][10] = 1;
	SetTargetFPS(5);
	game.state = 1;
	return 1;
}

void	handleEvents(void)
{
	if (IsKeyDown(KEY_ESCAPE))
		game.state = 0;
	else if (IsKeyDown(KEY_SPACE))
		game.want_update = 1;
}

void	create_new_generation(void)
{
	create_new_map(game.current_map, &game.new_map);
	game.current_map = game.new_map;
	game.nb_gen++;
}

void	update(void)
{
	create_new_generation();
	game.want_update = 0;
	game.tick++;
}

void	render(void)
{
	BeginDrawing();
	ClearBackground(RAYWHITE);
	
	draw_map(game.current_map);

	char	genText[20];
	sprintf(genText, "Générations : %d", game.nb_gen);
	DrawText(genText, 10, 10, 20, BLACK);
	
	EndDrawing();
}

void	game_loop(void)
{
	init_game();
	while (game.state != 0)
	{
		handleEvents();
		// if (game.want_update == 1)
		// 	update();
		update();
		render();
	}
	clean_game();
}

int	clean_game(void)
{
	CloseWindow();
	return 0;
}