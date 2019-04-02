/*
** EPITECH PROJECT, 2019
** display
** File description:
** yes
*/

#include "defender.h"

void display_sett(game_t *game, menu_t **title, sett_t **sett)
{
    sfEvent event;

    while (sfRenderWindow_isOpen(game->window)) {
        game->place = settw;
        sfRenderWindow_clear(game->window, sfBlack);
        while (sfRenderWindow_pollEvent(game->window, &event))
            sett_event(game, sett);
        sfRenderWindow_drawSprite(game->window, title[optback]->menu_s, NULL);
        sfRenderWindow_drawSprite(game->window, sett[vol]->vol_spr, NULL);
        sfRenderWindow_drawSprite(game->window, sett[vol_moy]->vol_spr, NULL);
        sfRenderWindow_drawSprite(game->window, sett[vol_max]->vol_spr, NULL);
        sfRenderWindow_drawSprite(game->window, sett[icone]->vol_spr, NULL);
        sfRenderWindow_drawSprite(game->window, sett[back_sett]->vol_spr, NULL);
        if (game->place != settw)
            return;
        mouse_spritex(game);
        sfRenderWindow_display(game->window);
    }
}

void popups(game_t *game, menu_t **title)
{
    if (title[0]->tuto == 1)
        sfRenderWindow_drawSprite(game->window, title[how_to_play]->menu_s,
            NULL);
    sfRenderWindow_drawSprite(game->window, title[how_icone]->menu_s, NULL);
    if (title[0]->credits == 1)
        sfRenderWindow_drawSprite(game->window, title[credits]->menu_s, NULL);
}

void display_menu(game_t *game, menu_t **title, sett_t **sett, play_t **pl)
{
    sfEvent event;

    while (sfRenderWindow_isOpen(game->window)) {
        game->place = menuw;
        menu_event(game, sett, title, pl);
        sfRenderWindow_clear(game->window, sfBlack);
        sfRenderWindow_drawSprite(game->window, title[back]->menu_s, NULL);
        sfRenderWindow_drawSprite(game->window, title[dbz]->menu_s, NULL);
        sfRenderWindow_drawSprite(game->window, title[play]->menu_s, NULL);
        sfRenderWindow_drawSprite(game->window, title[settings]->menu_s, NULL);
        sfRenderWindow_drawSprite(game->window, title[quit]->menu_s, NULL);
        sfRenderWindow_drawSprite(game->window, title[cred]->menu_s, NULL);
        popups(game, title);
        mouse_spritex(game);
        if (game->place == exitw) {
            return;
        }
        sfRenderWindow_display(game->window);
    }
}

void display_game(game_t *game, play_t **pl, menu_t **title, sett_t **sett)
{
    sfEvent event;

    while (sfRenderWindow_isOpen(game->window)) {
        sfRenderWindow_clear(game->window, sfBlack);
        gameplay_event(game, pl, title, sett);
        money_gain(game, pl);
        mouse_tower(game, pl);
        display_game_obj(game, pl);
        score_print(game);
        mouse_spritex(game);
        clock_sprite(pl, game);
        if (game->place == menuw)
            return;
        sfRenderWindow_display(game->window);
    }
}

void display_pause_game(game_t *game, menu_t **title, play_t **pl,
                        sett_t **sett)
{
    sfEvent event;

    while (sfRenderWindow_isOpen(game->window)) {
        sfRenderWindow_clear(game->window, sfBlack);
        pause_event(game, title, pl, sett);
        display_game_obj(game, pl);
        sfRenderWindow_drawSprite(game->window, pl[dark]->spr, NULL);
        sfRenderWindow_drawSprite(game->window, pl[bmenu]->spr, NULL);
        sfRenderWindow_drawSprite(game->window, pl[settpau]->spr, NULL);
        sfRenderWindow_drawSprite(game->window, pl[bgame]->spr, NULL);
        mouse_spritex(game);
        score_print(game);
        if (game->place == playw || game->place == menuw)
            return;
        sfRenderWindow_display(game->window);
    }
}
