/*
** EPITECH PROJECT, 2019
** event
** File description:
** yes
*/

#include "defender.h"

void button_credits(game_t *game, menu_t **title)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f mouse_f;
    sfVector2f pos = sfSprite_getPosition(title[cred]->menu_s);
    int save = title[0]->credits;

    mouse_f.x = mouse.x;
    mouse_f.y = mouse.y;
    if (pos.x < mouse_f.x && pos.x + 100 > mouse_f.x) {
        if (pos.y < mouse_f.y && pos.y + 100 > mouse_f.y && save == 0)
            title[0]->credits = 1;
        else if (pos.y < mouse_f.y && pos.y + 100 > mouse_f.y && save == 1)
            title[0]->credits = 0;
    }
}

void button_play(game_t *game, menu_t **title, play_t **pl, sett_t **sett)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f mouse_f;
    sfVector2f pos = sfSprite_getPosition(title[play]->menu_s);

    mouse_f.x = mouse.x;
    mouse_f.y = mouse.y;
    if (pos.x < mouse_f.x && pos.x + 380 > mouse_f.x) {
        if (pos.y < mouse_f.y && pos.y + 210 > mouse_f.y) {
            game->place = playw;
            audio_manager(game);
            display_game(game, pl, title, sett);
        }
    }
}

void back_to_menu(game_t *game, play_t **pl)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f mouse_f;
    sfVector2f pos = sfSprite_getPosition(pl[bmenu]->spr);

    mouse_f.x = mouse.x;
    mouse_f.y = mouse.y;
    if (pos.x < mouse_f.x && pos.x + 380 > mouse_f.x) {
        if (pos.y < mouse_f.y && pos.y + 210 > mouse_f.y) {
            game->place = menuw;
            audio_manager(game);
        }
    }
}

void back_to_game(game_t *game, play_t **pl)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f mouse_f;
    sfVector2f pos = sfSprite_getPosition(pl[back_g]->spr);

    if (pos.x < mouse_f.x && pos.x + 100 > mouse_f.x) {
        if (pos.y < mouse_f.y && pos.y + 100 > mouse_f.x) {
                game->place = play;
        }
    }
}