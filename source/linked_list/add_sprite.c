/*
** EPITECH PROJECT, 2018
** add_sprite
** File description:
** add_sprite
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

void add_sprite(sprite_list **head, char *text_path, sfVector2f p, sfIntRect r)
{
	sprite_list *new_node = malloc(sizeof(sprite_list));
	sprite_list *last = *head;
	sfSprite *sprite = sfSprite_create();

	new_node->texture = sfTexture_createFromFile(text_path, NULL);
	new_node->sprite = sprite;
	sfSprite_setTexture(new_node->sprite, new_node->texture, sfTrue);
	sfSprite_setPosition(new_node->sprite, p);
	sfSprite_setTextureRect(new_node->sprite, r);
	new_node->position = p;
	new_node->rect = r;
	new_node->next = NULL;
	if (*head == NULL) {
		*head = new_node;
		return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
}
