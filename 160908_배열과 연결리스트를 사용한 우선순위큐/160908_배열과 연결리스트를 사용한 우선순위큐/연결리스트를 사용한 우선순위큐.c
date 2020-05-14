/*
1. ���ĵ� �迭�� ����Ͽ� �켱 ���� ť �����Ͻÿ�.
2. �����Ͱ� ���ĵ��� �ʰ� �����ϴ� ���߿��Ḯ��Ʈ�� ����Ͽ� �켱����ť�� �����Ͻÿ�.
3. ���� 1,2���� ������ �켱����ť�� insert, delete �Լ��� �ּ� 20�̻� ȣ���ϴ� ���α׷��� �ۼ��ϰ� �����Ͽ� ������ �����Ͻÿ�.  
*/

//���߿��Ḯ��Ʈ�� �켱����ť

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
	if(temp == NULL) printf("�޸� �Ҵ� ����\n");

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
