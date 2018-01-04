// https://www.geeksforgeeks.org/find-smallest-value-represented-sum-subset-given-array/
#include<bits/stdc++.h>
using namespace std;

int findSmallest(int *arr, int n){
	int ans = 1;

	for(int i=0; i<n && arr[i] <= ans; i++)
		ans += arr[i];

	return ans;
}

int main(){
	while(1){
		int n;
		scanf("%d", &n);

		if(n < 1)
			break;

		int *arr = new int[n];
		for(int i=0; i<n; i++)
			scanf("%d", &arr[i]);

		printf("%d\n\n", findSmallest(arr, n));
	}
	return 0;
}