/*
*   sLList.h
*
*   FUNCOES QUE REPRESENTAO 
*   AS OPERACOES DE UMA Lista.
*
*   Arquivo com as definições dos cabeçalhos  
*   das operações implementadas em sLList.c
*/
#ifndef _SLL_H_
#define _SLL_H_
#define TRUE 1
#define FALSE 0

    typedef struct _sllist_ SLList;
    typedef struct _slnode_ SLNode;
    SLList * sllCreate( void ); 
    int sllDestroy(SLList *l );
    int sllInsertFirst(SLList *l, void *data);
    void *sllQuery( SLList *l, void *key, int (*cmp)(void *, void*));
    void *sllRemoveSpec( SLList *l, void *key, int (*cmp)(void *, void*));
    void *sllRemoveFirst ( SLList *l);
    int sllEmpty(SLList *l);
    void sllListElements(SLList *l, void (*printFunc)(void *));

#else
    #define TRUE 1
    #define FALSE 0
    typedef struct _sll_ SLList;
    typedef struct _slnode_ SLNode;
    extern SLList * sllCreate( void );
    extern int sllDestroy(SLList *l ); 
    extern int sllInsertFirst(SLList *l, void *data);
    extern void *sllQuery( SLList *l, void *key, int (*cmp)(void *, void*));
    extern void *sllRemoveSpec( SLList *l, void *key, int (*cmp)(void *, void*));
    extern void *sllRemoveFirst ( SLList *l);
    extern int sllEmpty(SLList *l);
    extern void sllListElements(SLList *l, void (*printFunc)(void *));
#endif