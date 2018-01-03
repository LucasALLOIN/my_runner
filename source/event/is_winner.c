/*
** EPITECH PROJECT, 2018
** is_winner
** File description:
** is_winner
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

void is_winner(sprite_list *player, sprite_list *end, int *win, music_list *m)
{
	if (is_on_end(player->sprite, end)) {
	        *win = 1;
		play_music(m, "win");
	}
}
