#include<bits/stdc++.h>
using namespace std;

class Graph{
	int V;
	list<char> *adj;
	bool *vi;

public:
	Graph(int);
	void addEdge(char, char);
	void runTopologicalSort();
	void dfs(char, stack<char> &);
};

Graph::Graph(int v){
	V = v;
	adj = new list<char>[V];
	vi = new bool[V];
	for(int i=0; i<v;i++)
		vi[i] = false;
}

void Graph::addEdge(char u, char v){
	adj[u-65].push_back(v);
}

void Graph::dfs(char src, stack<char> &s){
	list<char>::iterator it;

	for(it=adj[src].begin(); it!=adj[src].end(); it++){
		if(!vi[*it-65]){
			vi[*it-65] = true;
			dfs(*it-65, s);
		}
	}

	s.push(src+65);
}

void Graph::runTopologicalSort(){
	stack<char> s;

	for(int src=0; src<V; src++){
		if(!vi[src])
			dfs(src, s);
	}

	while(!s.empty()){
		printf("%c ", s.top());
		s.pop();
	}printf("\n");
}

int main(){
	Graph g(8);

	/*g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(2, 4);
	g.addEdge(3, 5);
	g.addEdge(4, 5);
	g.addEdge(4, 7);
	g.addEdge(5, 6);*/

	g.addEdge('A', 'C');
	g.addEdge('B', 'C');
	g.addEdge('B', 'D');
	g.addEdge('C', 'E');
	g.addEdge('D', 'F');
	g.addEdge('E', 'F');
	g.addEdge('E', 'H');
	g.addEdge('F', 'G');

	printf("Topological Sort: \n");
	g.runTopologicalSort();
	
	return 0;
}