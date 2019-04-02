/*
** EPITECH PROJECT, 2019
** event setts menu
** File description:
** yes
*/

#include "defender.h"

void how_to_play_event(game_t *game, menu_t **title)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f mouse_f;
    sfVector2f pos = sfSprite_getPosition(title[how_icone]->menu_s);
    int save = title[0]->tuto;

    mouse_f.x = mouse.x;
    mouse_f.y = mouse.y;
    if (pos.x < mouse_f.x && pos.x + 100 > mouse_f.x) {
        if (pos.y < mouse_f.y && pos.y + 100 > mouse_f.y && save == 1)
            title[0]->tuto = 0;
        else if (pos.y < mouse_f.y && pos.y + 100 > mouse_f.y && save == 0)
            title[0]->tuto = 1;
    }
}

void get_back_to_game(game_t *game, play_t **pl)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f mouse_f;
    sfVector2f pos = sfSprite_getPosition(pl[bgame]->spr);

    mouse_f.x = mouse.x;
    mouse_f.y = mouse.y;
    if (pos.x < mouse_f.x && pos.x + 380 > mouse_f.x) {
        if (pos.y < mouse_f.y && pos.y + 210 > mouse_f.y) {
            game->place = playw;
        }
    }
}

void pause_settings(game_t *game, menu_t **title, sett_t **sett, play_t **pl)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f mouse_f;
    sfVector2f pos = sfSprite_getPosition(pl[settpau]->spr);

    mouse_f.x = mouse.x;
    mouse_f.y = mouse.y;
    if (pos.x < mouse_f.x && pos.x + 380 > mouse_f.x)
        if (pos.y < mouse_f.y && pos.y + 210 > mouse_f.y) {
            game->place = settw;
            display_sett(game, title, sett);
            game->place = pausew;
        }
}