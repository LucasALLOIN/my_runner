/*
** EPITECH PROJECT, 2018
** add_text
** File description:
** add_text
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

void add_text(text_list **head, char *value, sfVector2f pos, sfColor color)
{
	text_list *new_node = malloc(sizeof(text_list));
	text_list *last = *head;
	sfText *text = sfText_create();
	sfFont *font = sfFont_createFromFile("ressources/arcade.ttf");

	new_node->text = text;
	sfText_setString(text, value);
	sfText_setFont(text, font);
	sfText_setCharacterSize(text, 50);
	sfText_setPosition(text, pos);
	sfText_setColor(text, color);
	new_node->next = NULL;
	if (*head == NULL) {
		*head = new_node;
		return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
}
