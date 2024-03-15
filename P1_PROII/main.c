/*
* TITLE: PROGRAMMING II LABS
* SUBTITLE: Practical 1
* AUTHOR 1: MANUEL TAIBO GONZÁLEZ LOGIN 1: manuel.taibo2
* AUTHOR 2: MARTÍN LÓPEZ LODEIRO LOGIN 2: martin.lopez.lodeiro
* GROUP: 2.4
* DATE: 12 / 03 / 24
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

#define MAX_BUFFER 255

#ifdef DYNAMIC_LIST
#include "dynamic_list.h"
#endif
#ifdef STATIC_LIST
#include "static_list.h"
#endif

void New(char *commandNumber, char command, char *param1, char *param2, tList *L){
    printf("********************\n");
    printf("%s %c: user %s category %s\n", commandNumber, command, param1, param2);

    if(findItem(param1, *L) != LNULL) {
        printf("+ Error: New not possible\n");

    }else{
        tItemL newUser;
        strcpy(newUser.userName, param1);
        if (strcmp(param2, "basic") == 0) {
            newUser.userCategory = basic;
        } else {
            newUser.userCategory = pro;
        }
        newUser.numPlay=0;

        if (insertItem(newUser, LNULL, L)) {
            printf("* New: user %s category %s\n", param1, param2);
        } else {
            printf("+ Error: New not possible\n");
        }
    }
}


void Delete(char *commandNumber, char command, char *param1, tList *L){
    printf("********************\n");
    printf("%s %c: user %s\n", commandNumber, command, param1);

    tPosL p = findItem(param1, *L);

    if (isEmptyList(*L) || p == LNULL) {
        printf("+ Error: Delete not possible\n");
    }else {
        tItemL user = getItem(p,*L);
        deleteAtPosition(p, L);
        printf("* Delete: user %s category %s numplays %d\n", param1, user.userCategory == basic ? "basic" : "pro", user.numPlay);
    }
}


void Upgrade(char *commandNumber, char command, char *param1, tList *L){
    printf("********************\n");
    printf("%s %c: user %s\n", commandNumber, command, param1);

    tPosL p = findItem(param1, *L);
    if (isEmptyList(*L) || p == LNULL) {
        printf("+ Error: Upgrade not possible\n");
        return;
    }

    tItemL user = getItem(p, *L);

    if (user.userCategory==pro) {
        printf("+ Error: Upgrade not possible\n");
        return;
    } else {
        user.userCategory = pro;
        updateItem(user,p,L);
        printf("* Upgrade: user %s category pro\n", param1);
    }
}


void Play(char *commandNumber, char command, char *param1, char *param2, tList *L){
    printf("********************\n");
    printf("%s %c: user %s song %s\n", commandNumber, command, param1, param2);

    tPosL p = findItem(param1, *L);

    if(findItem(param1, *L) == LNULL){
        printf("+ Error: Play not possible\n");
        return;
    }

    tItemL user = getItem(p, *L);

    if(p != LNULL) {
        user.numPlay++;
        updateItem(user,p,L);
        printf("* Play: user %s plays song %s numplays %d\n", param1, param2, user.numPlay);
    }
}


void Stats(char *commandNumber, char command, tList *L){
    printf("********************\n");
    printf("%s %c:\n", commandNumber, command);

    if(isEmptyList(*L)){
        printf("+ Error: Stats not possible");
        return;
    } else {
        tPosL p;
        for (p = first(*L); p!=LNULL; p=next(p, *L)) {
            tItemL user = getItem(p, *L);
            printf("User %s category %s numplays %d\n", user.userName, user.userCategory == basic ? "basic" : "pro", user.numPlay);
        }

        int basicUsers = 0, basicPlays = 0, proUsers = 0, proPlays = 0;
        for (p = first(*L); p != LNULL; p = next(p, *L)) {
            tItemL user = getItem(p, *L);
            if (user.userCategory == basic) {
                basicUsers++;
                basicPlays += user.numPlay;
            } else {
                proUsers++;
                proPlays += user.numPlay;
            }
        }
        printf("Category  Users  Plays  Average\n");
        printf("Basic         %d      %d     %.2f\n", basicUsers, basicPlays, (basicUsers != 0) ? (float)basicPlays / basicUsers : 0);
        printf("Pro           %d      %d     %.2f\n", proUsers, proPlays, (proUsers != 0) ? (float)proPlays / proUsers : 0);
    }
}


void processCommand(char *commandNumber, char command, char *param1, char *param2, tList *L) {

    switch (command) {
        case 'N':
            New(commandNumber, command, param1, param2, L);
            break;
        case 'D':
            Delete(commandNumber, command, param1, L);
            break;
        case 'U':
            Upgrade(commandNumber, command, param1, L);
            break;
        case 'P':
            Play(commandNumber, command, param1, param2, L);
            break;
        case 'S':
            Stats(commandNumber, command, L);
            break;
        default:


            break;
    }
}


void readTasks(char *filename) {
    FILE *f = NULL;
    char *commandNumber, *command, *param1, *param2;
    const char delimiters[] = " \n\r";
    char buffer[MAX_BUFFER];


    tList L;
    createEmptyList(&L);


    f = fopen(filename, "r");


    if (f != NULL) {


        while (fgets(buffer, MAX_BUFFER, f)) {
            commandNumber = strtok(buffer, delimiters);
            command = strtok(NULL, delimiters);
            param1 = strtok(NULL, delimiters);
            param2 = strtok(NULL, delimiters);


            processCommand(commandNumber, command[0], param1, param2, &L);
        }


        fclose(f);


    } else {
        printf("Cannot open file %s.\n", filename);
    }
}




int main(int nargs, char **args) {


    char *file_name = "new.txt";


    if (nargs > 1) {
        file_name = args[1];
    } else {
#ifdef INPUT_FILE
        file_name = INPUT_FILE;
#endif
    }


    readTasks(file_name);


    return 0;
}
