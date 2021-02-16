#include <stdlib.h>
#include <stdio.h>
#define L 9

struct bit_node {
    int v;
    struct bit_node *l, *r ;
};
typedef struct bit_node *Bit_node;
typedef int Item;
Bit_node bit_new( Item );
void bit_preorder( Bit_node );
void bit_inorder( Bit_node );
void bit_postorder( Bit_node );
void bit_print(Bit_node);
Bit_node bit_arr2tree(Item a[], int size, int i);
void bit_printassummary(Bit_node root, int spaces);

void bit_printassummary(Bit_node root, int spaces){
    for (int i=0; i<spaces; i++)
        printf(" ");
    printf("*");
    if (root){
        bit_print(root);
        printf("\n");
        if (root->l||root->r){
        bit_printassummary(root->l, spaces+1);
        bit_printassummary(root->r, spaces+1);
        }
    }else{
        printf("\n");
    }
    return;
}


Bit_node bit_new(Item i){
    Bit_node new = malloc(sizeof(struct bit_node));
    new->v=i;
    new->l=new->r=NULL;
    return new;
}

Bit_node bit_arr2tree(Item a[], int size, int i){
    Bit_node root=NULL;
    if (i<size){
        root=bit_new(a[i]);
        root->l=bit_arr2tree(a, size, 2*i+1);
        root->r=bit_arr2tree(a, size, 2*i+2);
    }
    return root;
}


void bit_print(Bit_node p){
    printf("%d ", p->v);
}
void bit_preorder (Bit_node p){
    if (p){
        bit_print(p);
        bit_preorder(p->l);
        bit_preorder(p->r);
    }
}

void bit_inorder(Bit_node p){
    if (p){
        bit_inorder(p->l);
        bit_print(p);
        bit_inorder(p->r);
    }
}

int main (void){
    int a[]={69, 89, 28, 39, 66, 44, 12, 2, 71};
    Bit_node r=bit_arr2tree(a, L, 0);
    bit_printassummary(r, 0);
    bit_inorder(r);
}