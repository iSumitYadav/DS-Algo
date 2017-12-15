#include<bits/stdc++.h>
using namespace std;

int lis(int *arr, int n){
	int dp[n], i, j, maxi = INT_MIN, seq;
	for(i=0; i<n; i++){
		dp[i] = 1;
	}

	for(i=1; i<n; i++){
		for(j=0; j<i; j++){
			if(arr[i] > arr[j] && dp[i] < dp[j] + 1){
				dp[i] = dp[j]+1;
				if(maxi < dp[i]){
					seq = i;
					maxi = dp[i];
				}
			}
		}
	}

	cout << arr[seq] << " ";
	for(i=seq-1; i>=0; i--){
		if(dp[i] == dp[seq] - 1){
			cout << arr[i] << " ";
			seq = i;
		}
	}cout << endl;

	return maxi;
}

int main(){
	int arr[] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
	int n = sizeof(arr)/sizeof(arr[0]);

	cout << "LIS of length: " << lis(arr, n) << endl;
	return 0;
}