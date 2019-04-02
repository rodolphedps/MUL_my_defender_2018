/*
** EPITECH PROJECT, 2019
** clocks
** File description:
** yes
*/

#include "defender.h"

void move_sprite_x_y(play_t **pl, game_t *game)
{
    static int go = 0;
    sfVector2f spr_pos = sfSprite_getPosition(pl[krillin]->spr);
    sfVector2f spr_pos2 = sfSprite_getPosition(pl[krillin2]->spr);
    sfVector2f spr_pos3 = sfSprite_getPosition(pl[krillin3]->spr);
    sfVector2f spr_pos4 = sfSprite_getPosition(pl[krillin4]->spr);
    sfVector2f spr_pos5 = sfSprite_getPosition(pl[krillin5]->spr);
    sfVector2f pos = {50, 155};
    sfVector2f pos_final = {1760, 920};

    first_path(pl, spr_pos, pos);
    second_path(pl, spr_pos2, pos);
    third_path(pl, spr_pos3, pos);
    fourth_path(pl, spr_pos4, pos);
    fifth_path(pl, spr_pos5, pos);
}

void move_rect(play_t **pl, int set, int max)
{
    pl[set]->pause.left += 33;
    if (pl[set]->pause.left >= max)
        pl[set]->pause.left = 0;
    sfSprite_setTextureRect(pl[set]->spr, pl[set]->pause);
}

void create_krillin2_clock(play_t **pl, game_t *game)
{
    int set = 0;
    int max = 99;

    pl[krillin2]->clock->time =
        sfClock_getElapsedTime(pl[krillin2]->clock->clock);
    pl[krillin2]->clock->seconds =
        pl[krillin2]->clock->time.microseconds / 1000000.0;
    if (pl[krillin2]->clock->seconds > 0.15) {
        move_rect(pl, krillin2, max);
        sfClock_restart(pl[krillin2]->clock->clock);
    }
}

void create_krillin3_clock(play_t **pl, game_t *game)
{
    int set = 0;
    int max = 99;

    pl[krillin3]->clock->time =
        sfClock_getElapsedTime(pl[krillin3]->clock->clock);
    pl[krillin3]->clock->seconds =
        pl[krillin3]->clock->time.microseconds / 1000000.0;
    if (pl[krillin3]->clock->seconds > 0.15) {
        move_rect(pl, krillin3, max);
        sfClock_restart(pl[krillin3]->clock->clock);
    }
}

void clock_sprite(play_t **pl, game_t *game)
{
    int set = 0;
    int max = 99;

    pl[krillin]->clock->time =
        sfClock_getElapsedTime(pl[krillin]->clock->clock);
    pl[krillin]->clock->seconds =
        pl[krillin]->clock->time.microseconds / 1000000.0;
    if (pl[krillin]->clock->seconds > 0.15) {
        move_rect(pl, krillin, max);
        sfClock_restart(pl[krillin]->clock->clock);
    }
    create_krillin2_clock(pl, game);
    create_krillin3_clock(pl, game);
    create_krillin4_clock(pl, game);
    create_krillin5_clock(pl, game);
    move_sprite_x_y(pl, game);
}