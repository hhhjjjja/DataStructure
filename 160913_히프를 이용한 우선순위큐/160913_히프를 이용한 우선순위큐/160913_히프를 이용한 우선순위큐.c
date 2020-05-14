/*������ upheap, downheap �˰����� ����Ͽ�
�켱����ť�� insert_max_heap �Լ��� delete_max_heap �Լ��� �����Ѵ�.
������ �Լ� 2���� �� 20�� �̻� ȣ���ϴ� main �Լ��� ���� ������ �����ϰ� ȣ���Ͽ�
������ ����� �������� Ȯ���Ѵ�. �̣� insert_max_heap�� delete_max_heap�� �ݺ�������
��� �����Ͽ� �񱳸� �����ϴ��� ����ؾ� �Ѵ�.*/


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
	printf("���Խ� ���� �� %d \n",loop);
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
	printf("������ ���� �� %d \n",loop); 
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