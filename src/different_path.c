/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** diffrent_path
*/

#include "defender.h"

void fifth_path(play_t **pl, sfVector2f spr_pos, sfVector2f pos)
{
    sfVector2f vec_go_x = {6.5, 0};
    sfVector2f vec_go_y = {0, 6.5};

    if (spr_pos.x <= 600)
        sfSprite_move(pl[krillin5]->spr, vec_go_x);
    if (spr_pos.x >= 600 && spr_pos.y <= 520) {
        pl[krillin5]->pause.top = 46;
        sfSprite_move(pl[krillin5]->spr, vec_go_y);
    }
    if (spr_pos.y >= 520 && spr_pos.x <= 1210) {
        pl[krillin5]->pause.top = 0;
        sfSprite_move(pl[krillin5]->spr, vec_go_x);
    }
    if (spr_pos.x >= 1210 && spr_pos.y <= 920) {
        pl[krillin5]->pause.top = 46;
        sfSprite_move(pl[krillin5]->spr, vec_go_y);
    }
    path_krillin_5(spr_pos, pos, pl, vec_go_x);
}

void fourth_path(play_t **pl, sfVector2f spr_pos, sfVector2f pos)
{
    sfVector2f vec_go_x = {4.5, 0};
    sfVector2f vec_go_y = {0, 4.5};

    if (spr_pos.x <= 600)
        sfSprite_move(pl[krillin4]->spr, vec_go_x);
    if (spr_pos.x >= 600 && spr_pos.y <= 520) {
        pl[krillin4]->pause.top = 46;
        sfSprite_move(pl[krillin4]->spr, vec_go_y);
    }
    if (spr_pos.y >= 520 && spr_pos.x <= 1760) {
        pl[krillin4]->pause.top = 0;
        sfSprite_move(pl[krillin4]->spr, vec_go_x);
    }
    if (spr_pos.x >= 1760) {
        pl[krillin4]->pause.top = 46;
        sfSprite_move(pl[krillin4]->spr, vec_go_y);
    }
    path_krillin_4(spr_pos, pos, pl);
}

void third_path(play_t **pl, sfVector2f spr_pos, sfVector2f pos)
{
    sfVector2f vec_go_x = {4, 0};
    sfVector2f vec_go_y = {0, 4};

    if (spr_pos.x <= 600)
        sfSprite_move(pl[krillin3]->spr, vec_go_x);
    if (spr_pos.x >= 600 && spr_pos.y <= 920) {
        pl[krillin3]->pause.top = 46;
        sfSprite_move(pl[krillin3]->spr, vec_go_y);
    }
    if (spr_pos.y >= 920) {
        pl[krillin3]->pause.top = 0;
        sfSprite_move(pl[krillin3]->spr, vec_go_x);
    }
    if (spr_pos.x >= 1620 && spr_pos.y >= 920)
        sfSprite_setPosition(pl[krillin3]->spr, pos);
}

void second_path(play_t **pl, sfVector2f spr_pos, sfVector2f pos)
{
    static int go = 0;
    sfVector2f vec_go_x = {3.5, 0};
    sfVector2f vec_go_y = {0, 3.5};

    if (go == 0) {
        pl[krillin2]->pause.top = 46;
        sfSprite_move(pl[krillin2]->spr, vec_go_y);
    }
    if (spr_pos.y >= 920)
        go = 1;
    if (go == 1) {
        pl[krillin2]->pause.top = 0;
        sfSprite_move(pl[krillin2]->spr, vec_go_x);
    }
    if (spr_pos.x >= 1620) {
        sfSprite_setPosition(pl[krillin2]->spr, pos);
        go = 0;
    }
}

void first_path(play_t **pl, sfVector2f spr_pos, sfVector2f pos)
{
    static int go = 0;
    sfVector2f vec_go_x = {4.5, 0};
    sfVector2f vec_go_y = {0, 4.5};

    if (go == 0)
        sfSprite_move(pl[krillin]->spr, vec_go_x);
    if (spr_pos.x >= 1760)
        go = 1;
    if (go == 1) {
        pl[krillin]->pause.top = 46;
        sfSprite_setTextureRect(pl[krillin]->spr, pl[krillin]->pause);
        sfSprite_move(pl[krillin]->spr, vec_go_y);
    }
    if (spr_pos.y >= 830) {
        sfSprite_setPosition(pl[krillin]->spr, pos);
        go = 0;
        pl[krillin]->pause.top = 0;
    }
}