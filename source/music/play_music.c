/*
** EPITECH PROJECT, 2018
** play_music
** File description:
** play_music
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

void play_music(music_list *music, char *to_play)
{
	while (music != NULL) {
		if (my_strcmp(music->data, to_play) == 0)
			sfMusic_play(music->music);
		music = music->next;
	}
}
