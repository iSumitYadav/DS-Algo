#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

class Compare{
public:
    bool operator() (pipii one, pipii two){
        if(one.first != two.first)
        	return one.first > two.first;
        else
        	return one.second.first < two.second.first;
    }
};

class Graph{
	int V;
	list<pii> *adj;

public:
	Graph(int v){
		this->V = v;
		adj = new list<pii>[v];
	}
	
	void addEdge(int src, int dest, int wt){
		adj[src].push_back(make_pair(dest, wt));
		adj[dest].push_back(make_pair(src, wt));
		// printf("%d---(%2d)---%d\n", src, wt, dest);
	}

	void primsAlgo(int);
};

void Graph::primsAlgo(int src){
	bool *visited = new bool[V];
	int *wts = new int[V];
	int *parent = new int[V];
	for(int i=0; i<V; i++){
		visited [i] = false;
		wts[i] = INT_MAX;
		parent[i] = -1;
	}

	int wt, u, v, idx;

	// (wt, (u, v))
	priority_queue<pipii, vector<pipii>, Compare> pq ,temp;
	pq.push(make_pair(0, make_pair(-1, src)));
	wts[src] = 0;

	list<pii>::iterator it;

	while(!pq.empty()){
		/*temp = pq;
		while(!temp.empty()){
			cout << temp.top().first << " " << temp.top().second.first << " " << temp.top().second.second << endl;
			temp.pop();
		}cout << "---------------" << endl;*/

		pipii edge = pq.top();
		pq.pop();
		wt = edge.first;
		u = edge.second.first;
		v = edge.second.second;
		visited[v] = true;

		for(it=adj[v].begin(); it!=adj[v].end(); it++){
			if(visited[(*it).first]==false && (*it).second < wts[(*it).first]){
				idx = (*it).first;
				wts[idx] = (*it).second;
				pq.push(make_pair(wts[idx], make_pair(v, idx)));
				parent[idx] = v;
			}
		}
		
	}

	printf("prnt  wt    V\n");
	for(int i=1; i<V; i++){
		printf("%d----(%d)----%d\n", parent[i], wts[i], i);
	}
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

	int src;
	scanf("%d", &src);

	g.primsAlgo(src);

	return 0;
}