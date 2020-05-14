/* 1) ��������� ����� �׷��� ǥ������ ������ ������ �����ϴ� ���� �Լ��� �ۼ��Ѵ�.
int delete_edge(GraphType *g, int start, int end); //���� 1, ���� 0����
int delete_vertics(GraphType *g, int v); //���� 1, ���� 0 ����

2) ÷���� ���Ͽ� �ִ� �׷��� G1�� ó���� �����. G1���� ������ �����Ͽ� G2�� ����� G2���� ���� 3�� �����Ͽ�
G3�� ����� �ٽ� ���� 2�� �����Ͽ� G4�� �����.
�� �ܰ迡�� ������� �׷����� ȭ�鿡 ��µǾ�� �ϸ� �̶� print_graph(GraphType *g) �Լ��� ����� ����Ѵ�.
�׷��� G2�� ����� ������ ���ƾ� �Ѵ�.
V={0,1,2,3}, E={(0,1), (0,3), (1,2)} */

/*�̹� ���� ���� ������ �ø��� �� �Ʒ� ������ �ּ� ó���Ͽ� �÷��ֽñ� �ٶ��ϴ�.
- ���� ���� ( dev c++ , visual studio 2012 express, etc..)
- ���α׷� ���� ȯ�� (��� os, ram, cpu, gpu )
- �ۼ��� �ڵ��� �ּ� (�� �� �ϼŵ� ������ ���ֽø� �����ϰڽ��ϴ�.)
- �ڵ� ������ ��ó�� ���� �� ( ��ó�� �� ������ �����ϰų� ���� �Ͻø� ������ �����ϴ�. + ����ī�� ����.)
 
�� ������ ���� �ڵ忡 ������ ������ ä������ ����ȯ�濡�� �̻��ϰ� ��µǰų� �ڵ尡 ���� �� ä�� ���Ǹ� ���� �ʰڽ��ϴ�.*/

#include <stdio.h>
#define MAX_VERTICES 50

typedef struct GraphType {
	int n;
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

void graph_init(GraphType *g) {
	int r, c;
	g->n=0;
	for(r=0;r<MAX_VERTICES;++r) {
		for(c=0;c<MAX_VERTICES;++c) {
			g->adj_mat[r][c]=0;
		}
	}
}
void insert_vertex(GraphType *g, int v) {
	if(((g->n)+1) > MAX_VERTICES) {
		fprintf(stderr, "�׷���: ������ ���� �ʰ�");
		return;
	}
	g->n++;
}
void insert_edge(GraphType *g, int start, int end) {
	if(start >= g->n || end >= g->n) {
		fprintf(stderr, "�׷���: ���� ��ȣ ����");
		return;
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}
int delete_vertex(GraphType *g, int v) {
	int i=0;
	if((g->n-1) < 0) {
		return 0;
	}
	if(g==NULL) {
		return 0;
	}
	g->n--;
	return 1;
}
int delete_edge(GraphType *g, int start, int end) {
	if((start < 0) || (start > MAX_VERTICES-1)) {
		return 0;
	}
	if((end < 0) || (end > MAX_VERTICES-1)) {
		return 0;
	}
	if(g==NULL) {
		return 0;
	}

	g->adj_mat[start][end] = 0;
	g->adj_mat[end][start] = 0;
	return 1;
}
void print_graph(GraphType *g) {
	int i, j;
	printf("V={");
	for(i=0;i<g->n;++i) {
		printf("%d ", i);
	}
	printf("}, E={");
	for(i=0;i<MAX_VERTICES;++i) {
		for(j=i;j<MAX_VERTICES;++j) {
			if(g->adj_mat[i][j]) {
				printf("(%d, %d)", i, j);
			}
		}
	}
	printf("}\n");
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
	printf("-------G1--------\n");
	print_graph(&G);

	delete_edge(&G, 0, 2);
	delete_edge(&G, 2, 3);
	printf("-------G2--------\n");
	print_graph(&G);

	delete_vertex(&G, 3);
	delete_edge(&G, 1, 2);
	delete_edge(&G, 0, 3);
	insert_edge(&G, 0, 2);
	printf("-------G3--------\n");
	print_graph(&G);

	delete_edge(&G, 0, 2);
	delete_vertex(&G, 2);
	printf("-------G4--------\n");
	print_graph(&G);
}