/*
** EPITECH PROJECT, 2018
** plat_mov
** File description:
** plat_mov
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

void plat_mov(sprite_list *plat)
{
	sfVector2f move = {-3.0, 0};

	while (plat != NULL) {
		sfSprite_move(plat->sprite, move);
		plat = plat->next;
	}
}
