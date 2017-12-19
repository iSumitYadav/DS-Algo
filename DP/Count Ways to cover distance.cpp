// http://www.geeksforgeeks.org/count-number-of-ways-to-cover-a-distance/
#include<bits/stdc++.h>
using namespace std;

int countWays(int n){
	int *dp = new int[n+1];

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	if(n < 4)
		return dp[n];

	for(int i=4; i<=n; i++){
		dp[i] = dp[i-3] + dp[i-2] + dp[i-1];
	}

	return dp[n];
}

int main(){
	int n;
	cin >> n;

	printf("%d", countWays(n));

	return 0;
}