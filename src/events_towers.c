/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** events_towers
*/

#include "defender.h"

void redtower_event(game_t *game, play_t **pl)
{
    sfVector2f pos_spr = sfSprite_getPosition(pl[tower_r]->spr);
    sfVector2i pos = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f mouse_f;

    mouse_f.x = pos.x;
    mouse_f.y = pos.y;
    if (pos_spr.x < mouse_f.x && pos_spr.x + 80 > mouse_f.x) {
        if (pos_spr.y < mouse_f.y && pos_spr.y + 80 > mouse_f.y) {
            game->towers->red = 1;
        }
    }
}

void bluetower_event(game_t *game, play_t **pl)
{
    sfVector2f pos_spr = sfSprite_getPosition(pl[tower_b]->spr);
    sfVector2i pos = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f mouse_f;

    mouse_f.x = pos.x;
    mouse_f.y = pos.y;
    if (pos_spr.x < mouse_f.x && pos_spr.x + 80 > mouse_f.x) {
        if (pos_spr.y < mouse_f.y && pos_spr.y + 80 > mouse_f.y) {
            game->towers->blue = 1;
        }
    }
}

void yellowtower_event(game_t *game, play_t **pl)
{
    sfVector2f pos_spr = sfSprite_getPosition(pl[tower_y]->spr);
    sfVector2i pos = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f mouse_f;

    mouse_f.x = pos.x;
    mouse_f.y = pos.y;
    if (pos_spr.x < mouse_f.x && pos_spr.x + 80 > mouse_f.x) {
        if (pos_spr.y < mouse_f.y && pos_spr.y + 80 > mouse_f.y) {
            game->towers->yellow = 1;
        }
    }
}

void greentower_event(game_t *game, play_t **pl)
{
    sfVector2f pos_spr = sfSprite_getPosition(pl[tower_g]->spr);
    sfVector2i pos = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f mouse_f;

    mouse_f.x = pos.x;
    mouse_f.y = pos.y;
    if (pos_spr.x < mouse_f.x && pos_spr.x + 80 > mouse_f.x) {
        if (pos_spr.y < mouse_f.y && pos_spr.y + 80 > mouse_f.y) {
            game->towers->green = 1;
        }
    }
}

void towers_event(game_t *game, play_t **pl, sfEvent event)
{
    if (event.type != sfEvtMouseButtonPressed
        || sfMouse_isButtonPressed(sfMouseLeft) != sfTrue)
        return;
    redtower_event(game, pl);
    greentower_event(game, pl);
    bluetower_event(game, pl);
    yellowtower_event(game, pl);
}