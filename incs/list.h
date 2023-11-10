#ifndef LIST_H
#define LIST_H

typedef int ElementType;

typedef struct Node *PtrToNote;
typedef PtrToNote List;
typedef PtrToNote Position;

struct Node {
    ElementType Element;
    Position Next;
    Position Prev;
};

/*Funciones basicas*/
List MakeEmpty(List L);
void Insert(ElementType X, List L, Position P);
void PrintList(List L);
void Delete(ElementType X, List L);
void DeleteList(List L);
/*Funciones de Busqueda*/
Position Find(ElementType X, List L);
Position FindPrevious(ElementType X, List L);
/*Funciones de evaluacion*/
int isEmptyList(List L);
int isFirst(Position P, List L);
int isLast(Position P, List L);
int isHeader(Position P, List L);
/*Funciones de acceso*/
Position Header(List L);
Position First(List L);
ElementType Retrieve(Position P);
Position Forward(Position P);
Position Backward(Position P);
/*Funciones de errores*/
void FatalError (char *s);

#endif