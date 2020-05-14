/*(1) 인접리스트를 이용하여 첨부한 파일의 그래프 G1을 프로그램으로 표현한다.
이때 각 정점에서 연결된 간선은 인접 정점의 크기가 증가되는 순서대로 리스트에 삽입되어야 한다.

(2) 그래프를 출력하는 print_graph 함수를 작성한다. 작성한 함수를 사용하여 위의 (1) 에서 프로그램에 표현된 그래프를 출력한다. 출력은 다음과 같아야 한다.
V(G) = {0,1,2,3}
V(E) = { (0,1), (0,2), (0,3), (1,2), (2,3)} */

/*이번 공지 이후 과제를 올리실 때 아래 사항을 주석 처리하여 올려주시기 바랍니다.
- 개발 도구 ( dev c++ , visual studio 2012 express, etc..)
- 프로그램 실행 환경 (사용 os, ram, cpu, gpu )
- 작성한 코드의 주석 (꼭 안 하셔도 되지만 해주시면 감사하겠습니다.)
- 코드 참조시 출처를 밝힐 것 ( 출처를 안 밝히고 참조하거나 복붙 하시면 점수가 없습니다. + 과제카피 포함.)
 
위 사항을 어길시 코드에 문제가 없지만 채점자의 실행환경에서 이상하게 출력되거나 코드가 같을 때 채점 이의를 받지 않겠습니다. */

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
		fprintf(stderr, "그래프: 정점의 개수 초과");
		return ;
	}
	g->n++;
}
void insert_edge(GraphType *g, int u, int v) {
	GraphNode *node;
	if(u >= g->n || v >= g->n) {
		fprintf(stderr, "그래프: 정점 번호 오류");
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