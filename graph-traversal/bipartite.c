#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "bfs-dfs.h"

#define UNCOLORED 0
#define BLACK 1
#define WHITE 2

extern bool discovered[];

int color[MAXV+1];
bool bipartite;

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

void process_edge(int x, int y)
{
	if (color[x] == color[y]) {
		bipartite = false;
		printf("Graph not bipartite due to edge (%d,%d)\n", x,y);
	}
}

void process_vertex_early(int v) {
}
void process_vertex_late(int v) {
}

void printcolor(graph *g) {
	for (int i=1; i<=g->nvertices; i++) {
		printf("color of vertex %d: %d\n", i, color[i]);
	}
}

int main() {
	graph* g = malloc(sizeof(graph));
	read_graph(g, true);
    twocolor(g);
    printcolor(g);
}