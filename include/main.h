/*
** EPITECH PROJECT, 2017
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

sfIntRect rect_calculator(void);
sfIntRect rect_enemy(int *pos);
sfIntRect rect_background(sfSprite *background);
sfIntRect rect_city(sfSprite *city);
void play_music(music_list *music, char *to_play);
void add_music(music_list **head, char *music_path, char *data);
void add_text(text_list **head, char *value, sfVector2f pos, sfColor color);
void add_menu(sprite_list **head, char *text_path);
void add_sprite(sprite_list **head, char *text_path, sfVector2f p, sfIntRect r);
void add_enemy(sprite_list **head, sfVector2f p);
void add_shoot(sprite_list **head, sfSprite *from, int mod);
void draw_sprite(sprite_list *list, sfRenderWindow *window);
void draw_text(text_list *text, sfRenderWindow *window);
sprite_list *get_sprite(sprite_list *list, int pos);
char *my_malloc(unsigned int size);
char *my_itoa(int num);
void update_life(text_list *text, int value);
void update_score(text_list *text, int valeur, int mod);
void degat(sprite_list *player, text_list *text, int mod);
void add_list(sprite_list **head, sprite_list *new_node);
sprite_list *is_plat_on_x(sfSprite *player, sprite_list *plat);
int is_plat_on_y(sfSprite *player, sprite_list *plat);
int is_on_end(sfSprite *player, sprite_list *end);
int jump(sfSprite *player, int action);
int is_on_platform(sfSprite *player, sprite_list *plat);
void apply_action(sprite_list *list, sprite_list *plat, int timer);
int is_on_spike(sfSprite *player, sprite_list *spike);
int is_on_enemy(sfSprite *player, sprite_list *enemy);
void s_enemy(sfVector2f s_p, sprite_list *enemy, sprite_list *shoot, game *g);
void shoot_player(sfVector2f s, sprite_list *p, sprite_list *shoot, game *game);
int on_shot(sprite_list *p, sprite_list *shoot, sprite_list *enemy, game *game);
void apply_action_two(game *game);
void init_map_two(map *m);
void init_map(map *m, char *maps);
void create_map_nline(map *m, game *game, int i);
void create_map(game *game, char *maps);
void plat_mov(sprite_list *plat);
void shoot_mov(sprite_list *shoot);
void enemy_shoot(sprite_list **shoot, sprite_list *enemy, music_list *music);
void is_looser(sprite_list *player, int *loose, music_list *music);
void is_winner(sprite_list *player, sprite_list *end, int *win, music_list *m);
void draw_specific_sprite(sprite_list *list, sfRenderWindow *window);
void draw_text_wl(text_list *list, sfRenderWindow *window);
void destroy_list(sprite_list **head);
void destroy_music(music_list **head);
void game_init_two(game *game);
void game_init(game *game, char **argv);
int verify_error(int argc, char **argv);
int verify_help(char **argv);
void init_sprite(game *game);
void window_close(game *game);
void jump_maker(game *game);
void shoot_maker(game *game);
void start_game(game *game);
void start_help(game *game);
void start_pause(game *game);
void reset_game(game *game, char **argv);
void draw_all(game *game);
void action(game *game);
void destroy_all(game *game);
void game_handler(game *game);
void event_game(game *game, char **argv);
int main(int argc, char **argv);

#endif
