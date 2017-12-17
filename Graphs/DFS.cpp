#include<bits/stdc++.h>
using namespace std;

class Graph{
	int nodes;
	list<int> *edge;

	void depthFirstSearchUtil(int node, bool visited[]);
public:
	Graph(int nodes){
		this->nodes = nodes;
		edge = new list<int>[nodes];
	}

	void addEdge(int a, int b){
		edge[a].push_back(b);
	}

	void depthFirstSearch(int src);
};

void Graph::depthFirstSearch(int src){
	bool *visited = new bool[nodes];
	memset(visited, false, sizeof(visited));

	stack<int> s;
	list<int>::iterator it;

	s.push(src);
	visited[src] = true;

	while(!s.empty()){
		src = s.top();
		s.pop();
		printf("%d ", src);

		for(it=edge[src].begin(); it!=edge[src].end(); it++){
			if(!visited[*it]){
				s.push(*it);
				visited[*it] = true;
			}
		}
	}
}

int main(){
	/*			GRAPH
			0---------1
		   ||		/
		   ||	  /
		   ||	/	 __
		   || /		| |
		   2---------3
		   \		/
		    \	   /
		     \	  /
		      \  /
		       4
		      |_|
	*/
	Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 4);
 
    cout << "Depth First Traversal\n";
    g.depthFirstSearch(2);

	return 0;
}