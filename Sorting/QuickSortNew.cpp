#include<bits/stdc++.h>
using namespace std;

void printArr(int *arr, int start, int end){
	for(int i=start; i<=end; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int findPivot(int *arr, int l, int h){
	int j = l, pivot = arr[h];

	for(int i=l; i<h; i++){
		if(arr[i] < pivot){
			if(i != j){
				swap(arr[i], arr[j]);
			}
			j++;
		}
		//printArr(arr, l, h);
	}
	swap(arr[j], arr[h]);
	//printArr(arr, l, h);
	return j;
}

void quickSort(int *arr, int l, int h){
	if(l >= h)
		return;

	int pivot = findPivot(arr, l, h);

	quickSort(arr, l, pivot-1);
	quickSort(arr, pivot+1, h);
}

int main(){
	int i, n;
	cin >> n;

	int *arr = new int[n];
	for(i=0; i<n; i++)
		cin >> arr[i];

	quickSort(arr, 0, n-1);

	for(i=0; i<n; i++)
		cout << arr[i] << " ";

	return 0;
}