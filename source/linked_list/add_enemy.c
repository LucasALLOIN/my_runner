/*
** EPITECH PROJECT, 2018
** add_enemy
** File description:
** add_enemy
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

const char *const enemy[] = {"ressources/enemy/testicule.png", \
                             "ressources/enemy/enemy1.png", \
                             "ressources/enemy/enemy2.png", \
			     "ressources/enemy/enemy3.png", \
			     "ressources/enemy/enemy4.png", \
			     "ressources/enemy/enemy5.png", \
			     "ressources/enemy/enemy6.png", \
			     "ressources/enemy/enemy7.png"};

void add_enemy(sprite_list **head, sfVector2f p)
{
	sprite_list *new_node = malloc(sizeof(sprite_list));
	sprite_list *last = *head;
	sfSprite *sprite = sfSprite_create();
	int ran = rand() % 8;

	new_node->texture = sfTexture_createFromFile(enemy[ran], NULL);
	new_node->sprite = sprite;
	sfSprite_setTexture(new_node->sprite, new_node->texture, sfTrue);
	sfSprite_setPosition(new_node->sprite, p);
	new_node->pos = 0;
	sfSprite_setTextureRect(new_node->sprite, rect_enemy(&new_node->pos));
	new_node->next = NULL;
	if (*head == NULL) {
		*head = new_node;
		return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
}
