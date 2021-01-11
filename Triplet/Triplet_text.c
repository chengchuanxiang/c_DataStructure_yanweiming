//
//  Triplet_text.c
//  dataStructure
//
//  Created by 程传翔 on 2020/12/31.
//

#include "Triplet_text.h"
#include "Triplet.h"
#include "../predefined/predefined.h"
#include <stdio.h>
#include <stdlib.h>
void Triplet_text(void){
    Triplet *T = InitTriplet(1, 2, 3);
    print(T);
    int e = 0;
    Get(T, 2, &e);
    printf("Get(T, 2, &e): %d\n",e);
    if(IsAscending(T)){
        printf("IsAscending\n");
    }
    Put(T, 2, 5);
    Get(T, 2, &e);
    printf("Put(T, 2, 5)\nGet(T, 2, &e): %d\n",e);
    Put(T, 1, 6);
    Put(T, 3, 4);;
    printf("Put(T, 1, 6)\nPut(T, 3, 4);\n");
    print(T);
    if(IsDescending(T)){
        printf("IsDescending\n");
    }
    Max(T, &e);
    printf("Max(T, e): %d\n", e);
    Min(T, &e);
    printf("MIn(T, e): %d\n", e);
    
    T = DestroyTriplet(T);
    if(T == NULL){
        printf("Memory released successfully\n");
    }
}

