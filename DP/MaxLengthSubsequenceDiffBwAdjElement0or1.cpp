#include<bits/stdc++.h>
using namespace std;

// Consecutive Elements O(n)
int LLS(int arr[], int n){
	int i=0, j=1, diff=0, maxLength=0;

	while(j < n){
		diff = abs(arr[j-1] - arr[j]);
		if(diff <= 1){
			if(j-i+1 > maxLength)
				maxLength = j-i+1;
		}else{
			i = j;
		}
		j++;
	}

	return maxLength;
}

int maxLenSubseq(int arr[], int n){
	int mls[n], max = 0;

	for(int i=0; i<n;i++)
		mls[i] = 1;

	for(int i=1; i<n; i++){
		for(int j=0; j<i; j++){
			if(abs(arr[i] - arr[j]) <= 1 && mls[i] < mls[j]+1){
				mls[i] = mls[j] + 1;
				if(max < mls[i])
					max = mls[i];
			}
		}
	}

	return max;
}

int main(){
	int arr[] = {-2, -1, 5, -1, 4, 0, 3};//{2, 5, 6, 3, 7, 6, 5, 8};
	int n = sizeof(arr)/sizeof(arr[0]);

	//cout << LLS(arr, n) << endl;

	cout << maxLenSubseq(arr, n);

	return 0;
}