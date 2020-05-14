/*
1. ���ĵ� �迭�� ����Ͽ� �켱 ���� ť �����Ͻÿ�.
2. �����Ͱ� ���ĵ��� �ʰ� �����ϴ� ���߿��Ḯ��Ʈ�� ����Ͽ� �켱����ť�� �����Ͻÿ�.
3. ���� 1,2���� ������ �켱����ť�� insert, delete �Լ��� �ּ� 20�̻� ȣ���ϴ� ���α׷��� �ۼ��ϰ� �����Ͽ� ������ �����Ͻÿ�.  
*/

//�迭�� �켱���� ť ����

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 200
typedef int element;

typedef struct priorityQ {
	element *array;
	int size;
}priorityQ;

element is_empty(priorityQ *q) {
	return (q->size == 0);
}

element is_full(priorityQ *q) {
	return (q->size == MAX_SIZE-1);
}

void insert_node(priorityQ *q, int x) {
	int i;
	int a=0;

	for(i=0;i<q->size;++i) {
		if(q->array[i] < x)
			continue;
		else
			break;
	}

	a=i;

	for(i=q->size-1;i>=a;i--) {
		q->array[i+1] = q->array[i];
	}

	q->array[a] = x;
	q->size ++;

	printf("<%d>\t", x);
}

element delete_node(priorityQ *q) {
	int tmp;
	tmp=q->array[q->size-1];
	q->size --;

	printf("<%d>\t", tmp);
	return tmp;
}

void init(priorityQ *q) {
	q->size=0;
}

void create_node(priorityQ *q) {
	q->array=(int*)malloc(sizeof(int)*MAX_SIZE);
}

void free(priorityQ *q) {
	free(q->array);
}

int main() {
	int i;
	priorityQ q;
	
	create_node(&q);
	init(&q);

	insert_node(&q, 5);
	insert_node(&q, 10);
	insert_node(&q, 15);
	insert_node(&q, 20);
	insert_node(&q, 25);
	insert_node(&q, 30);
	insert_node(&q, 35);
	insert_node(&q, 40);
	insert_node(&q, 45);
	insert_node(&q, 50);
	insert_node(&q, 55);
	insert_node(&q, 60);
	insert_node(&q, 65);
	insert_node(&q, 70);
	insert_node(&q, 75);
	insert_node(&q, 80);
	insert_node(&q, 85);
	insert_node(&q, 90);
	insert_node(&q, 95);
	insert_node(&q, 100);

	printf("\n\n");
	printf("------DELETE PRINT------\n\n");

	delete_node(&q);
	delete_node(&q);
	delete_node(&q);
	delete_node(&q);
	delete_node(&q);
	delete_node(&q);
	delete_node(&q);
	delete_node(&q);
	delete_node(&q);
	delete_node(&q);
	delete_node(&q);
	delete_node(&q);
	delete_node(&q);
	delete_node(&q);
	delete_node(&q);
	delete_node(&q);
	delete_node(&q);
	delete_node(&q);
	delete_node(&q);
	delete_node(&q);

	free(&q);
	return 0;
}