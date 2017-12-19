// http://www.geeksforgeeks.org/count-number-of-ways-to-cover-a-distance/
#include<bits/stdc++.h>
using namespace std;

int countWaysImproved(int n){
	int a=0, b=1, c=2, ans=4;

	for(int i=4; i<=n; i++){
		a = b;
		b = c;
		c = ans;
		ans = a + b + c;
	}

	return ans;
}

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

	printf("%d\n", countWays(n));

	printf("\nImproved Version: O(n) & O(1): %d\n", countWaysImproved(n));

	return 0;
}