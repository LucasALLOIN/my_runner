/*
** EPITECH PROJECT, 2018
** start_game
** File description:
** start_game
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

void start_game(game *game)
{
	if (game->event.type == sfEvtKeyPressed && game->event.key.code == \
	sfKeyReturn && !game->started && !game->help)
		game->started = 1;
}
