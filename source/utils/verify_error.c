/*
** EPITECH PROJECT, 2018
** verify_error
** File description:
** verify_error
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

int verify_error(int argc, char **argv)
{
	int fd;

	if (argc < 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0 && my_strcmp(argv[1], "-h") != 0)
		return (1);
	close(fd);
	return (0);
}
