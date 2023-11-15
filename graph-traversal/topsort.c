#include <stdbool.h>
#include <stdio.h>

#include "bfs-dfs.h"
#include "../data-structures/stack.h"

stack sorted;

extern bool discovered[];

void process_vertex_early(int v)
{
}

void process_vertex_late(int v)
{
    push(&sorted, v);
}

void process_edge(int x, int y)
{
    int class = edge_classification(x,y);
    if (class == BACK) {
        printf("Warning: directed cycle found, not a DAG\n");
    }
}

void topsort(graph *g)
{
    init_stack(&sorted);
    for (int i=1; i <= g->nvertices; i++) {
        if (discovered[i] == false) {
            dfs(g, i);
        }
    }
    print_stack(&sorted);
}

int main()
{
    graph g;
    read_graph(&g, true);
    print_graph(&g);
    topsort(&g);
}