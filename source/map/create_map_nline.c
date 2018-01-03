/*
** EPITECH PROJECT, 2018
** create_map_nline
** File description:
** create_map_nline
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

void create_map_nline(map *m, game *game, int i)
{
	char *p = "ressources/platform.png";
	char *path2 = "ressources/portal.png";
	char *p3 = "ressources/spike.png";

	if (m->nline % 2 == 0) {
		m->end_pos.x -= 30;
		if (m->line[i] == 'E')
			add_sprite(&game->end, path2, m->end_pos, m->end_rect);
		if (m->line[i] == 'S')
			add_sprite(&game->spike, p3, m->sp_pos, m->spike_rect);
		if (m->line[i] == 'K')
			add_enemy(&game->enemy, m->enemy_pos);
		m->sp_pos.x += 130;
		m->enemy_pos.x += 130;
		m->end_pos.x += 160;
	} else {
		if (m->line[i] == 'P')
			add_sprite(&game->plat, p, m->plat_pos, m->plat_rect);
		m->plat_pos.x += 130;
	}
}
