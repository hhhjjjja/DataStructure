/*
1) 퀵정렬 과정을 화면에 출력하는 print_qsort 함수를 작성한다.
출력 결과는 첨부 파일과 같아야 한다.
재귀호출에 의하여 분할된 리스트가 출력되어야 하며 피봇으로 선택된 값은 각 괄호에 표시되어야 한다

2) 앞 과제에서 구현한 선택정렬, 삽입정렬, 버블정렬과 이미 정렬된 배열, 역으로 정렬된 배열, 임의의 숫자로 무작위로 썩여진 배열에
   대하여 정렬을 실행하여 비교 횟수를 비교하라.

3) [보너스] 재귀적 방법으로 구현된 퀵정렬을 순환적 방법으로 구현하시오? */

/*이번 공지 이후 과제를 올리실 때 아래 사항을 주석 처리하여 올려주시기 바랍니다.
- 개발 도구 ( dev c++ , visual studio 2012 express, etc..)
- 프로그램 실행 환경 (사용 os, ram, cpu, gpu )
- 작성한 코드의 주석 (꼭 안 하셔도 되지만 해주시면 감사하겠습니다.)
- 코드 참조시 출처를 밝힐 것 ( 출처를 안 밝히고 참조하거나 복붙 하시면 점수가 없습니다. + 과제카피 포함.)
 
위 사항을 어길시 코드에 문제가 없지만 채점자의 실행환경에서 이상하게 출력되거나 코드가 같을 때 채점 이의를 받지 않겠습니다. */

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

	printf("<1번 배열>\n");
	for(i=0;i<n;++i) {
		printf("%d\t", list1[i]);
	}
	printf("\n\n");

	printf("중간과정 출력\n");
	quick_sort(list1, 0, n-1);
	printf("\n");

	printf("퀵정렬 후 배열\n");
	for(i=0;i<n;++i) {
		printf("%d\t", list1[i]);
	}
	printf("\n\n\n");

	srand (time(NULL));
	printf("<난수 정렬 전 배열>\n");

	for(i=0;i<n;++i) {
		list[i] = rand()%n;
		printf("%d ", list[i]);
	}
	printf("\n\n");

	printf("중간과정 출력\n");
	quick_sort(list, 0, n-1);
	printf("\n");

	printf("퀵정렬 후 배열\n");
	for(i=0;i<n;++i) {
		printf("%d\t", list[i]);
	}
	printf("\n\n\n");

	
	printf("<정렬된 배열>\n");
	for(i=0;i<n;++i) {
		list[i]=i;
		printf("%d ", list[i]);
	}
	printf("\n\n");

	printf("중간과정 출력\n");
	quick_sort(list, 0, n-1);
	printf("\n");

	printf("퀵정렬 후 배열\n");
	for(i=0;i<n;++i) {
		printf("%d\t", list[i]);
	}
	printf("\n\n\n");



	printf("<역정렬된 배열>\n");
	for(i=0;i<n;++i) {
		list[i]=n-i;
		printf("%d ", list[i]);
	}
	printf("\n\n");

	printf("중간과정 출력\n");
	quick_sort(list, 0, n-1);
	printf("\n");

	printf("퀵정렬 후 배열\n");
	for(i=0;i<n;++i) {
		printf("%d\t", list[i]);
	}
}