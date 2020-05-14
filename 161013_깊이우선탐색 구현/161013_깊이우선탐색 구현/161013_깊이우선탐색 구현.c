/*(1) �迭�� ������ ������ ����Ͽ� �׷����� ���̿켱Ž�� ���α׷��� �����Ѵ�.
�̶� �����Ǵ� �׷����� ���� �ǽ�, �������� ����� ���α׷��� �̿��Ѵ�.
�迭�� ������ ���õ� �ڷᱸ��(1)���� ������ ������ ����Ѵ�. ÷���� ���Ͽ� �ִ� �׷����� �̿��Ѵ�.
���α׷��� �����ϸ� �湮�ϴ� ��尡 ���ʷ� ��µǾ�� �Ѵ�. 

(2) Ž�� ����� ���̿켱Ž������ �����ϰ� ���� ��ſ� ť�� ����Ͽ� ���� (1)�� ���� ���α׷� �Ѵ�.  */
/*�̹� ���� ���� ������ �ø��� �� �Ʒ� ������ �ּ� ó���Ͽ� �÷��ֽñ� �ٶ��ϴ�.
- ���� ���� ( dev c++ , visual studio 2012 express, etc..)
- ���α׷� ���� ȯ�� (��� os, ram, cpu, gpu )
- �ۼ��� �ڵ��� �ּ� (�� �� �ϼŵ� ������ ���ֽø� �����ϰڽ��ϴ�.)
- �ڵ� ������ ��ó�� ���� �� ( ��ó�� �� ������ �����ϰų� ���� �Ͻø� ������ �����ϴ�. + ����ī�� ����.)
 
�� ������ ���� �ڵ忡 ������ ������ ä������ ����ȯ�濡�� �̻��ϰ� ��µǰų� �ڵ尡 ���� �� ä�� ���Ǹ� ���� �ʰڽ��ϴ�.*/

#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

#define MAX_VERTICES 50
#define TRUE 1
#define FALSE 0
int visited[MAX_VERTICES];

typedef struct GraphNode {
	int vertex;
	struct GraphNode *link;
} GraphNode;
typedef struct GraphType {
	int n;
	GraphNode *adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;
void graph_init(GraphType *g) {
	int v, i;
	g->n =0;
	for(v=0;v<MAX_VERTICES;++v) {
		for(i=0;i<MAX_VERTICES;++i) {
			g->adj_mat[v][i] = NULL;
		}
	}
}
void dfs_mat(GraphType *g, int v) {
	int w;
	visited[v] = TRUE;
	printf("%d ", v);
	for(w=0; w<g->n;++w) {
		if(g->adj_mat[v][w] && !visited[w])
			dfs_mat(g, w);
	}
}
void insert_edge(GraphType *g, int u, int v) {
	GraphNode *node;
	if(u >= g->n || v>= g->n) {
		fprintf(stderr, "�׷���: ������ ���� �ʰ�");
		return ;
	}
	node = (GraphNode *)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->adj_mat[u][v];
	g->adj_mat[u][v] = node;
}
void insert_vertex(GraphType *g, int v) {
	if(((g->n)+1) > MAX_VERTICES) {
		fprintf(stderr, "�׷���: ������ ���� �ʰ�");
		return ;
	}
	g->n++;
}

main() {
	int i;
	GraphType g;
	graph_init(&g);

	for(i=0;i<6;++i) {
		insert_vertex(&g, i);
	}
	insert_edge(&g, 1, 4);
	insert_edge(&g, 4, 1);
	insert_edge(&g, 4, 3);
	insert_edge(&g, 3, 4);
	insert_edge(&g, 4, 5);
	insert_edge(&g, 5, 4);
	insert_edge(&g, 5, 2);
	insert_edge(&g, 2, 5);
	insert_edge(&g, 5, 0);
	insert_edge(&g, 0, 5);
	insert_edge(&g, 0, 2);
	insert_edge(&g, 2, 0);
	insert_edge(&g, 2, 3);
	insert_edge(&g, 3, 2);
	dfs_mat(&g, 0);
}
