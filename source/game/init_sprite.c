/*
** EPITECH PROJECT, 2018
** init_sprite
** File description:
** init_sprite
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

void init_sprite(game *game)
{
	add_sprite(&game->list, "ressources/background.png", \
	game->back_pos, game->back_rect);
	add_sprite(&game->list, "ressources/city.png", game->back_pos,	\
	game->city_rect);
	add_sprite(&game->list, "ressources/player.png", game->ini_pos, \
	rect_calculator());
	add_menu(&game->menu, "ressources/menu/menu.png");
	add_menu(&game->menu, "ressources/menu/help.png");
	add_menu(&game->menu, "ressources/menu/pause.png");
	add_menu(&game->menu, "ressources/menu/win.png");
	add_menu(&game->menu, "ressources/menu/loose.png");
	add_text(&game->text, "Score   ", game->score_pos, sfGreen);
	add_text(&game->text, "Life   ", game->life_pos, sfRed);
	add_text(&game->text, "0", game->score_pos, sfGreen);
	add_text(&game->text, "3", game->life_pos2, sfRed);
	add_music(&game->music, "ressources/sounds/win.ogg", "win");
	add_music(&game->music, "ressources/sounds/loose.ogg", "loose");
	add_music(&game->music, "ressources/sounds/damage.ogg", "damage");
	add_music(&game->music, "ressources/sounds/kill.ogg", "kill");
	add_music(&game->music, "ressources/sounds/shoot.ogg", "shoot");
	get_sprite(game->list, 2)->life = 3;
}
