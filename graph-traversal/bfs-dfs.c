#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "bfs-dfs.h"

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