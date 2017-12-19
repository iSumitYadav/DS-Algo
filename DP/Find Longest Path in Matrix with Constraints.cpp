// http://www.geeksforgeeks.org/find-the-longest-path-in-a-matrix-with-given-constraints/
#include<bits/stdc++.h>
using namespace std;

#define N 3

int findLongestOverAllUtil(int mat[][N], int i, int j, int dp[][N]){
	if(i < 0 || i >= N || j < 0 || j >= N)
		return 0;

	if(dp[i][j] != -1)
		return dp[i][j];

	if(i > 0 && mat[i][j]+1 == mat[i-1][j])
		return 1 + findLongestOverAllUtil(mat, i-1, j, dp);

	if(i < N-1 && mat[i][j]+1 == mat[i+1][j])
		return 1 + findLongestOverAllUtil(mat, i+1, j, dp);

	if(j > 0 && mat[i][j]+1 == mat[i][j-1])
		return 1 + findLongestOverAllUtil(mat, i, j-1, dp);

	if(j < N-1 && mat[i][j]+1 == mat[i][j+1])
		return 1 + findLongestOverAllUtil(mat, i, j+1, dp);

	return 1;
}

int findLongestOverAll(int mat[][N]){
	int dp[N][N];
	memset(dp, -1, sizeof(dp));

	int ans = 1;

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(dp[i][j] == -1)
				dp[i][j] = findLongestOverAllUtil(mat, i, j, dp);

			ans = max(ans, dp[i][j]);
		}
	}

	return ans;
}

int main(){
	int  mat[N][N] = {{1, 2, 9},
                    {5, 3, 8},
                    {4, 6, 7}};
   cout << "Length of the longest path is " << findLongestOverAll(mat);

   return 0;
}