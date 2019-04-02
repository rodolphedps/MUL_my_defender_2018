/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** gameplay
*/

#include "defender.h"

void replace_towers(game_t *game, play_t **pl)
{
    sfVector2f spr = sfSprite_getPosition(pl[tower_g]->spr);
    sfVector2f pos = {1836, 205};

    if (game->towers->green == 0 && spr.x != pos.x && spr.y != pos.y)
        sfSprite_setPosition(pl[tower_g]->spr, pos);
    spr = sfSprite_getPosition(pl[tower_r]->spr);
    pos.y += 90;
    if (game->towers->red == 0 && spr.x != pos.x && spr.y != pos.y)
        sfSprite_setPosition(pl[tower_r]->spr, pos);
    spr = sfSprite_getPosition(pl[tower_b]->spr);
    pos.y += 90;
    if (game->towers->blue == 0 && spr.x != pos.x && spr.y != pos.y)
        sfSprite_setPosition(pl[tower_b]->spr, pos);
    spr = sfSprite_getPosition(pl[tower_y]->spr);
    pos.y += 87;
    if (game->towers->yellow == 0 && spr.x != pos.x && spr.y != pos.y)
        sfSprite_setPosition(pl[tower_y]->spr, pos);
}

void create_bool(game_t *game)
{
    game->towers = malloc(sizeof(bool_t));
    game->towers->yellow = 0;
    game->towers->blue = 0;
    game->towers->green = 0;
    game->towers->red = 0;
}

void reset_tower(game_t *game, play_t **pl)
{
    game->towers->green = 0;
    game->towers->red = 0;
    game->towers->blue = 0;
    game->towers->yellow = 0;
}

void mouse_tower(game_t *game, play_t **pl)
{
    sfVector2i mousei = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f mousef;

    mousef.x = mousei.x - 40;
    mousef.y = mousei.y - 40;
    if (game->towers->green == 1)
        sfSprite_setPosition(pl[tower_g]->spr, mousef);
    if (game->towers->red == 1)
        sfSprite_setPosition(pl[tower_r]->spr, mousef);
    if (game->towers->blue == 1)
        sfSprite_setPosition(pl[tower_b]->spr, mousef);
    if (game->towers->yellow == 1)
        sfSprite_setPosition(pl[tower_y]->spr, mousef);
}
