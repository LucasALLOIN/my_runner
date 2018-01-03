/*
** EPITECH PROJECT, 2018
** is_on_platform
** File description:
** is_on_platform
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

int is_on_platform(sfSprite *player, sprite_list *plat)
{
	sprite_list *platt = NULL;

	platt = (is_plat_on_x(player, plat));
	if (platt == NULL || !is_plat_on_y(player, platt)) {
		return (0);
	}
	return (1);
}
