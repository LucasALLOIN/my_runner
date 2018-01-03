/*
** EPITECH PROJECT, 2018
** game_init
** File description:
** game_init
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <sys/types.h>
#include <fcntl.h>
#include "my.h"
#include "main.h"

void game_init(game *game, char **argv)
{
	srand((long int) argv);
	game->mode.width = 1280;
	game->mode.height = 800;
	game->mode.bitsPerPixel = 32;
	game->window = sfRenderWindow_create(game->mode, "my_runner", \
	sfResize | sfClose, NULL);
	game->ini_pos.x = 0;
	game->ini_pos.y = 400;
	game->back_pos.x = 0;
	game->back_pos.y = 0;
	game->back_rect.left = 300;
	game->back_rect.top = 10;
	game->back_rect.width = 1280;
	game->back_rect.height = 720;
	game->city_rect.left = 0;
	game->city_rect.top = 750;
	game->city_rect.width = 1280;
	game->city_rect.height = 720;
	game->score_pos.x = 30;
	game->score_pos.y = 730;
	game_init_two(game);
}
