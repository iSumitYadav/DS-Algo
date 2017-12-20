#include<bits/stdc++.h>
using namespace std;

bool subSetSum(int arr[], int n, int sum){
	bool dp[n+1][sum+1];

	for(int i=0; i<=n; i++){
		for(int j=0; j<=sum; j++){
			if(j == 0){
				dp[i][j] = true;
			}else if(i == 0)
				dp[i][j] == false;
			else if(j < arr[i-1]){
				dp[i][j] = dp[i-1][j];
			}else if(j >= arr[i-1]){
				dp[i][j] = dp[i-1][j] || dp[i-1][j - arr[i-1]];
			}
		}
	}

	return dp[n][sum];
}

int main(){
	int arr[] = {2,3,7,8,10};
	int n = sizeof(arr)/sizeof(arr[0]);

	int sum;
	
	while(cin >> sum && sum > -1){
		if(subSetSum(arr, n, sum))
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}