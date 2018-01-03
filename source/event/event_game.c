/*
** EPITECH PROJECT, 2018
** event_game
** File description:
** event_game
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

void event_game(game *game, char **argv)
{
	window_close(game);
	jump_maker(game);
	shoot_maker(game);
	start_game(game);
	start_help(game);
	start_pause(game);
	reset_game(game, argv);
}
