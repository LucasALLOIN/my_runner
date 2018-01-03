/*
** EPITECH PROJECT, 2018
** shoot_maker
** File description:
** shoot_maker
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

void shoot_maker(game *game)
{
	if (game->event.type == sfEvtKeyPressed && game->event.key.code == \
	sfKeyS && game->started) {
		add_shoot(&game->shoot, get_sprite(game->list, 2)->sprite, 0);
		play_music(game->music, "shoot");
	}
}
