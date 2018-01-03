/*
** EPITECH PROJECT, 2018
** destroy_music
** File description:
** destroy_music
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

void destroy_music(music_list **head)
{
	music_list *last = *head;

	while (*head != NULL) {
		sfMusic_destroy((*head)->music);
	        last = *head;
		*head = (*head)->next;
		free(last);
	}
}
