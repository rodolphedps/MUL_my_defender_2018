/*
** EPITECH PROJECT, 2019
** settings
** File description:
** yes
*/

#include "defender.h"

void button_back_menu(game_t *game, sett_t **sett)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f mouse_final;
    sfVector2f pos = sfSprite_getPosition(sett[back_sett]->vol_spr);

    mouse_final.x = mouse.x;
    mouse_final.y = mouse.y;
    if (pos.x < mouse_final.x && pos.x + 100 > mouse_final.x) {
        if (pos.y < mouse_final.y && pos.y + 100 > mouse_final.y)
            game->place = menuw;
    }
}

void set_new_volume(sett_t **sett, game_t *game)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f mouse_final;
    sfVector2f pos = sfSprite_getPosition(sett[vol]->vol_spr);
    sfVector2f pos2 = sfSprite_getPosition(sett[vol_moy]->vol_spr);
    sfVector2f pos3 = sfSprite_getPosition(sett[vol_max]->vol_spr);

    mouse_final.x = mouse.x;
    mouse_final.y = mouse.y;
    if (pos.x < mouse_final.x && pos.x + 100 > mouse_final.x) {
        if (pos.y < mouse_final.y && pos.y + 100 > mouse_final.y)
            change_volume(game, 0);
    }
    if (pos2.x < mouse_final.x && pos2.x + 100 > mouse_final.x) {
        if (pos2.y < mouse_final.y && pos2.y + 100 > mouse_final.y)
            change_volume(game, 30);
    }
    if (pos3.x < mouse_final.x && pos3.x + 100 > mouse_final.x) {
        if (pos3.y < mouse_final.y && pos3.y + 100 > mouse_final.y)
            change_volume(game, 50);
    }
}

void button_sett_pause(game_t *game, sett_t **sett, menu_t **title)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f mouse_final;
    sfVector2f pos = sfSprite_getPosition(sett[back_sett]->vol_spr);

    mouse_final.x = mouse.x;
    mouse_final.y = mouse.y;
    if (pos.x < mouse_final.x && pos.x + 100 > mouse_final.x) {
        if (pos.y < mouse_final.y && pos.y + 100 > mouse_final.y)
            display_sett(game, title, sett);
    }
}
