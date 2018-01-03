/*
** EPITECH PROJECT, 2018
** enemy_shoot
** File description:
** enemy_shoot
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

void enemy_shoot(sprite_list **shoot, sprite_list *enemy, music_list *music)
{
	int ran = rand() % 500;
	sfVector2f pos;

	while (enemy != NULL) {
		ran = rand() % 500;
		pos = sfSprite_getPosition(enemy->sprite);
		if (ran > 497 && pos.x < 1280 && pos.x > 0) {
			add_shoot(shoot, enemy->sprite, 1);
			play_music(music, "shoot");
		}
		enemy = enemy->next;
	}
}
