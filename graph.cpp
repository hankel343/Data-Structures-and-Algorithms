#include "graph.h"

void Graph::addEdge(int v, int w) {
	adj[v].push_back(w); //add w to v's list
}

void Graph::DFS(int v) {
	//Mark current node as visited and print it
	visited[v] = true;
	std::cout << v << " ";

	//Recurse or all vertices adjacent to this vertex
	list<int>::iterator i; //Declaring a list iterator
	for (i = adj[v].begin(); i != adj[v].end(); i++) {
		if (!visited[*i])
			DFS(*i);
	}

}