/*
** EPITECH PROJECT, 2018
** update_score
** File description:
** update_score
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

void update_score(text_list *text, int valeur, int mod)
{
	static int value = 0;
	sfVector2f score_pos2 = {230, 730};
	char *val;

	if (mod)
		value = 0;
	value += valeur;
	val = my_itoa(value);
	text = text->next;
	text = text->next;
	sfText_setPosition(text->text, score_pos2);
	sfText_setString(text->text, val);
	free(val);
}
