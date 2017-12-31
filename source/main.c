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
	sfVector2f jump = {0, -7};
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
		spike_pos.y > player_co.y - 100 && \
		(player_co.x + 100 > spike_pos.x && \
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

void create_map(sprite_list **list, sprite_list **end, sprite_list **spike, sprite_list **enemy, char *map)
{
	FILE *fd = fopen(map, "r");
	char *line = NULL;
	sfVector2f plat_pos = {0, 196};
	sfVector2f end_pos = {0, -45};
	sfVector2f spike_pos = {0, 129};
	sfVector2f enemy_pos = {0, 49};
	size_t len = 0;
	char *path = "ressources/platform.png";
	char *path2 = "ressources/portal.png";
	char *path3 = "ressources/spike.png";
	sfIntRect plat_rect = {0, 0, 129, 65};
	sfIntRect end_rect = {0, 0, 200, 263};
	sfIntRect spike_rect = {0, 0, 129, 72};
	int nline = 0;

	while ((getline(&line, &len, fd)) != -1) {
		for (int i = 0; line[i]; i = i + 1) {
			if (nline % 2 == 0) {
				end_pos.x -= 30;
				if (line[i] == 'E')
					add_sprite(end, path2, end_pos, end_rect);
				if (line[i] == 'S')
					add_sprite(spike, path3, spike_pos, spike_rect);
				if (line[i] == 'K')
					add_enemy(enemy, enemy_pos);
				spike_pos.x += 130;
				enemy_pos.x += 130;
				end_pos.x += 160;
			} else {
				if (line[i] == 'P')
					add_sprite(list, path, plat_pos, plat_rect);
				plat_pos.x += 130;
			}
		}
		if (nline % 2 == 0) {
			spike_pos.y += 216;
			end_pos.y += 216;
			enemy_pos.y += 216;
		} else {
			plat_pos.y += 216;
		}
		end_pos.x = 0;
		spike_pos.x = 0;
		plat_pos.x = 0;
		enemy_pos.x = 0;
	        nline += 1;
	}
	fclose(fd);
}

void plat_mov(sprite_list *plat)
{
	sfVector2f move = {-2.5, 0};
	
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

void is_winner(sprite_list *player, sprite_list *end, int *win, music_list *music)
{
	if (is_on_end(player->sprite, end)) {
	        *win = 1;
		play_music(music, "win");
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

int main(int argc, char **argv)
{
	sfVideoMode mode = {1280, 800, 32};
	sfRenderWindow *window;
	sfEvent event;
	sfVector2f ini_pos = {0, 400};
	sfVector2f back_pos = {0, 0};
	sfIntRect back_rect = {10, 300, 1280, 720};
	sfIntRect city_rect = {0, 750, 1280, 720};
	sfVector2f score_pos = {30, 730};
	sfVector2f life_pos = {1000, 730};
	sfVector2f life_pos2 = {1150, 730};
	sprite_list *list = NULL;
	sprite_list *menu = NULL;
	sprite_list *plat = NULL;
	sprite_list *end = NULL;
	sprite_list *spike = NULL;
	sprite_list *enemy = NULL;
	sprite_list *shoot = NULL;
	text_list *text = NULL;
	music_list *music = NULL;
	int started = 0;
	int help = 0;
	int pause = 0;
	int win = 0;
	int loose = 0;
	int timer = 0;

	(void) argc;
	srand((long int) argv);
	window = sfRenderWindow_create(mode, "my_runner", sfResize | sfClose, NULL);
	if (!window)
		return (84);
	sfRenderWindow_setFramerateLimit(window, 60);
	add_sprite(&list, "ressources/background.png", back_pos, back_rect);
	add_sprite(&list, "ressources/city.png", back_pos, city_rect);
	add_sprite(&list, "ressources/player.png", ini_pos, rect_calculator());
	add_menu(&menu, "ressources/menu/menu.png");
	add_menu(&menu, "ressources/menu/help.png");
	add_menu(&menu, "ressources/menu/pause.png");
	add_menu(&menu, "ressources/menu/win.png");
	add_menu(&menu, "ressources/menu/loose.png");
	add_text(&text, "Score   ", score_pos, sfGreen);
	add_text(&text, "Life   ", life_pos, sfRed);
	add_text(&text, "0", score_pos, sfGreen);
	add_text(&text, "3", life_pos2, sfRed);
	add_music(&music, "ressources/sounds/win.ogg", "win");
	add_music(&music, "ressources/sounds/loose.ogg", "loose");
       	add_music(&music, "ressources/sounds/damage.ogg", "damage");
	add_music(&music, "ressources/sounds/kill.ogg", "kill");
	add_music(&music, "ressources/sounds/shoot.ogg", "shoot");
	get_sprite(list, 2)->life = 3;
	create_map(&plat, &end, &spike, &enemy, argv[1]);
	while (sfRenderWindow_isOpen(window)) {
		while (sfRenderWindow_pollEvent(window, &event)) {
			if (event.type == sfEvtClosed || (event.type == sfEvtKeyPressed && event.key.code == sfKeyQ))
				sfRenderWindow_close(window);
			if (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace && started)
				if (is_on_platform(get_sprite(list, 2)->sprite, plat))
				    jump(get_sprite(list, 2)->sprite, 1);
			if (event.type == sfEvtKeyPressed && event.key.code == sfKeyS && started) {
				add_shoot(&shoot, get_sprite(list, 2)->sprite, 0);
				play_music(music, "shoot");
			}
			if (event.type == sfEvtKeyPressed && event.key.code == sfKeyReturn && !started && !help)
				started = 1;
			if (event.type == sfEvtKeyPressed && event.key.code == sfKeyH && !started)
				help = 1;
			if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape && !started)
				help = 0;
			if (event.type == sfEvtKeyPressed && event.key.code == sfKeyP && started && !win && !loose)
				pause = 1;
			if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape && started && !win && !loose)
				pause = 0;
			if (event.type == sfEvtKeyPressed && event.key.code == sfKeyR && started && (win || loose)) {
					win = 0;
					loose = 0;
					update_score(text, 0, 1);
					get_sprite(list, 2)->life = 3;
					update_life(text, 3);
					destroy_list(&plat);
					destroy_list(&enemy);
					destroy_list(&spike);
					destroy_list(&end);
					destroy_list(&shoot);
					sfSprite_setPosition(get_sprite(list, 2)->sprite, ini_pos);
					create_map(&plat, &end, &spike, &enemy, argv[1]);
				}

		}
		sfRenderWindow_clear(window, sfBlack);
		if (started && !pause && !win && !loose) {
			enemy_shoot(&shoot, enemy, music); 
			apply_action(list, plat, timer);
			apply_action_two(list, spike, enemy, text, music);
			plat_mov(plat);
			plat_mov(end);
			plat_mov(spike);
			plat_mov(enemy);
			shoot_mov(shoot);
			is_on_shoot(get_sprite(list, 2), shoot, enemy, text, music);
			degat(get_sprite(list, 2), text, 0);
			is_winner(get_sprite(list, 2), end, &win, music);
			is_looser(get_sprite(list, 2), &loose, music);
			update_score(text, 1, 0);
			timer += 1;
			draw_sprite(list, window);
			draw_sprite(end, window);
			draw_sprite(spike, window);
			draw_sprite(shoot, window);
			draw_sprite(enemy, window);
			draw_sprite(get_sprite(list, 2), window);
			draw_sprite(plat, window);
			draw_text(text, window);
		} else if (!started) {
			draw_specific_sprite(get_sprite(menu, 0), window);
			if (help)
				draw_specific_sprite(get_sprite(menu, 1), window);
		} else if (pause) {
			draw_specific_sprite(get_sprite(menu, 2), window);
		} else if (win) {
			draw_specific_sprite(get_sprite(menu, 3), window);
			draw_text_wl(text, window);
		} else if (loose) {
			draw_specific_sprite(get_sprite(menu, 4), window);
			draw_text_wl(text, window);
		}
		sfRenderWindow_display(window);
		timer += 1;
	}
	destroy_music(&music);
	destroy_list(&plat);
	destroy_list(&enemy);
	destroy_list(&spike);
	destroy_list(&end);
	destroy_list(&shoot);
	destroy_list(&list);
	sfRenderWindow_destroy(window);
	return (0);
}
