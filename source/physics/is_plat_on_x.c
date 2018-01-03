/*
** EPITECH PROJECT, 2018
** is_plat_on_x
** File description:
** is_plat_on_x
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

sprite_list *is_plat_on_x(sfSprite *player, sprite_list *plat)
{
	sfVector2f player_co = sfSprite_getPosition(player);
	sfVector2f plat_pos;

	while (plat != NULL) {
		plat_pos = sfSprite_getPosition(plat->sprite);
		if (player_co.y < plat_pos.y && \
		(player_co.x + 55 >= plat_pos.x - 35 && \
		player_co.x + 55 <= plat_pos.x + 130)) {
			return (plat);
		}
		plat = plat->next;
	}
	return (NULL);
}
