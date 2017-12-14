#include<bits/stdc++.h>
using namespace std;

int lis(int *arr, int n){
	int dp[n], i, j, maxi = INT_MIN;;
	for(i=0; i<n; i++){
		dp[i] = 1;
	}

	for(i=0; i<n; i++){
		for(j=i+1; j<n; j++){
			if(arr[j] > arr[i] && dp[j] < dp[i] + 1){
				dp[j] = dp[i]+1;
				if(maxi < dp[j])
					maxi = dp[j];
			}
		}
	}

	return maxi;
}

int main(){
	int arr[] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
	int n = sizeof(arr)/sizeof(arr[0]);

	cout << "LIS of length: " << lis(arr, n) << endl;
	return 0;
}