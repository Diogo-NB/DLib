#ifndef GRAPH_TRAVERSAL_H_INCLUDED
#define GRAPH_TRAVERSAL_H_INCLUDED

#include "graph.h"

// Compare the estimates of vertices for sorting
int _compare_est(void *v1, void *v2);

// shortest_path with values
List shortest_path_values(Graph g, int fromValue, int toValue);

// Returns a list of vertices with the shortest path from two vertices
List shortest_path(Graph g, Vertex from, Vertex to);

// Returns a list of vertices from a depth_first search
List depth_first(Graph g, Vertex start);

// Returns a list of vertices from a breadth_first search
List breadth_first(Graph g, Vertex start);

// Prints a list of vertices that represents a path
void print_path(List path);

// Dijkstra's algorithm
void _run_dijkstra(Graph g, Vertex start);

void _reset_vertex(void *v);

void _debug_print_vertex(void *v);

#endif