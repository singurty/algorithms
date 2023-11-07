#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "graph.h"
#include "../data-structures/queue.h"

#define UNCOLORED 0
#define BLACK 1
#define WHITE 2

bool processed[MAXV+1];
bool discovered[MAXV+1];
int parent[MAXV+1];
int color[MAXV+1];
bool bipartite;

void initialize_search(graph *g)
{
	int i;
	
	for (i=1; i<=g->nvertices; i++) {
		processed[i] = discovered[i] = false;
		parent[i] = -1;
	}
}

void process_vertex_late(int v)
{
//	printf("processed vertex late %d\n", v);
}

void process_vertex_early(int v)
{
//	printf(" %d\n", v);
}

void process_edge(int x, int y)
{
	if (color[x] == color[y]) {
		bipartite = false;
		printf("Graph not bipartite due to edge (%d,%d)\n", x,y);
	}
}

void bfs(graph *g, int start)
{
	queue q;
	int v;				// current vertex
	int y;				// successor vertex
	edgenode *p;		// temporary pointer

	init_queue(&q);
	enqueue(&q, start);
	discovered[start] = true;
	
	while (empty_queue(&q) == false) {
		v = dequeue(&q);
		process_vertex_early(v);
		processed[v] = true;
		p = g->edges[v];
		while (p != NULL) {
			y = p->y;
			if ((processed[y] == false) || g->directed)
				process_edge(v, y);
			if (discovered[y] == false) {
				enqueue(&q, y);
				discovered[y] = true;
				parent[y] = v;
			}
			p = p->next;
		}
		process_vertex_late(v);
	}
}

void connected_components(graph *g)
{
	int c = 0;
	initialize_search(g);

	for (int i=1; i<=g->nvertices; i++) {
		if (discovered[i] == false) {
			c++;
			printf("Component %d:", c);
			bfs(g,i);
			printf("\n");
		}
	}
}

void twocolor(graph *g) {
	for (int i=1; i<g->nvertices; i++) {
		color[i] = UNCOLORED;
	}
	bipartite = true;
	initialize_search(g);
	for (int i=1; i<g->nvertices; i++) {
		if (discovered[i] == false) {
			color[i] = WHITE;
			bfs(g,i);
		}
	}
}

void printcolor(graph *g) {
	for (int i=1; i<=g->nvertices; i++) {
		printf("color of vertex %d: %d\n", i, color[i]);
	}
}

int main() {
	graph* g = malloc(sizeof(graph));
	read_graph(g, true);
//	connected_components(g);
	twocolor(g);
//	if (bipartite)
		printcolor(g);
}