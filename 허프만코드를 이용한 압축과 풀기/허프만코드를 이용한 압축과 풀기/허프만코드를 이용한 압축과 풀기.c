/*���α׷� 8.6(336������)�� ������ �ڵ带 �����Ѵ�.
1) ������ ������ �ڵ带 ����ϴ� ���α׷��� �ۼ��Ͻÿ�?
2) ������ �ڵ带 ����Ͽ� �Ʒ� ������ ������ ����� �����ΰ�?
"tennis is teen"
3) ���� 2)���� ������ ������ �ٽ� Ǫ�� ������ �׸����� ǥ���Ͻÿ�?
4)[���ʽ� ����: ����� �߰� ����] ���� 1)���� ������ ������ �ڵ带 ����Ͽ�
�����ϴ� �Լ� huffman_encompress�� �ۼ��Ͻÿ�. ���� ����� ������ Ǫ�� �Լ� huffman_decompress�� �ۼ��Ͻÿ�.*/

/*
- ���� ���� ( dev c++ , visual studio 2012 express, etc..)
- ���α׷� ���� ȯ�� (��� os, ram, cpu, gpu )
- �ۼ��� �ڵ��� �ּ� (�� �� �ϼŵ� ������ ���ֽø� �����ϰڽ��ϴ�.)
- �ڵ� ������ ��ó�� ���� �� ( ��ó�� �� ������ �����ϰų� ���� �Ͻø� ������ �����ϴ�. + ����ī�� ����.)
 
�� ������ ���� �ڵ忡 ������ ������ ä������ ����ȯ�濡�� �̻��ϰ� ��µǰų� �ڵ尡 ���� �� ä�� ���Ǹ� ���� �ʰڽ��ϴ�. */

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
      fprintf(stderr, "�޸� ����\n");
      exit(1);
   }
   node->left_child=left;
   node->right_child=right;

   return node;
}

/*����'http://m.blog.naver.com/mb851/'*/
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