/*
* TITLE: PROGRAMMING II LABS
* SUBTITLE: Practical 1
* AUTHOR 1: MANUEL TAIBO GONZÁLEZ LOGIN 1: manuel.taibo2
* AUTHOR 2: MARTÍN LÓPEZ LODEIRO LOGIN 2: martin.lopez.lodeiro
* GROUP: 2.4
* DATE: 16 / 02 / 24
*/


#ifndef STATIC_LIST_H
#define STATIC_LIST_H


#include "types.h"


#define LNULL -1


typedef int tPosL;
typedef struct{
    tItemL data[NAME_LENGTH_LIMIT];
    tPosL lastPos;
}tList;


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

