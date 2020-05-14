/*교재 4장에서 구현한 연결리스트를 활용하여 해쉬 체이닝을 구현한다. 구현을 한 후 이전 실습/과제와 마찬가지로 아래 실험을 실시한다.

다음과 같은 과정을 400번 수행한다.
---------------------------------------------------
1) x = 0에서 1,000까지의 난수
2) y = 0에서 1,000까지의 난수
3) x를 4으로 나눈 나머지에 따라서 다음을 수행
[0] 나머지가 0 또는 1 인 경우 y를 해쉬테이블에 삽입
[1] 나머지가 2인 경우 y를 해쉬테이블에서 삭제
[2] 나머지가 3인 경우 y를 해쉬테이블에서 탐색

또한 실험 결과 다음과 같은 횟수를 측정하여 출력한다.
1) 저장의 경우에 발생하는 충돌횟수(한개 이상의 노드가 만들어짐)
2) 탐색의 경우 탐색 성공 횟수와 탐색 과정에서 키값 비교 횟수(노드 방문 횟수)
3) 삭제의 경우 삭제 하는 키 값의 탐색 성공 횟수 및 총 키 값 비교 횟수*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linked_list.h"	//element타입, 연결리스트
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
	printf("1) 저장의 경우에 발생하는 충돌횟수(한개 이상의 노드가 만들어짐) : %d\n", colcnt);
	printf("2) 탐색 성공 횟수 : %d, 탐색 과정에서 키 값 비교 횟수(노드 방문 횟수) : %d\n", searchcompcnt, searchkeycnt);
	printf("3) 삭제 하는 키 값의 탐색 성공 횟수 : %d, 키 값 비교 횟수 : %d\n", deletecompcnt, deletekeycnt);
	return 0;
}