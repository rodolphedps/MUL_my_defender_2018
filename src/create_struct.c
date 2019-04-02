/*
** EPITECH PROJECT, 2019
** create struct
** File description:
** yes
*/

#include "defender.h"

void place_menu(menu_t **title, sfVector2f place, int which, char *sprite)
{
    title[which]->menu_tt = sfTexture_createFromFile(sprite, NULL);
    title[which]->menu_s = sfSprite_create();
    sfSprite_setTexture(title[which]->menu_s, title[which]->menu_tt, sfTrue);
    sfSprite_setTextureRect(title[which]->menu_s, title[which]->rect);
    title[which]->menu_f = place;
    sfSprite_setPosition(title[which]->menu_s, title[which]->menu_f);
}

void get_pos_menu(menu_t **title)
{
    sfVector2f place = {800, 300};
    sfVector2f menux = {630, 50};
    sfVector2f how_v = {1700, 850};
    sfVector2f cred_v = {1700, 425};
    sfVector2f how_to_play_v = {100, 200};
    sfVector2f how_icone_v = {100, 850};

    place_menu(title, menux, dbz, "assets/titre.png");
    place_menu(title, place, play, "assets/scope.png");
    place.y += 200;
    place_menu(title, place, settings, "assets/settings.png");
    place.y += 200;
    place_menu(title, place, quit, "assets/exit.png");
    place_menu(title, how_v, cred, "assets/cre.png");
    place_menu(title, how_to_play_v, how_to_play, "assets/how_to_play.png");
    place_menu(title, how_icone_v, how_icone, "assets/how.png");
}

void fill_menu(menu_t **title)
{
    sfVector2f place = {800, 300};
    sfVector2f menux = {630, 50};
    sfVector2f how_v = {1650, 900};
    sfVector2f cred_v = {1650, 400};

    title[back]->menu_tt = sfTexture_createFromFile("assets/world.png", NULL);
    title[back]->menu_s = sfSprite_create();
    title[optback]->menu_tt = sfTexture_createFromFile("./assets/house.png",
        NULL);
    title[optback]->menu_s = sfSprite_create();
    sfSprite_setTexture(title[optback]->menu_s, title[optback]->menu_tt,
        sfTrue);
    sfSprite_setTexture(title[back]->menu_s, title[back]->menu_tt, sfTrue);
    get_pos_menu(title);
    place_menu(title, cred_v, credits, "assets/credits.png");
}

menu_t **create_title(void)
{
    menu_t **title = malloc(sizeof(menu_t *) * (12));
    int i = 0;

    title[11] = NULL;
    while (i < 11) {
        title[i] = malloc(sizeof(menu_t));
        i++;
    }
    title[0]->tuto = 0;
    title[0]->credits = 0;
    setrect(title);
    fill_menu(title);
    return (title);
}

game_t *create_game(void)
{
    game_t *game = malloc(sizeof(game_t));
    sfFont *font = sfFont_createFromFile("./assets/font.ttf");
    sfVideoMode mode = {1920, 1080, 32};

    game->window = sfRenderWindow_create(mode, "DEFENDER BALL Z",
    sfFullscreen, NULL);
    create_bool(game);
    sfRenderWindow_setFramerateLimit(game->window, 60);
    game->place = 0;
    game->score = 0;
    create_audio(game);
    game->scoretxt = sfText_create();
    sfText_setFont(game->scoretxt, font);
    return (game);
}