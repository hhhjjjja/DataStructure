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
		fprintf(stderr, "스택 포화 에라\n");
		return;
	}
	else stack[++top] = item;
}
element pop() {
	if(stack_is_empty()) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return stack[top--];
}
element peek() {
	if(stack_is_empty()) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return stack[top];
}
#endif