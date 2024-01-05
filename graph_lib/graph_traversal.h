#ifndef GRAPH_TRAVERSAL_H_INCLUDED
#define GRAPH_TRAVERSAL_H_INCLUDED

#include "graph.h"

int _compare_est(void *v1, void *v2);

List shortest_path_values(Graph g, int fromValue, int toValue);

List shortest_path(Graph g, Vertex from, Vertex to);

List depth_first(Graph g, Vertex start);

List breadth_first(Graph g, Vertex start);

void print_path(List path);

// Dijkstra's algorithm
void _run_dijkstra(Graph g, Vertex start);

void _reset_vertex(void *v);

void _debug_print_vertex(void *v);

#endif