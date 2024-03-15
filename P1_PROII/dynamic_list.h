/*
* TITLE: PROGRAMMING II LABS
* SUBTITLE: Practical 1
* AUTHOR 1: MANUEL TAIBO GONZÁLEZ LOGIN 1: manuel.taibo2
* AUTHOR 2: MARTÍN LÓPEZ LODEIRO LOGIN 2: martin.lopez.lodeiro
* GROUP: 2.4
* DATE: 06 / 03 / 24
*/

#ifndef DYNAMIC_LIST_H
#define DYNAMIC_LIST_H

#define LNULL NULL

#include "types.h"
#include <stdbool.h>

typedef struct tNodo* tPosL;

struct tNodo{
    tItemL data;
    tPosL next;
};

typedef tPosL tList;

void createEmptyList(tList *L);

bool isEmptyList(tList L);

tPosL first(tList L);

tPosL last(tList L);

tPosL next(tPosL p, tList L);

tPosL previous(tPosL p, tList L);

bool insertItem(tItemL item, tPosL p, tList *L);

void deleteAtPosition(tPosL p, tList *L);

tItemL getItem(tPosL p, tList L);

void updateItem(tItemL item, tPosL p, tList *L);

tPosL findItem(tUserName name, tList L);

#endif
