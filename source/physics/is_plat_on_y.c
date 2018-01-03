/*
** EPITECH PROJECT, 2018
** is_plat_on_y
** File description:
** is_plat_on_y
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

int is_plat_on_y(sfSprite *player, sprite_list *plat)
{
	sfVector2f player_co = sfSprite_getPosition(player);
	sfVector2f plat_pos;
	float y = player_co.y + 146;

	if (plat == NULL)
		return (0);
	plat_pos = sfSprite_getPosition(plat->sprite);
	if (y >= plat_pos.y - 4 && y <= plat_pos.y + 4)
		return (1);
	return (0);
}
