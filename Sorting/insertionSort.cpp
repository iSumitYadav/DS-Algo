#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n){
	int i, j, temp;

	for(i=1; i<n; i++){

		j = i-1;
		temp = arr[i];

		while(j >= 0 && arr[j] > temp){
			arr[j+1] = arr[j];
			j--;
		}

		arr[j+1] = temp;

		for(int k=0; k<=i; k++)
			cout << arr[k] << " ";
		cout << endl;
	}

	return;
}

int main() {
	int n, i;
	n = 12;
	cin >> n;
	int *arr = new int[n];
	//9
	//9 7 6 15 16 5 10 11 1

	//int arr[12] = {9, 7, 6, 15, 16, 5, 10, 11, 1, -1, 10, 2};

	for(i=0; i<n; i++){
		cin >> arr[i];
		cout << arr[i] << " ";
	}cout << endl;

	insertionSort(arr, n);

	for(i=0; i<n; i++){
		cout << arr[i] << " ";
	}

	return 0;
}
