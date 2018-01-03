/*
** EPITECH PROJECT, 2018
** jump_maker
** File description:
** jump_maker
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

void jump_maker(game *game)
{
	if (game->event.type == sfEvtKeyPressed && game->event.key.code == \
	sfKeySpace && game->started)
		if (is_on_platform(get_sprite(game->list, 2)->sprite, \
		game->plat))
			jump(get_sprite(game->list, 2)->sprite, 1);
}
