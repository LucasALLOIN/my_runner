/*
** EPITECH PROJECT, 2018
** apply_action_two
** File description:
** apply_action_two
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

void apply_action_two(game *game)
{
	sprite_list *p = get_sprite(game->list, 2);
	static int timer = 0;
	sprite_list *head = game->enemy;

	if (game->timer % 7 == 0) {
		while (game->enemy != NULL) {
			sfSprite_setTextureRect(game->enemy->sprite, \
			rect_enemy(&game->enemy->pos));
			game->enemy = game->enemy->next;
		}
	}
	if (is_on_spike(p->sprite, game->spike) || is_on_enemy(p->sprite, \
	game->enemy)) {
		degat(p, game->text, 1);
		play_music(game->music, "damage");
	}
	game->enemy = head;
	timer += 1;
}
