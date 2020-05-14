/*���� �ǽ�/�������� �ؽ����̺��� �����Ͽ���.
�̶� �����Լ����� �����÷ο�(�� ���ϴ� ������ 1���̸� �浹�� �� �����÷ο찡 ��)��
�߻��ϸ� �������� ���ϰ� ���ȴ�. �� ���α׷��� �����Ͽ� �Ʒ��� ���� �浹 �ذ��
3������ ���� �����Ͽ� ���� ������ �ǽ��Ѵ�.
�̶� �����÷ο� Ƚ���� �������� ������ ���ؽ̿� ���Ͽ� �߻��ϴ� �浹Ƚ���� �����Ͽ��� �Ѵ�. 
���� ������ ���� 100��, ���ϴ� ������ ���� 1��, �ؽ� �Լ��� 100�� �����Լ��� ����Ѵ�.
* �浹�ذ�å
1) ���������
2) ���������
3) �����ؽ̹� 2�� �ؽ��Լ�(�����Լ�)�� C - (k MOD C) , C=11*/
/*�̹� ���� ���� ������ �ø��� �� �Ʒ� ������ �ּ� ó���Ͽ� �÷��ֽñ� �ٶ��ϴ�.
- ���� ���� ( dev c++ , visual studio 2012 express, etc..)
- ���α׷� ���� ȯ�� (��� os, ram, cpu, gpu )
- �ۼ��� �ڵ��� �ּ� (�� �� �ϼŵ� ������ ���ֽø� �����ϰڽ��ϴ�.)
- �ڵ� ������ ��ó�� ���� �� ( ��ó�� �� ������ �����ϰų� ���� �Ͻø� ������ �����ϴ�. + ����ī�� ����.)
 
�� ������ ���� �ڵ忡 ������ ������ ä������ ����ȯ�濡�� �̻��ϰ� ��µǰų� �ڵ尡 ���� �� ä�� ���Ǹ� ���� �ʰڽ��ϴ�.*/

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
	printf("���� �õ� : %d, ���� : %d\n", addcnt, addcomcnt);
	printf("�浹 COUNT : %d\n", colcnt);
	printf("tableovercount : %d\n", tableovcnt);
	printf("Ž�� ���� : %d, ���� : %d\n", searchcnt, searchcompcnt);
	printf("���� ���� : %d, ���� : %d\n", removecnt, removecomcnt);

	return 0;
}