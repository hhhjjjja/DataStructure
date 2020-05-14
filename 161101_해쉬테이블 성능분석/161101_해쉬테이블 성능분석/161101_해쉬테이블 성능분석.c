/*다음과 같은 과정을 400번 수행한다.
---------------------------------------------------
1) x = 0에서 1,000까지의 난수
2) y = 0에서 1,000까지의 난수
3) x를 4으로 나눈 나머지에 따라서 다음을 수행
[0] 나머지가 0 또는 1 인 경우 y를 해쉬테이블에 삽입
[1] 나머지가 2인 경우 y를 해쉬테이블에서 삭제
[2] 나머지가 3인 경우 y를 해쉬테이블에서 탐색
------------------------------------------------
저장할 때 오버플로우가 발생하면 저장될 값을 저장하지 않고 버린다.

위 과정을 다음 경우에 대하여 수행한다.
1) 버켓의 수는 100개, 버켓당 슬롯의 수는 1개, 해쉬 함수는 100보다 작은 가장 큰 소수의 제산함수
2) 버켓의 수는 50개, 버켓당 슬롯의 수는 2개, 해수 함수는 50보다 작은 가장 큰 소수의 제산 함수
3) 버켓의 수는 10개, 커벳당 슬롯의 수는 10개, 해수 함수는 10의 제산함수
4) 버켓의 수는 50개, 버켓당 슬롯의 수는 2개, 해쉬함수는 2자리 이동 폴딩 후 50으로 나눈 나머지

위와 같이 4가지 경우에 대하여 다음 횟수를 출력한다.
1) 저장의 경우에 발생하는 충돌횟수, 오버플로우 횟수
2) 삭제와 탐색의 경우 삭제와 탐색 성공 횟수, 총 키값 비교 횟수

위의 출력을 분석한 의견을 간단하게 제시한다.*/

/*이번 공지 이후 과제를 올리실 때 아래 사항을 주석 처리하여 올려주시기 바랍니다.
- 개발 도구 ( dev c++ , visual studio 2012 express, etc..)
- 프로그램 실행 환경 (사용 os, ram, cpu, gpu )
- 작성한 코드의 주석 (꼭 안 하셔도 되지만 해주시면 감사하겠습니다.)
- 코드 참조시 출처를 밝힐 것 ( 출처를 안 밝히고 참조하거나 복붙 하시면 점수가 없습니다. + 과제카피 포함.)
 
위 사항을 어길시 코드에 문제가 없지만 채점자의 실행환경에서 이상하게 출력되거나 코드가 같을 때 채점 이의를 받지 않겠습니다.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	int slot[1];
	int cnt;
}Hashtable1;
typedef struct {
	int slot[2];
	int cnt;
}Hashtable2;
typedef struct {
	int slot[10];
	int cnt;
}Hashtable3;

int overflowcnt, colcnt, keycompcnt, searchcompcnt, removecomcnt=0;	//오버플로우, 충돌, 키값비교횟수, 탐색성공, 삭제성공

Hashtable1 hashtable1[100];
void inithash1() {
	int i;
	for(i=0;i<100;++i) {
		hashtable1[i].cnt=0;
	}
}
void add1(int value) {
	int index = hash_function1(value);
	int slotcnt = 1;
	if(hashtable1[index].cnt >= 1) {
		if(hashtable1[index].cnt >= slotcnt) {
			overflowcnt++;
			return;
		}
		colcnt++;
	}
	hashtable1[index].slot[hashtable1[index].cnt] = value;
	(hashtable1[index].cnt)++;
}
int delete_hash1(int value) {
	int slotcnt = 1;
	int i, removeIndex = search1(value, 0);
	if(removeIndex == -1) return;
	removecomcnt++;
	(hashtable1[removeIndex].cnt)--;
	for(i=removeIndex;i<slotcnt-1;++i) {
		hashtable1[i] = hashtable1[i+1];
	}
}
int search1(int value, int searchf) {
	int i;
	int slot = 1;
	for(i=0;i<slot;++i) {
		keycompcnt++;
		if(value == hashtable1[hash_function1(value)].slot[i]) {
			if(searchf) searchcompcnt++;
			return i;
		}
	}
	return -1;
}
int hash_function1(int key) {
	int hash_index = key % 97;
	if(hash_index < 0) hash_index += 97;
	return hash_index;
}

Hashtable2 hashtable2[50];
void inithash2() {
	int i;
	for(i=0;i<50;++i) {
		hashtable2[i].cnt=0;
	}
}
void add2(int value) {
	int index = hash_function2(value);
	int slotcnt = 2;
	if(hashtable2[index].cnt >= 2) {
		if(hashtable1[index].cnt >= slotcnt) {
			overflowcnt++;
			return;
		}
		colcnt++;
	}
	hashtable2[index].slot[hashtable2[index].cnt] = value;
	(hashtable2[index].cnt)++;
}
int delete_hash2(int value) {
	int slotcnt = 2;
	int i, removeIndex = search2(value, 0);
	if(removeIndex == -1) return;
	removecomcnt++;
	(hashtable2[removeIndex].cnt)--;
	for(i=removeIndex;i<slotcnt-1;++i) {
		hashtable2[i] = hashtable2[i+1];
	}
}
int search2(int value, int searchf) {
	int i;
	int slot = 2;
	for(i=0;i<slot;++i) {
		keycompcnt++;
		if(value == hashtable2[hash_function2(value)].slot[i]) {
			if(searchf) searchcompcnt++;
			return i;
		}
	}
	return -1;
}
int hash_function2(int key) {
	int hash_index = key % 47;
	if(hash_index < 0) hash_index += 47;
	return hash_index;
}


Hashtable3 hashtable3[10];
void inithash3() {
	int i;
	for(i=0;i<10;++i) {
		hashtable3[i].cnt=0;
	}
}
int hash_function3(int key) {
	int hash_index = key % 7;
	if(hash_index < 0) hash_index += 7;
	return hash_index;
}
void add3(int value) {
	int index = hash_function3(value);
	int slotcnt = 10;
	if(hashtable3[index].cnt >= 10) {
		if(hashtable3[index].cnt >= slotcnt) {
			overflowcnt++;
			return;
		}
		colcnt++;
	}
	hashtable3[index].slot[hashtable3[index].cnt] = value;
	(hashtable3[index].cnt)++;
}
int delete_hash3(int value) {
	int slotcnt = 10;
	int i, removeIndex = search3(value, 0);
	if(removeIndex == -1) return;
	removecomcnt++;
	(hashtable3[removeIndex].cnt)--;
	for(i=removeIndex;i<slotcnt-1;++i) {
		hashtable3[i] = hashtable3[i+1];
	}
}
int search3(int value, int searchf) {
	int i;
	int slot = 10;
	for(i=0;i<slot;++i) {
		keycompcnt++;
		if(value == hashtable3[hash_function3(value)].slot[i]) {
			if(searchf) searchcompcnt++;
			return i;
		}
	}
	return -1;
}

int main() {
	int i, x, y;
	inithash1();
	srand (time(NULL));
	for(i=0;i<400;++i) {
		x=rand()%1001;
		y=rand()%1001;
		if(x%4==0 || x%4==1) {
			add1(y);
		}
		else if(x%4==2) {
			delete_hash1(y);
		}
		else if(x%4==3) {
			search1(y, 1);
		}
	}
   printf("버켓=100개, 버켓당 슬롯수=1개, 해쉬 함수=100보다 작은 가장 큰 소수의 제산함수\n");
   printf("충돌count : %d \n", colcnt);
   printf("오버플로우count : %d \n", overflowcnt);
   printf("탐색 성공 : %d \n", searchcompcnt);
   printf("삭제 성공 : %d \n", removecomcnt);
   printf("키 값 비교 : %d \n", keycompcnt);

   inithash2();
   for(i=0;i<400;++i) {
		x=rand()%1001;
		y=rand()%1001;
		if(x%4==0 || x%4==1) {
			add2(y);
		}
		else if(x%4==2) {
			delete_hash2(y);
		}
		else if(x%4==3) {
			search2(y, 1);
		}
	}
   printf("\n------------------------------------------------------------------------------\n");
   printf("버켓=50개, 버켓당 슬롯수=2개, 해쉬 함수=50보다 작은 가장 큰 소수의 제산함수\n");
   printf("충돌count : %d \n", colcnt);
   printf("오버플로우count : %d \n", overflowcnt);
   printf("탐색 성공 : %d \n", searchcompcnt);
   printf("삭제 성공 : %d \n", removecomcnt);
   printf("키 값 비교 : %d \n", keycompcnt);

   inithash3();
   for(i=0;i<400;++i) {
		x=rand()%1001;
		y=rand()%1001;
		if(x%4==0 || x%4==1) {
			add3(y);
		}
		else if(x%4==2) {
			delete_hash3(y);
		}
		else if(x%4==3) {
			search3(y, 1);
		}
	}
   printf("\n------------------------------------------------------------------------------\n");
   printf("버켓=10개, 버켓당 슬롯수=10개, 해쉬 함수=10보다 작은 가장 큰 소수의 제산함수\n");
   printf("충돌count : %d \n", colcnt);
   printf("오버플로우count : %d \n", overflowcnt);
   printf("탐색 성공 : %d \n", searchcompcnt);
   printf("삭제 성공 : %d \n", removecomcnt);
   printf("키 값 비교 : %d \n", keycompcnt);

   return 0;
}