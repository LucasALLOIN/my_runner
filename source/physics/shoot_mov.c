/*
** EPITECH PROJECT, 2018
** shoot_mov
** File description:
** shoot_mov
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

void shoot_mov(sprite_list *shoot)
{
	sfVector2f move = {0, 0};
	sfVector2f move2 = {0, 12000};
	sfVector2f shoot_pos;

	while (shoot != NULL) {
		shoot_pos = sfSprite_getPosition(shoot->sprite);
		if (shoot_pos.x > 1280 || shoot_pos.x < 0)
			sfSprite_move(shoot->sprite, move2);
		move.x = (shoot->mod == 0) ? 6 : -6;
		sfSprite_move(shoot->sprite, move);
		shoot = shoot->next;
	}
}
