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

typedef struct s_game {
	sfVideoMode mode;
	sfRenderWindow *window;
	sfEvent event;
	sfVector2f ini_pos;
	sfVector2f back_pos;
	sfIntRect back_rect;
	sfIntRect city_rect;
	sfVector2f score_pos;
	sfVector2f life_pos;
	sfVector2f life_pos2;
	sprite_list *list;
	sprite_list *menu;
	sprite_list *plat;
	sprite_list *end;
	sprite_list *spike;
	sprite_list *enemy;
	sprite_list *shoot;
	text_list *text;
	music_list *music;
	int started;
	int help;
	int pause;
	int win;
	int loose;
	int timer;
} game;

typedef struct s_map {
	FILE *fd;
	char *line;
	sfVector2f plat_pos;
	sfVector2f end_pos;
	sfVector2f sp_pos;
	sfVector2f enemy_pos;
	size_t len;
	sfIntRect plat_rect;
	sfIntRect end_rect;
	sfIntRect spike_rect;
	int nline;
} map;

#endif
