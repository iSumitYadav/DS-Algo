#include<bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> pipii;
typedef pair<int, int> pii;

struct Parent{
	int prnt;
	int rank;
};

class compare{
public:
	bool operator()(pipii one, pipii two){
		if(one.first != two.first)
			return one.first > two.first;

		return one.second.first < two.second.first;
	}
};

class Graph{
	int V;
	list<pii> *adj;
	Parent *parent;

public:
	Graph(int);
	void addEdge(int, int, int);
	void runKrushkalAlgo();
	int findParent(int);
	void unionSet(int, int);
};

Graph::Graph(int v){
	this->V = v;
	adj = new list<pii>[V];
	parent = new Parent[V];
	for(int i=0; i<V; i++){
		parent[i].prnt = i;
		parent[i].rank = 0;
	}
}

void Graph::addEdge(int u, int v, int wt){
	adj[u].push_back(make_pair(v, wt));
	adj[v].push_back(make_pair(u, wt));
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
	else if(parent[a_parent].rank < parent[b_parent].rank)
		parent[a_parent].prnt = b_parent;
	else{
		parent[b_parent].prnt = a_parent;
		parent[a_parent].rank++;
	}
}

void Graph::runKrushkalAlgo(){
	bool *vi = new bool[V];
	for(int i=0; i<V; i++){
		vi[i] = false;
	}

	priority_queue<pipii, vector<pipii>, compare> pq;

	queue<pii> q;
	list<pii>::iterator lit;

	// seed random for a truly random function
	srand(time(NULL));
	int src = rand() % V, dest, wt, src_parent, dest_parent;

	q.push(make_pair(src, 0));
	vi[src] = true;

	while(!q.empty()){
		src = q.front().first;
		wt = q.front().second;
		q.pop();

		for(lit=adj[src].begin(); lit!=adj[src].end(); lit++){
			pq.push(make_pair((*lit).second, make_pair(src, (*lit).first)));

			if(vi[(*lit).first] == false){
				vi[(*lit).first] = true;
				q.push(make_pair((*lit).first, (*lit).second));
			}
		}
	}

	while(!pq.empty()){
		wt = pq.top().first;
		src = pq.top().second.first;
		dest = pq.top().second.second;

		src_parent = findParent(src);
		dest_parent = findParent(dest);

		if(src_parent != dest_parent){
			printf("%2d----(%2d)----%2d\n", src, wt, dest);
			unionSet(src_parent, dest_parent);
		}
		pq.pop();
	}printf("\n");
}

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

	printf("MST using Krushkal Algo:\n\n");
	g.runKrushkalAlgo();

	Graph g2(4);

	g2.addEdge(0, 1, 10);
	g2.addEdge(0, 2, 6);
	g2.addEdge(0, 3, 5);
	g2.addEdge(1, 3, 15);
	g2.addEdge(2, 3, 4);

	printf("\n\nMST using Krushkal Algo:\n\n");
	g2.runKrushkalAlgo();

	return 0;
}