/*
** EPITECH PROJECT, 2018
** add_music
** File description:
** add_music
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

void add_music(music_list **head, char *music_path, char *data)
{
	music_list *new_node = malloc(sizeof(music_list));
	music_list *last = *head;
	sfMusic *music;

	music = sfMusic_createFromFile(music_path);
	new_node->music = music;
	my_strcpy(new_node->data, data);
	new_node->next = NULL;
	if (*head == NULL) {
		*head = new_node;
		return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
}
