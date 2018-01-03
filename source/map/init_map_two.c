/*
** EPITECH PROJECT, 2018
** init_map_two
** File description:
** init_map_two
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

void init_map_two(map *m)
{
	m->plat_rect.left = 0;
	m->plat_rect.top = 0;
	m->plat_rect.width = 129;
	m->plat_rect.height = 65;
	m->end_rect.left = 0;
	m->end_rect.top = 0;
	m->end_rect.width = 200;
	m->end_rect.height = 263;
	m->spike_rect.left = 0;
	m->spike_rect.top = 0;
	m->spike_rect.width = 129;
	m->spike_rect.height = 72;
	m->nline = 0;
}
