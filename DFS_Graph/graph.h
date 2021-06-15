#ifndef GRAPH_H
#define GRAPH_H
#include <map>
#include <list>
#include <iostream>
using std::map; using std::list;

class Graph {
public:
	map<int, bool> visited; //int is key, bool records t/f depending on whether node has been visited
	map<int, list<int>> adj; //Adjacency list, int is key of array that gives access to a linked list
							//of all nodes that are adjacent to that node in the graph

	//function to add an edge to the graph
	void addEdge(int v, int w);

	//DFS traversal of the vertices reachable from v
	void DFS(int v);
};

#endif