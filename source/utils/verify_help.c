/*
** EPITECH PROJECT, 2018
** verify_help
** File description:
** verify_help
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

int verify_help(char **argv)
{
	if (my_strcmp(argv[1], "-h") == 0) {
		my_putstr("USAGE\n\tmy_runner map.txt\n\n");
		my_putstr("OPTION\n -h\tLaunch help mode\n\n");
		my_putstr("USER INTERACTION\n");
		my_putstr("\tSpace to jump\n");
		my_putstr("\tS to shoot\n");
		return (1);
	}
	return (0);
}
