#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "graph.h"
#include "../data-structures/queue.h"

bool processed[MAXV+1];
bool discovered[MAXV+1];
int parent[MAXV+1];

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
	printf(" %d\n", v);
}

void process_edge(int x, int y)
{
//	printf("processed edge (%d,%d)\n", x, y);
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

int main() {
	graph* g = malloc(sizeof(graph));
	read_graph(g, true);
	connected_components(g);
}