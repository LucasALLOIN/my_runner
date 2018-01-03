/*
** EPITECH PROJECT, 2018
** is_on_spike
** File description:
** is_on_spike
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

int is_on_spike(sfSprite *player, sprite_list *spike)
{
	sfVector2f player_co = sfSprite_getPosition(player);
	sfVector2f spike_pos;
	float y = player_co.y + 147;

	while (spike != NULL) {
		spike_pos = sfSprite_getPosition(spike->sprite);
		if (y > spike_pos.y + 20 && \
		spike_pos.y > player_co.y - 70 && \
		(player_co.x + 90 > spike_pos.x && \
		player_co.x < spike_pos.x + 65)) {
			return (1);
		}
		spike = spike->next;
	}
	return (0);
}
