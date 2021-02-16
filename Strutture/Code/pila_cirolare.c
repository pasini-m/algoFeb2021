#include <stdio.h>
#include <stdlib.h>
#define L 2
struct pila{
    int *a;
    int tail, head, len, count;
};
typedef struct pila *Pila;

Pila create(){
    Pila p = malloc(sizeof(struct pila));
    p->a=calloc(L, sizeof(int));
    p->tail=p->head=p->count=0;
    p->len=L;
    return p;
}
void myrealloc(Pila p){
    int *new_arr=malloc(2*p->len);
    for (int i=0; i<p->len; i++){
        new_arr[i]=p->a[(i+p->tail)%p->len];
    }
    free(p->a);
    p->a=new_arr;
    p->head=p->count; //la testa è nella posizione "massima"
    p->tail=0; //l'ho copiata, quindi sarà sicuramente nella posizione iniziale
    p->len=2*p->len;
}

void push (Pila p, int n){
    if (p->count<p->len){ //se c'è spazio aggiungo l'elemento
        p->a[p->head]=n;
        p->head++;
        //sposto di uno la testa
    }
    if (p->head==p->len){ //se ho raggiunto la fine dell'array circolare 
           p->head=0;
    }
    p->count++;
    if (p->count==p->len){
        printf("\tRicreo la coda...\n");
        myrealloc(p); 
    }
}

int pop (Pila p){
    int elem=p->a[p->head-1];
    p->head--;
    p->count--;
    return elem;
}

void stampa(Pila p){
    for (int i=p->tail; i<p->head; i++){
        printf("%d\t", p->a[i%(p->len)]);
    }
    printf("\n");
}

int main (void){
    Pila p=create();
    push(p, 1);
    push(p, 2);
    push(p, 3);
    printf("pop: %d\n",pop(p));
    push(p, 5);
    push(p, 6);
    stampa(p);
 
}