/*
* TITLE: PROGRAMMING II LABS
* SUBTITLE: Practical 1
* AUTHOR 1: MANUEL TAIBO GONZÁLEZ LOGIN 1: manuel.taibo2
* AUTHOR 2: MARTÍN LÓPEZ LODEIRO LOGIN 2: martin.lopez.lodeiro
* GROUP: 2.4
* DATE: 06 / 03 / 24
*/

#include "dynamic_list.h"

#include <stdlib.h>
#include <string.h>

void createEmptyList(tList *L){
    *L = LNULL;     //L apunta a LNULL para crear una lista vacía
}

bool isEmptyList(tList L){
    return L == LNULL;   //Si L == LNULL(lista vacía) devolverá true sino false
}

tPosL first(tList L){
    return L;       //
}

tPosL last(tList L){
    tPosL p;
    for(p = L; p->next != LNULL; p = p->next); //Bucle que acaba cuando la siguiente posición a p sea LNULL
    return p;       //p será la última posición
}

tPosL next(tPosL p, tList L){
    return p->next;     //Devolvemos a siguiente posición a p
}

tPosL previous(tPosL p, tList L){
    tPosL q;
    if(p == L){
        return LNULL;   //Si p es igual a L no tendrá previo y devuelve LNULL
    } else {
        for(q = L; q->next != p; q = q->next);  //Bucle que recorre hasta la posción anterior de p
        return q;       //q será la posición anterior a p
    }
}

bool createNodo(tPosL *p){
    *p = malloc(sizeof (struct tNodo));
    return *p != LNULL;
}

bool insertItem(tItemL d, tPosL p, tList *L){
    tPosL q, r;
    if(!createNodo(&q)){     //Si no se pudo crear un nuevo nodo, el elemento no se inserta y devuelve false
        return false;
    } else{
        q->data = d;        //Se crea un nuevo nodo con el item a insertar
        q->next = LNULL;
        if(*L == LNULL){        //Si la lista está vacía, L apuntará al nuevo nodo
            *L = q;
        } else if(p == LNULL){
            for(r = *L; r->next != LNULL; r = r->next);  //Si p es NULL insertaremos el nodo al final, recorremos la lista y r apuntara a q
            r->next = q;
        }else if(p == *L){ //Insertar en la primera posición
            q->next = p;
            *L = q;
        }else{      //Insertar en posición intermedia
            q->data = p->data;      //Recogemos el dato que hay en p en q, para no perder información
            p->data = d;            //Introducimos el item en la posición p
            q->next = p->next;      //Actualizamos la posición siguiente de q, que será la actual de p
            p->next = q;            //Actualizamos la posición siguiente de p, que será q
        }
        return true;
    }
}

void deleteAtPosition(tPosL p, tList *L){
    tPosL  q;
    if(p == *L){    //borrar el primer nodo
        *L = p->next;       //Si se borra el primer nodo, L apuntará a la siguiente posición del nodo borrado
    }else if(p->next == LNULL){ //borrar último nodo
        for(q = *L; q->next != p; q = q->next);     //Recorremos la lista hasta penúltima posición, que apuntará a LNULL
        q->next = LNULL;
    }else{  //borrar nodo intermedio
        q = p->next;
        p->data = q->data;
        p->next = q->next;
        p = q;
    }
    free(p);
}

tItemL getItem(tPosL p, tList L){
    return p->data;     //Devolvemos el dato de la posición indicada
}

void updateItem(tItemL d, tPosL p, tList *L){
    p->data = d;
}

tPosL findItem(tUserName name, tList L){
    tPosL p;
    for(p = L; (p != LNULL)&&(strcmp(p->data.userName,name) != 0); p = p->next);
    return p;
}