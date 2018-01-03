/*
** EPITECH PROJECT, 2018
** game_init_two
** File description:
** game_init_two
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

void game_init_two(game *game)
{
	game->life_pos.x = 1000;
	game->life_pos.y = 730;
	game->life_pos2.x = 1150;
	game->life_pos2.y = 730;
	game->list = NULL;
	game->menu = NULL;
	game->plat = NULL;
	game->end = NULL;
	game->spike = NULL;
	game->enemy = NULL;
	game->shoot = NULL;
	game->text = NULL;
	game->music = NULL;
	game->started = 0;
	game->help = 0;
	game->pause = 0;
	game->win = 0;
	game->loose = 0;
	game->timer = 0;
}
