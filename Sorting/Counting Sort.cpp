#include<bits/stdc++.h>
using namespace std;

#define RANGE 9

void countingSort(int arr[], int n){
	int *count = new int[RANGE+1];
	memset(count, 0, RANGE+1);

	// count the element occureneces
	for(int i=0; i<n; i++)
		count[arr[i]]++;

	// get the correct position of the element in the array
	for(int i=1; i<RANGE; i++)
		count[i] += count[i-1];

	int *out = new int[n];

	// place the element in their correct position in output array
	for(int i=0; i<n; i++){
		out[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
	}

	for(int i=0; i<n; i++)
		arr[i] = out[i];
}

int main(){
	int arr[] = {1,4,1,2,7,5,2};
	int n = sizeof(arr)/sizeof(arr[0]);

	countingSort(arr, n);

	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << endl;

	return 0;
}