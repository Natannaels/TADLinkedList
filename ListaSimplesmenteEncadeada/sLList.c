/*
*   sLList.c
*   
*   FUNCOES QUE REPRESENTAO 
*   AS OPERACOES DE UMA lista.
*
*   Arquivo com a implementação das 
*   operações definidas em sLList.h
*/

#ifndef _SLL_C_
#define _SLL_C_
#include "sLList.h"
#include <stdlib.h>

typedef struct _slnode_ {
    void *data;
    struct _slnode_ *next;
} SLNode;

typedef struct _sllist_ {
    SLNode *first;
}SLList;

SLList * sllCreate( void ) {
    SLList *l;
    l = (SLList * ) malloc(sizeof(SLList ));
    if ( l != NULL ) {
        l->first = NULL;
        return l;
        }
    return NULL;
}

int sllDestroy(SLList *l ){
    if ( l != NULL ) {
        if ( l->first == NULL ) {
            free (l);
            return TRUE;
        }
    }
    return FALSE;
}

int sllInsertFirst(SLList *l, void *data) {
    SLNode * newnode;
    if ( l != NULL) {
        newnode = (SLNode *)malloc(sizeof(SLNode));
        if ( newnode != NULL ) {
            newnode->data = data;
            newnode->next = l->first;
            l->first = newnode;
            return TRUE;
        }
    }
        return FALSE;
}

void *sllQuery( SLList *l, void *key, int (*cmp)(void *, void*)){
    SLNode *cur; int stat;
    if ( l != NULL) {
        if ( l->first != NULL) {
            cur = l->first;
            stat = cmp (cur->data, key);
            while ( stat != TRUE && cur->next != NULL){
                cur = cur->next;
                stat = cmp (cur->data, key);
            }
            if ( stat == TRUE) {
                return cur->data;
            }
        }
    }
    return NULL;
}

void *sllRemoveSpec( SLList *l, void *key, int (*cmp)(void *, void*)) {
    SLNode *spec, *prev; int stat; void *dat;
    if ( l != NULL) {
        if ( l->first != NULL) {
            spec = l->first; 
            prev = NULL;
            stat = cmp(spec->data, key);
            while ( stat != TRUE && spec->next != NULL){
                prev = spec; 
                spec= spec->next;
                stat = cmp(spec->data, key);
            }
            if ( stat == TRUE) {
                dat = spec->data;
                if ( prev == NULL) {
                    l->first = spec->next;
                } else {
                    prev->next =spec->next;
                }
                free (spec);
                return dat;
            }
        }
    }
    return NULL;
}

void *sllRemoveFirst ( SLList *l) {
    SLNode *first; void *data;
    if ( l != NULL) {
        if ( l->first != NULL ) {
            first = l->first;
            data = first->data;
            l->first = first->next;
            free(first);
            return data;
        }
    }
    return NULL;
}

int sllEmpty(SLList *l) {
    SLNode *current = l->first;
    SLNode *next;
    if (l != NULL) {
        if ( l->first != NULL ) {
            while (current != NULL) {
                next = current->next;
                free(current);
                current = next;
            }
            l->first = NULL;
            return TRUE;
        }
    }
    return FALSE;
}

void* sllGetNext(SLList *l) {
    static SLNode *cur = NULL;
    if (l != NULL) {
        if (cur == NULL) {
            cur = l->first;
        } else {
            cur = cur->next;
        }
        if (cur != NULL) {
            return cur->data;
        }
    }
    return NULL;
}
#endif