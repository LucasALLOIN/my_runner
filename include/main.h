/*
1;5002;0c** EPITECH PROJECT, 2017
** Project my_runner
** File description:
** Header file
*/

#ifndef MAIN_H_
#define MAIN_H_

typedef struct s_sprite_list {
	sfSprite *sprite;
	sfTexture *texture;
	sfVector2f position;
	sfIntRect rect;
	int pos;
	int mod;
	int life;
	struct s_sprite_list *next;
} sprite_list;

typedef struct s_text_list {
	sfText *text;
	struct s_text_list *next;
} text_list;

typedef struct s_music_list {
	sfMusic *music;
	char data[10];
	struct s_music_list *next;
} music_list;

#endif
