#include<bits/stdc++.h>
using namespace std;

int lcs(char x[], char y[], int m, int n){
	int dp[m+1][n+1] = {0}, i, j, maxi = INT_MIN;

	for(i=0; i<=m; i++){
		for(j=0; j<=n; j++){
			if(i==0 || j== 0)
				dp[i][j] = 0;
			else if(x[i-1] == y[j-1])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max(dp[i][j-1], dp[i-1][j]);

			if(maxi < dp[i][j])
				maxi = dp[i][j];
		}
	}

	/*for(i=0; i<=m; i++){
		for(j=0; j<=n; j++){
			cout << dp[i][j] << " ";
		}cout << endl;
	}*/

	return maxi;
}

int main(){
	char x[] = "AGGTABY";
	char y[] = "GXTXAYBY";

	int m = strlen(x);
	int n = strlen(y);

	cout << "LCS of " << x << " and " << y << " is: " << lcs(x, y, m, n) << endl;

	return 0;
}