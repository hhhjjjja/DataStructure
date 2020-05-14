/* 1) 인접행렬을 사용한 그래프 표현에서 정점과 간선을 삭제하는 다음 함수를 작성한다.
int delete_edge(GraphType *g, int start, int end); //성공 1, 실패 0리턴
int delete_vertics(GraphType *g, int v); //성공 1, 실패 0 리턴

2) 첨부한 파일에 있는 그래프 G1을 처음에 만든다. G1에서 간선을 삭제하여 G2를 만들고 G2에서 정점 3을 삭제하여
G3를 만들고 다시 정점 2을 삭제하여 G4를 만든다.
각 단계에서 만들어진 그래프는 화면에 출력되어야 하며 이때 print_graph(GraphType *g) 함수를 만들어 사용한다.
그래프 G2의 출력은 다음과 같아야 한다.
V={0,1,2,3}, E={(0,1), (0,3), (1,2)} */

/*이번 공지 이후 과제를 올리실 때 아래 사항을 주석 처리하여 올려주시기 바랍니다.
- 개발 도구 ( dev c++ , visual studio 2012 express, etc..)
- 프로그램 실행 환경 (사용 os, ram, cpu, gpu )
- 작성한 코드의 주석 (꼭 안 하셔도 되지만 해주시면 감사하겠습니다.)
- 코드 참조시 출처를 밝힐 것 ( 출처를 안 밝히고 참조하거나 복붙 하시면 점수가 없습니다. + 과제카피 포함.)
 
위 사항을 어길시 코드에 문제가 없지만 채점자의 실행환경에서 이상하게 출력되거나 코드가 같을 때 채점 이의를 받지 않겠습니다.*/

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
		fprintf(stderr, "그래프: 정점의 개수 초과");
		return;
	}
	g->n++;
}
void insert_edge(GraphType *g, int start, int end) {
	if(start >= g->n || end >= g->n) {
		fprintf(stderr, "그래프: 정점 번호 오류");
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