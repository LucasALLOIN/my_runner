/*
** EPITECH PROJECT, 2018
** destroy_list
** File description:
** destroy_list
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

void destroy_list(sprite_list **head)
{
	sprite_list *last = *head;

	while (*head != NULL) {
		sfSprite_destroy((*head)->sprite);
		sfTexture_destroy((*head)->texture);
		last = *head;
		*head = (*head)->next;
		free(last);
	}
}
