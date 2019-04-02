/*
** EPITECH PROJECT, 2019
** play
** File description:
** yes
*/

#include "defender.h"

void fill_play(play_t **pl)
{
    sfVector2f bot = {770, 100};
    sfVector2f top = {770, 700};
    sfVector2f mid = {770, 400};

    set_back(pl, backg, "assets/map.png");
    set_back(pl, dark, "assets/pause_menu.png");
    set_icones(pl, bot, bgame, "assets/back_to_game.png");
    set_icones(pl, mid, settpau, "assets/sett_pause.png");
    set_icones(pl, top, bmenu, "assets/polm.png");
}

void set_krillin(play_t **pl)
{
    sfVector2f pos = {50, 155};

    place_krillin(pl, pos, krillin, "assets/krillin.png");
    place_krillin(pl, pos, krillin2, "assets/krillin.png");
    place_krillin(pl, pos, krillin3, "assets/krillin.png");
    place_krillin(pl, pos, krillin4, "assets/krillin.png");
    place_krillin(pl, pos, krillin5, "assets/krillin.png");
    for (int i = 0; pl[i] != NULL; i++) {
        pl[i]->clock = malloc(sizeof(move_t));
        pl[i]->clock->clock = sfClock_create();
        pl[i]->clock->seconds = 0;
    }
}

void place_tow(play_t **pl, sfVector2f pos, int set, char *file)
{
    sfIntRect towers = {0, 0, 80, 80};

    pl[set]->tex = sfTexture_createFromFile(file, NULL);
    pl[set]->spr = sfSprite_create();
    sfSprite_setTexture(pl[set]->spr, pl[set]->tex, sfTrue);
    sfSprite_setTextureRect(pl[set]->spr, towers);
    sfSprite_setPosition(pl[set]->spr, pos);
}

void set_towers_toolbar(play_t **pl)
{
    sfVector2f pos = {1836, 205};

    place_tow(pl, pos, tower_g, "assets/tower_green.png");
    pos.y += 90;
    place_tow(pl, pos, tower_r, "assets/tower_red.png");
    pos.y += 90;
    place_tow(pl, pos, tower_b, "assets/tower_blue.png");
    pos.y += 87;
    place_tow(pl, pos, tower_y, "assets/tower_yell.png");
}

play_t **create_play(void)
{
    play_t **pl = malloc(sizeof(play_t) *17);
    int i = 0;
    sfIntRect pause_b = {0, 0, 100, 100};
    sfIntRect size_ico = {0, 0, 380, 210};
    sfIntRect charac = {0, 0, 33, 47};

    pl[16] = NULL;
    while (i < 16) {
        pl[i] = malloc(sizeof(play_t));
        i++;
    }
    for (int i = krillin; i != krillin5 + 1; i++)
        pl[i]->pause = charac;
    fill_play(pl);
    set_krillin(pl);
    set_toolbar(pl);
    set_towers_toolbar(pl);
    return (pl);
}