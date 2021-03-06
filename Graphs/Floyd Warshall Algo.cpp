#include<bits/stdc++.h>
using namespace std;

#define V 4
#define INF INT_MAX

void floydWarshall(int g[V][V]){
	int sol[V][V]={0}, path[V][V]={0};

	for(int i=0;i<V; i++){
		for(int j=0; j<V; j++){
			sol[i][j] = g[i][j];

			if(g[i][j] != INF)
				path[i][j] = i;
			else
				path[i][j] = -1;
		}
	}

	for(int k=0; k<V; k++){
		for(int i=0;i<V; i++){
			for(int j=0; j<V; j++){
				if(sol[i][k] != INF && sol[k][j] != INF && sol[i][j] > sol[i][k] + sol[k][j]){
					sol[i][j] = sol[i][k] + sol[k][j];
					path[i][j] = path[k][j];
				}
			}
		}
	}

	printf("Solution Matrix:\n");
	for(int i=0;i<V; i++){
		for(int j=0; j<V; j++){
			printf("%2d ", sol[i][j]!=INF ? sol[i][j] : -1);
		}printf("\n");
	}

	/*printf("\nPath Matrix: \n");
	for(int i=0;i<V; i++){
		for(int j=0; j<V; j++){
			printf("%2d ", path[i][j]);
		}printf("\n");
	}*/

	printf("\nPrint every Existing Path:");
	for(int i=0;i<V; i++){
		for(int j=0; j<V; j++){
			if(i != j){
				int sink = j;
				printf("\nSrc: %d, Sink: %d\n", i, sink);
				while(sink != i){
					printf("%d(%d) <- ", sink, sol[i][sink]);
					sink = path[i][sink];
				}
				printf("%d\n", i);
			}
		}
	}
}

int main(){
	/*
            10
       (0)------->(3)
        |         /|\
      5 |          |
        |          | 1
       \|/         |
       (1)------->(2)
            3           */
    /*int graph[V][V] = { {0,   5,  INF, 10},
                        {INF, 0,   3, INF},
                        {INF, INF, 0,   1},
                        {INF, INF, INF, 0}
                      };*/

	int graph[V][V] = { {  0,  3,    6,  15},
						{INF,  0,   -2, INF},
						{INF, INF,   0,   2},
						{  1, INF, INF,   0}};
 
    floydWarshall(graph);

	return 0;
}