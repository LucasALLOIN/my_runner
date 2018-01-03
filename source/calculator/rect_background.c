/*
** EPITECH PROJECT, 2018
** rect_background
** File description:
** rect_background
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

sfIntRect rect_background(sfSprite *background)
{
	sfIntRect res;
	sfIntRect old = sfSprite_getTextureRect(background);

	res.left = old.left + 2;
	res.top = old.top;
	res.width = old.width;
	res.height = old.height;
	if (res.left == 3840)
		res.left = 0;
	return (res);
}
