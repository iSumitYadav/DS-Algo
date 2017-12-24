// https://www.geeksforgeeks.org/articulation-points-or-cut-vertices-in-a-graph/
#include<bits/stdc++.h>
using namespace std;

class Graph{
	int V;
	list<int> *adj;
	void articulationPointUtil(int, vector<bool> &, vector<int> &, vector<int> &, vector<int> &, set<int> &, int *);

public:
	Graph(int v);
	void addEdge(int u, int v);
	void articulationPoint();
};

Graph::Graph(int v){
	V = v;
	adj = new list<int>[V];
}

void Graph::addEdge(int u, int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void Graph::articulationPointUtil(int u, vector<bool> &visited, vector<int> &parent, vector<int> &discovery, vector<int> &low, set<int> &ap, int *curr_time){

	int children = 0;
	visited[u] = true;
	discovery[u] = low[u] = ++(*curr_time);

	list<int>::iterator it;
	for(it=adj[u].begin(); it!=adj[u].end(); it++){
		if(!visited[*it]){
			children++;
			parent[*it] = u;

			articulationPointUtil(*it, visited, parent, discovery, low, ap, curr_time);

			// 
			low[u] = min(low[u], low[*it]);

			// If root node and has more than 1 child, then it's an articulation point
			if(parent[u] == -1 && children >= 2){
				ap.insert(u);
			}

			// If not root node and discovery of parent node is before the earliest of the child node discovered under this parent node
			if(parent[u] != -1 && low[*it] >= discovery[u]){
				ap.insert(u);
			}
		}
		// Back-Edge, if the child of current node is already explored and not parent of current node : it means this child node is explored before this current parent by some other parent node having an edge to this child and then it's possible that it's disovered before the current parent
		else if(*it != parent[u]){
			low[u] = min(low[u], discovery[*it]);
		}
	}
}

void Graph::articulationPoint(){
	vector<bool> visited(V, false);
	vector<int> parent(V, -1);
	vector<int> discovery(V, -1);
	vector<int> low(V, -1);
	set<int> ap;
	int curr_time = 0;

	srand(time(NULL));
	int src = rand()%V;

	for(int i=0; i<V; i++){
		if(!visited[i]){
			articulationPointUtil(i, visited, parent, discovery, low, ap, &curr_time);
		}
	}

	set<int>::iterator it;
	for(it=ap.begin(); it!=ap.end(); it++){
			cout << *it << " ";
	}
}

int main(){
	cout << "Articulation points in first graph \n";
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.articulationPoint();
 
    cout << "\nArticulation points in second graph \n";
    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.articulationPoint();
 
    cout << "\nArticulation points in third graph \n";
    Graph g3(7);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 0);
    g3.addEdge(1, 3);
    g3.addEdge(1, 4);
    g3.addEdge(1, 6);
    g3.addEdge(3, 5);
    g3.addEdge(4, 5);
    g3.articulationPoint();

    cout << "\nArticulation points in fourth graph \n";
    Graph g4(8);
    g4.addEdge(0, 1);
    g4.addEdge(0, 2);
    g4.addEdge(1, 2);
    g4.addEdge(2, 3);
    g4.addEdge(3, 4);
    g4.addEdge(4, 5);
    g4.addEdge(4, 6);
    g4.addEdge(5, 6);
    g4.addEdge(5, 7);
    
    g4.articulationPoint();

	return 0;
}