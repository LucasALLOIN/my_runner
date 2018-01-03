/*
** EPITECH PROJECT, 2018
** shoot_player
** File description:
** shoot_player
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

void shoot_player(sfVector2f s, sprite_list *p, sprite_list *shoot, game *game)
{
	sfVector2f p_pos = sfSprite_getPosition(p->sprite);
	sfVector2f move = {0, -1200};

	if (shoot->mod == 1 && s.x > p_pos.x + 30 && \
	s.x < p_pos.x + 60 && s.y > p_pos.y -20  \
	&& s.y < p_pos.y + 149) {
		sfSprite_move(shoot->sprite, move);
		degat(p, game->text, 1);
		play_music(game->music, "damage");
	}
}
