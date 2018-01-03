/*
** EPITECH PROJECT, 2018
** jump
** File description:
** jump
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

int jump(sfSprite *player, int action)
{
	sfVector2f jump = {0, -6.0};
	static int is_jump = 0;
	static int timer = 0;

	if (action == 0 || timer > 45) {
		is_jump = 0;
		timer = 0;
		return (0);
	} else if (action == 1)
		is_jump = 1;
	if (is_jump) {
		sfSprite_move(player, jump);
		timer += 1;
	}
	return (is_jump);
}
