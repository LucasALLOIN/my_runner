/*
** EPITECH PROJECT, 2018
** draw_all
** File description:
** draw_all
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

void draw_all(game *game)
{
	draw_sprite(game->list, game->window);
	draw_sprite(game->end, game->window);
	draw_sprite(game->spike, game->window);
	draw_sprite(game->shoot, game->window);
	draw_sprite(game->enemy, game->window);
	draw_sprite(get_sprite(game->list, 2), game->window);
	draw_sprite(game->plat, game->window);
	draw_text(game->text, game->window);
}
