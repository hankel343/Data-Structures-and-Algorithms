#include <iostream>
#include "graph.h"
using std::cout; using std::endl;

int main(void) {
	Graph g;
	g.addEdge(0, 1);
	g.addEdge(0, 9);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(9, 3);

	cout << "Depth-first traversal of the graph starting at " << "vertex 2\n";
	g.DFS(2);

	return 0;
}