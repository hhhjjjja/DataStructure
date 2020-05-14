/*(1) ��������Ʈ�� �̿��Ͽ� ÷���� ������ �׷��� G1�� ���α׷����� ǥ���Ѵ�.
�̶� �� �������� ����� ������ ���� ������ ũ�Ⱑ �����Ǵ� ������� ����Ʈ�� ���ԵǾ�� �Ѵ�.

(2) �׷����� ����ϴ� print_graph �Լ��� �ۼ��Ѵ�. �ۼ��� �Լ��� ����Ͽ� ���� (1) ���� ���α׷��� ǥ���� �׷����� ����Ѵ�. ����� ������ ���ƾ� �Ѵ�.
V(G) = {0,1,2,3}
V(E) = { (0,1), (0,2), (0,3), (1,2), (2,3)} */

/*�̹� ���� ���� ������ �ø��� �� �Ʒ� ������ �ּ� ó���Ͽ� �÷��ֽñ� �ٶ��ϴ�.
- ���� ���� ( dev c++ , visual studio 2012 express, etc..)
- ���α׷� ���� ȯ�� (��� os, ram, cpu, gpu )
- �ۼ��� �ڵ��� �ּ� (�� �� �ϼŵ� ������ ���ֽø� �����ϰڽ��ϴ�.)
- �ڵ� ������ ��ó�� ���� �� ( ��ó�� �� ������ �����ϰų� ���� �Ͻø� ������ �����ϴ�. + ����ī�� ����.)
 
�� ������ ���� �ڵ忡 ������ ������ ä������ ����ȯ�濡�� �̻��ϰ� ��µǰų� �ڵ尡 ���� �� ä�� ���Ǹ� ���� �ʰڽ��ϴ�. */

#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICS 50

typedef struct GraphNode {
	int vertex;
	struct GraphNode *link;
} GraphNode;
typedef struct GraphType {
	int n;
	GraphNode *adj_list[MAX_VERTICS];
} GraphType;

void graph_init(GraphType *g) {
	int v;
	g->n=0;
	for(v=0;v<MAX_VERTICS;++v) {
		g->adj_list[v]=NULL;
	}
}
void insert_vertex(GraphType *g, int v) {
	if(((g->n)+1) > MAX_VERTICS) {
		fprintf(stderr, "�׷���: ������ ���� �ʰ�");
		return ;
	}
	g->n++;
}
void insert_edge(GraphType *g, int u, int v) {
	GraphNode *node;
	if(u >= g->n || v >= g->n) {
		fprintf(stderr, "�׷���: ���� ��ȣ ����");
		return ;
	}
	node = (GraphNode *)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;
}
void print_graph(GraphType *g) {
	int i;
	GraphNode *node;

	printf("V(G)={ ");
	for(i=0;i<g->n;++i) {
		printf("%d ", i);
	}
	printf("}\nV(E)={ ");
	for(i=0;i<MAX_VERTICS;++i) {
		node = g->adj_list[i];
		while(node) {
			if(i<node->vertex) {
				printf("(%d, %d) ", i, node->vertex);
			}
			node = node->link;
		}
	}
	printf("}");
}
main() {
	GraphType G;
	graph_init(&G);

	insert_vertex(&G, 0);
	insert_vertex(&G, 1);
	insert_vertex(&G, 2);
	insert_vertex(&G, 3);
	insert_edge(&G, 0, 1);
	insert_edge(&G, 0, 2);
	insert_edge(&G, 0, 3);
	insert_edge(&G, 1, 2);
	insert_edge(&G, 2, 3);
	insert_edge(&G, 1, 0);
	insert_edge(&G, 2, 0);
	insert_edge(&G, 3, 0);
	insert_edge(&G, 2, 1);
	insert_edge(&G, 3, 2);
	print_graph(&G);
}