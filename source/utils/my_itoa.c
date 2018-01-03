/*
** EPITECH PROJECT, 2018
** my_itoa
** File description:
** my_itoa
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

char *my_itoa(int num)
{
	int i = 0;
	int rem;
	int len = 0;
	int n = num;
	char *result;

	while (n != 0) {
		len = len + 1;
		n /= 10;
	}
	result = my_malloc(len + 1);
	for (; i < len; i = i + 1) {
		rem = num % 10;
		num = num / 10;
		result[len - (i + 1)] = rem + '0';
	}
	result[len] = '\0';
	return (result);
}
