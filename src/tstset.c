#include <stdio.h>
#include <stdlib.h>
#include "../incs/set.h"

int main()
{    
    Set A = MakeSet(NULL);
    Set B = MakeSet(NULL);
    Set C = MakeSet(NULL);

    for(int i=2; i<=20; i+=2)
    {
        AddSet(i, A);
        if(i % 4 == 0)
            AddSet(i, C);   //C es un subconjunto de A
    }
    for(int i=1; i<=20; i+=2)
        AddSet(i, B);
    for(int i=2; i<=20; i+=4)
        AddSet(i, B);

    printf("Set 'A' has %d elements and his list is: \n", Cardinality(A));
    PrintList(A->setList);
    printf("Set 'B' has %d elements and his list is: \n", Cardinality(B));
    PrintList(B->setList);
    printf("Set 'C' has %d elements and his list is: \n", Cardinality(C));
    PrintList(C->setList);

    Set AB_Union = Union(A, B);
    Set AB_Intersection = Intersection(A, B);  
    Set AB_Complement = Complement(A, B);

    printf("Set 'Union A-B' has %d elements and his list is: \n", Cardinality(AB_Union));
    PrintList(AB_Union->setList);

    printf("Set 'Intersection A-B' has %d elements and his list is: \n", Cardinality(AB_Intersection));
    PrintList(AB_Intersection->setList);

    printf("Set 'Complement A-B' has %d elements and his list is: \n", Cardinality(AB_Complement));
    PrintList(AB_Complement->setList);

    /*int i = 10;
    if(GetElement(i, A) != -1)
        printf("El elemento %d es %d", i, GetElement(i, A));
    
    if(Equals(A, B))
        printf("A and B are equals");
    if(Inequals(A, B))
        printf("A and B aren't equals");*/

    if(Subset(C, A))
        printf("\nC is a subset of A");
    else
        printf("\nC isn't a subset of A");


    DelSet(5, A);
    printf("\nSet 'A' has %d elements and his list is: \n", Cardinality(A));
    PrintList(A->setList);

    printf("min is: %d\n", min(A));
    printf("max is: %d\n", max(A));
    

    return 0;
}