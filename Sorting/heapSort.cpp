#include<bits/stdc++.h>
using namespace std;

/*void swap(int *a, int *b){
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}*/

void heapify(int arr[], int n, int i){
	int largest = i;
	int left  = 2*i + 1;
	int right = 2*i + 2;

	if(left < n && arr[largest] < arr[left])
		largest = left;
	if(right < n && arr[largest] < arr[right])
		largest = right;

	if(largest != i){
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}

void heapsort(int arr[], int n){
	for(int i=n/2 - 1; i>=0; i--){
		heapify(arr, n, i);
	}

	for(int i=n-1; i>=0; i--){
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

int main(){
	int i, n;
	cin >> n;

	int arr[n];
	for(i=0; i<n; i++){
		cin >> arr[i];
		cout << arr[i] << " ";
	}cout << endl;
	
	heapsort(arr, n);

	for(i=0; i<n; i++)
		cout << arr[i] << " ";

	return 0;
}