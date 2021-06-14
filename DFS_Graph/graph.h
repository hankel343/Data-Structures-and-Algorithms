#ifndef GRAPH_H
#define GRAPH_H
#include <map>
#include <list>
#include <iostream>
using std::map; using std::list;

class Graph {
public:
	map<int, bool> visited;
	map<int, list<int>> adj;

	//function to add an edge to the graph
	void addEdge(int v, int w);

	//DFS traversal of the vertices reachable from v
	void DFS(int v);
};

#endif