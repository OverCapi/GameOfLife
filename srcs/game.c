#include "../includes/Game.h"
#include <stdio.h>

struct Game game = 
{
	.state = 0,
	.nb_gen = 0,
	.tick = 0,
	.speed_index = 3,	// default speed (SPEED_0)
};

const int SPEED[NB_SPEED] = {SLOW_3, SLOW_2, SLOW_1, SPEED_0, SPEED_1, SPEED_2, SPEED_3, SPEED_4};

int	init_game(void)
{
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, GAME_TITLE);
	init_map(&game.current_map);
	SetTargetFPS(TARGET_FPS);
	game.state = 1;
	return 1;
}

void	handleEvents(void)
{
	int	x;
	int	y;

	if (IsKeyPressed(KEY_ESCAPE))
		game.state = 0;
	if (IsKeyPressed(KEY_SPACE))
	{
		if (game.state == 1)
			game.state = 2;
		else
			game.state = 1;
	}
	if (IsKeyPressed(KEY_UP))
		game.speed_index = (game.speed_index + 1) % NB_SPEED;
	if (IsKeyPressed(KEY_DOWN))
	{
		game.speed_index--;
		if (game.speed_index < 0)
			game.speed_index = NB_SPEED - 1;
	}
	if (game.state == 2)
	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			x = GetMouseX() / SQUARE_SIZE;
			y = GetMouseY() / SQUARE_SIZE;
			add_square(&game.current_map, x, y);
		}
		if (IsKeyPressed(KEY_C))
		{
			init_map(&game.current_map);
		}
	}
}

void	create_new_generation(void)
{
	create_new_map(game.current_map, &game.new_map);
	game.current_map = game.new_map;
	game.nb_gen++;
}

void	draw_info(void)
{
	char	genText[20];
	char	gameSpeed[10];

	sprintf(genText, "Generation %d", game.nb_gen);
	sprintf(gameSpeed, "x%.2f", (float)SPEED_0/SPEED[game.speed_index]);
	if (game.state == 2)
		DrawText("PAUSE", WINDOW_WIDTH-100, 10, 20, BLACK);
	DrawText(gameSpeed, WINDOW_WIDTH-100, WINDOW_HEIGHT-100, 20, BLACK);
	DrawText(genText, 10, 10, 20, BLACK);
}

void	update(void)
{
	create_new_generation();
}

void	render(void)
{
	BeginDrawing();
	ClearBackground(RAYWHITE);
	
	draw_map(game.current_map);
	draw_info();

	EndDrawing();
}

void	game_loop(void)
{
	init_game();
	while (game.state != 0)
	{
		handleEvents();
		if (game.state == 1)
		{
			game.tick++;
			if (game.tick % SPEED[game.speed_index] == 0)
				update();
		}
		render();
	}
	clean_game();
}

int	clean_game(void)
{
	CloseWindow();
	return 0;
}