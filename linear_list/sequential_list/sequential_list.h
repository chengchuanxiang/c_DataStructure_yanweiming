//
//  sequential_list.h
//  dataStructure
//
//  Created by 程传翔 on 2020/12/31.
//

#ifndef sequential_list_h
#define sequential_list_h

#include <stdio.h>
#include "../../predefined/predefined.h"
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef struct SqList{
    ElemType *elem;
    int length;
    int listsize;
}SqList;

SqList* InitList_Sq(void);
SqList* DestroyList_Sq(SqList*);
Status ListInsert_Sq(SqList *L, int i, ElemType e);
Status ListDelete_Sq(SqList *L, int i, ElemType *e);
int LocateElem_Sq(SqList *L, ElemType e, Status (*compare)(ElemType, ElemType));
void MergeList_Sq(SqList *La, SqList *Lb, SqList *Lc);
void print(SqList *L);

#endif /* sequential_list_h */

