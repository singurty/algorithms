#include "graph.h"
#include "../data-structures/queue.h"

void initialize_search(graph *g);
void bfs(graph *g, int start);
void process_edge(int x, int y);
void process_vertex_late(int v);
void process_vertex_early(int v);