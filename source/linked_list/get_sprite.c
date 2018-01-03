/*
** EPITECH PROJECT, 2018
** get_sprite
** File description:
** get_sprite
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

sprite_list *get_sprite(sprite_list *list, int pos)
{
	int i = 0;

	for (;i < pos; i = i + 1)
		list = list->next;
	return (list);
}
