#include "graph.h"

extern bool processed[];
extern bool discovered[];
extern int parent[];
extern int entry_time[];
extern int exit_time[];

void initialize_search(graph *g);
void bfs(graph *g, int start);
void process_edge(int x, int y);
void process_vertex_late(int v);
void process_vertex_early(int v);
void dfs(graph *g, int v);

#define TREE 3
#define BACK 4
#define FORWARD 5
#define CROSS 6
int edge_classification(int v, int y);