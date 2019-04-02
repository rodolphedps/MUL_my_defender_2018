/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** score
*/

#include "defender.h"

void update_score(game_t *game, play_t **pl)
{
    sfVector2f spr_pos = sfSprite_getPosition(pl[krillin]->spr);
    sfVector2f pos = {50, 155};

    for (int i = krillin; i <= krillin5 + 1; i++) {
        if (spr_pos.x == pos.x && spr_pos.y == pos.y && game->money != 0) {
            game->score -= 20;
        }
        spr_pos = sfSprite_getPosition(pl[i]->spr);
    }
}

void money_gain(game_t *game, play_t **pl)
{
    pl[backg]->clock->time = sfClock_getElapsedTime(pl[backg]->clock->clock);
    pl[backg]->clock->seconds = pl[backg]->clock->time.microseconds / 1000000;
    if (pl[backg]->clock->seconds > 0.0009) {
        game->score += 10;
        game->money++;
        sfClock_restart(pl[backg]->clock->clock);
    }
    update_score(game, pl);
}

void money_print(game_t *game)
{
    sfVector2f money = {1730, 25};
    sfText_setString(game->scoretxt, "Money:");
    sfText_setPosition(game->scoretxt, money);
    sfText_setOutlineColor(game->scoretxt, sfBlack);
    sfText_setOutlineThickness(game->scoretxt, 1.2);
    sfRenderWindow_drawText(game->window, game->scoretxt, NULL);
    money.y += 50;
    money.x = 1880;
    money.x -= (25 * getnbrlen(game->money));
    sfText_setString(game->scoretxt, my_itoa(game->money));
    sfText_setPosition(game->scoretxt, money);
    sfText_setOutlineColor(game->scoretxt, sfBlack);
    sfText_setOutlineThickness(game->scoretxt, 1.2);
    sfRenderWindow_drawText(game->window, game->scoretxt, NULL);
}

void score_print(game_t *game)
{
    sfVector2f bot = {750, 1035};

    sfText_setString(game->scoretxt, "Score:");
    sfText_setPosition(game->scoretxt, bot);
    sfText_setOutlineColor(game->scoretxt, sfBlack);
    sfText_setOutlineThickness(game->scoretxt, 1.2);
    sfRenderWindow_drawText(game->window, game->scoretxt, NULL);
    if (game->score == 0)
        sfText_setString(game->scoretxt, "0");
    else
        sfText_setString(game->scoretxt, my_itoa(game->score));
    bot.x += 170;
    sfText_setPosition(game->scoretxt, bot);
    sfText_setOutlineColor(game->scoretxt, sfBlack);
    sfText_setOutlineThickness(game->scoretxt, 1.2);
    sfRenderWindow_drawText(game->window, game->scoretxt, NULL);
    money_print(game);
}