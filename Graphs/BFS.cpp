#include<bits/stdc++.h>
using namespace std;

class Graph{
	int nodes;
	list<int> *adj_list;

public:
	Graph(int nodes){
		this->nodes = nodes;
		adj_list = new list<int>[nodes];
	}

	void addEdge(int a, int b){
		adj_list[a].push_back(b);
	}

	void breadthFirstSearch(int src);
};

void Graph::breadthFirstSearch(int src){
	bool *visited = new bool[nodes];
	memset(visited, false, sizeof(visited));

	list<int> q;
	list<int>::iterator it;

	q.push_back(src);
	visited[src] = true;

	while(!q.empty()){
		src = q.front();
		printf("%d ", src);
		q.pop_front();

		for(it=adj_list[src].begin(); it!=adj_list[src].end(); it++){
			if(!visited[*it]){
				q.push_back(*it);
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
	*/
	Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    printf("Breadth First Traversal: \n");
    g.breadthFirstSearch(2);

	return 0;
}