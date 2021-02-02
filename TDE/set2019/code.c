#include <stdio.h>
#include <stdlib.h>

struct node {
  struct node *next;
  int val;
};

typedef struct node *Node;

Node newNode( int val, Node p );
int f1 ( Node p );
Node f2 ( Node p );
Node f3 ( Node p, Node q );

int main(){
	Node x = newNode( 1, NULL );
	Node head = newNode( 2, x );
    printf("    %d\n", f1(head));
}


Node newNode( int val, Node p ){
	Node new = malloc( sizeof (struct node));
	new -> val = val;
	new -> next = p;
	return new;
}

int f1 ( Node p ){
	//getchar(); //non ha senso, non va avanti finchè non inserisco un char?
	if ( p -> next == NULL )
		return 1;
	else
        //se il valore successivo è minore return 0
		if ( p -> val < p -> next -> val )
			return 0;
		else //vado avanti. Se la funzione ritorna nulla significa che la lista è in ordine decrescente
			return f1( p -> next );
}

Node f2 ( Node p ){
	getchar();
	if (  p -> next == NULL ) 
		return p; //se sono in fondo restituisco l'ultimo nodo
	else 
		return f3( p -> next, p );
}

// questa funzione ritorna il minimo della lista
Node f3 ( Node p, Node q ){
	Node temp;
	if ( p -> val < q -> val ) //successivo<precedente
		temp = p; //temp=p->next
	else
		temp = q;
	if ( p -> next == NULL ) //il nodo successivo del successivo
		return temp; //restituisce il minore tra il nodo successivo e quello corrente
	else 
		return f3( p -> next, temp );
	
}


