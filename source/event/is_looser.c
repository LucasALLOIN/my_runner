/*
** EPITECH PROJECT, 2018
** is_looser
** File description:
** is_looser
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

void is_looser(sprite_list *player, int *loose, music_list *music)
{
	sfVector2f p = sfSprite_getPosition(player->sprite);

	if (p.y > 800 || player->life < 1) {
		*loose = 1;
		play_music(music, "loose");
	}
}
