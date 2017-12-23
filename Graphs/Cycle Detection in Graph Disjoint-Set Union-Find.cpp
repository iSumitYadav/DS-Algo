#include<bits/stdc++.h>
using namespace std;

class Graph{
	int V, E;
	list<int> *adj;
	int *parent;

public:
	Graph(int v, int e){
		this->V = v;
		this->E = e;
		adj = new list<int>[V];
		parent = new int[V];
		for(int i=0; i<V; i++)
			parent[i] = i;
	}

	void addEdge(int, int);
	int findParent(int);
	void unionSet(int, int);
	bool isCyclic();
};

void Graph::addEdge(int u, int v){
	adj[u].push_back(v);
	// No back edge OR edge from dest to src, coz that'll be wrongly detected as a cycle.
}

int Graph::findParent(int i){
	// if(parent[i] == -1)
	// 	return i;

	if(parent[i] == i)
		return i;

	return findParent(parent[i]);
}

void Graph::unionSet(int a, int b){
	int a_set = findParent(a);
	int b_set = findParent(b);

	parent[a_set] = b_set;
}

bool Graph::isCyclic(){
	list<int>::iterator it;

	for(int i=0; i<V; i++){
		for(it=adj[i].begin(); it!=adj[i].end(); it++){
			int x = findParent(i);
			int y = findParent(*it);

			if(x == y)
				return true;

			unionSet(x, y);
		}
	}

	return false;
}

int main(){
	Graph g(4, 5);

	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(0, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 0);

	printf("%s\n", g.isCyclic() ? "Cyclic" : "Not Cyclic");

	return 0;
}