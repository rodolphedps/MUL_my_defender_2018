/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** audio_manager
*/

#include "defender.h"

void create_audio(game_t *game)
{
    game->audio = malloc(sizeof(audio_t));
    game->audio->volume = 30;
    game->audio->chala = sfMusic_createFromFile("./assets/menu.ogg");
    sfMusic_setLoop(game->audio->chala, sfTrue);
    sfMusic_play(game->audio->chala);
    game->audio->ingame = sfMusic_createFromFile("./assets/game.ogg");
    sfMusic_setLoop(game->audio->ingame, sfTrue);
    game->audio->dash = sfSound_create();
    game->audio->dashb = sfSoundBuffer_createFromFile("./assets/dash.ogg");
    sfSound_setBuffer(game->audio->dash, game->audio->dashb);
    game->audio->chepo = sfSound_create();
    game->audio->chepob = sfSoundBuffer_createFromFile("./assets/krilin.ogg");
    sfSound_setBuffer(game->audio->chepo, game->audio->chepob);
    change_volume(game, 30);
}

void change_volume(game_t *game, float new_vol)
{
    sfMusic_setVolume(game->audio->chala, new_vol);
    sfMusic_setVolume(game->audio->ingame, new_vol);
    sfSound_setVolume(game->audio->dash, new_vol / 2);
    sfSound_setVolume(game->audio->chepo, new_vol / 2);
}

void audio_manager(game_t *game)
{
    if (game->place == playw) {
        sfSound_play(game->audio->dash);
        sfMusic_stop(game->audio->chala);
        sfSound_play(game->audio->chepo);
        sfMusic_play(game->audio->ingame);
    }
    else if (game->place == menuw) {
        sfSound_play(game->audio->dash);
        sfMusic_stop(game->audio->ingame);
        sfMusic_play(game->audio->chala);
    }
}