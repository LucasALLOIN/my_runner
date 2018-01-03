##
## EPITECH PROJECT, 2017
## Project my_runner
## File description:
## Build my_runner binary.
##

SRC     =	source/physics/is_on_enemy.c \
		source/physics/is_on_spike.c \
		source/physics/is_plat_on_y.c \
		source/physics/is_plat_on_x.c \
		source/physics/jump.c \
		source/physics/jump_maker.c \
		source/physics/is_on_end.c \
		source/physics/is_on_platform.c \
		source/physics/plat_mov.c \
		source/physics/shoot_mov.c \
		source/physics/on_shot.c \
		source/music/play_music.c \
		source/menu/start_pause.c \
		source/menu/start_game.c \
		source/menu/start_help.c \
		source/main.c \
		source/hud/update_life.c \
		source/hud/update_score.c \
		source/linked_list/add_sprite.c \
		source/linked_list/destroy_all.c \
		source/linked_list/add_enemy.c \
		source/linked_list/add_text.c \
		source/linked_list/destroy_music.c \
		source/linked_list/add_menu.c \
		source/linked_list/get_sprite.c \
		source/linked_list/add_list.c \
		source/linked_list/add_shoot.c \
		source/linked_list/destroy_list.c \
		source/linked_list/add_music.c \
		source/game/game_handler.c \
		source/game/apply_action.c \
		source/game/init_sprite.c \
		source/game/game_init_two.c \
		source/game/game_init.c \
		source/game/action.c \
		source/game/apply_action_two.c \
		source/event/is_winner.c \
		source/event/event_game.c \
		source/event/shoot_maker.c \
		source/event/reset_game.c \
		source/event/enemy_shoot.c \
		source/event/shoot_player.c \
		source/event/s_enemy.c \
		source/event/window_close.c \
		source/event/degat.c \
		source/event/is_looser.c \
		source/calculator/rect_enemy.c \
		source/calculator/rect_background.c \
		source/calculator/rect_calculator.c \
		source/calculator/rect_city.c \
		source/utils/my_malloc.c \
		source/utils/verify_error.c \
		source/utils/my_itoa.c \
		source/utils/verify_help.c \
		source/drawer/draw_text_wl.c \
		source/drawer/draw_all.c \
		source/drawer/draw_specific_sprite.c \
		source/drawer/draw_text.c \
		source/drawer/draw_sprite.c \
		source/map/create_map_nline.c \
		source/map/init_map.c \
		source/map/create_map.c \
		source/map/init_map_two.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Werror -Wextra -W -Wall -Wparentheses -Wsign-compare -Wpointer-sign -Wuninitialized -Wunused-but-set-variable -I ./include/ -L lib/my -lmy -lc_graph_prog

NAME	=	my_runner

CC	=	gcc

all:	$(NAME)

$(NAME):	$(OBJ)
		make -C lib/my
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
