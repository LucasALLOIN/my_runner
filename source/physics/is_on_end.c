/*
** EPITECH PROJECT, 2018
** is_on_end
** File description:
** is_on_end
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

int is_on_end(sfSprite *player, sprite_list *end)
{
	sfVector2f player_co = sfSprite_getPosition(player);
	sfVector2f end_pos;

	while (end != NULL) {
		end_pos = sfSprite_getPosition(end->sprite);
		if (end_pos.y < player_co.y && \
		end_pos.y > player_co.y - 100 && \
		(player_co.x >= end_pos.x && player_co.x <= end_pos.x + 100)) {
			return (1);
		}
		end = end->next;
	}
	return (0);
}
