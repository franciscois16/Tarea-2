#include "../incs/list.h"
#include <stdio.h>
#include <stdlib.h>

/*Funciones basicas*/
List MakeEmpty(List L){
    if(L != NULL)
        DeleteList(L);

    L = malloc(sizeof(struct Node));
    if(L == NULL)
        FatalError("Out of memory!");

    L->Next = L->Prev = L;
    return L;
}

void Insert(ElementType X, List L, Position P){
    Position TmpCell = malloc(sizeof(struct Node));
    if(TmpCell == NULL)
        FatalError("Out of memory!");
    
    TmpCell -> Element = X;
    TmpCell -> Next = P -> Next;
    TmpCell -> Prev = P;
    
    (TmpCell -> Next) -> Prev = TmpCell;
    P->Next = TmpCell;
} 

void PrintList(List L){
    Position P = Header(L);
    if(isEmptyList(L))
        printf("Empty list\n");
    else
    {
        do{
            P = Forward(P);
            printf("%d ", Retrieve(P));
        }while(!isLast(P, L));
        printf("\n");  
    }
}

void Delete(ElementType X, List L){
    Position P = Find(X, L);
    (P->Prev)->Next = P->Next; 
    (P->Next)->Prev = P->Prev;
    free(P);
}

void DeleteList(List L){
    Position P, TmpCell;
    P = First(L);
    L->Next = L->Prev = L;
    while(!isLast(P, L))
    {
        TmpCell = P->Next;
        free(P);
        P = TmpCell;
    }
}

/*Funciones de Busqueda*/
Position Find(ElementType X, List L){
    Position P = First(L);

    while(!isHeader(P, L) && Retrieve(P) != X)
        P = Forward(P);
    
    return P;
}

Position FindPrevious(ElementType X, List L){
    Position P = Header(L);

    while(!isLast(P, L) && Retrieve(P->Next) != X)
        P = Forward(P);

    return P;
}

/*Funciones de evaluacion*/
int isEmptyList(List L){
    return L->Next == L;
}

int isFirst(Position P, List L) {
    return P->Prev == L;    //Quizas pueda agregar una condicion '&& !isHeader(P, L)'
}

int isLast(Position P, List L){
    return P->Next == L; //Quizas pueda agregar una condicion '&& !isHeader(P, L)'
}

int isHeader(Position P, List L){
    return P == L;
}

/*Funciones de acceso*/
Position Header(List L){
    return L;
}

Position First(List L){
    return L->Next;
}

ElementType Retrieve(Position P){
    return P->Element;
}

Position Forward(Position P){
    return P->Next;
}

Position Backward(Position P){
    return P->Prev;
}

/*Funciones de errores*/
void FatalError (char *s){
	printf("Error: %s\r\n", s);
	exit(-1);
}