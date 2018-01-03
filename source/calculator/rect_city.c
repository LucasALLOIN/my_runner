/*
** EPITECH PROJECT, 2018
** rect_city
** File description:
** rect_city
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

sfIntRect rect_city(sfSprite *city)
{
	sfIntRect res;
	sfIntRect old = sfSprite_getTextureRect(city);

	res.left = old.left + 5;
	res.top = old.top;
	res.width = old.width;
	res.height = old.height;
	if (res.left >= 2999)
		res.left = 0;
	return (res);
}
