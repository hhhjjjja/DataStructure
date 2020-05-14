/*
1) ������ ������ ȭ�鿡 ����ϴ� print_qsort �Լ��� �ۼ��Ѵ�.
��� ����� ÷�� ���ϰ� ���ƾ� �Ѵ�.
���ȣ�⿡ ���Ͽ� ���ҵ� ����Ʈ�� ��µǾ�� �ϸ� �Ǻ����� ���õ� ���� �� ��ȣ�� ǥ�õǾ�� �Ѵ�

2) �� �������� ������ ��������, ��������, �������İ� �̹� ���ĵ� �迭, ������ ���ĵ� �迭, ������ ���ڷ� �������� �⿩�� �迭��
   ���Ͽ� ������ �����Ͽ� �� Ƚ���� ���϶�.

3) [���ʽ�] ����� ������� ������ �������� ��ȯ�� ������� �����Ͻÿ�? */

/*�̹� ���� ���� ������ �ø��� �� �Ʒ� ������ �ּ� ó���Ͽ� �÷��ֽñ� �ٶ��ϴ�.
- ���� ���� ( dev c++ , visual studio 2012 express, etc..)
- ���α׷� ���� ȯ�� (��� os, ram, cpu, gpu )
- �ۼ��� �ڵ��� �ּ� (�� �� �ϼŵ� ������ ���ֽø� �����ϰڽ��ϴ�.)
- �ڵ� ������ ��ó�� ���� �� ( ��ó�� �� ������ �����ϰų� ���� �Ͻø� ������ �����ϴ�. + ����ī�� ����.)
 
�� ������ ���� �ڵ忡 ������ ������ ä������ ����ȯ�濡�� �̻��ϰ� ��µǰų� �ڵ尡 ���� �� ä�� ���Ǹ� ���� �ʰڽ��ϴ�. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 9

int n=0;
int pivot;
int list[MAX_SIZE]={0};
int list1[MAX_SIZE]={5,3,8,4,9,1,6,2,7};

#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))

void print_qsort(int list[], int left, int right, int high) {
	int i;

	for(i=0;i<=right;++i) {
		if(i<left) {
			printf("\t");
		}
		else if(i == high) {
			printf("[%d]\t", list[i]);
		}
		else {
			printf("%d\t", list[i]);
		}
	}
	printf("\n\n");
}

int partition(int list[], int left, int right) {
	int temp;
	int low, high;

	low=left;
	high=right+1;
	pivot=list[left];

	do {
		do {
			low++;
		} while(low <= right && list[low] < pivot);
		do {
			high--;
		} while(high >= left && list[high] > pivot);
		if(low < high) {
			SWAP(list[low], list[high], temp);
		}
	} while(low < high);

	SWAP(list[left], list[high], temp);
	print_qsort(list, left, right, high);
	return high;
}

void quick_sort(int list[], int left, int right) {
	if(left<right) {
		int q=partition(list, left, right);
		quick_sort(list, left, q-1);
		quick_sort(list, q+1, right);
	}
}

int main() {
	int i;
	n = MAX_SIZE;

	printf("<1�� �迭>\n");
	for(i=0;i<n;++i) {
		printf("%d\t", list1[i]);
	}
	printf("\n\n");

	printf("�߰����� ���\n");
	quick_sort(list1, 0, n-1);
	printf("\n");

	printf("������ �� �迭\n");
	for(i=0;i<n;++i) {
		printf("%d\t", list1[i]);
	}
	printf("\n\n\n");

	srand (time(NULL));
	printf("<���� ���� �� �迭>\n");

	for(i=0;i<n;++i) {
		list[i] = rand()%n;
		printf("%d ", list[i]);
	}
	printf("\n\n");

	printf("�߰����� ���\n");
	quick_sort(list, 0, n-1);
	printf("\n");

	printf("������ �� �迭\n");
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
	quick_sort(list, 0, n-1);
	printf("\n");

	printf("������ �� �迭\n");
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
	quick_sort(list, 0, n-1);
	printf("\n");

	printf("������ �� �迭\n");
	for(i=0;i<n;++i) {
		printf("%d\t", list[i]);
	}
}