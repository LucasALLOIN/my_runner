/*
** EPITECH PROJECT, 2018
** is_on_enemy
** File description:
** is_on_enemy
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

int is_on_enemy(sfSprite *player, sprite_list *enemy)
{
	sfVector2f player_co = sfSprite_getPosition(player);
	sfVector2f enemy_pos;
	float y = player_co.y + 147;

	while (enemy != NULL) {
		enemy_pos = sfSprite_getPosition(enemy->sprite);
		if (y > enemy_pos.y && enemy_pos.y > \
		player_co.y - 50 && (player_co.x + 50 > enemy_pos.x \
		&& player_co.x < enemy_pos.x + 50)) {
			return (1);
		}
		enemy = enemy->next;
	}
	return (0);
}
