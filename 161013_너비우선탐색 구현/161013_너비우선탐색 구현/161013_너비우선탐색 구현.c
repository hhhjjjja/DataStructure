/*(1) 배열로 구현된 스택을 사용하여 그래프의 깊이우선탐색 프로그램을 구현한다.
이때 생성되는 그래프는 앞의 실습, 과제에서 사용한 프로그램을 이용한다.
배열로 구현된 스택도 자료구조(1)에서 구현한 스택을 사용한다. 첨부한 파일에 있는 그래프를 이용한다.
프로그램을 실행하면 방문하는 노드가 차례로 출력되어야 한다. 

(2) 탐색 방법을 넓이우선탐색으로 변경하고 스택 대신에 큐를 사용하여 앞의 (1)과 같이 프로그램 한다.  */
/*이번 공지 이후 과제를 올리실 때 아래 사항을 주석 처리하여 올려주시기 바랍니다.
- 개발 도구 ( dev c++ , visual studio 2012 express, etc..)
- 프로그램 실행 환경 (사용 os, ram, cpu, gpu )
- 작성한 코드의 주석 (꼭 안 하셔도 되지만 해주시면 감사하겠습니다.)
- 코드 참조시 출처를 밝힐 것 ( 출처를 안 밝히고 참조하거나 복붙 하시면 점수가 없습니다. + 과제카피 포함.)
 
위 사항을 어길시 코드에 문제가 없지만 채점자의 실행환경에서 이상하게 출력되거나 코드가 같을 때 채점 이의를 받지 않겠습니다.*/

#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50

typedef struct GraphNode {
	int vetex;
	struct GraphNode *link;
} GraphNode;
typedef struct GraphType {
	int n;
	GraphNode *adj_list[MAX_VERTICES];
} GraphType;
void graph_init(GraphType *g) {
	int v;
	g->n =0;
	for(v=0;v<MAX_VERTICES;++v) {
		g->adj_list[v] = NULL;
	}
}
void insert_vertex(GraphType *g, int v) {
	if(((g->n)+1) > MAX_VERTICES) {
		fprintf(stderr, "그래프:정점의 개수 초과");
			return;
	}
	g->n++;
}
void insert_edge(GraphType *g, int u, int v) {
	GraphNode *node;
	if(u>=g->n || v>= g->n) {
		fprintf(stderr, "그래프:정점 번호 오류");
		return;
	}
	node = (GraphNode *)malloc(sizeof(GraphNode));
	node->vetex = v;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;
}
int visited[MAX_VERTICES];
void bfs_list(GraphType *g, int v) {
	GraphNode *w;
	QueueType q;
	init(&q);
	visited[v] = TRUE;
	printf("%d ", v);
	enqueue(&q, v);
	while(!is_empty(&q)) {
		v=dequeue(&q);
		for(w=g->adj_list[v];w;w=w->link) {
			if(!visited[w->vetex]) {
				visited[w->vetex] = TRUE;
				printf("%d ", w->vetex);
				enqueue(&q, w->vetex);
			}
		}
	}
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
	bfs_list(&g, 0);
}
