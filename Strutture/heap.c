#include <stdio.h>
#include <stdlib.h>
typedef int Item;
typedef Item *Heap;
struct pqueue{
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

Item pqueue_extractmin(Pqueue p){
    //il minimo si trova tutto a sx, ossia l'ultima posizione dell'array
    Item min = p->h[p->count];
    p->count--;
    return min;
}

void swap (int arr[], int i, int j){
    int tmp=arr[i];
    arr[i]=arr[j];
    arr[j]=tmp;
    return;
}

void heapify_up(Heap h, int i){
    if (i>1){
        int father = i/2;
        //printf("father: %d, i: %d\t v_f: %d, v_i: %d\n", father, i, h[father], h[i]);
        if (h[father]<h[i]){
            //printf("Il padre è minore\n");
            swap(h, i, father);
            heapify_up(h, father);
        }
    }
}

void pqueue_insert(Pqueue p, Item i){
    p->count++; //lo faccio prima dato che non considero la prima posizione dell'array.
    //facendo così posso anche estrarre il minimo passando p->count
    p->h[p->count] = i;
    //printf("p->count: %d\n", p->count);
    heapify_up(p->h, p->count);
    return;
}

Pqueue pqueue_new(int n){
    Pqueue new = malloc(sizeof(struct pqueue));
    Item *arr=calloc(n, sizeof(int));
    new->h=arr;
    new->size=n; 
    new->count=0; 
    return new;
}

void pqueue_destroy ( Pqueue p){
    for (int i=1; i<p->count;i++){
        p->h[i]=0;
    }
    free(p->h);
    p->count=0;
    return;
}

void stampa (Pqueue p){
    for (int i=1; i<=p->count; i++){
        printf("%d ", p->h[i]);
    }
    printf("\n");
}

int main (void){
    Pqueue p=pqueue_new(6);
    pqueue_insert(p, 3);
    pqueue_insert(p, 4);
    pqueue_insert(p, 6);
    pqueue_insert(p, 2);
    pqueue_insert(p, 12);
    stampa(p);
    printf("%d \n", pqueue_extractmin(p) );
    pqueue_destroy(p);
    stampa(p);

}
