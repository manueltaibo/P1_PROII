/*
* TITLE: PROGRAMMING II LABS
* SUBTITLE: Practical 1
* AUTHOR 1: MANUEL TAIBO GONZÁLEZ LOGIN 1: manuel.taibo2
* AUTHOR 2: MARTÍN LÓPEZ LODEIRO LOGIN 2: martin.lopez.lodeiro
* GROUP: 2.4
* DATE: 16 / 02 / 24
*/


#include "static_list.h"

#include <string.h>



void createEmptyList(tList *L){
    L->lastPos = LNULL;             //Indicamos que la última posición del array es -1, por lo que se crea una lista vacía
}


bool isEmptyList(tList L){
    return L.lastPos == LNULL;        //Si la última posición es LNULL, la lista está vacía
}


tPosL first(tList L){
    return 0;                       //La primera posición de cualquier array es la posición 0
}


tPosL last(tList L){
    return L.lastPos;               //Lastpos recorre la última posición del array
}


tPosL next(tPosL p, tList L){
    if (p == L.lastPos){    //Comprobamos si la lista está llena
        return LNULL;
    } else {
        return ++p;         //Si no, que nos devuelva la posición siguiente a p
    }
}


tPosL previous(tPosL p, tList L){
    if(p == 0){
        return LNULL;   //Precondición, si p no tiene anterior, devolvemos LNULL
    } else {
        return --p;     //Devolvemos la posición anterior a p
    }
}


bool insertItem(tItemL item, tPosL p, tList *L){
    tPosL i;
    if (L->lastPos == NAME_LENGTH_LIMIT - 1) {             //Comprobamos si la lista está llena
        return false;
    } else {
        L->lastPos++;                                    //Añadimos una posición más para insertar el nuevo item
        if (p == LNULL) {
            L->data[L->lastPos] = item;                  //Condición de insertar al final
        } else {
            for (i = L->lastPos;i > p; i--) {       //Movemos los items de necesarios hacia la derecha para insertar el nuevo item
                L->data[i] = L->data[i - 1];
            }
            L->data[p] = item;                       //Insertamos el nuevo item
        }
        return true;
    }
}

void deleteAtPosition(tPosL p, tList *L){
    L->lastPos--;                                       //Eliminamos una posición de la lista, si es válida
    for (tPosL i = p; i <= L->lastPos; i++) {
        L->data[i] = L->data[i + 1];                    //Recolocamos el resto de items
    }
}


tItemL getItem(tPosL p, tList L){
    return L.data[p];                 //Devolvemos el item de la posición indicada, si es válida
}


void updateItem(tItemL item, tPosL p, tList *L){
    L->data[p] = item;                  //Insertamos el nuevo item en la posición deseada, si es válida
}

tPosL findItem(tUserName name, tList L){
    if (L.lastPos == LNULL) { // Comprobamos si la lista está vacía
        return LNULL;
    } else {
        for (tPosL p = 0; p <= L.lastPos; p++) { // Recorremos la lista
            if (strcmp(name, L.data[p].userName) == 0) {
                return p; // Si el username es igual al indicado, devuelve la posición
            }
        }
        return LNULL;
    }
}




