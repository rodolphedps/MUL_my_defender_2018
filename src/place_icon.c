/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** place_icone
*/

#include "defender.h"

void set_back_menu(sett_t **sett, sfVector2f pos, int set, char *file)
{
    sett[set]->vol_tex = sfTexture_createFromFile(file, NULL);
    sett[set]->vol_spr = sfSprite_create();
    sfSprite_setTexture(sett[set]->vol_spr, sett[set]->vol_tex, sfTrue);
    sfSprite_setTextureRect(sett[set]->vol_spr, sett[set]->back_m);
    sett[set]->sett_f = pos;
    sfSprite_setPosition(sett[set]->vol_spr, sett[set]->sett_f);
}

void set_icone_position(sett_t **sett, sfVector2f pos, int set, char *file)
{
    sett[set]->vol_tex = sfTexture_createFromFile(file, NULL);
    sett[set]->vol_spr = sfSprite_create();
    sfSprite_setTexture(sett[set]->vol_spr, sett[set]->vol_tex, sfTrue);
    sfSprite_setTextureRect(sett[set]->vol_spr, sett[set]->volume);
    sett[set]->sett_f = pos;
    sfSprite_setPosition(sett[set]->vol_spr, sett[set]->sett_f);
}

void set_positions(sett_t **sett, sfVector2f pos, int set, char *file)
{
    sett[set]->vol_tex = sfTexture_createFromFile(file, NULL);
    sett[set]->vol_spr = sfSprite_create();
    sfSprite_setTexture(sett[set]->vol_spr, sett[set]->vol_tex, sfTrue);
    sfSprite_setTextureRect(sett[set]->vol_spr, sett[set]->vol_rect);
    sett[set]->sett_f = pos;
    sfSprite_setPosition(sett[set]->vol_spr, sett[set]->sett_f);
}

void set_positions_size(sett_t **sett, sfVector2f pos, int set, char *file)
{
    sett[set]->vol_tex = sfTexture_createFromFile(file, NULL);
    sett[set]->vol_spr = sfSprite_create();
    sfSprite_setTexture(sett[set]->vol_spr, sett[set]->vol_tex, sfTrue);
    sfSprite_setTextureRect(sett[set]->vol_spr, sett[set]->size);
    sett[set]->sett_f = pos;
    sfSprite_setPosition(sett[set]->vol_spr, sett[set]->sett_f);
}
