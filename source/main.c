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

void free_list(sprite_list *head)
{
	sprite_list *last = head;

	while (last != NULL) {
		free(last);
		last = last->next;
	}
}

void draw_sprite(sprite_list *list, sfRenderWindow *window)
{
	while (list != NULL) {
		sfRenderWindow_drawSprite(window, list->sprite, NULL);
		list = list->next;
	}
}

sprite_list *get_sprite(sprite_list *list, int pos)
{
	int i = 0;

	for (;i < pos; i = i + 1)
		list = list->next;
	return (list);
}

void degat(sprite_list *player, int mod)
{
	static int timer = 0;
	static int damaged = 0;
        sfColor color = {255, 0, 0, 128};
	sfColor color2 = {255, 255, 255, 255};

	if (mod == 1 && !damaged) {
		player->life -= 1;
		damaged = 1;
	}
	if (timer < 180 && damaged) {
		if (timer % 10 == 0) {
			sfSprite_setColor(player->sprite, color);
		} else if (timer % 5 == 0 && timer % 10 != 0) {
			sfSprite_setColor(player->sprite, color2);
		}
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
                if (player_co.y < plat_pos.y && (player_co.x + 55 >= plat_pos.x - 35 && player_co.x + 55 <= plat_pos.x + 130)) {
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
		if (end_pos.y < player_co.y && end_pos.y > player_co.y - 100 && (player_co.x >= end_pos.x && player_co.x <= end_pos.x + 100)) {
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
                if (y > spike_pos.y + 20 && spike_pos.y > player_co.y - 100 && (player_co.x + 100 > spike_pos.x && player_co.x < spike_pos.x + 65)) {
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
                if (y > enemy_pos.y && enemy_pos.y > player_co.y - 50 && (player_co.x + 50 > enemy_pos.x && player_co.x < enemy_pos.x + 50)) {
                        return(1);
                }
                enemy = enemy->next;
        }
        return (0);
}

int is_on_shoot(sprite_list *p, sprite_list *shoot, sprite_list *enemy)
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
				sfSprite_move(enemy->sprite, move);
			}
			enemy = enemy->next;
		}
	        if (shoot->mod == 1 && shoot_pos.x > p_pos.x + 30 && shoot_pos.x < p_pos.x + 60 && shoot_pos.y > p_pos.y -20 && shoot_pos.y < p_pos.y + 149) {
			sfSprite_move(shoot->sprite, move);
		        degat(p, 1);
		}
		enemy = head;
	        shoot = shoot->next;
	}
	return (0);
}

void apply_action_two(sprite_list *list, sprite_list *spike, sprite_list *enemy, int timer)
{
	sprite_list *p = get_sprite(list, 2);

	if (timer % 7 == 0) {
		while (enemy != NULL) {
			sfSprite_setTextureRect(enemy->sprite, rect_enemy(&enemy->pos));
			enemy = enemy->next;
		}
	}
	if (is_on_spike(p->sprite, spike) || is_on_enemy(p->sprite, enemy))
		degat(p, 1);
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

void enemy_shoot(sprite_list **shoot, sprite_list *enemy)
{
	int ran = rand() % 500;
	sfVector2f pos;

	while (enemy != NULL) {
		ran = rand() % 500;
		pos = sfSprite_getPosition(enemy->sprite);
		if (ran > 497 && pos.x < 1280 && pos.x > 0)
			add_shoot(shoot, enemy->sprite, 1);
		enemy = enemy->next;
	}
}

void is_looser(sprite_list *player)
{
	sfVector2f p = sfSprite_getPosition(player->sprite);

	if (p.y > 800 || player->life < 0)
		printf("%s\n", "C'est la mort fdp");
}

void is_winner(sprite_list *player, sprite_list *end)
{
	if (is_on_end(player->sprite, end)) {
		printf("%s\n", "C'est la win");
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
        sprite_list *list = NULL;
	sprite_list *plat = NULL;
	sprite_list *end = NULL;
	sprite_list *spike = NULL;
	sprite_list *enemy = NULL;
	sprite_list *shoot = NULL;
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
	get_sprite(list, 2)->life = 3;
        create_map(&plat, &end, &spike, &enemy, argv[1]);
        while (sfRenderWindow_isOpen(window)) {
		while (sfRenderWindow_pollEvent(window, &event)) {
			if (event.type == sfEvtClosed)
				sfRenderWindow_close(window);
			if (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace)
				if (is_on_platform(get_sprite(list, 2)->sprite, plat))
				    jump(get_sprite(list, 2)->sprite, 1);
			if (event.type == sfEvtKeyPressed && event.key.code == sfKeyS)
				add_shoot(&shoot, get_sprite(list, 2)->sprite, 0);
		}
		enemy_shoot(&shoot, enemy); 
        	apply_action(list, plat, timer);
		apply_action_two(list, spike, enemy, timer);
		plat_mov(plat);
		plat_mov(end);
		plat_mov(spike);
		plat_mov(enemy);
		shoot_mov(shoot);
		is_on_shoot(get_sprite(list, 2), shoot, enemy);
		degat(get_sprite(list, 2), 0);
		is_winner(get_sprite(list, 2), end);
		is_looser(get_sprite(list, 2));
		sfRenderWindow_clear(window, sfBlack);
	        draw_sprite(list, window);
		draw_sprite(end, window);
		draw_sprite(spike, window);
		draw_sprite(shoot, window);
		draw_sprite(enemy, window);
		draw_sprite(get_sprite(list, 2), window);
		draw_sprite(plat, window);
        	sfRenderWindow_display(window);
		timer += 1;
	}
	sfRenderWindow_destroy(window);
	return (0);
}
