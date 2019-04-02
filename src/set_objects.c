/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** set_objects
*/

#include "defender.h"

void set_back(play_t **pl, int set, char *file)
{
    pl[set]->tex = sfTexture_createFromFile(file, NULL);
    pl[set]->spr = sfSprite_create();
    sfSprite_setTexture(pl[set]->spr, pl[set]->tex, sfTrue);
}

void set_icones(play_t **pl, sfVector2f pos, int set, char *file)
{
    pl[set]->tex = sfTexture_createFromFile(file, NULL);
    pl[set]->spr = sfSprite_create();
    sfSprite_setTexture(pl[set]->spr, pl[set]->tex, sfTrue);
    sfSprite_setPosition(pl[set]->spr, pos);
}

void set_toolbar(play_t **pl)
{
    sfIntRect tool = {0, 0, 86, 352};
    sfVector2f pos = {1834, 200};

    pl[toolbar]->tex = sfTexture_createFromFile("assets/tool_bar.png", NULL);
    pl[toolbar]->spr = sfSprite_create();
    sfSprite_setTexture(pl[toolbar]->spr, pl[toolbar]->tex, sfTrue);
    sfSprite_setTextureRect(pl[toolbar]->spr, tool);
    sfSprite_setPosition(pl[toolbar]->spr, pos);
}