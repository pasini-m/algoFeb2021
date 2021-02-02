/* A me un problema dove avevi tipo una lista concatenata
1 2 3 4 5 6 
E la dovevi far diventare
2 1 4 3 6 5 solo scambiando puntatori.
*/
#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *next;
};
typedef struct node *Node;
Node new_node (int n){
    Node new=malloc(sizeof(struct node));
    new->val=n;
    new->next=NULL;
    return new;
}

Node insert (Node root, int n){
    Node new = new_node(n);
    new->next=root;
    root=new;
    return root;
}

void stampa (Node n){
    Node tmp;
    for (tmp=n; tmp!=NULL; tmp=tmp->next){
        printf("%d ", tmp->val);
    }
    printf("\n");
}

void scambia (Node n){
    Node curr=n, succ=NULL;
    while(1){
        succ=curr->next; //questo assegnamento lo faccio per una questione di leggibilità
        printf("\tSto scambiando %d con %d\n", curr->val, succ->val);
        //curr->next=succ->next;
        curr->next=curr->next->next;
        succ->next=curr;
        curr=succ;
        if (curr->next->next==NULL) break;
        curr=curr->next->next;
    }
}

int main (void){
    Node root=NULL;
    root=insert(root, 6);
    root=insert(root, 5);
    root=insert(root, 4);
    root=insert(root, 3);
    root=insert(root, 2);
    root=insert(root, 1);
    stampa(root);
    scambia(root);
    stampa(root);
}