/*������ ���� ������ 400�� �����Ѵ�.
---------------------------------------------------
1) x = 0���� 1,000������ ����
2) y = 0���� 1,000������ ����
3) x�� 4���� ���� �������� ���� ������ ����
[0] �������� 0 �Ǵ� 1 �� ��� y�� �ؽ����̺� ����
[1] �������� 2�� ��� y�� �ؽ����̺��� ����
[2] �������� 3�� ��� y�� �ؽ����̺��� Ž��
------------------------------------------------
������ �� �����÷ο찡 �߻��ϸ� ����� ���� �������� �ʰ� ������.

4) ������ ���� 50��, ���ϴ� ������ ���� 2��, �ؽ��Լ��� 2�ڸ� �̵� ���� �� 50���� ���� ������

���� ���� 4���� ��쿡 ���Ͽ� ���� Ƚ���� ����Ѵ�.
1) ������ ��쿡 �߻��ϴ� �浹Ƚ��, �����÷ο� Ƚ��
2) ������ Ž���� ��� ������ Ž�� ���� Ƚ��, �� Ű�� �� Ƚ��

���� ����� �м��� �ǰ��� �����ϰ� �����Ѵ�.*/

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

#define BUCKETCNT 50
#define SLOTCNT 2

typedef struct {
	int slot[SLOTCNT];
	int cnt;
}Hashtable;

Hashtable hashtable[BUCKETCNT];
int overflowcnt, colcnt, keycompcnt, searchcompcnt, removecomcnt=0;	//�����÷ο�, �浹, Ű����Ƚ��, Ž������, ��������

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
   printf("����=50��, ���ϴ� ���Լ�=2��, �ؽ��Լ�=2�ڸ� �̵� ���� �� 50���� ���� ������\n");
   printf("�浹count : %d\n", colcnt);
   printf("�����÷ο�count : %d\n", overflowcnt);
   printf("Ž�� ���� : %d\n", searchcompcnt);
   printf("���� ���� : %d\n", removecomcnt);
   printf("Ű �� �� : %d\n", keycompcnt);
   return 0;
}