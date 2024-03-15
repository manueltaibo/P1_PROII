/*
* TITLE: PROGRAMMING II LABS
* SUBTITLE: Practical 1
* AUTHOR 1: MANUEL TAIBO GONZÁLEZ LOGIN 1: manuel.taibo2
* AUTHOR 2: MARTÍN LÓPEZ LODEIRO LOGIN 2: martin.lopez.lodeiro
* GROUP: 2.4
* DATE: 16 / 02 / 24
*/

#ifndef PRO2_2023_P1_TYPES_H
#define PRO2_2023_P1_TYPES_H

#define NAME_LENGTH_LIMIT 25
#include <stdbool.h>


typedef char tUserName[NAME_LENGTH_LIMIT];
typedef char tSongTitle[NAME_LENGTH_LIMIT];
typedef int tNumPlay;


typedef enum {basic, pro} tUserCategory;


typedef struct tItemL {
    tUserName userName;
    tNumPlay numPlay;
    tUserCategory userCategory;
} tItemL;


typedef struct tSong{
    tSongTitle songTitle;
} tSong;


#endif //PRO2_2023_P1_TYPES_H
