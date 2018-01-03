/*
** EPITECH PROJECT, 2018
** draw_sprite
** File description:
** draw_sprite
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

void draw_sprite(sprite_list *list, sfRenderWindow *window)
{
	while (list != NULL) {
		sfRenderWindow_drawSprite(window, list->sprite, NULL);
		list = list->next;
	}
}
