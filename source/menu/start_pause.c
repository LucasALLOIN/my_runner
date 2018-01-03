/*
** EPITECH PROJECT, 2018
** start_pause
** File description:
** start_pause
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

void start_pause(game *game)
{
	if (game->event.type == sfEvtKeyPressed && game->event.key.code == \
	sfKeyP && game->started && !game->win && !game->loose)
		game->pause = 1;
	if (game->event.type == sfEvtKeyPressed && game->event.key.code == \
	sfKeyEscape && game->started && !game->win && !game->loose)
		game->pause = 0;
}
