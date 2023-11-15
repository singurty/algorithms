#include <stdio.h>
#include <stdbool.h>

#include "bfs-dfs.h"
#include "articulation.h"

extern int discovered[];
extern int processed[];
extern int entry_time[];

int reachable_ancestor[MAXV+1];
int tree_out_degree[MAXV+1];

void process_vertex_early(int v)
{
    reachable_ancestor[v] = v;
}

void process_edge(int v, int y)
{
    int class = edge_classification(v,y);
    if (class = TREE) {
        tree_out_degree[v] = tree_out_degree[v] + 1;
    }
    if ((class = BACK) && (parent[v] != y)) {
        if (entry_time[y] < entry_time[reachable_ancestor[v]]) {
            reachable_ancestor[v] = y;
        }
    }
    
}

void process_vertex_late(int v)
{
    int time_v;         // earliest reachable time
    int time_parent;    // earliest reachable time for parent[v]

    if (parent[v] < 1) {
        if (tree_out_degree[v] > 1) {
            printf("root articulation vertex: %d\n", v);
        }
        return;
    }

    if ((reachable_ancestor[v] == parent[v]) && !(parent[parent[v]] < 1)) { // test if parent is reachable and parent is not root
        printf("parent articulation vertex:%d\n", v);
    }

    if (reachable_ancestor[v] == v) {
        printf("bridge articulation vertex: %d\n", parent[v]);
        if (tree_out_degree[v] > 0) { // text if v is not a leaf
            printf("bridge articulation vertex: %d\n", v);
        }
    }

    time_v = entry_time[reachable_ancestor[v]];
    time_parent = entry_time[reachable_ancestor[parent[v]]];
    if (time_v < time_parent) {
        reachable_ancestor[parent[v]] = reachable_ancestor[v];
    }
}