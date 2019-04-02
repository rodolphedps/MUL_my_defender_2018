/*
** EPITECH PROJECT, 2019
** def
** File description:
** def
*/

#ifndef DEFENDER_H
#define DEFENDER_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include "my.h"

typedef struct button_s {
    sfRectangleShape *rect;
    sfVector2f pos_rect;
}              button_t;

typedef struct audio_s{
    sfMusic *chala;
    float volume;
    sfMusic *ingame;
    sfSound *dash;
    sfSound *chepo;
    sfSoundBuffer *dashb;
    sfSoundBuffer *chepob;
}           audio_t;


typedef struct towermove{
    bool green;
    bool red;
    bool blue;
    bool yellow;
}   bool_t;

typedef struct game_s {
    int place;
    int state;
    int disp_how;
    int money;
    int score;
    sfSprite *cloud;
    bool_t *towers;
    audio_t *audio;
    sfText *scoretxt;
    sfRenderWindow *window;
}              game_t;

enum menu_place{
    menu,
    inopt,
    play_but,
    playin,
    pause_men,
    back_g,
    how_disp,
};

enum where{
    menuw,
    playw,
    pausew,
    settw,
    exitw,
};

enum menu_part{
    back,
    optback,
    dbz,
    play,
    settings,
    quit,
    cred,
    credits,
    how_to_play,
    how_icone,
};

enum sett_part{
    vol,
    vol_moy,
    vol_max,
    icone,
    screen,
    def,
    back_sett,
};

enum game_part {
    backg,
    settpau,
    dark,
    bmenu,
    bgame,
    krillin,
    krillin2,
    krillin3,
    krillin4,
    krillin5,
    toolbar,
    tower_g,
    tower_r,
    tower_b,
    tower_y,
};

typedef struct clock_s {
    sfClock *clock;
    sfTime time;
    float seconds;
}              move_t;

typedef struct title_s {
    sfTexture *menu_tt;
    sfSprite *menu_s;
    sfIntRect rect;
    sfVector2f menu_f;
    sfBool tuto;
    sfBool credits;
}              menu_t;

typedef struct sett_s {
    sfTexture *vol_tex;
    sfSprite *vol_spr;
    sfIntRect vol_rect;
    sfVector2f sett_f;
    sfIntRect volume;
    sfIntRect back_m;
    sfIntRect size;
}              sett_t;

typedef struct play_s {
    sfTexture *tex;
    sfSprite *spr;
    sfIntRect pause;
    sfIntRect mvt;
    move_t *clock;
}              play_t;

//manage event
int manage_event(game_t *game, menu_t **title, sett_t **sett, play_t **pl);
void button_exit(game_t *game, menu_t **title);
void get_key_pressed(game_t *game);
void button_play(game_t *game, menu_t **title, play_t **pl, sett_t **sett);
void button_pause(game_t *game, play_t **play, menu_t **title_s);
void back_to_menu(game_t *game, play_t **pl);
void button_settings(game_t *game, menu_t **title, sett_t **sett);
void button_credits(game_t *game, menu_t **title);
void how_to_play_event(game_t *game, menu_t **title);
void get_back_to_game(game_t *game, play_t **pl);
void pause_settings(game_t *game, menu_t **title, sett_t **sett, play_t **pl);

//create struct
menu_t **create_title(void);
void fill_menu(menu_t **title);
void place_menu(menu_t **title, sfVector2f place, int which, char *sprite);
game_t *create_game(void);
void close_all(game_t *game, menu_t **title, sett_t **sett, play_t **pl);
void create_audio(game_t *game);
void create_bool(game_t *game);

//create settings
sett_t **create_settings(void);
void fill_settings(sett_t **sett);
void set_positions(sett_t **sett, sfVector2f pos, int set, char *file);
void set_icone_position(sett_t **sett, sfVector2f pos, int set, char *file);
void set_back_menu(sett_t **sett, sfVector2f pos, int set, char *file);
void set_icone_position(sett_t **sett, sfVector2f pos, int set, char *file);
void set_positions(sett_t **sett, sfVector2f pos, int set, char *file);
void set_positions_size(sett_t **sett, sfVector2f pos, int set, char *file);
void setrect(menu_t **title);

//manage settings & menu
void button_back_menu(game_t *game, sett_t **sett);
void set_new_volume(sett_t **sett, game_t *game);

//audio manager
void audio_manager(game_t *game);
void create_audio(game_t *game);
void change_volume(game_t *game, float new_vol);

//create game
play_t **create_play(void);
void fill_play(play_t **pl);

//display all
void display_sett(game_t *game, menu_t **title, sett_t **sett);
void display_menu(game_t *game, menu_t **title, sett_t **sett, play_t **pl);
void display_game(game_t *game, play_t **pl, menu_t **title, sett_t **sett);
void display_pause_game(game_t *game, menu_t **title, play_t **pl, sett_t **sett);
void display_creds(game_t *game, menu_t **title);
void display_how_to(game_t *game, menu_t **title);
void mouse_spritex(game_t *game);
void display_game_obj(game_t *game, play_t **pl);

//event scene
void sett_event(game_t *game, sett_t **sett);
void menu_event(game_t *game, sett_t **sett, menu_t **title, play_t **pl);
void pause_event(game_t *game, menu_t **title, play_t **pl, sett_t **sett);

//clocks move
void clock_sprite(play_t **pl, game_t *game);
void move_rect(play_t **pl, int set, int max);
void create_krillin4_clock(play_t **pl, game_t *game);
void create_krillin5_clock(play_t **pl, game_t *game);

//about score
void score_print(game_t *game);

//gameplay
void money_gain(game_t *game, play_t **pl);
void gameplay_event(game_t *game, play_t **pl, menu_t **title, sett_t **sett);
void towers_event(game_t *game, play_t **pl, sfEvent event);
void sprite_mouse_towers(game_t *game, play_t **pl, int which, sfVector2f mouse);
void mouse_tower(game_t *game, play_t **pl);
void reset_tower(game_t *game, play_t **pl);
void replace_towers(game_t *game, play_t **pl);
//different path
void first_path(play_t **pl, sfVector2f spr_pos, sfVector2f pos);
void second_path(play_t **pl, sfVector2f spr_pos, sfVector2f pos);
void third_path(play_t **pl, sfVector2f spr_pos, sfVector2f pos);
void fourth_path(play_t **pl, sfVector2f spr_pos, sfVector2f pos);
void path_krillin_4(sfVector2f spr, sfVector2f p, play_t **pl);
void path_krillin_5(sfVector2f spr, sfVector2f p, play_t **pl, sfVector2f vec);
void fifth_path(play_t **pl, sfVector2f spr_pos, sfVector2f pos);

//set objects map
void set_back(play_t **pl, int set, char *file);
void set_icones(play_t **pl, sfVector2f pos, int set, char *file);
void set_toolbar(play_t **pl);
void place_tow(play_t **pl, sfVector2f pos, int set, char *file);
void place_krillin(play_t **pl, sfVector2f pos, int set, char *file);

#endif /* !DEFENDER_H */