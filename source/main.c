/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
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

int main(int argc, char **argv)
{
	game *game = malloc(sizeof(struct s_game));

	if (verify_error(argc, argv))
		return (84);
	if (verify_help(argv))
		return (0);
	game_init(game, argv);
	if (!game->window)
		return (84);
	sfRenderWindow_setFramerateLimit(game->window, 60);
	init_sprite(game);
	create_map(game, argv[1]);
	while (sfRenderWindow_isOpen(game->window)) {
		while (sfRenderWindow_pollEvent(game->window, &game->event))
			event_game(game, argv);
	        sfRenderWindow_clear(game->window, sfBlack);
		game_handler(game);
	}
	destroy_all(game);
	return (0);
}
