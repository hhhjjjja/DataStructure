/*(1) ���翡 ���õ� �������� ���α׷��� ������ ���� 3������ �����Ѵ�.
	[1] �÷��׸� �����Ͽ� �߰��� ������ �� ���¸� �ľ��ϰ� �ߴ�
	[2] ���ĵǴ� �߰� ������ ���
	[3] �� Ƚ���� �� �� �ְ� ����

(2) ���� (1)�� ���� ������ �� ���� �ǽ��� ���������� ���������� (1) ���� �߻����� ������� ������ �迭,
		 (2)���ĵ� �迭, (3)�����ĵ� �迭�� ��쿡 ���Ͽ� �� ��Ƚ���� ����Ͽ� �� �м��Ѵ�. 

(3) ���� �ǽ��� ���� ���Ͽ� ��Ƚ���� ����� �м��Ѵ�. */

/*�̹� ���� ���� ������ �ø��� �� �Ʒ� ������ �ּ� ó���Ͽ� �÷��ֽñ� �ٶ��ϴ�.
- ���� ���� ( dev c++ , visual studio 2012 express, etc..)
- ���α׷� ���� ȯ�� (��� os, ram, cpu, gpu )
- �ۼ��� �ڵ��� �ּ� (�� �� �ϼŵ� ������ ���ֽø� �����ϰڽ��ϴ�.)
- �ڵ� ������ ��ó�� ���� �� ( ��ó�� �� ������ �����ϰų� ���� �Ͻø� ������ �����ϴ�. + ����ī�� ����.)
 
�� ������ ���� �ڵ忡 ������ ������ ä������ ����ȯ�濡�� �̻��ϰ� ��µǰų� �ڵ尡 ���� �� ä�� ���Ǹ� ���� �ʰڽ��ϴ�. */

#include <stdio.h>
#include <stdlib.h>
#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))
#define MAX_SIZE 10

int list[MAX_SIZE];
int n=0;

void bubble_sort(int list[], int n) {
	int i, j, temp, flag, a;
	int count=0;

	for(i=n-1;i>0;--i) {
		flag=0;
		for(j=0;j<i;++j) {
			count++;
			if(list[j]>list[j+1]) {
				SWAP(list[j], list[j+1], temp);
				flag=1;
				for(a=0;a<n;++a) {
					printf("%d\t", list[a]);
				}
				printf("\n");
			}
		}
		if(flag==0) break;
	}
	printf("\n");
	printf("count : %d\n", count);
}

int main() {
	int i;
	n = MAX_SIZE;

	printf("<���� ���� �� �迭>\n");
	for(i=0;i<n;++i) {
		list[i] = rand()%n;
		printf("%d ", list[i]);
	}
	printf("\n\n");

	printf("�߰����� ���\n");
	bubble_sort(list, n);
	printf("\n");

	printf("�������� �� �迭\n");
	for(i=0;i<n;++i) {
		printf("%d\t", list[i]);
	}
	printf("\n\n\n");



	printf("<���ĵ� �迭>\n");
	for(i=0;i<n;++i) {
		list[i]=i;
		printf("%d ", list[i]);
	}
	printf("\n\n");

	printf("�߰����� ���\n");
	bubble_sort(list, n);
	printf("\n");

	printf("�������� �� �迭\n");
	for(i=0;i<n;++i) {
		printf("%d\t", list[i]);
	}
	printf("\n\n\n");



	printf("<�����ĵ� �迭>\n");
	for(i=0;i<n;++i) {
		list[i]=n-i;
		printf("%d ", list[i]);
	}
	printf("\n\n");

	printf("�߰����� ���\n");
	bubble_sort(list, n);
	printf("\n");

	printf("�������� �� �迭\n");
	for(i=0;i<n;++i) {
		printf("%d\t", list[i]);
	}
}