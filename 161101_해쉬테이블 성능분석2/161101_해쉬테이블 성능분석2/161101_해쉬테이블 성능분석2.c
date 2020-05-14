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
#include <string.h>
#include <time.h>

#define BUCKETCNT 50
#define SLOTCNT 2

typedef struct {
	int slot[SLOTCNT];
	int cnt;
}Hashtable;

Hashtable hashtable[BUCKETCNT];
int overflowcnt, colcnt, keycompcnt, searchcompcnt, removecomcnt=0;	//오버플로우, 충돌, 키값비교횟수, 탐색성공, 삭제성공

void inithash() {
	int i;
	for(i=0;i<BUCKETCNT;++i) {
		hashtable[i].cnt = 0;
	}
}
int move_folding(int key) {
	int i;
	char str[256] = {0};
	char tmp[3] = {0};
	int result=0, tempcnt=0, length=0;
	itoa(key, str, 10);
	length = strlen(str);

	for(i=0;i<length;++i) {
		tmp[tempcnt] = str[i];
		tempcnt++;
		if(tempcnt == 2 || i == length-1) {
			result += atoi(tmp);
			tempcnt = 0;
			memset(tmp, 0, sizeof(tmp));
		}
	}
	return result % 50;
}
void add(int value) {
	int key = move_folding(value);
	int slotcnt = SLOTCNT;
	if(hashtable[key].cnt >= 1) {
		if(hashtable[key].cnt >= slotcnt) {
			++overflowcnt;
			return;
		}
		++colcnt;
	}
	hashtable[key].slot[hashtable[key].cnt] = value;
	++(hashtable[key].cnt);
}
int search(int value, int sflag) {
	int i;
	int slot = SLOTCNT;
	for(i=0;i<slot;++i) {
		keycompcnt++;
		if(value == hashtable[move_folding(value)].slot[i]) {
			if(sflag) searchcompcnt++;
			return i;
		}
	}
	return -1;
}
void delete_hash(int value) {
	int slotcnt = SLOTCNT;
	int i, removeIndex = search(value, 0);
	if(removeIndex == -1) return;
	++removecomcnt;
	--(hashtable[removeIndex].cnt);
	for(i = removeIndex ; i < slotcnt-1 ; ++i) {
		hashtable[i] = hashtable[i+1];
	}
}
int main() {
	int i, x, y;
	inithash();
	srand ((unsigned int)time(NULL));
	
	for(i=0;i<400;++i) {
		x=rand()%1001;
		y=rand()%1001;
		if(x%4==0 || x%4==1) {
			add(y);
		}
		else if(x%4==2) {
			delete_hash(y);
		}
		else if(x%4==3) {
			search(y, 1);
		}
	}
   printf("버켓=50개, 버켓당 슬롯수=2개, 해쉬함수=2자리 이동 폴딩 후 50으로 나눈 나머지\n");
   printf("충돌count : %d\n", colcnt);
   printf("오버플로우count : %d\n", overflowcnt);
   printf("탐색 성공 : %d\n", searchcompcnt);
   printf("삭제 성공 : %d\n", removecomcnt);
   printf("키 값 비교 : %d\n", keycompcnt);
   return 0;
}