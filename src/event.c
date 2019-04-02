/*
** EPITECH PROJECT, 2019
** event manager
** File description:
** yes
*/

#include "defender.h"

void get_key_pressed(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue) {
        game->place = 2;
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ) == sfTrue)
        sfRenderWindow_close(game->window);
}

void button_exit(game_t *game, menu_t **title)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f mouse_f;
    sfVector2f pos = sfSprite_getPosition(title[quit]->menu_s);

    mouse_f.x = mouse.x;
    mouse_f.y = mouse.y;
    if (pos.x < mouse_f.x && pos.x + 380 > mouse_f.x)
        if (pos.y < mouse_f.y && pos.y + 210 > mouse_f.y) {
            my_printf("Thanks for playing !\n");
            game->place = exitw;
        }
}

void button_settings(game_t *game, menu_t **title, sett_t **sett)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f mouse_f;
    sfVector2f pos = sfSprite_getPosition(title[settings]->menu_s);

    mouse_f.x = mouse.x;
    mouse_f.y = mouse.y;
    if (pos.x < mouse_f.x && pos.x + 380 > mouse_f.x)
        if (pos.y < mouse_f.y && pos.y + 210 > mouse_f.y) {
            display_sett(game, title, sett);
        }
}

void close_all(game_t *game, menu_t **title, sett_t **sett, play_t **pl)
{
    sfMusic_destroy(game->audio->chala);
    sfMusic_destroy(game->audio->ingame);
    sfSound_destroy(game->audio->dash);
    sfSound_destroy(game->audio->chepo);
    sfSoundBuffer_destroy(game->audio->chepob);
    sfSoundBuffer_destroy(game->audio->dashb);
    sfRenderWindow_destroy(game->window);
    free (game);
    free (sett);
    free (pl);
    free (title);
}