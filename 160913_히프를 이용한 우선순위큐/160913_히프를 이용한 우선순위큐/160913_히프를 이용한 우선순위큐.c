/*히프의 upheap, downheap 알고리즘을 사용하여
우선순위큐의 insert_max_heap 함수와 delete_max_heap 함수를 구현한다.
구현한 함수 2개를 총 20번 이상 호출하는 main 함수를 이전 과제와 동일하게 호출하여
동일한 결과가 나오는지 확인한다. 이？ insert_max_heap와 delete_max_heap는 반복과정을
몇번 수행하여 비교를 수행하는지 출력해야 한다.*/


#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct {
	int key;
}element; 
typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

void init(HeapType *h) {
	h->heap_size=0;
}

void insert_max_heap(HeapType *h, element item) {
	int i;
	int loop = 0;
	i = ++(h->heap_size);
	
	while((i != 1) && (item.key > h->heap[i/2].key)) {
		h->heap[i] = h->heap[i/2];
		i /= 2;
		loop++;
	}
	h->heap[i] = item;
	printf("삽입시 루프 수 %d \n",loop);
}

element delete_max_heap(HeapType *h) {
	int parent, child;
	int loop = 0;
	element item, temp;
	
	item=h->heap[1];
	temp=h->heap[(h->heap_size)--];
	parent=1;
	child=2;
	
	while(child <= h->heap_size) {
		if((child<h->heap_size) && (h->heap[child].key) < h->heap[child+1].key) {
			child++;
		}
		if(temp.key >= h->heap[child].key) break;
		
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
		loop++;
	}
	h->heap[parent] = temp;
	printf("삭제시 루프 수 %d \n",loop); 
	return item;
}



int main(int argc, char *argv[]) {
	element e1;
	HeapType heap;
	
	init(&heap);
	e1.key = 10;
	insert_max_heap(&heap, e1);
	e1.key = 5;
	insert_max_heap(&heap, e1);
	e1.key = 20;
	insert_max_heap(&heap, e1);
	e1.key = 40;
	insert_max_heap(&heap, e1);
	e1.key = 16;
	insert_max_heap(&heap, e1);
	e1.key = 23;
	insert_max_heap(&heap, e1);
	e1.key = 1;
	insert_max_heap(&heap, e1);
	e1.key = 25;
	insert_max_heap(&heap, e1);
	e1.key = 45;
	insert_max_heap(&heap, e1);
	e1.key = 7;
	insert_max_heap(&heap, e1);
	
	
	e1=delete_max_heap(&heap);
	printf("<%d>", e1.key);
	e1=delete_max_heap(&heap);
	printf("<%d>", e1.key);
	e1=delete_max_heap(&heap);
	printf("<%d>", e1.key);
	e1=delete_max_heap(&heap);
	printf("<%d>", e1.key);
	e1=delete_max_heap(&heap);
	printf("<%d>", e1.key);
	e1=delete_max_heap(&heap);
	printf("<%d>", e1.key);
	e1=delete_max_heap(&heap);
	printf("<%d>", e1.key);
	e1=delete_max_heap(&heap);
	printf("<%d>", e1.key);
	e1=delete_max_heap(&heap);
	printf("<%d>", e1.key);
	e1=delete_max_heap(&heap);
	printf("<%d>", e1.key);

	return 0;
}