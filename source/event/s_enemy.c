/*
** EPITECH PROJECT, 2018
** s_enemy
** File description:
** s_enemy
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

void s_enemy(sfVector2f s_p, sprite_list *enemy, sprite_list *shoot, game *game)
{
	sfVector2f enemy_pos = sfSprite_getPosition(enemy->sprite);
	sfVector2f move = {0, -1200};
	sfVector2f shoot_pos = s_p;

	if (shoot_pos.x > enemy_pos.x + 40 && shoot_pos.x < enemy_pos.x + 100 \
	&& shoot_pos.y > enemy_pos.y - 20 && \
	shoot_pos.y < enemy_pos.y + 149 && shoot->mod == 0) {
		sfSprite_move(shoot->sprite, move);
		move.y += 200;
		update_score(game->text, 50, 0);
		play_music(game->music, "kill");
		sfSprite_move(enemy->sprite, move);
	}
}
