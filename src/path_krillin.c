/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** path_krillin
*/

#include "defender.h"

void path_krillin_5(sfVector2f spr, sfVector2f p, play_t **pl, sfVector2f vec)
{
    if (spr.x >= 1210 && spr.y >= 920) {
        pl[krillin5]->pause.top = 0;
        sfSprite_move(pl[krillin5]->spr, vec);
    }
    if (spr.x >= 1620 && spr.y >= 920) {
        pl[krillin5]->pause.top = 0;
        sfSprite_setPosition(pl[krillin5]->spr, p);
    }
}

void path_krillin_4(sfVector2f spr, sfVector2f p, play_t **pl)
{
    if (spr.x >= 1760 && spr.y >= 830) {
        pl[krillin4]->pause.top = 0;
        sfSprite_setPosition(pl[krillin4]->spr, p);
    }
}

void place_krillin(play_t **pl, sfVector2f pos, int set, char *file)
{
    pl[set]->tex = sfTexture_createFromFile(file, NULL);
    pl[set]->spr = sfSprite_create();
    sfSprite_setTexture(pl[set]->spr, pl[set]->tex, sfTrue);
    sfSprite_setTextureRect(pl[set]->spr, pl[set]->pause);
    sfSprite_setPosition(pl[set]->spr, pos);
}

void create_krillin4_clock(play_t **pl, game_t *game)
{
    int set = 0;
    int max = 99;

    pl[krillin4]->clock->time =
        sfClock_getElapsedTime(pl[krillin4]->clock->clock);
    pl[krillin4]->clock->seconds =
        pl[krillin4]->clock->time.microseconds / 1000000.0;
    if (pl[krillin4]->clock->seconds > 0.15) {
        move_rect(pl, krillin4, max);
        sfClock_restart(pl[krillin4]->clock->clock);
    }
}

void create_krillin5_clock(play_t **pl, game_t *game)
{
    int set = 0;
    int max = 99;

    pl[krillin5]->clock->time =
        sfClock_getElapsedTime(pl[krillin5]->clock->clock);
    pl[krillin5]->clock->seconds =
        pl[krillin5]->clock->time.microseconds / 1000000.0;
    if (pl[krillin5]->clock->seconds > 0.15) {
        move_rect(pl, krillin5, max);
        sfClock_restart(pl[krillin5]->clock->clock);
    }
}