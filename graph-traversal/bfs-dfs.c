#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "bfs-dfs.h"

bool processed[MAXV+1];
bool discovered[MAXV+1];
int parent[MAXV+1];

int entry_time[MAXV+1];
int exit_time[MAXV+1];
int time;
bool finished = false;

void initialize_search(graph *g)
{
	for (int i=1; i<=g->nvertices; i++) {
		processed[i] = discovered[i] = false;
		parent[i] = -1;
	}
	time = 0;
}

void find_path(int start, int end, int parents[]) {
	if (start == end || end == -1) {
		printf("\n%d", start);
	} else {
		find_path(start, parents[end], parents);
		printf(" %d", end);
	}
}

//void process_vertex_early(int v) {
//
//}
//void process_vertex_late(int v) {
//
//}

//void process_edge(int v, int y) {
//	if (parent[v] != y) {	// found back edge
//		printf("Cycle from %d to %d\n", y, v);
//		find_path(y, v, parent);
//		printf("\n\n");
//	}
//}

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

void dfs(graph *g, int v) {
	edgenode *p; 		// temporary pointer
	int y;				// successor vertex
	if (finished) return;

	discovered[v] = true;
	time++;
	entry_time[v] = time;

	process_vertex_early(v);

	p = g->edges[v];
	while (p != NULL) {
		y = p->y;
		if (discovered[y] == false) {
			parent[y] = v;
			process_edge(v, y);
			dfs(g, y);
		}
		else if ((!processed[y]) || (g->directed))
			process_edge(v,y);
		if (finished) return;
		p = p->next;
	}
	process_vertex_late(v);
	time++;
	exit_time[v] = time;
	processed[v] = true;
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
	initialize_search(g);
	dfs(g, 1);
}