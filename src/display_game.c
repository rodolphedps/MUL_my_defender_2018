/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** display_game
*/

#include "defender.h"

void display_game_obj(game_t *game, play_t **pl)
{
    sfRenderWindow_drawSprite(game->window, pl[backg]->spr, NULL);
    sfRenderWindow_drawSprite(game->window, pl[krillin]->spr, NULL);
    sfRenderWindow_drawSprite(game->window, pl[krillin2]->spr, NULL);
    sfRenderWindow_drawSprite(game->window, pl[krillin3]->spr, NULL);
    sfRenderWindow_drawSprite(game->window, pl[krillin4]->spr, NULL);
    sfRenderWindow_drawSprite(game->window, pl[krillin5]->spr, NULL);
    sfRenderWindow_drawSprite(game->window, pl[toolbar]->spr, NULL);
    sfRenderWindow_drawSprite(game->window, pl[tower_g]->spr, NULL);
    sfRenderWindow_drawSprite(game->window, pl[tower_r]->spr, NULL);
    sfRenderWindow_drawSprite(game->window, pl[tower_b]->spr, NULL);
    sfRenderWindow_drawSprite(game->window, pl[tower_y]->spr, NULL);
}