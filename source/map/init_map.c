/*
** EPITECH PROJECT, 2018
** init_map
** File description:
** init_map
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

void init_map(map *m, char *maps)
{
	m->fd = fopen(maps, "r");
	m->line = NULL;
	m->plat_pos.x = 0;
	m->plat_pos.y = 196;
	m->end_pos.x = 0;
	m->end_pos.y = -45;
	m->sp_pos.x = 0;
	m->sp_pos.y = 129;
	m->enemy_pos.x = 0;
	m->enemy_pos.y = 49;
	m->len = 0;
	init_map_two(m);
}
