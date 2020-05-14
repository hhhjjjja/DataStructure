#ifndef QUEUE_H
#define QUEUE_H

typedef int element;

typedef struct QueueNode {
	element item;
	struct QueueNode *link;
}QueueNode;
typedef struct {
	QueueNode *front, *rear;
}QueueType;

void init(QueueType *q) {
	q->front = q->rear =NULL;
}
void enqueue(QueueType *q, element item) {
	QueueNode *temp=(QueueNode *)malloc(sizeof(QueueNode));
	if(temp==NULL) {
		printf("메모리를 할당할 수 없습니다");
		exit(1);
	}
	else {
		temp->item =item;
		temp->link = NULL;
		if(is_empty(q)) {
			q->front = temp;
			q->rear = temp;
		}
		else {
			q->rear->link = temp;
			q->rear = temp;
		}
	}
}
element dequeue(QueueType *q) {
	QueueNode *temp=q->front;
	element item;
	if(is_empty(q)) {
		printf("메모리를 할당할 수 없습니다");
		exit(1);
	}
	else {
		item = temp->item;
		q->front = q->front->link;
		if(q->front==NULL)
			q->rear = NULL;
		free(temp);
		return item;
	}

}
int is_empty(QueueType *q) {
	return (q->front == NULL);
}
#endif