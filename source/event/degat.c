/*
** EPITECH PROJECT, 2018
** degat
** File description:
** degat
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

void degat(sprite_list *player, text_list *text, int mod)
{
	static int timer = 0;
	static int damaged = 0;
	sfColor color = {255, 0, 0, 128};
	sfColor color2 = {255, 255, 255, 255};

	if (mod == 1 && !damaged) {
		player->life -= 1;
		update_life(text, player->life);
		damaged = 1;
	}
	if (timer < 180 && damaged) {
		if (timer % 10 == 0)
			sfSprite_setColor(player->sprite, color);
		else if (timer % 5 == 0 && timer % 10 != 0)
			sfSprite_setColor(player->sprite, color2);
		timer += 1;
	} else if (timer >= 180) {
		timer = 0;
		damaged = 0;
	}
}
