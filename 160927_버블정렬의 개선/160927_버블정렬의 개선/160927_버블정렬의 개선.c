/*(1) 교재에 제시된 버블정렬 프로그램을 다음과 같이 3가지를 개선한다.
	[1] 플래그를 삽입하여 중간에 정렬이 된 상태를 파악하고 중단
	[2] 정렬되는 중간 과정을 출력
	[3] 비교 횟수를 셀 수 있게 개선

(2) 앞의 (1)과 같이 개선한 후 이전 실습과 과제에서와 마찬가지로 (1) 난수 발생으로 만들어진 임의의 배열,
		 (2)정렬된 배열, (3)역정렬된 배열의 경우에 대하여 각 비교횟수를 출력하여 비교 분석한다. 

(3) 이전 실습의 경우와 비교하여 비교횟수가 어떠한지 분석한다. */

/*이번 공지 이후 과제를 올리실 때 아래 사항을 주석 처리하여 올려주시기 바랍니다.
- 개발 도구 ( dev c++ , visual studio 2012 express, etc..)
- 프로그램 실행 환경 (사용 os, ram, cpu, gpu )
- 작성한 코드의 주석 (꼭 안 하셔도 되지만 해주시면 감사하겠습니다.)
- 코드 참조시 출처를 밝힐 것 ( 출처를 안 밝히고 참조하거나 복붙 하시면 점수가 없습니다. + 과제카피 포함.)
 
위 사항을 어길시 코드에 문제가 없지만 채점자의 실행환경에서 이상하게 출력되거나 코드가 같을 때 채점 이의를 받지 않겠습니다. */

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

	printf("<난수 정렬 전 배열>\n");
	for(i=0;i<n;++i) {
		list[i] = rand()%n;
		printf("%d ", list[i]);
	}
	printf("\n\n");

	printf("중간과정 출력\n");
	bubble_sort(list, n);
	printf("\n");

	printf("버블정렬 후 배열\n");
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
	bubble_sort(list, n);
	printf("\n");

	printf("버블정렬 후 배열\n");
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
	bubble_sort(list, n);
	printf("\n");

	printf("버블정렬 후 배열\n");
	for(i=0;i<n;++i) {
		printf("%d\t", list[i]);
	}
}