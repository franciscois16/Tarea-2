#include "list.h"

#ifndef SET_H
#define SET_H

typedef struct setElems *PtrToSet;
typedef PtrToSet Set;
//typedef PtrToSet setPosition;

struct setElems{
    int NElem;
    List setList;
};

/*Funciones basicas*/
Set MakeSet(Set S);
void AddSet(ElementType X, Set S);
void DelSet(ElementType X, Set S);
/*Funciones de conjuntos*/
Set Union(Set A, Set B);
Set Intersection(Set A, Set B);
Set Complement(Set A, Set B);
/*Funciones de Busqueda*/
ElementType min(Set S);
ElementType max(Set S);
ElementType GetElement(int i, Set S);
/*Funciones de evaluacion*/
int isEmpty(Set S);
int ElementOf(ElementType X, Set S);
int Equals(Set A, Set B);
int Inequals(Set A, Set B);
int Subset(Set A, Set B);
/*Funciones de acceso*/
int Cardinality(Set S);
//Set MinCardinalitySet(Set A, Set B);

#endif







