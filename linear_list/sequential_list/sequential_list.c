//
//  sequential_list.c
//  dataStructure
//
//  Created by 程传翔 on 2020/12/31.
//

#include "sequential_list.h"
#include <stdlib.h>
#include<stdio.h>
SqList* InitList_Sq(void){
    SqList *L = (SqList*)malloc(sizeof(SqList));
    if(!L)return NULL;
    L->elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if(!L->elem)return NULL;
    L->length = 0;
    L->listsize = LIST_INIT_SIZE;
    return L;
}

SqList* DestroyList_Sq(SqList *L){
	free(L->elem);
	L->elem = NULL;
    free(L);
    L = NULL;
    return L;
}

Status ListInsert_Sq(SqList *L, int i, ElemType e){
	//i之前插入  1<=i<=L->length+1
    if(i < 1 || i > L->length + 1)return ERROR;

    if(L->length >= L->listsize){
        ElemType *newbase = (ElemType*)realloc(L->elem,(L->listsize + LISTINCREMENT) * sizeof(ElemType));
        if(!newbase)return OVERFLOW;
        L->elem = newbase;
        L->listsize += LISTINCREMENT;
    }

    ElemType *q = &(L->elem[i-1]);
    for (ElemType *p = &(L->elem[L->length-1]); p >= q; --p) {
        *(p + 1) = *p;
    }
    *q = e;
    ++L->length;
    return OK;
}

Status ListDelete_Sq(SqList *L, int i, ElemType *e){
    if(i < 1 || i > L->length )return ERROR;

    ElemType *p = &(L->elem[i-1]);
    *e = *p;

    ElemType *q = L->elem + L->length - 1;
    for (++p; p<=q; ++p) {
        *(p-1) = *p;
    }
    --L->length;
    return OK;
}

int LocateElem_Sq(SqList *L, ElemType e, Status (*compare)(ElemType, ElemType)){
    int i = 1;
    ElemType *p = L->elem;
    while(i <= L->length && !(*compare)(*p++, e)){
        ++i;
    }
    if(i <= L->length)return i;
    else return 0;
}

void MergeList_Sq(SqList *La, SqList *Lb, SqList *Lc){
    ElemType *pa = La->elem;
    ElemType *pb = Lb->elem;
    Lc->listsize = Lc->length = La->length + Lb->length;
    ElemType *pc = Lc->elem = (ElemType*)malloc(Lc->listsize*sizeof(ElemType));
    if(!pc)exit(OVERFLOW);

    ElemType *pa_last = La->elem + La->length - 1;
    ElemType *pb_last = Lb->elem + Lb->length - 1;
    while (pa <= pa_last && pb <= pb_last) {
        if(*pa <= *pb)*pc++ = *pa++;
        else *pc++ = *pb++;
    }
    while (pa <= pa_last) {
        *pc++ = *pa++;
    }
    while (pb <= pb_last) {
        *pc++ = *pb++;
    }
}

void print(SqList *L){
	if(L == NULL || L->elem == NULL)
		return ;
	for(int i = 0; i < L->length ; ++i){
		printf("%d",L->elem[i]);
		if(i != L->length-1)
			printf("->");
	}
	printf("\n");
	printf("The listsize of L is :%d\n",L->listsize);
	printf("The length of L is :%d\n",L->length);
	return ;
}


