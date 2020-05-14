/*프로그램 8.6(336페이지)은 허프만 코드를 생성한다.
1) 생성된 허프만 코드를 출력하는 프로그램을 작성하시오?
2) 생성된 코드를 사용하여 아래 문장을 압축한 결과는 무엇인가?
"tennis is teen"
3) 앞의 2)에서 압축한 문장을 다시 푸는 과정을 그림으로 표현하시오?
4)[보너스 문제: 제출시 추가 점수] 앞의 1)에서 생성한 허프만 코드를 사용하여
압축하는 함수 huffman_encompress을 작성하시오. 또한 압축된 문장을 푸는 함수 huffman_decompress도 작성하시오.*/

/*
- 개발 도구 ( dev c++ , visual studio 2012 express, etc..)
- 프로그램 실행 환경 (사용 os, ram, cpu, gpu )
- 작성한 코드의 주석 (꼭 안 하셔도 되지만 해주시면 감사하겠습니다.)
- 코드 참조시 출처를 밝힐 것 ( 출처를 안 밝히고 참조하거나 복붙 하시면 점수가 없습니다. + 과제카피 포함.)
 
위 사항을 어길시 코드에 문제가 없지만 채점자의 실행환경에서 이상하게 출력되거나 코드가 같을 때 채점 이의를 받지 않겠습니다. */

#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 100

/*typedef struct {
	int alphabet;
	int freq;
}AlphabetType;*/

typedef struct TreeNode {
   int weight;
   struct TreeNode *left_child;
   struct TreeNode *right_child;
}TreeNode;
typedef struct {
   TreeNode *ptree;
   int key;
}element;
typedef struct {
   element heap[MAX_ELEMENT];
   int heap_size;
}HeapType;


int init(HeapType *h) {
   h->heap_size=0;
}

void insert_min_heap(HeapType *h,element item) {
   int i;
   i=++(h->heap_size);

   while((i!=1)&&(item.key<h->heap[i/2].key)){
      h->heap[i]=h->heap[i/2];
      i/=2;
   }
   h->heap[i]=item;
}

element delete_min_heap(HeapType *h) {
   int parent, child;
   element item, temp;

   item=h->heap[1];
   temp=h->heap[(h->heap_size)--];
   parent=1;
   child=2;
   while(child<=h->heap_size){
      if((child <= h->heap_size)&&(h->heap[child].key)>h->heap[child+1].key)
         child++;
      if(temp.key <= h->heap[child].key) break;

      h->heap[parent]=h->heap[child];
      parent=child;
      child*=2;
   }
   h->heap[parent]=temp;
   return item;
}

TreeNode *make_tree(TreeNode *left, TreeNode *right) {
   TreeNode *node=
      (TreeNode *)malloc(sizeof(TreeNode));
   if(node == NULL) {
      fprintf(stderr, "메모리 에러\n");
      exit(1);
   }
   node->left_child=left;
   node->right_child=right;

   return node;
}

/*참조'http://m.blog.naver.com/mb851/'*/
void print_Tree (TreeNode *p, int i, char *ap) {
	if(p) {
		i++;
		ap[i] = '1';
		print_Tree(p->left_child, i, ap);
		ap[i] = '0';
		print_Tree(p->right_child, i, ap);
		ap[i] = '\0';

		if(p->left_child == NULL && p->right_child == NULL) {
			printf("%d - %s \n", p->weight, ap);
		}
	}
}

void destroy_tree(TreeNode *root) {
   if(root==NULL) return;
   destroy_tree(root->left_child);
   destroy_tree(root->right_child);
   free(root);
}

void huffman_tree(int freq[], int n) {
   int i;
   TreeNode *node, *x;
   HeapType heap;
   element e, e1, e2;

   char *ap = (char *)malloc(sizeof(char));

   init(&heap);
   for(i=0;i<n;i++){
      node = make_tree(NULL, NULL);
      e.key= node->weight=freq[i];
      e.ptree=node;
      insert_min_heap(&heap, e);
   }

   for(i=1;i<n;i++){   
      e1=delete_min_heap(&heap);
      e2=delete_min_heap(&heap);

      x=make_tree(e1.ptree, e2.ptree);
      e.key=x->weight=e1.key+e2.key;
      e.ptree=x;
      insert_min_heap(&heap,e);
   }
   print_Tree(e.ptree, -1, ap);

   e=delete_min_heap(&heap);
   destroy_tree(e.ptree);
}

void main() {
   int freq[]={15,12,8,6,4};
   huffman_tree(freq, 5);
}