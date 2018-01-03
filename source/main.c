/*
** EPITECH PROJECT, 2017
** Project my_runner
** File description:
** Main file.
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

const char *const enemy[] = {"ressources/enemy/testicule.png", \
			     "ressources/enemy/enemy1.png", \
			     "ressources/enemy/enemy2.png"};

sfIntRect rect_calculator()
{
	sfIntRect res;
	static int pos = 0;
	int dec = 0;

	if (pos == 0)
		dec = 5;
	else
		dec = 5 * pos + 5;
	res.top = 178;
	res.left = pos * 124 + dec;
	res.width = 124;
	res.height = 147;
	pos = pos + 1;
	if (pos == 4)
		pos = 0;
	return (res);
}

sfIntRect rect_enemy(int *pos)
{
	sfIntRect res;
	int dec = 0;

	if (*pos == 0)
		dec = 5;
	else
		dec = 5 * *pos + 5;
	res.top = 178;
	res.left = *pos * 124 + dec;
	res.width = 124;
	res.height = 147;
	*pos = *pos + 1;
	if (*pos == 4)
		*pos = 0;
	return (res);
}

sfIntRect rect_background(sfSprite *background)
{
	sfIntRect res;
	sfIntRect old = sfSprite_getTextureRect(background);

	res.left = old.left + 2;
	res.top = old.top;
	res.width = old.width;
	res.height = old.height;
	if (res.left == 3840)
		res.left = 0;
	return (res);
}

sfIntRect rect_city(sfSprite *city)
{
	sfIntRect res;
	sfIntRect old = sfSprite_getTextureRect(city);

	res.left = old.left + 5;
	res.top = old.top;
	res.width = old.width;
	res.height = old.height;
	if (res.left >= 2999)
		res.left = 0;
	return (res);
}

void play_music(music_list *music, char *to_play)
{
	while (music != NULL) {
		if (my_strcmp(music->data, to_play) == 0)
			sfMusic_play(music->music);
		music = music->next;
	}
}

void add_music(music_list **head, char *music_path, char *data)
{
	music_list *new_node = malloc(sizeof(music_list));
	music_list *last = *head;
	sfMusic *music;

	music = sfMusic_createFromFile(music_path);
	new_node->music = music;
	my_strcpy(new_node->data, data);
	new_node->next = NULL;
	if (*head == NULL) {
		*head = new_node;
		return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
}

void add_text(text_list **head, char *value, sfVector2f pos, sfColor color)
{
	text_list *new_node = malloc(sizeof(text_list));
	text_list *last = *head;
	sfText *text = sfText_create();
	sfFont *font = sfFont_createFromFile("ressources/arcade.ttf");

	new_node->text = text;
	sfText_setString(text, value);
	sfText_setFont(text, font);
	sfText_setCharacterSize(text, 50);
	sfText_setPosition(text, pos);
	sfText_setColor(text, color);
	new_node->next = NULL;
	if (*head == NULL) {
		*head = new_node;
		return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
}

void add_menu(sprite_list **head, char *text_path)
{
	sprite_list *new_node = malloc(sizeof(sprite_list));
	sprite_list *last = *head;
	sfVector2f p = {0, 0}; 
	sfSprite *sprite = sfSprite_create();

	new_node->texture = sfTexture_createFromFile(text_path, NULL);
	new_node->sprite = sprite;
	sfSprite_setTexture(new_node->sprite, new_node->texture, sfTrue);
	sfSprite_setPosition(new_node->sprite, p);
	new_node->position = p;
	new_node->next = NULL;
	if (*head == NULL) {
		*head = new_node;
		return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
}

void add_sprite(sprite_list **head, char *text_path, sfVector2f p, sfIntRect r)
{
	sprite_list *new_node = malloc(sizeof(sprite_list));
	sprite_list *last = *head;
	sfSprite *sprite = sfSprite_create();

	new_node->texture = sfTexture_createFromFile(text_path, NULL);
	new_node->sprite = sprite;
	sfSprite_setTexture(new_node->sprite, new_node->texture, sfTrue);
	sfSprite_setPosition(new_node->sprite, p);
	sfSprite_setTextureRect(new_node->sprite, r);
	new_node->position = p;
	new_node->rect = r;
	new_node->next = NULL;
	if (*head == NULL) {
		*head = new_node;
		return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
}

void add_enemy(sprite_list **head, sfVector2f p)
{
	sprite_list *new_node = malloc(sizeof(sprite_list));
	sprite_list *last = *head;
	sfSprite *sprite = sfSprite_create();
	int ran = rand() % 3;

	new_node->texture = sfTexture_createFromFile(enemy[ran], NULL);
	new_node->sprite = sprite;
	sfSprite_setTexture(new_node->sprite, new_node->texture, sfTrue);
	sfSprite_setPosition(new_node->sprite, p);
	new_node->pos = 0;
	sfSprite_setTextureRect(new_node->sprite, rect_enemy(&new_node->pos));
	new_node->next = NULL;
	if (*head == NULL) {
		*head = new_node;
		return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
}

void add_shoot(sprite_list **head, sfSprite *from, int mod)
{
	sprite_list *new_node = malloc(sizeof(sprite_list));
	sprite_list *last = *head;
	sfSprite *sprite = sfSprite_create();
	sfVector2f pos = {0, sfSprite_getPosition(from).y + 60};
	float x = sfSprite_getPosition(from).x;

	pos.x = (mod == 0) ? x + 50 : x - 50;
	new_node->texture = sfTexture_createFromFile("ressources/shoot.png", NULL);
	new_node->sprite = sprite;
	sfSprite_setTexture(new_node->sprite, new_node->texture, sfTrue);
	sfSprite_setPosition(new_node->sprite, pos);
	new_node->mod = mod;
	new_node->next = NULL;
	if (*head == NULL) {
		*head = new_node;
		return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
}

void draw_sprite(sprite_list *list, sfRenderWindow *window)
{
	while (list != NULL) {
		sfRenderWindow_drawSprite(window, list->sprite, NULL);
		list = list->next;
	}
}

void draw_text(text_list *text, sfRenderWindow *window)
{
	while (text != NULL) {
		sfRenderWindow_drawText(window, text->text, NULL);
		text = text->next;
	}
}

sprite_list *get_sprite(sprite_list *list, int pos)
{
	int i = 0;

	for (;i < pos; i = i + 1)
		list = list->next;
	return (list);
}

char *my_malloc(unsigned int size)
{
	char *mall = malloc(size);

	for (unsigned int i = 0; i < size; i = i + 1)
		mall[i] = '\0';
	return (mall);
}

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

void update_life(text_list *text, int value)
{
	char *val;

	val = my_itoa(value);
	text = text->next;
	text = text->next;
	text = text->next;
	sfText_setString(text->text, val);
	free(val);
}

void update_score(text_list *text, int valeur, int mod)
{
	static int value = 0;
	sfVector2f score_pos2 = {230, 730};
	char *val;

	if (mod)
		value = 0;
	value += valeur;
	val = my_itoa(value);
	text = text->next;
	text = text->next;
	sfText_setPosition(text->text, score_pos2);
	sfText_setString(text->text, val);
	free(val);
}

void degat(sprite_list *player, text_list *text, int mod)
{
	static int timer = 0;
	static int damaged = 0;
	sfColor color = {255, 0, 0, 128};
	sfColor color2 = {255, 255, 255, 255};

	if (mod == 1 && !damaged) {
		player->life -= 1;
		update_life(text, player->life);
		damaged = 1;
	}
	if (timer < 180 && damaged) {
		if (timer % 10 == 0)
			sfSprite_setColor(player->sprite, color);
		else if (timer % 5 == 0 && timer % 10 != 0)
			sfSprite_setColor(player->sprite, color2);
		timer += 1;
	} else if (timer >= 180) {
		timer = 0;
		damaged = 0;
	}
}

void add_list(sprite_list **head, sprite_list *new_node)
{
	sprite_list *last = *head;
	
	if (*head == NULL) {
		*head = new_node;
		return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
}

sprite_list *is_plat_on_x(sfSprite *player, sprite_list *plat)
{
	sfVector2f player_co = sfSprite_getPosition(player);
	sfVector2f plat_pos;

	while (plat != NULL) {
		plat_pos = sfSprite_getPosition(plat->sprite);
		if (player_co.y < plat_pos.y && \
		(player_co.x + 55 >= plat_pos.x - 35 && \
		player_co.x + 55 <= plat_pos.x + 130)) {
			return(plat);
		}
		plat = plat->next;
	}
	return (NULL);
}

int is_plat_on_y(sfSprite *player, sprite_list *plat)
{
	sfVector2f player_co = sfSprite_getPosition(player);
	sfVector2f plat_pos;
	float y = player_co.y + 146;

	if (plat == NULL)
		return (0);
	plat_pos = sfSprite_getPosition(plat->sprite);
	if (y >= plat_pos.y - 4 && y <= plat_pos.y + 4)
		return (1);
	return (0);
}

int is_on_end(sfSprite *player, sprite_list *end)
{
	sfVector2f player_co = sfSprite_getPosition(player);
	sfVector2f end_pos;

	while (end != NULL) {
		end_pos = sfSprite_getPosition(end->sprite);
		if (end_pos.y < player_co.y && \
		end_pos.y > player_co.y - 100 && \
		(player_co.x >= end_pos.x && player_co.x <= end_pos.x + 100)) {
			return(1);
		}
		end = end->next;
	}
	return (0);
}

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

int is_on_platform(sfSprite *player, sprite_list *plat)
{
	sprite_list *platt = NULL;

	platt = (is_plat_on_x(player, plat));
	if (platt == NULL || !is_plat_on_y(player, platt)) {
		return (0);
	}
	return (1);
}

void apply_action(sprite_list *list, sprite_list *plat, int timer)
{
	sfSprite *player = get_sprite(list, 2)->sprite;
	sfSprite *back = get_sprite(list, 0)->sprite;
	sfSprite *city = get_sprite(list, 1)->sprite;
	sfVector2f fall = {0, 7};
	sfIntRect no_anim = {248, 174, 124, 146};
	int is_fall = is_on_platform(player, plat);
	static int is_jump = 0;

	if (timer % 5 == 0)
		sfSprite_setTextureRect(back, rect_background(back));
	if (timer % 3 == 0)
		sfSprite_setTextureRect(city, rect_city(city));
	if (timer % 7 == 0 && !is_jump && is_fall)
		sfSprite_setTextureRect(player, rect_calculator());
	if (timer % 1 == 0)
		is_jump = jump(player, 2);
	if (is_jump || !is_fall) {
		sfSprite_setTextureRect(player, no_anim);
	}
	if (!is_fall && !is_jump) {
		sfSprite_move(player, fall);
	}
}

int is_on_spike(sfSprite *player, sprite_list *spike)
{
	sfVector2f player_co = sfSprite_getPosition(player);
	sfVector2f spike_pos;
	float y = player_co.y + 147;
	
	while (spike != NULL) {
		spike_pos = sfSprite_getPosition(spike->sprite);
		if (y > spike_pos.y + 20 && \
		spike_pos.y > player_co.y - 70 && \
		(player_co.x + 90 > spike_pos.x && \
		player_co.x < spike_pos.x + 65)) {
			return(1);
		}
		spike = spike->next;
	}
	return (0);
}

int is_on_enemy(sfSprite *player, sprite_list *enemy)
{
	sfVector2f player_co = sfSprite_getPosition(player);
	sfVector2f enemy_pos;
	float y = player_co.y + 147;

	while (enemy != NULL) {
		enemy_pos = sfSprite_getPosition(enemy->sprite);
		if (y > enemy_pos.y && enemy_pos.y > \
		player_co.y - 50 && (player_co.x + 50 > enemy_pos.x \
		&& player_co.x < enemy_pos.x + 50)) {
			return(1);
		}
		enemy = enemy->next;
	}
	return (0);
}

int is_on_shoot(sprite_list *p, sprite_list *shoot, sprite_list *enemy, text_list *text, music_list *music)
{
	sfVector2f shoot_pos;
	sfVector2f enemy_pos;
	sfVector2f p_pos = sfSprite_getPosition(p->sprite);
	sfVector2f move = {0, -1200};
	sprite_list *head = enemy;

	while (shoot != NULL) {
		shoot_pos = sfSprite_getPosition(shoot->sprite);
		while (enemy != NULL) {
			enemy_pos = sfSprite_getPosition(enemy->sprite);
			if (shoot_pos.x > enemy_pos.x + 40 && shoot_pos.x < enemy_pos.x + 100 && shoot_pos.y > enemy_pos.y - 20 && shoot_pos.y < enemy_pos.y + 149 && shoot->mod == 0) {
				sfSprite_move(shoot->sprite, move);
				move.y += 200;
				update_score(text, 50, 0);
				play_music(music, "kill");
				sfSprite_move(enemy->sprite, move);
			}
			enemy = enemy->next;
		}
	        if (shoot->mod == 1 && shoot_pos.x > p_pos.x + 30 && shoot_pos.x < p_pos.x + 60 && shoot_pos.y > p_pos.y -20 && shoot_pos.y < p_pos.y + 149) {
			sfSprite_move(shoot->sprite, move);
		        degat(p, text, 1);
			play_music(music, "damage");
		}
		enemy = head;
	        shoot = shoot->next;
	}
	return (0);
}

void apply_action_two(sprite_list *list, sprite_list *spike, sprite_list *enemy, text_list *text, music_list *music)
{
	sprite_list *p = get_sprite(list, 2);
	static int timer = 0;

	if (timer % 7 == 0) {
		while (enemy != NULL) {
			sfSprite_setTextureRect(enemy->sprite, rect_enemy(&enemy->pos));
			enemy = enemy->next;
		}
	}
	if (is_on_spike(p->sprite, spike) || is_on_enemy(p->sprite, enemy)) {
		degat(p, text, 1);
		play_music(music, "damage");
	}
	timer += 1;
}

void init_map_two(map *m)
{
	m->plat_rect.left = 0;
        m->plat_rect.top = 0;
 	m->plat_rect.width = 129;
	m->plat_rect.height = 65;
        m->end_rect.left = 0;
        m->end_rect.top = 0;
	m->end_rect.width = 200;
        m->end_rect.height = 263;
        m->spike_rect.left = 0;
	m->spike_rect.top = 0;
        m->spike_rect.width = 129;
        m->spike_rect.height = 72;
        m->nline = 0;
}

void init_map(map *m, char *maps)
{
	m->fd = fopen(maps, "r");
        m->line = NULL;
        m->plat_pos.x = 0;
	m->plat_pos.y = 196;
        m->end_pos.x = 0;
        m->end_pos.y = -45;
        m->sp_pos.x = 0;
        m->sp_pos.y = 129;
        m->enemy_pos.x = 0;
        m->enemy_pos.y = 49;
	m->len = 0;
	init_map_two(m);
}

void create_map_nline(map *m, game *game, int i)
{
	char *p = "ressources/platform.png";
        char *path2 = "ressources/portal.png";
        char *p3 = "ressources/spike.png";

	if (m->nline % 2 == 0) {
		m->end_pos.x -= 30;
		if (m->line[i] == 'E')
			add_sprite(&game->end, path2, m->end_pos, m->end_rect);
		if (m->line[i] == 'S')
			add_sprite(&game->spike, p3, m->sp_pos, m->spike_rect);
		if (m->line[i] == 'K')
			add_enemy(&game->enemy, m->enemy_pos);
		m->sp_pos.x += 130;
		m->enemy_pos.x += 130;
		m->end_pos.x += 160;
	} else {
		if (m->line[i] == 'P')
			add_sprite(&game->plat, p, m->plat_pos, m->plat_rect);
		m->plat_pos.x += 130;
	}
}

void create_map(game *game, char *maps)
{
	map *m = malloc(sizeof(map));

        init_map(m, maps);
	while ((getline(&m->line, &m->len, m->fd)) != -1) {
		for (int i = 0; m->line[i]; i = i + 1) {
			create_map_nline(m, game, i);
		}
		if (m->nline % 2 == 0) {
			m->sp_pos.y += 216;
			m->end_pos.y += 216;
			m->enemy_pos.y += 216;
		} else
			m->plat_pos.y += 216;
		m->end_pos.x = 0;
		m->sp_pos.x = 0;
		m->plat_pos.x = 0;
		m->enemy_pos.x = 0;
	        m->nline += 1;
	}
	fclose(m->fd);
	free(m);
}

void plat_mov(sprite_list *plat)
{
	sfVector2f move = {-3.0, 0};
	
	while (plat != NULL) {
		sfSprite_move(plat->sprite, move);
		plat = plat->next;
	}
}

void shoot_mov(sprite_list *shoot)
{
	sfVector2f move = {0, 0};
	sfVector2f move2 = {0, 12000};
	sfVector2f shoot_pos;

	while (shoot != NULL) {
		shoot_pos = sfSprite_getPosition(shoot->sprite);
		if (shoot_pos.x > 1280 || shoot_pos.x < 0)
			sfSprite_move(shoot->sprite, move2);
		move.x = (shoot->mod == 0) ? 6 : -6;
		sfSprite_move(shoot->sprite, move);
		shoot = shoot->next;
	}
}

void enemy_shoot(sprite_list **shoot, sprite_list *enemy, music_list *music)
{
	int ran = rand() % 500;
	sfVector2f pos;

	while (enemy != NULL) {
		ran = rand() % 500;
		pos = sfSprite_getPosition(enemy->sprite);
		if (ran > 497 && pos.x < 1280 && pos.x > 0) {
			add_shoot(shoot, enemy->sprite, 1);
			play_music(music, "shoot");
		}
		enemy = enemy->next;
	}
}

void is_looser(sprite_list *player, int *loose, music_list *music)
{
	sfVector2f p = sfSprite_getPosition(player->sprite);

	if (p.y > 800 || player->life < 1) {
		*loose = 1;
		play_music(music, "loose");
	}
}

void is_winner(sprite_list *player, sprite_list *end, int *win, music_list *m)
{
	if (is_on_end(player->sprite, end)) {
	        *win = 1;
		play_music(m, "win");
	}
}

void draw_specific_sprite(sprite_list *list, sfRenderWindow *window)
{
	sfRenderWindow_drawSprite(window, list->sprite, NULL);
}

void draw_text_wl(text_list *list, sfRenderWindow *window)
{
	sfVector2f score_wl = {542, 508};
		
	list = list->next;
	list = list->next;
	sfText_setPosition(list->text, score_wl);
	sfRenderWindow_drawText(window, list->text, NULL);
}

void destroy_list(sprite_list **head)
{
	sprite_list *last = *head;

	while (*head != NULL) {
		sfSprite_destroy((*head)->sprite);
		sfTexture_destroy((*head)->texture);
		last = *head;
		*head = (*head)->next;
		free(last);
	}
}

void destroy_music(music_list **head)
{
	music_list *last = *head;

	while (*head != NULL) {
		sfMusic_destroy((*head)->music);
	        last = *head;
		*head = (*head)->next;
		free(last);
        }
}

void game_init_two(game *game)
{
	game->life_pos.x = 1000;
	game->life_pos.y = 730;
	game->life_pos2.x = 1150;
	game->life_pos2.y = 730;
	game->list = NULL;
	game->menu = NULL;
	game->plat = NULL;
	game->end = NULL;
	game->spike = NULL;
	game->enemy = NULL;
	game->shoot = NULL;
	game->text = NULL;
	game->music = NULL;
	game->started = 0;
	game->help = 0;
	game->pause = 0;
	game->win = 0;
	game->loose = 0;
	game->timer = 0;
}

void game_init(game *game, char **argv)
{
        srand((long int) argv);
	game->mode.width = 1280;
	game->mode.height = 800;
	game->mode.bitsPerPixel = 32;
	game->window = sfRenderWindow_create(game->mode, "my_runner", sfResize | \
	sfClose, NULL);
	game->ini_pos.x = 0;
	game->ini_pos.y = 400;
	game->back_pos.x = 0;
	game->back_pos.y = 0;
	game->back_rect.left = 300;
	game->back_rect.top = 10;
	game->back_rect.width = 1280;
	game->back_rect.height = 720;
	game->city_rect.left = 0;
	game->city_rect.top = 750;
	game->city_rect.width = 1280;
	game->city_rect.height = 720;
	game->score_pos.x = 30;
	game->score_pos.y = 730;
	game_init_two(game);
}

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

void window_close(game *game)
{
	if (game->event.type == sfEvtClosed \
	|| (game->event.type == sfEvtKeyPressed && \
	game->event.key.code == sfKeyQ))
		sfRenderWindow_close(game->window);
}

void jump_maker(game *game)
{
	if (game->event.type == sfEvtKeyPressed && game->event.key.code == \
	sfKeySpace && game->started)
		if (is_on_platform(get_sprite(game->list, 2)->sprite, \
		game->plat))
			jump(get_sprite(game->list, 2)->sprite, 1);
}

void shoot_maker(game *game)
{
	if (game->event.type == sfEvtKeyPressed && game->event.key.code == \
	sfKeyS && game->started) {
		add_shoot(&game->shoot, get_sprite(game->list, 2)->sprite, 0);
		play_music(game->music, "shoot");
	}
}

void start_game(game *game)
{
	if (game->event.type == sfEvtKeyPressed && game->event.key.code == \
	sfKeyReturn && !game->started && !game->help)
		game->started = 1;
}

void start_help(game *game)
{
	if (game->event.type == sfEvtKeyPressed && game->event.key.code == \
	sfKeyH && !game->started)
		game->help = 1;
	if (game->event.type == sfEvtKeyPressed && game->event.key.code == \
	sfKeyEscape && !game->started)
		game->help = 0;
}

void start_pause(game *game)
{
	if (game->event.type == sfEvtKeyPressed && game->event.key.code == \
	sfKeyP && game->started && !game->win && !game->loose)
		game->pause = 1;
	if (game->event.type == sfEvtKeyPressed && game->event.key.code == \
	sfKeyEscape && game->started && !game->win && !game->loose)
		game->pause = 0;
}

void reset_game(game *game, char **argv)
{
	if (game->event.type == sfEvtKeyPressed && game->event.key.code == \
	sfKeyR && game->started && (game->win || game->loose)) {
		game->win = 0;
		game->loose = 0;
		update_score(game->text, 0, 1);
		get_sprite(game->list, 2)->life = 3;
		update_life(game->text, 3);
		destroy_list(&game->plat);
		destroy_list(&game->enemy);
		destroy_list(&game->spike);
		destroy_list(&game->end);
		destroy_list(&game->shoot);
		sfSprite_setPosition(get_sprite(game->list, 2)->sprite, \
		game->ini_pos);
		create_map(game, argv[1]);
	}
}

void draw_all(game *game)
{
	draw_sprite(game->list, game->window);
	draw_sprite(game->end, game->window);
	draw_sprite(game->spike, game->window);
	draw_sprite(game->shoot, game->window);
	draw_sprite(game->enemy, game->window);
	draw_sprite(get_sprite(game->list, 2), game->window);
	draw_sprite(game->plat, game->window);
	draw_text(game->text, game->window);
}

void action(game *game)
{
	enemy_shoot(&game->shoot, game->enemy, game->music);
	apply_action(game->list, game->plat, game->timer);
	apply_action_two(game->list, game->spike, game->enemy, game->text, \
	game->music);
	plat_mov(game->plat);
	plat_mov(game->end);
	plat_mov(game->spike);
	plat_mov(game->enemy);
	shoot_mov(game->shoot);
	is_on_shoot(get_sprite(game->list, 2), game->shoot, game->enemy, \
	game->text, game->music);
	degat(get_sprite(game->list, 2), game->text, 0);
	is_winner(get_sprite(game->list, 2), game->end, &game->win, \
	game->music);
	is_looser(get_sprite(game->list, 2), &game->loose, game->music);
	update_score(game->text, 1, 0);
	game->timer += 1;
	draw_all(game);
}

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

void game_handler(game *game)
{
	if (game->started && !game->pause && !game->win && !game->loose) {
		action(game);
	} else if (!game->started) {
		draw_specific_sprite(get_sprite(game->menu, 0), game->window);
		if (game->help)
			draw_specific_sprite(get_sprite(game->menu, 1), \
			game->window);
	} else if (game->pause) {
		draw_specific_sprite(get_sprite(game->menu, 2), game->window);
	} else if (game->win) {
		draw_specific_sprite(get_sprite(game->menu, 3), game->window);
		draw_text_wl(game->text, game->window);
	} else if (game->loose) {
		draw_specific_sprite(get_sprite(game->menu, 4), game->window);
		draw_text_wl(game->text, game->window);
	}
	sfRenderWindow_display(game->window);
	game->timer += 1;
}

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

int main(int argc, char **argv)
{
	game *game = malloc(sizeof(*game));

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
