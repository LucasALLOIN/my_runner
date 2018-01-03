/*
** EPITECH PROJECT, 2018
** destroy_all
** File description:
** destroy_all
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

void destroy_all(game *game)
{
	destroy_music(&game->music);
	destroy_list(&game->plat);
	destroy_list(&game->enemy);
	destroy_list(&game->spike);
	destroy_list(&game->end);
	destroy_list(&game->shoot);
	destroy_list(&game->list);
	sfRenderWindow_destroy(game->window);
}
