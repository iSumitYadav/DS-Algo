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

	int idx = maxi;
	char ans[idx];

	i=m, j=n;
	ans[idx--] = '\0';

	while(i>0 && j>0){
		if(dp[i][j] == dp[i-1][j]){
			i--;
		}else if(dp[i][j] == dp[i][j-1]){
			j--;
		}else if(dp[i][j] == dp[i-1][j-1]+1){
			ans[idx--] = x[i-1];
			i--;
			j--;
		}
	}

	cout << "LCS of " << x << " and " << y << " is: " << ans << endl;

	return maxi;
}

int main(){
	char x[] = "ABCDGH";
	char y[] = "AEDFHR";

	int m = strlen(x);
	int n = strlen(y);

	cout << "LCS of " << x << " and " << y << " is of length: " << lcs(x, y, m, n) << endl;

	return 0;
}