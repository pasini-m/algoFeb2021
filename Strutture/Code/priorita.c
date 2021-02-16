#include <stdio.h>
#include <stdlib.h>
typedef int Item;
typedef Item *Heap; //sostanzialmente heap è un array di int
struct pqueue {
    Heap h;
    int size, count;
};
typedef struct pqueue *Pqueue;

/* crea una coda di priorità vuota che potrà contenere al massimo n Item */
Pqueue pqueue_new( int n );
/* distrugge la coda di priorità */
void pqueue_destroy ( Pqueue );
/* restituisce la lunghezza della coda di priorità */
int pqueue_length ( Pqueue );
/* inserisce l’Item nella coda di priorità */
void pqueue_insert ( Pqueue , Item );
/* estrae dalla coda di priorità l’Item con chiave minima */
Item pqueue_extractmin ( Pqueue );
/* restituisce l’Item con chiave minima nella coda di priorità */
Item pqueue_min( Pqueue );

Pqueue new(int n){
    int *he=calloc(n, sizeof(int));
    Pqueue p = malloc(sizeof(struct pqueue));
    p->h=he;
    p->size=n;
    return p;
}

void pqueue_destroy(Pqueue p){
    free(p);
}

int pqueue_length (Pqueue p){
    return p->count;
}

void pqueue_insert (Pqueue p, Item i){

}