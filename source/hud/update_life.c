/*
** EPITECH PROJECT, 2018
** update_life
** File description:
** update_life
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

void update_life(text_list *text, int value)
{
	char *val;

	val = my_itoa(value);
	text = text->next;
	text = text->next;
	text = text->next;
	sfText_setString(text->text, val);
	free(val);
}
