/*
** EPITECH PROJECT, 2018
** add_shoot
** File description:
** add_shoot
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

void add_shoot(sprite_list **head, sfSprite *from, int mod)
{
	sprite_list *new_node = malloc(sizeof(sprite_list));
	sprite_list *last = *head;
	sfSprite *sprite = sfSprite_create();
	sfVector2f pos = {0, sfSprite_getPosition(from).y + 60};
	float x = sfSprite_getPosition(from).x;
	char *path = "ressources/shoot.png";

	pos.x = (mod == 0) ? x + 50 : x - 50;
	new_node->texture = sfTexture_createFromFile(path, NULL);
	new_node->sprite = sprite;
	sfSprite_setTexture(new_node->sprite, new_node->texture, sfTrue);
	sfSprite_setPosition(new_node->sprite, pos);
	new_node->mod = mod;
	new_node->next = NULL;
	if (*head == NULL) {
		*head = new_node;
		return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
}
