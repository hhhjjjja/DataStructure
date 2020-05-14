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

�� ������ ���� ��쿡 ���Ͽ� �����Ѵ�.
1) ������ ���� 100��, ���ϴ� ������ ���� 1��, �ؽ� �Լ��� 100���� ���� ���� ū �Ҽ��� �����Լ�
2) ������ ���� 50��, ���ϴ� ������ ���� 2��, �ؼ� �Լ��� 50���� ���� ���� ū �Ҽ��� ���� �Լ�
3) ������ ���� 10��, Ŀ���� ������ ���� 10��, �ؼ� �Լ��� 10�� �����Լ�
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

int overflowcnt, colcnt, keycompcnt, searchcompcnt, removecomcnt=0;	//�����÷ο�, �浹, Ű����Ƚ��, Ž������, ��������

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
   printf("����=100��, ���ϴ� ���Լ�=1��, �ؽ� �Լ�=100���� ���� ���� ū �Ҽ��� �����Լ�\n");
   printf("�浹count : %d \n", colcnt);
   printf("�����÷ο�count : %d \n", overflowcnt);
   printf("Ž�� ���� : %d \n", searchcompcnt);
   printf("���� ���� : %d \n", removecomcnt);
   printf("Ű �� �� : %d \n", keycompcnt);

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
   printf("����=50��, ���ϴ� ���Լ�=2��, �ؽ� �Լ�=50���� ���� ���� ū �Ҽ��� �����Լ�\n");
   printf("�浹count : %d \n", colcnt);
   printf("�����÷ο�count : %d \n", overflowcnt);
   printf("Ž�� ���� : %d \n", searchcompcnt);
   printf("���� ���� : %d \n", removecomcnt);
   printf("Ű �� �� : %d \n", keycompcnt);

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
   printf("����=10��, ���ϴ� ���Լ�=10��, �ؽ� �Լ�=10���� ���� ���� ū �Ҽ��� �����Լ�\n");
   printf("�浹count : %d \n", colcnt);
   printf("�����÷ο�count : %d \n", overflowcnt);
   printf("Ž�� ���� : %d \n", searchcompcnt);
   printf("���� ���� : %d \n", removecomcnt);
   printf("Ű �� �� : %d \n", keycompcnt);

   return 0;
}