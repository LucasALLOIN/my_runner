/*
** EPITECH PROJECT, 2018
** reset_game
** File description:
** reset_game
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

void reset_game(game *game, char **argv)
{
	if (game->event.type == sfEvtKeyPressed && game->event.key.code == \
	sfKeyR && game->started && (game->win || game->loose)) {
		game->win = 0;
		game->loose = 0;
		update_score(game->text, 0, 1);
		get_sprite(game->list, 2)->life = 3;
		update_life(game->text, 3);
		destroy_list(&game->plat);
		destroy_list(&game->enemy);
		destroy_list(&game->spike);
		destroy_list(&game->end);
		destroy_list(&game->shoot);
		sfSprite_setPosition(get_sprite(game->list, 2)->sprite, \
		game->ini_pos);
		create_map(game, argv[1]);
	}
}
