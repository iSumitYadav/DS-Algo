#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int l, int h){
	int pElement = arr[h];
	int i = l;

	for(int j=l; j<h; j++){
		if(arr[j] < pElement){
			if(i != j)
				swap(arr[i], arr[j]);
			i++;
		}
	}
	swap(arr[i], arr[h]);
	return i;
}

void quickSortTailRecursive(int arr[], int l, int h){
	while(l < h){
		int pivot = partition(arr, l, h);
		quickSortTailRecursive(arr, l, pivot-1);
		l = pivot + 1;
	}
}

int main(){
	int arr[] = {5,9,8,7,6,5,5,5,4,3,2,1,5};
	int n = sizeof(arr)/sizeof(arr[0]);

	quickSortTailRecursive(arr, 0, n-1);

	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << endl;

	return 0;
}