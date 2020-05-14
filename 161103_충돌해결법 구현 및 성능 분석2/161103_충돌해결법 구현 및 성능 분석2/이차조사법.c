/*이전 실습/과제에서 해쉬테이블을 구현하였다.
이때 저장함수에서 오버플로우(각 버켓당 슬롯이 1개이면 충돌은 곧 오버플로우가 됨)가
발생하면 저장하지 못하고 버렸다. 이 프로그램을 수정하여 아래와 같은 충돌 해결법
3가지를 각각 적용하여 같은 실험을 실시한다.
이때 오버플로우 횟수는 측정하지 않으며 재해싱에 의하여 발생하는 충돌횟수도 측정하여야 한다. 
리고 버켓의 수는 100개, 버켓당 슬롯의 수는 1개, 해쉬 함수는 100의 제산함수를 사용한다.
* 충돌해결책
1) 선형조사법
2) 이차조사법
3) 이중해싱법 2차 해쉬함수(스테함수)는 C - (k MOD C) , C=11*/
/*이번 공지 이후 과제를 올리실 때 아래 사항을 주석 처리하여 올려주시기 바랍니다.
- 개발 도구 ( dev c++ , visual studio 2012 express, etc..)
- 프로그램 실행 환경 (사용 os, ram, cpu, gpu )
- 작성한 코드의 주석 (꼭 안 하셔도 되지만 해주시면 감사하겠습니다.)
- 코드 참조시 출처를 밝힐 것 ( 출처를 안 밝히고 참조하거나 복붙 하시면 점수가 없습니다. + 과제카피 포함.)
 
위 사항을 어길시 코드에 문제가 없지만 채점자의 실행환경에서 이상하게 출력되거나 코드가 같을 때 채점 이의를 받지 않겠습니다.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define KEY_SIZE 1
#define TABLE_SIZE 100

#define NOT_USED 0
#define BLANK 1
#define USING 2

typedef struct {
	int slot[KEY_SIZE];
	int cnt;
	int flag;
}Hashtable;

Hashtable hashtable[TABLE_SIZE];
int colcnt=0, searchcompcnt=0, addcnt=0, addcomcnt=0, removecomcnt=0, comparecnt=0, tableovcnt=0;
int removecnt=0, searchcnt=0;
void inithash() {
	int i;
	for(i=0;i<100;++i) {
		hashtable[i].cnt = 0;
		hashtable[i].flag = 0;
	}
}
int hash_function(int key) {
	int hash_index = key % TABLE_SIZE;
	if(hash_index < 0) hash_index += TABLE_SIZE;
	return hash_index;
}

void add(int value) {
	int slot=KEY_SIZE;
	int hashvalue=0;
	int index=hashvalue=hash_function(value);
	int inc=0;
	while(hashtable[index].cnt!=0) {
		colcnt++;
		inc = inc+1;
		index=(index+inc*inc)%100;
		if(index==hashvalue) {
			++tableovcnt;
			return;
		}
	}
	++addcomcnt;
	hashtable[index].slot[hashtable[index].cnt]=value;
	++(hashtable[index].cnt);
	(hashtable[index].flag) = USING;
}
int search(int value, int searchflag) {
	int slot=KEY_SIZE;
	int hashvalue=0;
	int index=hashvalue= hash_function(value);
	int inc=0;
	while(hashtable[index].cnt != 0 || hashtable[index].flag == BLANK) {
		if(searchflag) ++searchcnt;
		if(hashtable[index].slot[0] == value) {
			if(searchflag) ++searchcompcnt;
			return index;
		}
		inc = inc+1;
		index=(index+inc*inc)%100;
		if(index==hashvalue) return -1;
	}
	return -1;
}
void delete_hash(int value) {
	int slot = KEY_SIZE;
	int i, removeIndex = search(value, 0);
	if(removeIndex == -1) return ;
	++removecomcnt;
	++removecnt;
	--(hashtable[removeIndex].cnt);
	hashtable[removeIndex].flag = BLANK;
	for(i=removeIndex;i<slot-1;++i) {
		hashtable[i] = hashtable[i+1];
	}
}
int main() {
	int i, x, y;
	inithash();
	srand (time(NULL));
	for(i=0;i<400;++i) {
		x=rand()%1001;
		y=rand()%1001;
		if(x%4==0 || x%4==1) {
			addcnt++;
			add(y);
		}
		else if(x%4==2) {
			delete_hash(y);
		}
		else if(x%4==3) {
			search(y, 1);
		}
	}
	printf("저장 시도 : %d, 성공 : %d\n", addcnt, addcomcnt);
	printf("충돌 COUNT : %d\n", colcnt);
	printf("tableovercount : %d\n", tableovcnt);
	printf("탐색 실행 : %d, 성공 : %d\n", searchcnt, searchcompcnt);
	printf("삭제 실행 : %d, 성공 : %d\n", removecnt, removecomcnt);

	return 0;
}