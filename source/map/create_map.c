/*
** EPITECH PROJECT, 2018
** create_map
** File description:
** create_map
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

void create_map(game *game, char *maps)
{
	map *m = malloc(sizeof(map));

	init_map(m, maps);
	while ((getline(&m->line, &m->len, m->fd)) != -1) {
		for (int i = 0; m->line[i]; i = i + 1) {
			create_map_nline(m, game, i);
		}
		if (m->nline % 2 == 0) {
			m->sp_pos.y += 216;
			m->end_pos.y += 216;
			m->enemy_pos.y += 216;
		} else
			m->plat_pos.y += 216;
		m->end_pos.x = 0;
		m->sp_pos.x = 0;
		m->plat_pos.x = 0;
		m->enemy_pos.x = 0;
	        m->nline += 1;
	}
	fclose(m->fd);
	free(m);
}
