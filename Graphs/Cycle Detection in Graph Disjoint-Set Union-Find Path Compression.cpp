#include<bits/stdc++.h>
using namespace std;

struct Parent{
	int prnt;
	int rank;
};

class Graph{
	int V;
	list<int> *adj;
	Parent *parent;

public:
	Graph(int v){
		this->V = v;
		adj = new list<int>[V];
		parent = new Parent[V];
		for(int i=0; i<V; i++){
			parent[i].prnt = i;
			parent[i].rank = 0;
		}
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
	if(parent[i].prnt != i)
		parent[i].prnt = findParent(parent[i].prnt);

	return parent[i].prnt;
}

void Graph::unionSet(int a, int b){
	int a_parent = findParent(a);
	int b_parent = findParent(b);

	if(parent[a_parent].rank > parent[b_parent].rank)
		parent[b_parent].prnt = a_parent;
	else if(parent[b_parent].rank > parent[a_parent].rank)
		parent[a_parent].prnt = b_parent;
	else{
		parent[b_parent].prnt = a_parent;
		parent[a_parent].rank++;
	}
}

bool Graph::isCyclic(){
	list<int>::iterator it;

	for(int i=0; i<V; i++){
		for(it=adj[i].begin(); it!=adj[i].end(); it++){
			int a = findParent(i);
			int b = findParent(*it);

			if(a == b)
				return true;

			unionSet(a, b);
		}
	}

	return false;
}

int main(){
	Graph g(4);

	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 0);

	printf("%s\n", g.isCyclic() ? "Cyclic" : "Not Cyclic");

	return 0;
}