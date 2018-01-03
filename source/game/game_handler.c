/*
** EPITECH PROJECT, 2018
** game_handler
** File description:
** game_handler
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

void game_handler(game *game)
{
	if (game->started && !game->pause && !game->win && !game->loose) {
		action(game);
	} else if (!game->started) {
		draw_specific_sprite(get_sprite(game->menu, 0), game->window);
		if (game->help)
			draw_specific_sprite(get_sprite(game->menu, 1), \
			game->window);
	} else if (game->pause) {
		draw_specific_sprite(get_sprite(game->menu, 2), game->window);
	} else if (game->win) {
		draw_specific_sprite(get_sprite(game->menu, 3), game->window);
		draw_text_wl(game->text, game->window);
	} else if (game->loose) {
		draw_specific_sprite(get_sprite(game->menu, 4), game->window);
		draw_text_wl(game->text, game->window);
	}
	sfRenderWindow_display(game->window);
	game->timer += 1;
}
