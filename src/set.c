#include "../incs/set.h"
//#include "../incs/list.h"
#include <stdio.h>
#include <stdlib.h>

//Nota: Traducir al ingles
/*Funciones basicas*/
Set MakeSet(Set S){
    if(S != NULL)
        printf("Set is not null!");
//Nota: Crear DeleteSet(S);
    S = malloc(sizeof(struct setElems));
    if(S == NULL)
        FatalError("Out of memory!");

    S->NElem = 0;
    S->setList = MakeEmpty(NULL);
    return S;
}

void AddSet(ElementType X, Set S){
    Position P = Header(S->setList);
    if(!ElementOf(X, S))
    {
        Insert(X, S->setList, P);
        S->NElem++;
    }
}

void DelSet(ElementType X, Set S){
    if(isEmpty(S))
        printf("\nEmpty Set!");
    else if(!ElementOf(X, S))
         printf("\nElement %d isn't a member of the Set\n", X);
    else
    {
        Delete(X, S->setList);
        S->NElem--;
    }   
}

/*Funciones de conjuntos*/
Set Union(Set A, Set B){
    Set UnionSet = MakeSet(NULL);
    Position P;
    
    P = Header(A->setList);
    do{
        P = Forward(P);
        AddSet(Retrieve(P), UnionSet);
    }while(!isLast(P, A->setList));
    
    P = Header(B->setList);
    do{
        P = Forward(P);
        AddSet(Retrieve(P), UnionSet);
    }while(!isLast(P, B->setList));

    return UnionSet;
}

Set Intersection(Set A, Set B){
    Set IntersectionSet = MakeSet(NULL);
    Position P;
//Nota: Quizas sea mas eficiente determinar cual set tiene menor cardninalidad para recorrerlo, preguntar esto
    P = Header(A->setList);
    do{
        P = Forward(P);
        if(ElementOf(Retrieve(P), B))
            AddSet(Retrieve(P), IntersectionSet);
    }while(!isLast(P, A->setList));

    return IntersectionSet;
}

Set Complement(Set A, Set B){
    Set ComplementSet = MakeSet(NULL);
    Position P = Header(A->setList);
    
    do{
        P = Forward(P);
        if(!ElementOf(Retrieve(P), B))
            AddSet(Retrieve(P), ComplementSet);
    }while(!isLast(P, A->setList));

    return ComplementSet;
}

/*Funciones de Busqueda*/
ElementType min(Set S){
    if(isEmpty(S))
        printf("\nEmpty Set!");
    else
    {
        Position P = First(S->setList);
        int Min = Retrieve(P);
        
        do{
            P = Forward(P);
            if(Min > Retrieve(P))
                Min = Retrieve(P);
        }while(!isLast(P, S->setList));

        return Min;
    }
}

ElementType max(Set S){
    if(isEmpty(S))
        printf("\nEmpty Set!");
    else
    {
         Position P = First(S->setList);
        int Max = Retrieve(P);
        
        do{
            P = Forward(P);
            if(Max < Retrieve(P))
                Max = Retrieve(P);
        }while(!isLast(P, S->setList));

        return Max;
    }
}

ElementType GetElement(int i, Set S){
    Position P = Header(S->setList);
    if(Cardinality(S) <= i)
    {
        printf("The set has fewer than %d elements", i);
        return -1;
    }

    for(int j = 0; j <= i; j++)
        P = Forward(P);

    return Retrieve(P);
/*Nota: Si 'i' excede la cardinalidad de 'S' debemos indicar que no hay mas elementos o 
continuar el ciclo*/
    /*Position P = Header(S->setList);
    for(int j = 0; j <= i; j++){
        P = Forward(P);
        if(isHeader(P, S->setList))
            P = Forward(P);
    }
    return Retrieve(P);*/
}

/*Funciones de evaluacion*/
int isEmpty(Set S){
    return Cardinality(S) == 0 && isEmptyList(S->setList);
}

int ElementOf(ElementType X, Set S){
    return !isHeader(Find(X, S->setList), S->setList);
}

int Equals(Set A, Set B){
    return Cardinality(A) == Cardinality(B) && Cardinality(Union(A, B)) == Cardinality(A);
}

int Inequals(Set A, Set B){
    return !Equals(A, B);
}

int Subset(Set A, Set B){
    Position P = Header(A->setList);
    
    do{
        P = Forward(P);
        if(!ElementOf(Retrieve(P), B))
            return 0;   //false
    }while(!isLast(P, A->setList));
    
    return 1;   //true
}

/*Funciones de acceso*/
int Cardinality(Set S){
    return S->NElem;
}

/*Set MinCardinalitySet(Set A, Set B){
    if(Cardinality(A) < Cardinality(B))
        return A;
    return B;
}*/

Set arraytoset(int arr[], int size) {
    Set arrSet = MakeSet(NULL);

    for (int i = 0; i < size; i++) {
        AddSet(arr[i], arrSet);
    }

    return arrSet;
}

