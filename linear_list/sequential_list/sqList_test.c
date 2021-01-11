#include"sqList_test.h"
#include"sequential_list.h"
#include "../../predefined/predefined.h"

Status bigger(ElemType a, ElemType b){
	if(a > b)
		return TRUE;
	return FALSE;
} 

void sqList_test(){
	SqList *pa = InitList_Sq();
	SqList *pb = InitList_Sq();
	SqList *pc = InitList_Sq();
	printf("\nListInsert_Sq testing:\n\n");
	for(ElemType i = 10 ;i >= 1 ; --i){
		ListInsert_Sq(pa, 1, i);
	}
	print(pa);

	for(ElemType i = 20 ;i >=11 ; --i){
		ListInsert_Sq(pb, 1, i);
	}
	print(pb);
	printf("\n");

	printf("MegegList_Sq testing:\n\n");
	MergeList_Sq(pa, pb, pc);
	print(pc);
	
	printf("\nListDelete_Sq testing:\n\n");
	ElemType e = 0;
	ListDelete_Sq(pc, 3, &e);
	print(pc);
	
	printf("\nListInsert_Sq testing:\n\n");
	ListInsert_Sq(pc, 3, 21);
	ListInsert_Sq(pc, 3, 22);
	print(pc);

	printf("\nLocateElem_Sq testing:\n\n");
	printf("The first number location is bigger than 10 in Sq is: %d\n",LocateElem_Sq(pc, 10, bigger));

	pa = DestroyList_Sq(pa);
	pb = DestroyList_Sq(pb);
	pc = DestroyList_Sq(pc);
}
