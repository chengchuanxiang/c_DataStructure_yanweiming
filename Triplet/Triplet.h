//
//  Triplet.h
//  dataStructure
//
//  Created by 程传翔 on 2020/12/31.
//

#ifndef Triplet_h
#define Triplet_h

#include <stdio.h>
#include "../predefined/predefined.h"
typedef struct Triplet{
    ElemType first;
    ElemType second;
    ElemType third;
}Triplet;

Triplet* InitTriplet(ElemType v1, ElemType v2, ElemType v3);
Triplet* DestroyTriplet(Triplet *T);
Status Get(Triplet *T, int i, ElemType *e);
Status Put(Triplet *T, int i, ElemType e);
Status IsAscending(Triplet *T);
Status IsDescending(Triplet *T);
Status Max(Triplet *T, ElemType *e);
Status Min(Triplet *T, ElemType *e);
void print(Triplet *T);

#endif /* Triplet_h */

