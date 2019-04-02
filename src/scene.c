/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** scene
*/

#include "defender.h"

void general_event(game_t *game, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(game->window);
    if (event.type == sfEvtKeyPressed
    && sfKeyboard_isKeyPressed(sfKeyQ) == sfTrue)
        sfRenderWindow_close(game->window);
}

void sett_event(game_t *game, sett_t **sett)
{
    sfEvent event;

    if (event.type == sfEvtMouseButtonPressed
    && sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        button_back_menu(game, sett);
        set_new_volume(sett, game);
    }
    general_event(game, event);
}

void menu_event(game_t *game, sett_t **sett, menu_t **title, play_t **pl)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (event.type == sfEvtMouseButtonPressed
        && sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            button_exit(game, title);
            button_play(game, title, pl, sett);
            button_settings(game, title, sett);
            button_credits(game, title);
            how_to_play_event(game, title);
        }
        general_event(game, event);
    }
}

void pause_event(game_t *game, menu_t **title, play_t **pl, sett_t **sett)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (event.type == sfEvtMouseButtonPressed
        && sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            get_back_to_game(game, pl);
            pause_settings(game, title, sett, pl);
            back_to_menu(game, pl);
        }
        if (event.type == sfEvtKeyPressed
            && sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
            game->place = playw;
        general_event(game, event);
    }
}

void gameplay_event(game_t *game, play_t **pl, menu_t **title, sett_t **sett)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (event.type == sfEvtKeyPressed
            && sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue) {
            game->place = pausew;
            display_pause_game(game, title, pl, sett);
            }
        if (event.type == sfEvtMouseButtonPressed
            && sfMouse_isButtonPressed(sfMouseRight) == sfTrue)
            replace_towers(game, pl);
        towers_event(game, pl, event);
        if (event.type == sfEvtMouseButtonReleased)
            reset_tower(game, pl);
        general_event(game, event);
    }
}