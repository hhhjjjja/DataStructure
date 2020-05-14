/*���� 4�忡�� ������ ���Ḯ��Ʈ�� Ȱ���Ͽ� �ؽ� ü�̴��� �����Ѵ�. ������ �� �� ���� �ǽ�/������ ���������� �Ʒ� ������ �ǽ��Ѵ�.

������ ���� ������ 400�� �����Ѵ�.
---------------------------------------------------
1) x = 0���� 1,000������ ����
2) y = 0���� 1,000������ ����
3) x�� 4���� ���� �������� ���� ������ ����
[0] �������� 0 �Ǵ� 1 �� ��� y�� �ؽ����̺� ����
[1] �������� 2�� ��� y�� �ؽ����̺��� ����
[2] �������� 3�� ��� y�� �ؽ����̺��� Ž��

���� ���� ��� ������ ���� Ƚ���� �����Ͽ� ����Ѵ�.
1) ������ ��쿡 �߻��ϴ� �浹Ƚ��(�Ѱ� �̻��� ��尡 �������)
2) Ž���� ��� Ž�� ���� Ƚ���� Ž�� �������� Ű�� �� Ƚ��(��� �湮 Ƚ��)
3) ������ ��� ���� �ϴ� Ű ���� Ž�� ���� Ƚ�� �� �� Ű �� �� Ƚ��*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linked_list.h"	//elementŸ��, ���Ḯ��Ʈ
#define BUCKET_CNT 100
#define M 100

ListNode *HashTable[BUCKET_CNT];
int colcnt;
int searchcompcnt, searchkeycnt;
int deletecompcnt, deletekeycnt;

int hash_function(int key) {
	int hash_index = key % M;
	if (hash_index < 0)
		hash_index += M;
	return hash_index;
}
void add(element value, ListNode *hashTable[]) {
	int first;
	int HashValue = hash_function(value);
	ListNode *pNewNode = NULL;
	ListNode *pPrevNode = NULL;
	ListNode *pCur = hashTable[HashValue];
	pNewNode = create_node(value, NULL);
	for (; pCur; pPrevNode = pCur, pCur = pCur->link) {
		if (pCur->data == value) {
			return; 
		}
	}
	insert_last_node(&hashTable[HashValue], pNewNode, &first);
	if(!first) ++colcnt;
	pNewNode = (ListNode*)malloc(sizeof(ListNode));
	pNewNode->data = value;
	pNewNode->link = NULL;
	if (pPrevNode) {
		   pPrevNode->link = pNewNode;
	}
	else {
		hashTable[HashValue] = pNewNode;
	}
}
void search(element value, ListNode *hashTable[]) {
	ListNode *pNode;
	int HashValue = hash_function(value);
	for (pNode = hashTable[HashValue]; pNode; pNode = pNode->link) {
		++searchkeycnt;
		if (pNode->data == value) {
			++searchcompcnt;
			return;
		}
	}
}
void delete_hash(element value, ListNode *hashTable[]) {
	ListNode *pPrevNode = NULL;
	ListNode *pCurNode = NULL;

	int Hashvalue = hash_function(value); 

	for (pCurNode = hashTable[Hashvalue]; pCurNode; pCurNode = pCurNode->link) {
		deletekeycnt++;
		if (pCurNode->data == value) {
			deletecompcnt++;
			if (pPrevNode == NULL) hashTable[Hashvalue] = pCurNode->link;
			else if (pCurNode->link == NULL) pPrevNode->link = NULL;
			else pPrevNode->link = pCurNode->link;
			free(pCurNode);
		  
			return; 
		}
		pPrevNode = pCurNode;
	}
}
int main() {
	int i, x, y;
	srand((unsigned int)time(NULL));
	for (i = 0; i < 400; ++i) {
		x = rand() % 1001;
		y = rand() % 1001;
		if(x%4==0 ||x%4==1) {
			add(y, HashTable);
		}
		else if(x%4==2) {
			delete_hash(y, HashTable);
		}
		else if(x%4==3) {
			search(y, HashTable);
		}
	}
	printf("1) ������ ��쿡 �߻��ϴ� �浹Ƚ��(�Ѱ� �̻��� ��尡 �������) : %d\n", colcnt);
	printf("2) Ž�� ���� Ƚ�� : %d, Ž�� �������� Ű �� �� Ƚ��(��� �湮 Ƚ��) : %d\n", searchcompcnt, searchkeycnt);
	printf("3) ���� �ϴ� Ű ���� Ž�� ���� Ƚ�� : %d, Ű �� �� Ƚ�� : %d\n", deletecompcnt, deletekeycnt);
	return 0;
}