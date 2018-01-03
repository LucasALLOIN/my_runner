/*
** EPITECH PROJECT, 2018
** draw_specific_sprite
** File description:
** draw_specific_sprite
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

void draw_specific_sprite(sprite_list *list, sfRenderWindow *window)
{
	sfRenderWindow_drawSprite(window, list->sprite, NULL);
}
