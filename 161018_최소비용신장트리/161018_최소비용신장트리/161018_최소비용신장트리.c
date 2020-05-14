/*첨부한 파일은 수도권 지하철 및 전철 노선도이다.

1) 노선도을 가중치 그래프로 표현한다. 정점은 각 노선의 마지막 역과 갈아타는 역이며 간선의 가중치는 두 역간의 역 숫자이다.
서울역부터 시작하는 깊이 우선 탐색을 실시한다. 탐색 결과를 출력하여 모든 종착역과 갈아타는 역이 출력되는지 확인한다.

2) 지하철/전철 노선을 따라서 모든 역을 연결하는 인터넷 통신망을 구축하려고 한다.
이때 최소 비용(지나가는 역의 숫자를 최소로)으로 구축하는 연결도를 구하는 프로그램을 작성한다.
연결도는 정점과 비용으로 출력되어야 한다. 예를 들면 연결도에 인천국제공항과 계양구간이 포함되면 (인천국제공항--계양: 4)로 출력되어야 한다.*/

/*이번 공지 이후 과제를 올리실 때 아래 사항을 주석 처리하여 올려주시기 바랍니다.
- 개발 도구 ( dev c++ , visual studio 2012 express, etc..)
- 프로그램 실행 환경 (사용 os, ram, cpu, gpu )
- 작성한 코드의 주석 (꼭 안 하셔도 되지만 해주시면 감사하겠습니다.)
- 코드 참조시 출처를 밝힐 것 ( 출처를 안 밝히고 참조하거나 복붙 하시면 점수가 없습니다. + 과제카피 포함.)
 
위 사항을 어길시 코드에 문제가 없지만 채점자의 실행환경에서 이상하게 출력되거나 코드가 같을 때 채점 이의를 받지 않겠습니다.*/

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
   insert_heap_edge(h, 0, 1, 13,"소요산","도봉산"); insert_heap_edge(h, 1, 2, 3,"도봉산","창동"); insert_heap_edge(h, 2, 3, 4,"창동","석계");
   insert_heap_edge(h, 3, 4, 3,"석계","회기"); insert_heap_edge(h, 4, 5, 3,"회기","신설동"); insert_heap_edge(h, 5, 6, 1,"신설동","동묘앞");
   insert_heap_edge(h, 6, 7, 1,"동묘앞","동대문"); insert_heap_edge(h, 7, 8, 2,"동대문","종로3가"); insert_heap_edge(h, 8, 9, 1,"종로3가","시청");
   insert_heap_edge(h, 9, 10, 1,"시청","서울역"); insert_heap_edge(h, 10, 11, 2,"서울역","용산"); insert_heap_edge(h, 11, 12, 3,"용산","신길");
   insert_heap_edge(h, 12, 13, 2,"신길","신도림"); insert_heap_edge(h, 13, 14, 1,"신도림","구로"); insert_heap_edge(h, 14, 15, 4,"구로","온수");
   insert_heap_edge(h, 15, 16, 7,"온수","부평"); insert_heap_edge(h, 16, 17, 9,"부평","인천"); insert_heap_edge(h, 14, 18, 1,"구로","가산 디지털단지");
   insert_heap_edge(h, 18, 19, 3,"가산 디지털단지","광명"); insert_heap_edge(h, 18, 20, 7,"가산 디지털단지","금정"); insert_heap_edge(h, 20, 21, 19,"금정","천안"); //1호선 18

   insert_heap_edge(h, 22, 23, 3,"교대","사당"); insert_heap_edge(h, 23, 24, 7,"사당","대림"); insert_heap_edge(h, 24, 13, 1,"대림","신도림");
   insert_heap_edge(h, 13, 25, 4,"신도림","까치산"); insert_heap_edge(h, 13, 26, 2,"신도림","영등포구청"); insert_heap_edge(h, 26, 27, 2,"영등포구청","합정");
   insert_heap_edge(h, 27, 28, 5,"합정","충정로"); insert_heap_edge(h, 28, 9, 1,"충정로","시청"); insert_heap_edge(h, 9, 29, 2,"시청","을지로3가");
   insert_heap_edge(h, 29, 30, 1,"을지로3가","을지로4가"); insert_heap_edge(h, 30, 31, 1,"을지로4가","동대문운동장"); insert_heap_edge(h, 31, 32, 1,"동대문운동장","신당");
   insert_heap_edge(h, 32, 33, 2,"신당","왕십리"); insert_heap_edge(h, 33, 34, 2,"왕십리","성수"); insert_heap_edge(h, 34, 35, 1,"성수","건대입구");
   insert_heap_edge(h, 35, 36, 4,"건대입구","잠실"); insert_heap_edge(h, 36, 37, 4,"잠실","선릉"); insert_heap_edge(h, 37, 22, 3,"선릉","교대"); //2호선 18

   insert_heap_edge(h, 38, 39, 11,"대화","연신내"); insert_heap_edge(h, 39, 40, 2,"연신내","불광"); insert_heap_edge(h, 40, 8, 7,"불광","종로3가");
   insert_heap_edge(h, 8, 29, 1,"종로3가","을지로3가"); insert_heap_edge(h, 29, 41, 1,"을지로3가","충무로"); insert_heap_edge(h, 41, 42, 2,"충무로","약수");
   insert_heap_edge(h, 42, 43, 2,"약수","옥수"); insert_heap_edge(h, 43, 44, 4,"옥수","고속터미널"); insert_heap_edge(h, 44, 22, 1,"고속터미널","교대");
   insert_heap_edge(h, 22, 45, 4,"교대","도곡"); insert_heap_edge(h, 45, 46, 5,"도곡","수서"); //3호선 14

   insert_heap_edge(h, 47, 48, 2,"당고개","노원"); insert_heap_edge(h, 48, 2, 1,"노원","창동"); insert_heap_edge(h, 2, 7, 9,"창동","동대문");
   insert_heap_edge(h, 7, 31, 1,"동대문","동대문운동장"); insert_heap_edge(h, 31, 41, 1,"동대문운동장","충무로"); insert_heap_edge(h, 41, 10, 3,"충무로","서울역");
   insert_heap_edge(h, 10, 49, 2,"서울역","삼각지"); insert_heap_edge(h, 49, 50, 2,"용산","이촌"); insert_heap_edge(h, 50, 51, 2,"이촌","총신대입구");
   insert_heap_edge(h, 51, 23, 1,"총신대입구","사당"); insert_heap_edge(h, 23, 20, 10,"사당","금정"); insert_heap_edge(h, 20, 52, 14,"금정","오이도"); //4호선 12

   insert_heap_edge(h, 53, 54, 2,"방화","김포공항"); insert_heap_edge(h, 54, 25, 6,"김포공항","까치산"); insert_heap_edge(h, 25, 26, 5,"까치산","영등포구청");
   insert_heap_edge(h, 26, 12, 2,"영등포구청","신길"); insert_heap_edge(h, 12, 55, 4,"신길","공덕"); insert_heap_edge(h, 55, 28, 2,"공덕","충청로");
   insert_heap_edge(h, 28, 8, 3,"충청로","종로3가"); insert_heap_edge(h, 8, 30, 1,"종로3가","을지로4가"); insert_heap_edge(h, 30, 31, 1,"을지로4가","동대문운동장");
   insert_heap_edge(h, 31, 56, 1,"동대문운동장","청구"); insert_heap_edge(h, 56, 33, 3,"청구","왕십리"); insert_heap_edge(h, 33, 57, 4,"왕십리","군자");
   insert_heap_edge(h, 57, 58, 3,"군자","천호"); insert_heap_edge(h, 58, 59, 1,"천호","강동"); insert_heap_edge(h, 59, 60, 5,"강동","상일동");
   insert_heap_edge(h, 59, 61, 7,"강동","마천"); //5호선 16

   insert_heap_edge(h, 62, 63, 2,"봉화산","태릉입구"); insert_heap_edge(h, 63, 3, 1,"태릉입구","석계"); insert_heap_edge(h, 3, 6, 8,"석계","동묘앞");
   insert_heap_edge(h, 6, 32, 1,"동묘앞","신당"); insert_heap_edge(h, 32, 56, 1,"신당","청구"); insert_heap_edge(h, 56, 42, 1,"청구","약수"); 
   insert_heap_edge(h, 42, 49, 5,"약수","삼각지"); insert_heap_edge(h, 49, 55, 2,"삼각지","공덕"); insert_heap_edge(h, 55, 27, 4,"공덕","합정");
   insert_heap_edge(h, 27, 39, 9,"합정","연신내"); insert_heap_edge(h, 27, 40, 9,"합정","불광"); insert_heap_edge(h, 39, 40, 2,"연신내","불광"); //6호선 12

   insert_heap_edge(h, 64, 1, 1,"장암","도봉산"); insert_heap_edge(h, 1, 48, 3,"도봉산","노원"); insert_heap_edge(h, 48, 63, 4,"노원","태릉입구");
   insert_heap_edge(h, 63, 57, 8,"태릉입구","군자"); insert_heap_edge(h, 57, 35, 2,"군자","건대입구"); insert_heap_edge(h, 35, 44, 7,"건대입구","고속터미널");
   insert_heap_edge(h, 44, 51, 2,"고속터미널","총신대입구"); insert_heap_edge(h, 51, 24, 8,"총신대입구","대림"); insert_heap_edge(h, 24, 18, 2,"대림","가산 디지털단지");
   insert_heap_edge(h, 18, 15, 4,"가산 디지털단지","온수"); //7호선 13

   insert_heap_edge(h, 65, 58,1,"암사","천호"); insert_heap_edge(h, 58, 36, 3,"천호","잠실"); insert_heap_edge(h, 36, 66, 6,"잠실","복정");
   insert_heap_edge(h, 66, 67, 6,"복정","모란"); //8호선 4

   insert_heap_edge(h, 70, 16, 10, "계양", "부평"); insert_heap_edge(h, 16, 71, 12,"부평","동막");	//인천1호선 2

   insert_heap_edge(h, 37, 45, 2, "선릉", "도곡"); insert_heap_edge(h, 45, 46, 4,"도곡","수서"); insert_heap_edge(h, 46, 66, 1,"수서","복정");
   insert_heap_edge(h, 66, 67, 3, "복정", "모란"); insert_heap_edge(h, 67, 68, 9,"모란","보정"); //분당선 5

   insert_heap_edge(h, 72, 4, 10, "팔당", "회기"); insert_heap_edge(h, 4, 33, 2, "회기", "왕십리"); insert_heap_edge(h, 33, 43, 2, "왕십리", "옥수");
   insert_heap_edge(h, 43, 50, 3, "옥수", "이촌"); insert_heap_edge(h, 50, 11, 1, "이촌", "용산");	//중앙선 5

   insert_heap_edge(h, 69, 70, 5, "인천국제공항", "계양"); insert_heap_edge(h, 70, 54, 1, "계양", "김포공항");	//공항철도 2
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