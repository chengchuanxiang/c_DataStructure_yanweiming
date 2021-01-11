//
//  Triplet.c
//  dataStructure
//
//  Created by 程传翔 on 2020/12/31.
//
#include<stdlib.h>
#include <stdio.h>
#include "Triplet.h"
#include "../predefined/predefined.h"

Triplet* InitTriplet(ElemType v1, ElemType v2, ElemType v3){
    Triplet *T = (Triplet*)malloc(sizeof(Triplet));
    if (T == NULL) {
        return NULL;
    }
    ;
    T->first = v1;
    T->second = v2;
    T->third = v3 ;
    return T;
}

Triplet* DestroyTriplet(Triplet *T){
    free(T);
    T = NULL;
    return T;
}

Status Get(Triplet *T, int i, ElemType *e){
    if(i < 1 || i > 3) return FALSE;
    if (T == NULL) {
        printf("T == NULL\n");
    }
    if(i == 1) *e = T->first;
    else if(i == 2) *e = T->second;
    else if(i == 3) *e = T->third;
    return OK;
}

Status Put(Triplet *T, int i, ElemType e){
    if(i < 1 || i > 3) return FALSE;
    else if(i == 1) T->first = e;
    else if(i == 2) T->second = e;
    else if(i == 3) T->third = e;
    return OK;
}

Status IsAscending(Triplet *T){
    return (T->first <= T->second) && (T->second <= T->third);
}

Status IsDescending(Triplet *T){
    return (T->first >= T->second) && (T->second >= T->third);
}

Status Max(Triplet *T, ElemType *e){
    *e = (T->first >= T->second)? ((T->first >= T->third)? T->first : T->third) :
    ((T->second >= T->third)? T->second : T->third);
    return OK;
}

Status Min(Triplet *T, ElemType *e){
    *e = (T->first <= T->second)? ((T->first <= T->third)? T->first : T->third) :
    ((T->second <= T->third)?  T->second : T->third);
    return OK;
}

void print(Triplet *T){
    printf("first: %d second: %d third: %d \n", T->first, T->second, T->third);
}

