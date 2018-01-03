/*
** EPITECH PROJECT, 2018
** rect_enemy
** File description:
** rect_enemy
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

sfIntRect rect_enemy(int *pos)
{
	sfIntRect res;
	int dec = 0;

	if (*pos == 0)
		dec = 5;
	else
		dec = 5 * *pos + 5;
	res.top = 178;
	res.left = *pos * 124 + dec;
	res.width = 124;
	res.height = 147;
	*pos = *pos + 1;
	if (*pos == 4)
		*pos = 0;
	return (res);
}
