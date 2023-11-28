#include <stdio.h>

#include "bfs-dfs.h"
#include "graph.h"
#include "../data-structures/stack.h"

int low[MAXV+1];            // oldest vertex surely in component of v
int scc[MAXV+1];            // strong component number for each vertex

int components_found;

extern int entry_time[];
stack active;

void strong_components(graph *g)
{
    for (int i=1; i<g->nvertices; i++) {
        low[i] = i;
        scc[i] = -1;
    }
    components_found = 0;
    init_stack(&active);
    initialize_search(&g);

    for (int i=1; i<g->nvertices; i++) {
        if (discovered[i] == false) {
            dfs(g,i);
        }
    }
}

void process_edge(int x, int y)
{
    int class = edge_classification(x, y);
    if (class == BACK) {
        if (entry_time[y] < entry_time[low[x]]) {
            low[x] = y;
        }
    }

    if (class = CROSS) {
        if (scc[y] == -1) {
            if (entry_time[y] < entry_time[low[x]]) {
                low[x] = y;
            }
        }
    }
}

void process_vertex_early(int v) {
    push(&active, v);
}

void pop_component(int v)
{
    int t;
    components_found++;

    scc[v] = components_found;
    while ((t = pop(&active)) != v) {
        scc[t] = components_found;
    }
}

void process_vertex_late(int v) {
    if (low[v] == v) {
        pop_component(v);
    }

    if (entry_time[low[v]] < entry_time[low[parent[v]]]) {
        low[parent[v]] = low[v];
    }
}