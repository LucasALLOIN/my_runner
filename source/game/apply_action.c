/*
** EPITECH PROJECT, 2018
** apply_action
** File description:
** apply_action
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

static void app_back(int timer, sfSprite *back, sfSprite *city)
{
	if (timer % 5 == 0)
		sfSprite_setTextureRect(back, rect_background(back));
	if (timer % 3 == 0)
		sfSprite_setTextureRect(city, rect_city(city));

}

static void app_fall(int is_fall, int is_jump, sfSprite *player, sfIntRect no)
{
	if (is_jump || !is_fall)
		sfSprite_setTextureRect(player, no);
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

	app_back(timer, back, city);
	if (timer % 7 == 0 && !is_jump && is_fall)
		sfSprite_setTextureRect(player, rect_calculator());
        if (timer % 1 == 0)
                is_jump = jump(player, 2);
	app_fall(is_fall, is_jump, player, no_anim);
        if (!is_fall && !is_jump)
                sfSprite_move(player, fall);
}
