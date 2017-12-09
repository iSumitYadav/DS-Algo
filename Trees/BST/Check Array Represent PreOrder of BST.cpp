//http://www.geeksforgeeks.org/check-if-a-given-array-can-represent-preorder-traversal-of-binary-search-tree/

#include<bits/stdc++.h>
using namespace std;

int ifPreOrderOfBSTUtil(int *arr, int start, int end){
	if(start >= end)
		return 1;

	int i=start;

	while(i <= end && arr[i] <= arr[start])
		i++;

	int j = i;
	while(j <= end && arr[start] < arr[j])
		j++;

	if(j != end+1)
		return 0;

	return ifPreOrderOfBSTUtil(arr, start+1, i-1) && ifPreOrderOfBSTUtil(arr, i+1, end);
}

int ifPreOrderOfBST(int arr[], int n){
	return ifPreOrderOfBSTUtil(arr, 0, n-1);
}

int main(){
	int t, n;
	cin >> t;

	while(t--){
		cin >> n;

		int *arr = new int[n];
		for(int i=0; i<n; i++){
			cin >> arr[i];
		}

		if(ifPreOrderOfBST(arr, n))
			cout << "Yes\n";
		else
			cout << "No\n";
	}

	return 0;
}