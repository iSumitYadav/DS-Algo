#include<bits/stdc++.h>
using namespace std;

class Graph{
	int v;
	list<pair<int, int>> *adj;

public:
	Graph(int v){
		this->v = v;
		adj = new list<pair<int, int>>[v];
	}
	
	void addEdge(int src, int dest, int wt){
		adj[src].push_back(make_pair(dest, wt));
		adj[dest].push_back(make_pair(src, wt));
		// printf("%d---(%2d)---%d\n", src, wt, dest);
	}
};

int main(){
	Graph g(9);

	g.addEdge(0, 1, 4);
	g.addEdge(0, 7, 8);
	g.addEdge(1, 2, 8);
	g.addEdge(1, 7, 11);
	g.addEdge(2, 3, 7);
	g.addEdge(2, 5, 4);
	g.addEdge(2, 8, 2);
	g.addEdge(3, 4, 9);
	g.addEdge(3, 5, 14);
	g.addEdge(4, 5, 10);
	g.addEdge(5, 6, 2);
	g.addEdge(6, 7, 1);
	g.addEdge(6, 8, 6);
	g.addEdge(7, 8, 7);

	return 0;
}