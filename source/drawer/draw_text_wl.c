/*
** EPITECH PROJECT, 2018
** draw_text_wl
** File description:
** draw_text_wl
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

void draw_text_wl(text_list *list, sfRenderWindow *window)
{
	sfVector2f score_wl = {542, 508};

	list = list->next;
	list = list->next;
	sfText_setPosition(list->text, score_wl);
	sfRenderWindow_drawText(window, list->text, NULL);
}
