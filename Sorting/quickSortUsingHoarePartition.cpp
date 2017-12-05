#include<bits/stdc++.h>
using namespace std;

int hoarePartition(int arr[], int l, int h){
	int pElement = arr[l];

	int i = l-1, j = h+1;
	//9 8 7 6 5 4 3 2 1

	while(1){
		do{
			j--;
		}while(arr[j] > pElement);

		do{
			i++;
		}while(arr[i] < pElement);

		if(i < j)
			swap(arr[i], arr[j]);
		else
			return j;
	}
}

void sortDivideConquer(int arr[], int l, int h){
	if(l >= h)
		return;

	int pivot = hoarePartition(arr, l, h);

	sortDivideConquer(arr, l, pivot);
	sortDivideConquer(arr, pivot+1, h);
}

int main(){
	int arr[] = {9,8,7,6,5,4,3,2,1,9,8,7,4,5,5};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	sortDivideConquer(arr, 0, n-1);

	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << endl;

	return 0;
}