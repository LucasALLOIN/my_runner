/*
** EPITECH PROJECT, 2018
** my_malloc
** File description:
** my_malloc
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

char *my_malloc(unsigned int size)
{
	char *mall = malloc(size);

	for (unsigned int i = 0; i < size; i = i + 1)
		mall[i] = '\0';
	return (mall);
}
