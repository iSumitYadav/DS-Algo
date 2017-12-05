#include<bits/stdc++.h>
using namespace std;

void quickSort(int arr[], int l, int h){
	if(h <= l)
		return;

	/*for(int k=l; k<=h; k++)
		cout << arr[k] << " ";
	cout << endl;*/
	int pivot = arr[h];//cout << pivot << " " << l << " " << h << endl;
	int i = l, j = h-1;
	while(i < j){
		if(arr[i] <= pivot){
			i++;
		}
		/*if(arr[j] > pivot){
			j--;
		}*/
		if(arr[i] > pivot){
			swap(arr[i], arr[j]);
			//i++;
			j--;
		}
	}
	// 9(i) 1 2 3 5 4 7(j) 6
	// 7(i) 1 2 3 5 4(j) 9 6
	// 4(i) 1 2 3 5(j) 7 9 6
	// 4 1(i) 2 3 5(j) 7 9 6
	// 4 1 2(i) 3 5(j) 7 9 6
	// 4 1 2 3(i) 5(j) 7 9 6

	// 4 1 2 3 5 6 9 7

	// 4(i) 1 2 3(j) 5		6		9[i][j] 7
	// 4 1[i] 2 3[j] 5				7 9
	// 4 1 2[i] 3[j] 5				7 9
	// 4 1 2 3[i][j] 5		6		7 9

	// 4[i] 1 2[j] 3	5	6		7 9
	// 2[i] 1[j] 4 3	5	6		7 9
	// 2 1[i][j] 3 4	5	6		7 9
	
	// 2[i][j] 1		3 4	5	6		7 9
	// 1 2				3 4	5	6		7 9

	if(arr[j+1] > arr[h])
		swap(arr[j+1], arr[h]);
	if(i == j && arr[j] > arr[h])
		swap(arr[j], arr[h]);
	//for(int k=l; k<=h; k++)
		//cout << arr[k] << " ";
	cout  << endl;
	pivot = j+1;

	quickSort(arr, l, pivot-1);
	quickSort(arr, pivot+1, h);
}

int main(){
	int i, n;
	cin >> n;
	int arr[n];

	for(i=0; i<n; i++)
		cin >> arr[i];

	quickSort(arr, 0, n-1);

	for(i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << endl;

	return 0;
}