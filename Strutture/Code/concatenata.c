#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};
typedef struct node *Node;

struct list {
    Node head;
};
typedef struct list *List;

int size(List l);
int contains(List l, int e);
void removeAtStart(List l);
void removeAtEnd(List l);
void addAtStart(List l, int n);
void removeAtEnd(List l);
void print_list(Node l);
void print_reverse(List l);
Node list_search (Node root, int n);

void print_list(Node l){
    Node tmp;
    for ( tmp=l; tmp!=NULL; tmp=tmp->next){
        printf("%d ", tmp->info);
    }
    printf("\n");
}

Node list_search (Node root, int n){
    Node tmp;
    for (tmp=root; tmp!=NULL; tmp=tmp->next){
        if (tmp->info==n) return tmp;
    }
    return NULL;
}

Node list_search_rec(Node root, int n){
    if (root->info==n) return root;
    return list_search_rec(root->next, n);
}

Node list_insert(Node root, int n){
    Node new=malloc(sizeof(struct node));
    new->info=n;
    new->next=root;
    return new;
}
Node new_node (int n){
    Node new=malloc(sizeof(struct node));
    new->info=n;
    new->next=NULL;
    return new;
}
void list_delete(Node root, int n){
    Node curr, prev;
    for (curr=root, prev=NULL; curr!=NULL; prev=curr, curr=curr->next){
        if (curr->info==n) break;
    }
    if (curr==NULL) {
        printf("Elem non tovato\n");
        return;
    }
    if (prev==NULL) {
        printf("\tElemento in pria posizione\n");
        *root=*root->next; //devo passare l'indirizzo, passo per riferimento non per variabile
    }else{
        prev->next=curr->next;
    }
    printf("\tRimuovo %d\n", curr->info);
    free(curr);
    //return root;
}
//funzione che aggiunge il valore nella lista ordinata
Node olist_insert (Node root, int n){
    Node curr=root, prev=NULL;
    Node new= new_node(n);
    if (root==NULL){
        return new;
    }
    while (curr->info<n){
        prev=curr; curr=curr->next;
        if (curr==NULL) break;
    }
    prev->next=new;
    new->next=curr;
    return root;
    //devo fare il caso in cui il posto giusto sia in prima posizione
}

int *listToArray (Node root){
    int *arr=malloc(sizeof(int)*10);
    Node tmp;
    int i=0;
    for ( tmp=root; tmp!=NULL;  tmp=tmp->next){
        arr[i++]=tmp->info;
    }
    return arr;
}

int main (void){
    Node root=NULL;
    root=olist_insert(root, 1);
    root=olist_insert(root, 2);
    root=olist_insert(root, 5);
    root=olist_insert(root, 4);
    print_list(root);
    printf("%d\n", root->next->info);
    int *arr=listToArray(root);
    for (int i=0; i<4; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    //Node find = list_search_rec(root, 3); printf(" tr %d\n", find->info);
    //list_delete(root, 4);
    //print_list(root);
}