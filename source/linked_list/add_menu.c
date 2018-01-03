/*
** EPITECH PROJECT, 2018
** add_menu
** File description:
** add_menu
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

void add_menu(sprite_list **head, char *text_path)
{
	sprite_list *new_node = malloc(sizeof(sprite_list));
	sprite_list *last = *head;
	sfVector2f p = {0, 0};
	sfSprite *sprite = sfSprite_create();

	new_node->texture = sfTexture_createFromFile(text_path, NULL);
	new_node->sprite = sprite;
	sfSprite_setTexture(new_node->sprite, new_node->texture, sfTrue);
	sfSprite_setPosition(new_node->sprite, p);
	new_node->position = p;
	new_node->next = NULL;
	if (*head == NULL) {
		*head = new_node;
		return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
}
