/*
** EPITECH PROJECT, 2019
** defender
** File description:
** defender
*/

#include "defender.h"

void init_button(button_t *button, sfVector2f position, sfVector2f size)
{
    sfRectangleShape_create();
    sfRectangleShape_setPosition(button->rect, position);
    sfRectangleShape_setSize(button->rect, size);
    sfRectangleShape_setFillColor(button->rect, sfRed);
}

void mouse_spritex(game_t *game)
{
    static int i = 0;
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f pos_final;

    if (i == 0) {
        sfTexture *mouse_tex = sfTexture_createFromFile("assets/cloud.png",
            NULL);
        game->cloud = sfSprite_create();
        sfSprite_setTexture(game->cloud, mouse_tex, sfTrue);
    }
    pos_final.x = pos_mouse.x - 50;
    pos_final.y = pos_mouse.y - 49;
    sfRenderWindow_setMouseCursorVisible(game->window, 0);
    sfSprite_setPosition(game->cloud, pos_final);
    sfRenderWindow_drawSprite(game->window, game->cloud, NULL);
}

int launch_program(void)
{
    game_t *game = create_game();
    menu_t **title = create_title();
    sett_t **sett = create_settings();
    play_t **pl = create_play();

    display_menu(game, title, sett, pl);
    close_all(game, title, sett, pl);
}

int main(void)
{
    launch_program();
}