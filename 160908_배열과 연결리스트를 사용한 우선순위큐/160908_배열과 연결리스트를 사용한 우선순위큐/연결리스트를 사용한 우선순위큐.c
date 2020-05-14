/*
1. 정렬된 배열을 사용하여 우선 순위 큐 구현하시오.
2. 데이터가 정렬되지 않게 저장하는 이중연결리스트를 사용하여 우선순위큐를 구현하시오.
3. 앞의 1,2에서 구현한 우선순위큐의 insert, delete 함수를 최소 20이상 호촐하는 프로그램을 작성하고 실행하여 구현을 검증하시오.  
*/

//이중연결리스트로 우선순위큐

#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	int data;
	struct ListNode *llink;
	struct ListNode *rlink;
}ListNode;

typedef struct ListHeader {
	int length;
	ListNode *head;
	ListNode *tail;
}ListHeader;

void init(ListHeader *plist) {
	plist->length = 0;
	plist->head = plist->tail = NULL;
}

void insert_list(ListHeader *before, int data) {
	ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
	if(temp == NULL) printf("메모리 할당 에러\n");

	temp->data=data;

	if(before->length == 0) {
		before->head = temp;
		before->tail = temp;
		temp->rlink = temp->llink= NULL;
	}
	else {
		temp->rlink = NULL;
		before->tail->rlink = temp;
		temp->llink = before->tail;
		before->tail = temp;
	}
	(before->length)++;
	printf("<%d>\t", data);

	return;
}

element delete_list(ListHeader *plist) {
	ListNode *pcur=plist->head;
	ListNode *ptmp=pcur;
	
	int value = pcur->data;

	while( pcur != NULL ) {
		 if(value < pcur->data) {
         value = pcur->data; 
         ptmp = pcur;
		 }

		 pcur = pcur->rlink;
   }
	if(ptmp == plist->head || ptmp == plist->tail) {
		if(plist->head == plist->tail) {
			free(ptmp); 
			plist->head = NULL; 
			plist->tail = NULL; 
		}
		else if(plist->head == ptmp) {
			ptmp->rlink->llink = NULL;
			plist->head = ptmp->rlink;
			free(ptmp);
		}
		else if(plist->tail == ptmp) {
			ptmp->llink->rlink = NULL;
			plist->tail = ptmp->llink; 
			free(ptmp);
		}
   }
   else {
	   ptmp->llink->rlink = ptmp->rlink; 
	   ptmp->rlink->llink = ptmp->llink;
	   free(ptmp);
   }
   (plist->length)--;

   printf("%d \n", value);
   return value;
}

int main(int argc, char *argv[]) {
	ListHeader list;
	init(&list);

	insert_list(&list,1);
	insert_list(&list,2);
	insert_list(&list,3);
	insert_list(&list,4);
	insert_list(&list,5);
	insert_list(&list,6);
	insert_list(&list,7);
	insert_list(&list,8);
	insert_list(&list,9);
	insert_list(&list,10);
	insert_list(&list,11);
	insert_list(&list,12);
	insert_list(&list,13);
	insert_list(&list,14);
	insert_list(&list,15);
	insert_list(&list,16);
	insert_list(&list,17);
	insert_list(&list,18);
	insert_list(&list,19);
	insert_list(&list,20);
	
	printf("\n\n");
	printf("------DELETE PRINT------\n\n");

	delete_list(&list);
	delete_list(&list);
	delete_list(&list);
	delete_list(&list);
	delete_list(&list);
	delete_list(&list);
	delete_list(&list);
	delete_list(&list);
	delete_list(&list);
	delete_list(&list);
	delete_list(&list);
	delete_list(&list);
	delete_list(&list);
	delete_list(&list);
	delete_list(&list);
	delete_list(&list);
	delete_list(&list);
	delete_list(&list);
	delete_list(&list);
	delete_list(&list);
	
	return 0;
}
