/*
** EPITECH PROJECT, 2018
** start_help
** File description:
** start_help
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

void start_help(game *game)
{
	if (game->event.type == sfEvtKeyPressed && game->event.key.code == \
	sfKeyH && !game->started)
		game->help = 1;
	if (game->event.type == sfEvtKeyPressed && game->event.key.code == \
	sfKeyEscape && !game->started)
		game->help = 0;
}
