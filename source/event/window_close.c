/*
** EPITECH PROJECT, 2018
** window_close
** File description:
** window_close
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

void window_close(game *game)
{
	if (game->event.type == sfEvtClosed \
	|| (game->event.type == sfEvtKeyPressed && \
	game->event.key.code == sfKeyQ))
		sfRenderWindow_close(game->window);
}
