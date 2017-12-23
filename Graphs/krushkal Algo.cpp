#include<bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> pipii;
typedef pair<int, int> pii;

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

public:
	Graph(int);
	void addEdge(int, int, int);
	void runKrushkalAlgo();
};

Graph::Graph(int v){
	this->V = v;
	adj = new list<pii>[V];
}

void Graph::addEdge(int u, int v, int wt){
	adj[u].push_back(make_pair(v, wt));
	adj[v].push_back(make_pair(u, wt));
}

void Graph::runKrushkalAlgo(){
	bool *vi = new bool[V];
	for(int i=0; i<V; i++){
		vi[i] = false;
	}

	priority_queue<pipii, vector<pipii>, compare> pq, temp;

	queue<pii> q;
	list<pii>::iterator lit;

	// seed random for a truly random function
	srand(time(NULL));
	int src = rand() % V, wt;

	q.push(make_pair(src, 0));
	vi[src] = true;

	while(!q.empty()){
		src = q.front().first;cout << src << " ";
		wt = q.front().second;
		q.pop();

		for(lit=adj[src].begin(); lit!=adj[src].end(); lit++){
			// if(vi[src] == true && vi[(*lit).first] == false)
				pq.push(make_pair((*lit).second, make_pair(src, (*lit).first)));

			if(vi[(*lit).first] == false){
				vi[(*lit).first] = true;
				q.push(make_pair((*lit).first, (*lit).second));
			}
		}
	}
cout<<endl;
	/*for(int i=0; i<V-1; i++){
		cout << pq.top().second.first << " " << pq.top().first << " " << pq.top().second.second << endl;
		pq.pop();
		pq.pop();
	}*/

	temp = pq;cout<<endl;
	while(!temp.empty()){
		cout << temp.top().first << " " << temp.top().second.first << " " << temp.top().second.second << endl;
		temp.pop();
	}cout << "---------------" << endl;
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

	g.runKrushkalAlgo();

	return 0;
}