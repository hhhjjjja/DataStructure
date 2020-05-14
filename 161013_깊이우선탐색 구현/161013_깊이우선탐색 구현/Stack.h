#ifndef STACK_H
#define STACK_H

#define MAX_STACK_SIZE 50
typedef int element;
element stack[MAX_STACK_SIZE];
int top=-1;

int is_full() {
	return (top==(MAX_STACK_SIZE-1));
}
int stack_is_empty() {
	return (top==-1);
}
void push(element item) {
	if(is_full()) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else stack[++top] = item;
}
element pop() {
	if(stack_is_empty()) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return stack[top--];
}
element peek() {
	if(stack_is_empty()) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return stack[top];
}
#endif