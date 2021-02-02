#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
    struct node *prev;
};
typedef struct node *Node;

struct list {
    Node head;
    Node tail;
};

Node new_node (int v){
    Node new=malloc(sizeof(struct node));
    new->info=v;
    new->next=new->prev=NULL;
    return new;
}
typedef struct list *List;
int size(List l);
int contains(List l, int e);
void removeAtStart(List l);
void removeAtEnd(List l);
void addAtStart(List l, int n);
void removeAtEnd(List l);
void print_list(List l);
void print_reverse(List l);

void print_list(List l){
    Node tmp;
    for ( tmp=l->head; tmp!=NULL; tmp=tmp->next){
        printf("%d ", tmp->info);
    }
    printf("\n");
}

void print_reverse(List l){
    Node tmp;
    for (tmp=l->tail; tmp!=NULL; tmp=tmp->prev){
        printf("%d ", tmp->info);
    }
    printf("\n");
}

int size(List l){
    Node tmp;
    int s=0;
    for (tmp=l->head; tmp!=NULL; tmp=tmp->next){
        s++;
    }
    return s;
}

int contains(List l, int e){
    Node tmp;
    for (tmp=l->head; tmp!=NULL; tmp=tmp->next){
        if (tmp->info==e) return 1;
    }
    return 0;
}

void addAtStart(List l, int n){
    Node new=new_node(n);
    //potrei anche farlo senza senza size(),
    // basta controllare che head e tail siano NULL
    if (size(l)==0){
        l->head=l->tail=new;
        return;
    }
    if (size(l)==1){
        //questo lo faccio solo una volta, in modo
        //che tail->prev non sia NULL
        l->tail->prev=new;
    }
    l->head->prev=new;
    new->next=l->head;
    l->head=new;
    return;
}

void removeAtStart(List l){
    if (size(l)==1){
        printf("\t\tSize 1\n");
        //non sono sicuro funzioni
        l->head=l->tail=NULL;
        free(l->head);
    }
    Node tmp=l->head;
    printf("Sto rimuovendo %d... \n", tmp->info);
    l->head=l->head->next;
    l->head->prev=NULL;
    free(tmp);
}

void addAtEnd(List l, int n){
    Node new=new_node(n);
    if (size(l)==0){
        l->head=l->tail=new;
        return;
    }
    if (size(l)==1){
        l->head->next=new;
    }
    new->prev=l->tail;
    l->tail->next=new;
    l->tail=new;
}

void removeAtEnd(List l){
    if (size(l)==1){
        l->tail=l->head=NULL;
        return;
    }
    Node tmp=l->tail;
    l->tail=l->tail->prev;
    free(tmp);
}

int main (void){
    List l=malloc(sizeof(struct list));
    addAtEnd(l,1);
    addAtEnd(l,2);
    addAtEnd(l,3);
    removeAtEnd(l);
    print_list(l);
    print_reverse(l);
    /* 
    addAtStart(l, 1);
    addAtStart(l, 2);
    addAtStart(l, 3);
    addAtStart(l, 4);
    removeAtStart(l);
    print_list(l);
    */


}

