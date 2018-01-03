/*
** EPITECH PROJECT, 2018
** action
** File description:
** action
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

void action(game *game)
{
	enemy_shoot(&game->shoot, game->enemy, game->music);
	apply_action(game->list, game->plat, game->timer);
	apply_action_two(game);
	plat_mov(game->plat);
	plat_mov(game->end);
	plat_mov(game->spike);
	plat_mov(game->enemy);
	shoot_mov(game->shoot);
	on_shot(get_sprite(game->list, 2), game->shoot, game->enemy, game);
	degat(get_sprite(game->list, 2), game->text, 0);
	is_winner(get_sprite(game->list, 2), game->end, &game->win, \
	game->music);
	is_looser(get_sprite(game->list, 2), &game->loose, game->music);
	update_score(game->text, 1, 0);
	game->timer += 1;
	draw_all(game);
}
