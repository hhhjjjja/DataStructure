/*	50���� ������ �� �ִ� �迭�� ����� ������ ���� 50���� ����� �����Ѵ�.
�̶� ����Ǵ� ������ ũ��� 0~99�̾�� �Ѵ�. �迭�� ����� ���ڸ� 9�忡�� ������ ����� ����Ͽ� �����Ѵ�.
0~99������ ������ ���ڸ� �߻�Ű�Ѽ� ����Ž��, ����Ž��, ����Ž���� 20�� �ǽ��Ѵ�.
�� Ž���� �ǽ��� ���� ��Ƚ���� ����Ͽ� ������ �����ϰ� �м��Ѵ�. ����Ž���� �� ������ ũ��� 5�� �Ѵ�.*/

/*- ���� ���� ( dev c++ , visual studio 2012 express, etc..)
- ���α׷� ���� ȯ�� (��� os, ram, cpu, gpu )
- �ۼ��� �ڵ��� �ּ� (�� �� �ϼŵ� ������ ���ֽø� �����ϰڽ��ϴ�.)
- �ڵ� ������ ��ó�� ���� �� ( ��ó�� �� ������ �����ϰų� ���� �Ͻø� ������ �����ϴ�. + ����ī�� ����.) */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50
#define INDEX_SIZE 5
#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))
typedef struct {
	int key;
	int index;
}itable;

itable index_list[INDEX_SIZE];
int list[MAX]={0,};
int pivot;
int binarycnt;
int indexedseqcnt[20];
int interpolationcnt;

int binary_search(int key, int low, int high, int index) {
	int middle;
	while(low <= high) {
		++binarycnt;
		middle = (low+high)/2;
		if(key == list[middle]) {
			return middle;
		}
		else if(key > list[middle]) {
			low =middle+1;
		}
		else {
			high = middle-1;
		}
	}
	return -1;
}
int seq_search(int key, int low, int high, int index) {
	int i;
	list[high] = key;
	for(i=low; list[i] != key; ++i) {
		++indexedseqcnt[index];
	}
	if(i==(high)) return -1;
	else return i;
}
int search_index(int key, int index) {
	int i, low, high;
	if(key<list[0] || key>list[MAX-1]) {
		++indexedseqcnt[index];
		return -1;
	}
	for(i=0;i<INDEX_SIZE;++i) {
		++indexedseqcnt[index];
		if(index_list[i].key <= key && index_list[i+1].key>key) {
			break;
		}
	}
	if(i==INDEX_SIZE) {
		low = index_list[i-1].index;
		high = MAX-1;
	}
	else {
		low = index_list[i].index;
		high = index_list[i+1].index-1;
	}
	return seq_search(key, low, high, i);
}
int search_interpolation(int key, int n) {
	int low, high, j;
	low = 0;
	high = n-1;
	++interpolationcnt;
	while((list[high] >= key) && (key > list[low])) {
		++interpolationcnt;
		j = ((float)(key-list[low])/(list[high]-list[low]) * (high-low)) + low;
		if(key > list[j]) {
			low = j+1;
		}
		else if(key < list[j]) {
			high = j-1;
		}
		else {
			low = j;
		}
	}
	if(list[low] == key) return(low);
	else return -1;
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
	int a=0;
	srand ((unsigned int)time(NULL));
	for(i=0;i<MAX;++i) {
		list[i] = rand()%100;
		printf("%d ", list[i]);
	}
	printf("\n<����Ž��>\n");
	quick_sort(list, 0, 49);

	for(i=0;i<20;++i) {
		a = rand()%100;
		binary_search(a, 0, 49, i);
		printf("%d ��Ƚ�� : %d\n", i+1, binarycnt);
		binarycnt=0;
	}

	printf("\n<����Ž��>\n");
	index_list[0].index = 0;
	index_list[0].key = list[0];
	index_list[1].index = 10;
	index_list[1].key = list[10];
	index_list[2].index = 20;
	index_list[2].key = list[20];
	index_list[3].index = 30;
	index_list[3].key = list[30];
	index_list[4].index = 40;
	index_list[4].key = list[40];

	for(i=0;i<20;++i) {
		a = rand()%100;
		search_index(a, i);
		printf("%d ��Ƚ�� : %d\n", i+1, indexedseqcnt[i]);
	}
	printf("\n<����Ž��>\n");
	for(i=0;i<20;++i) {
		a = rand()%100;
		search_interpolation(a, MAX);
		printf("%d ��Ƚ�� : %d\n", i+1, interpolationcnt);
		interpolationcnt=0;
	}
	return 0;
}