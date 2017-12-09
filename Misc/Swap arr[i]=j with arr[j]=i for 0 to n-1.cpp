#include<bits/stdc++.h>
using namespace std;

void swapIJUtil(int arr[], int n, int i){
	int val = -(i+1);
	i = arr[i] - 1;

	while(arr[i] > 0){
		int new_idx = arr[i] - 1;

		arr[i] = val;

		for(int j=0; j<n; j++)
			cout << arr[j] << " ";
		cout << endl;

		val = -(i+1);
		i = new_idx;
	}
}

void swapIJ(int arr[], int n){
	for(int i=0; i<n; i++)
		arr[i]++;

	for(int i=0; i<n; i++){
		if(arr[i] > 0)
			swapIJUtil(arr, n, i);
	}

	for(int i=0; i<n; i++){
		arr[i] = -arr[i] - 1;
		cout << arr[i] << " ";
	}
}

int main(){
	int arr[] = {3,2,4,7,8,1,0,6,5};//{2, 0, 1, 4, 5, 3};
	int n = sizeof(arr)/sizeof(arr[0]);

	swapIJ(arr, n);

	return 0;
}