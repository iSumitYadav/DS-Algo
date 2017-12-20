#include<bits/stdc++.h>
using namespace std;

bool subSetSum(int arr[], int n, int sum){
	bool dp[n+1][sum+1];
	memset(dp, false, sizeof(dp));
	int i, j;

	for(i=0; i<=n; i++){
		for(j=0; j<=sum; j++){
			if(j == 0){
				dp[i][j] = true;
			}else if(i == 0){
				dp[i][j] == false;
			}
			else if(j < arr[i-1]){
				dp[i][j] = dp[i-1][j];
			}else if(j >= arr[i-1]){
				dp[i][j] = dp[i-1][j] || dp[i-1][j - arr[i-1]];
			}
		}
	}

	/*for(i=0; i<=n; i++){
		for(j=0; j<=sum; j++){
			printf("%d ", dp[i][j]);
		}printf("\n");
	}*/

	if(dp[n][sum]){
		printf("Elements Included in subset for sum=%d are: ", sum);
		i = n, j = sum;
		while(i > 0 && j > 0){
			if(dp[i][j] == dp[i-1][j]){
				i--;
			}else{
				i--;
				j -= arr[i];
				printf("%d ", arr[i]);
			}
		}
	}

	return dp[n][sum];
}

int main(){
	int arr[] = {2, 3, 7, 8, 10};
	int n = sizeof(arr)/sizeof(arr[0]);

	int sum;
	
	while(cin >> sum && sum > -1){
		if(subSetSum(arr, n, sum))
			printf("\nYes\n");
		else
			printf("\nNo\n");
	}

	return 0;
}