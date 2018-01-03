/*
** EPITECH PROJECT, 2018
** draw_text
** File description:
** draw_text
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

void draw_text(text_list *text, sfRenderWindow *window)
{
	while (text != NULL) {
		sfRenderWindow_drawText(window, text->text, NULL);
		text = text->next;
	}
}
