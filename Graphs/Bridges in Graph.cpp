// https://www.geeksforgeeks.org/bridge-in-a-graph/
#include<bits/stdc++.h>
using namespace std;

class Graph{
	int V;
	list<int> *adj;
	void findBridgesUtil(int, vector<bool> &, vector<int> &, vector<int> &, vector<int> &, int *);

public:
	Graph(int);
	void addEdge(int, int);
	void findBridges();
};

Graph::Graph(int v){
	V = v;
	adj = new list<int>[V];
}

void Graph::addEdge(int u, int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void Graph::findBridgesUtil(int src, vector<bool> &visited, vector<int> &parent, vector<int> &discovery_time, vector<int> &lowest_time, int *curr_time){

	visited[src] = true;
	discovery_time[src] = lowest_time[src] = ++(*curr_time);

	list<int>::iterator it;
	for(it=adj[src].begin(); it!=adj[src].end(); it++){
		if(!visited[*it]){
			parent[*it] = src;
			findBridgesUtil(*it, visited, parent, discovery_time, lowest_time, curr_time);

			lowest_time[src] = min(lowest_time[src], lowest_time[*it]);

			// if the curr node has already been discovered/explored before it's child than this src node is connected via a Bridge
			if(discovery_time[src] < lowest_time[*it])
				cout << src << " " << *it << endl;

		}else if(*it != parent[src]){
			lowest_time[src] = min(lowest_time[src], discovery_time[*it]);
		}
	}
}

void Graph::findBridges(){
	vector<bool> visited(V, false);
	vector<int> parent(V, -1);
	vector<int> discovery_time(V, -1);
	vector<int> lowest_time(V, -1);

	int curr_time = 0;

	for(int i=0 ;i<V; i++){
		findBridgesUtil(i, visited, parent, discovery_time, lowest_time, &curr_time);
	}
}

int main(){
	cout << "Bridges in first graph \n";
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.findBridges();
 
    cout << "\nBridges in second graph \n";
    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.findBridges();
 
    cout << "\nBridges in third graph \n";
    Graph g3(7);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 0);
    g3.addEdge(1, 3);
    g3.addEdge(1, 4);
    g3.addEdge(1, 6);
    g3.addEdge(3, 5);
    g3.addEdge(4, 5);
    g3.findBridges();

	return 0;
}