#include <stdlib.h>
#include <stdio.h>
#define L 5 //dimensione dell'array
typedef int Item;

struct queue {
    int size;
    int *arr;
    int rear, front;
};
typedef struct queue *Queue;



// Put element on rear
void enqueue( Queue q, Item i );
// Remove and return element from front
Item dequeue( Queue );
// Return front element
Item frontValue( Queue );
// Check if queue is empty
int is_empty_queue( Queue );
// Print queue content
void print_queue( Queue );

void print_queue(Queue q){
    for (int i=q->front; i<q->size; i++){
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}
void enqueue( Queue q, Item i ){
    if (q->size==L) {
        printf("La coda è piena, non posso aggiungere\t");
    }
    q->arr[q->rear]=i; //lo metto nel fondo, da front estraggo
    //quando incremento utilizzo il modulo:
    q->rear=(q->rear+1)%L;
    q->size++;
};
/* c'è un problema di indistinguibilità tra la coda piena e la coda vuota, 
quando c'è un unico elemento invece front=rear 
*/

Item dequeue (Queue q){
    Item elem;
    if (q->size==0){
        printf("\tLa lista è vuota, non posso estrarre\n");
        return -1;
    }
    elem=q->arr[q->front];
    q->front=(q->front+1)%L;
    q->size--;
    return elem;
}

Queue new_q(){
    Queue q = malloc(sizeof(struct queue));
    q->front=q->rear=q->size=0;
    q->arr=malloc(sizeof(int)*L);
    return q;
}

int main (void){
    Queue q = new_q();
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    print_queue(q);
    printf("\t%d\n", dequeue(q));
    printf("\t%d\n", dequeue(q));
    enqueue(q, 10);
    print_queue(q);
    printf("\tsize%d\n", (q->size));
    printf("\t%d\n", dequeue(q));
    printf("\t%d\n", dequeue(q));
    print_queue(q);
    enqueue(q, 10); enqueue(q, 20); enqueue(q, 30);

    //non funziona il print, non ho testato se 
    //una volta piena torna al primo elemento
}
