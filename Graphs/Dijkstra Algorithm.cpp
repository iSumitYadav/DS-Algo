#include<bits/stdc++.h>
using namespace std;

class Graph{
	int v, e;
	list<pair<int, int>> *adj;

public:
	Graph(int v){
		this->v = v;
		this->e = 0;
		adj = new list<pair<int, int>>[v];
	}

	void addEdge(int a, int b, int wt){
		adj[a].push_back(make_pair(b, wt));
		adj[b].push_back(make_pair(a, wt)); // This is for Undirected Graph, Working For DAG also
		// e++; // increase count for no. of edges
		// cout << a << " " << adj[a].back().first << " " << adj[a].back().second << endl;
	}

	void printGraph(int);

	void runDijkstra(int);
};

void Graph::printGraph(int src){
	/*int *visited = new int[v];
	memset(visited, 0, sizeof(visited));

	queue<int> q;
	list<pair<int, int>>::iterator it;

	q.push(src);

	while(!q.empty()){
		int src = q.front();
		q.pop();

		cout << src << endl;

		for(it=adj[src].begin(); it!=adj[src].end(); it++){
			cout << src << "---(" << (*it).second << ")---" << (*it).first << endl;
			q.push((*it).first);
		}
	}*/
}

void Graph::runDijkstra(int src){
	int *wts = new int[v], wt;
	int *parent = new int[v];

	for(int i=0;i<v;i++){
		wts[i] = INT_MAX;
		// cout << wts[i] << " ";
		parent[i] = -1;
		// cout << parent[i] << " ";
	}

	wts[src] = 0;
	parent[src] = -1;

	list<pair<int, int>>::iterator it;

	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(src, 0));

	while(!pq.empty()){
		pair<int, int> p = pq.top();
		pq.pop();
		src = p.first;
		wt = p.second;

		for(it=adj[src].begin(); it!=adj[src].end(); it++){
			if(wts[(*it).first] > wt + (*it).second){
				wts[(*it).first] = wt + (*it).second;
				parent[(*it).first] = src;
				pq.push(make_pair((*it).first, wts[(*it).first]));
			}
		}
	}

	printf("Vtx   Wt    Prnt\n");
	for(int i=0; i<v; i++){
		printf("%2d   (%2d)   %2d\n", i, wts[i], parent[i]);
	}cout << endl;
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

	Graph g2(6);
	g2.addEdge(0, 1, 5);
	g2.addEdge(0, 3, 9);
	g2.addEdge(0, 4, 2);
	g2.addEdge(1, 2, 2);
	g2.addEdge(2, 3, 3);
	g2.addEdge(3, 5, 2);
	g2.addEdge(4, 5, 3);

	int src;
	cin >> src;

	//g.printGraph(src);

	g2.runDijkstra(src);

	return 0;
}