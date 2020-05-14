/*÷���� ������ ������ ����ö �� ��ö �뼱���̴�.

1) �뼱���� ����ġ �׷����� ǥ���Ѵ�. ������ �� �뼱�� ������ ���� ����Ÿ�� ���̸� ������ ����ġ�� �� ������ �� �����̴�.
���￪���� �����ϴ� ���� �켱 Ž���� �ǽ��Ѵ�. Ž�� ����� ����Ͽ� ��� �������� ����Ÿ�� ���� ��µǴ��� Ȯ���Ѵ�.

2) ����ö/��ö �뼱�� ���� ��� ���� �����ϴ� ���ͳ� ��Ÿ��� �����Ϸ��� �Ѵ�.
�̶� �ּ� ���(�������� ���� ���ڸ� �ּҷ�)���� �����ϴ� ���ᵵ�� ���ϴ� ���α׷��� �ۼ��Ѵ�.
���ᵵ�� ������ ������� ��µǾ�� �Ѵ�. ���� ��� ���ᵵ�� ��õ�������װ� ��籸���� ���ԵǸ� (��õ��������--���: 4)�� ��µǾ�� �Ѵ�.*/

/*�̹� ���� ���� ������ �ø��� �� �Ʒ� ������ �ּ� ó���Ͽ� �÷��ֽñ� �ٶ��ϴ�.
- ���� ���� ( dev c++ , visual studio 2012 express, etc..)
- ���α׷� ���� ȯ�� (��� os, ram, cpu, gpu )
- �ۼ��� �ڵ��� �ּ� (�� �� �ϼŵ� ������ ���ֽø� �����ϰڽ��ϴ�.)
- �ڵ� ������ ��ó�� ���� �� ( ��ó�� �� ������ �����ϰų� ���� �Ͻø� ������ �����ϴ�. + ����ī�� ����.)
 
�� ������ ���� �ڵ忡 ������ ������ ä������ ����ȯ�濡�� �̻��ϰ� ��µǰų� �ڵ尡 ���� �� ä�� ���Ǹ� ���� �ʰڽ��ϴ�.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_VERTICS 300
#define INF 1000
#define MAX_ELEMENT 300
int parent[MAX_VERTICS];
int num[MAX_VERTICS];

void set_init(int n)
{
   int i;
   for(i=0; i<n; i++) {
      parent[i] = -1;
      num[i] = 1;
   }
}
int set_find(int vertex) {
   int p,s,i=-1;
   for(i=vertex;(p=parent[i])>=0; i=p) ;
   s=i;
   for(i=vertex;(p=parent[i])>=0;i=p) {
      parent[i]=s;
   }
   return s;
}
void set_union(int s1,int s2) {
   if(num[s1] < num[s2]) {
      parent[s1] = s2;
      num[s2] += num[s1];
   }
   else {
      parent[s2] = s1;
      num[s1] += num[s2];
   }
}
typedef struct {
   int key;
   int u;
   int v;
   char sub1[30];
   char sub2[30];
}element;

typedef struct {
   element heap[MAX_ELEMENT];
   int heap_size;
}HeapType;

void heap_init(HeapType *h) {
   h->heap_size = 0;
}
int heap_is_empty(HeapType *h) {
   if(h->heap_size == 0) return 1;
   else return 0;
}

void insert_min_heap(HeapType *h,element item) {
   int i;
   i = ++(h->heap_size);
   while((i!=1) && (item.key < h->heap[i/2].key)) {
      h->heap[i] = h->heap[i/2];
      i/=2;
   }
   h->heap[i] = item;
}

element delete_min_heap(HeapType *h) {
   int parent, child;
   element item, temp;

   item = h->heap[1];
   temp = h->heap[(h->heap_size)--];
   parent = 1;
   child = 2;
   while(child <= h->heap_size) {
      if((child <= h->heap_size)&&(h->heap[child].key)>=h->heap[child+1].key) child ++;
      if(temp.key <= h->heap[child].key) break;
      h->heap[parent] = h->heap[child];
      parent = child;
      child *= 2;
   }
   h->heap[parent] = temp;
   return item;
}
void insert_heap_edge(HeapType *h, int u, int v, int weight,char Sub1[],char Sub2[]) {
   element e;
   e.u = u;
   e.v = v;
   e.key = weight;
   strcpy(e.sub1 , Sub1);
   strcpy(e.sub2 , Sub2);
   insert_min_heap(h,e);
}
void insert_all_edges(HeapType *h)
{
   insert_heap_edge(h, 0, 1, 13,"�ҿ��","������"); insert_heap_edge(h, 1, 2, 3,"������","â��"); insert_heap_edge(h, 2, 3, 4,"â��","����");
   insert_heap_edge(h, 3, 4, 3,"����","ȸ��"); insert_heap_edge(h, 4, 5, 3,"ȸ��","�ż���"); insert_heap_edge(h, 5, 6, 1,"�ż���","������");
   insert_heap_edge(h, 6, 7, 1,"������","���빮"); insert_heap_edge(h, 7, 8, 2,"���빮","����3��"); insert_heap_edge(h, 8, 9, 1,"����3��","��û");
   insert_heap_edge(h, 9, 10, 1,"��û","���￪"); insert_heap_edge(h, 10, 11, 2,"���￪","���"); insert_heap_edge(h, 11, 12, 3,"���","�ű�");
   insert_heap_edge(h, 12, 13, 2,"�ű�","�ŵ���"); insert_heap_edge(h, 13, 14, 1,"�ŵ���","����"); insert_heap_edge(h, 14, 15, 4,"����","�¼�");
   insert_heap_edge(h, 15, 16, 7,"�¼�","����"); insert_heap_edge(h, 16, 17, 9,"����","��õ"); insert_heap_edge(h, 14, 18, 1,"����","���� �����д���");
   insert_heap_edge(h, 18, 19, 3,"���� �����д���","����"); insert_heap_edge(h, 18, 20, 7,"���� �����д���","����"); insert_heap_edge(h, 20, 21, 19,"����","õ��"); //1ȣ�� 18

   insert_heap_edge(h, 22, 23, 3,"����","���"); insert_heap_edge(h, 23, 24, 7,"���","�븲"); insert_heap_edge(h, 24, 13, 1,"�븲","�ŵ���");
   insert_heap_edge(h, 13, 25, 4,"�ŵ���","��ġ��"); insert_heap_edge(h, 13, 26, 2,"�ŵ���","��������û"); insert_heap_edge(h, 26, 27, 2,"��������û","����");
   insert_heap_edge(h, 27, 28, 5,"����","������"); insert_heap_edge(h, 28, 9, 1,"������","��û"); insert_heap_edge(h, 9, 29, 2,"��û","������3��");
   insert_heap_edge(h, 29, 30, 1,"������3��","������4��"); insert_heap_edge(h, 30, 31, 1,"������4��","���빮���"); insert_heap_edge(h, 31, 32, 1,"���빮���","�Ŵ�");
   insert_heap_edge(h, 32, 33, 2,"�Ŵ�","�սʸ�"); insert_heap_edge(h, 33, 34, 2,"�սʸ�","����"); insert_heap_edge(h, 34, 35, 1,"����","�Ǵ��Ա�");
   insert_heap_edge(h, 35, 36, 4,"�Ǵ��Ա�","���"); insert_heap_edge(h, 36, 37, 4,"���","����"); insert_heap_edge(h, 37, 22, 3,"����","����"); //2ȣ�� 18

   insert_heap_edge(h, 38, 39, 11,"��ȭ","���ų�"); insert_heap_edge(h, 39, 40, 2,"���ų�","�ұ�"); insert_heap_edge(h, 40, 8, 7,"�ұ�","����3��");
   insert_heap_edge(h, 8, 29, 1,"����3��","������3��"); insert_heap_edge(h, 29, 41, 1,"������3��","�湫��"); insert_heap_edge(h, 41, 42, 2,"�湫��","���");
   insert_heap_edge(h, 42, 43, 2,"���","����"); insert_heap_edge(h, 43, 44, 4,"����","����͹̳�"); insert_heap_edge(h, 44, 22, 1,"����͹̳�","����");
   insert_heap_edge(h, 22, 45, 4,"����","����"); insert_heap_edge(h, 45, 46, 5,"����","����"); //3ȣ�� 14

   insert_heap_edge(h, 47, 48, 2,"���","���"); insert_heap_edge(h, 48, 2, 1,"���","â��"); insert_heap_edge(h, 2, 7, 9,"â��","���빮");
   insert_heap_edge(h, 7, 31, 1,"���빮","���빮���"); insert_heap_edge(h, 31, 41, 1,"���빮���","�湫��"); insert_heap_edge(h, 41, 10, 3,"�湫��","���￪");
   insert_heap_edge(h, 10, 49, 2,"���￪","�ﰢ��"); insert_heap_edge(h, 49, 50, 2,"���","����"); insert_heap_edge(h, 50, 51, 2,"����","�ѽŴ��Ա�");
   insert_heap_edge(h, 51, 23, 1,"�ѽŴ��Ա�","���"); insert_heap_edge(h, 23, 20, 10,"���","����"); insert_heap_edge(h, 20, 52, 14,"����","���̵�"); //4ȣ�� 12

   insert_heap_edge(h, 53, 54, 2,"��ȭ","��������"); insert_heap_edge(h, 54, 25, 6,"��������","��ġ��"); insert_heap_edge(h, 25, 26, 5,"��ġ��","��������û");
   insert_heap_edge(h, 26, 12, 2,"��������û","�ű�"); insert_heap_edge(h, 12, 55, 4,"�ű�","����"); insert_heap_edge(h, 55, 28, 2,"����","��û��");
   insert_heap_edge(h, 28, 8, 3,"��û��","����3��"); insert_heap_edge(h, 8, 30, 1,"����3��","������4��"); insert_heap_edge(h, 30, 31, 1,"������4��","���빮���");
   insert_heap_edge(h, 31, 56, 1,"���빮���","û��"); insert_heap_edge(h, 56, 33, 3,"û��","�սʸ�"); insert_heap_edge(h, 33, 57, 4,"�սʸ�","����");
   insert_heap_edge(h, 57, 58, 3,"����","õȣ"); insert_heap_edge(h, 58, 59, 1,"õȣ","����"); insert_heap_edge(h, 59, 60, 5,"����","���ϵ�");
   insert_heap_edge(h, 59, 61, 7,"����","��õ"); //5ȣ�� 16

   insert_heap_edge(h, 62, 63, 2,"��ȭ��","�¸��Ա�"); insert_heap_edge(h, 63, 3, 1,"�¸��Ա�","����"); insert_heap_edge(h, 3, 6, 8,"����","������");
   insert_heap_edge(h, 6, 32, 1,"������","�Ŵ�"); insert_heap_edge(h, 32, 56, 1,"�Ŵ�","û��"); insert_heap_edge(h, 56, 42, 1,"û��","���"); 
   insert_heap_edge(h, 42, 49, 5,"���","�ﰢ��"); insert_heap_edge(h, 49, 55, 2,"�ﰢ��","����"); insert_heap_edge(h, 55, 27, 4,"����","����");
   insert_heap_edge(h, 27, 39, 9,"����","���ų�"); insert_heap_edge(h, 27, 40, 9,"����","�ұ�"); insert_heap_edge(h, 39, 40, 2,"���ų�","�ұ�"); //6ȣ�� 12

   insert_heap_edge(h, 64, 1, 1,"���","������"); insert_heap_edge(h, 1, 48, 3,"������","���"); insert_heap_edge(h, 48, 63, 4,"���","�¸��Ա�");
   insert_heap_edge(h, 63, 57, 8,"�¸��Ա�","����"); insert_heap_edge(h, 57, 35, 2,"����","�Ǵ��Ա�"); insert_heap_edge(h, 35, 44, 7,"�Ǵ��Ա�","����͹̳�");
   insert_heap_edge(h, 44, 51, 2,"����͹̳�","�ѽŴ��Ա�"); insert_heap_edge(h, 51, 24, 8,"�ѽŴ��Ա�","�븲"); insert_heap_edge(h, 24, 18, 2,"�븲","���� �����д���");
   insert_heap_edge(h, 18, 15, 4,"���� �����д���","�¼�"); //7ȣ�� 13

   insert_heap_edge(h, 65, 58,1,"�ϻ�","õȣ"); insert_heap_edge(h, 58, 36, 3,"õȣ","���"); insert_heap_edge(h, 36, 66, 6,"���","����");
   insert_heap_edge(h, 66, 67, 6,"����","���"); //8ȣ�� 4

   insert_heap_edge(h, 70, 16, 10, "���", "����"); insert_heap_edge(h, 16, 71, 12,"����","����");	//��õ1ȣ�� 2

   insert_heap_edge(h, 37, 45, 2, "����", "����"); insert_heap_edge(h, 45, 46, 4,"����","����"); insert_heap_edge(h, 46, 66, 1,"����","����");
   insert_heap_edge(h, 66, 67, 3, "����", "���"); insert_heap_edge(h, 67, 68, 9,"���","����"); //�д缱 5

   insert_heap_edge(h, 72, 4, 10, "�ȴ�", "ȸ��"); insert_heap_edge(h, 4, 33, 2, "ȸ��", "�սʸ�"); insert_heap_edge(h, 33, 43, 2, "�սʸ�", "����");
   insert_heap_edge(h, 43, 50, 3, "����", "����"); insert_heap_edge(h, 50, 11, 1, "����", "���");	//�߾Ӽ� 5

   insert_heap_edge(h, 69, 70, 5, "��õ��������", "���"); insert_heap_edge(h, 70, 54, 1, "���", "��������");	//����ö�� 2
}
void kruskal(int n)
{
   int edge_accepted=0;
   HeapType h;
   int uset, vset;
   element e;

   heap_init(&h);
   insert_all_edges(&h);
   set_init(n);
   while(edge_accepted < (n-1)) {
      e=delete_min_heap(&h);
      uset = set_find(e.u);
      vset = set_find(e.v);
      if(uset != vset) {
         printf("%s -- %s: %d \n",e.sub1,e.sub2,e.key);
         edge_accepted++;
         set_union(uset,vset);
      }
   }
}
main() {
   HeapType heap;
   heap_init(&heap);
   kruskal(73);
}