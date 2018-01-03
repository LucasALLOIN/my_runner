/*
** EPITECH PROJECT, 2018
** on_shot
** File description:
** on_shot
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

int on_shot(sprite_list *p, sprite_list *shoot, sprite_list *enemy, game *game)
{
	sfVector2f shoot_pos;
	sprite_list *head = enemy;

	while (shoot != NULL) {
		shoot_pos = sfSprite_getPosition(shoot->sprite);
		while (enemy != NULL) {
			s_enemy(shoot_pos, enemy, shoot, game);
			enemy = enemy->next;
		}
		shoot_player(shoot_pos, p, shoot, game);
		enemy = head;
	        shoot = shoot->next;
	}
	return (0);
}
