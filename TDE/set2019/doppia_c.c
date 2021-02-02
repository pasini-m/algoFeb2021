/* In una lista doppiamente concatenata, il numero 
di puntatori sui quali si interviene per
un'operazione di inserimento è: */

#include <stdio.h>
#include <stdlib.h>
struct node {
    int v;
    struct node *next;
    struct node *prev;
};

typedef struct node *Node;
struct list {
    Node tail;
    Node head;
};
typedef struct list *List;

Node new_node (int n){
    Node new = malloc(sizeof(struct node));
    new ->v=n;
    new->next=new->prev=NULL;
    return new;
}

List new_list(int n){
    List l=malloc(sizeof(struct list));
    Node new=new_node(n);
    l->head=l->tail=new;
    return l;
}

void insert (List l, int v ){
    Node n=new_node(v);
    l->tail->next=n;
    n->prev=l->tail;
    l->tail=n; 
    return;
}

void print(List l){
    Node tmp;
    for (tmp=l->head; tmp!=NULL; tmp=tmp->next){
        printf("%d ", tmp->v);
    }
    printf("\n");
}

void print_reverse(List l){
    Node tmp;
    for (tmp=l->tail; tmp!=NULL; tmp=tmp->prev){
        printf("%d ", tmp->v);
    }
    printf("\n");
}

int main (void){
    List root=new_list(1);
    insert(root,2);
    insert(root,3);
    insert(root,4);
    print(root);
    print_reverse(root);

}