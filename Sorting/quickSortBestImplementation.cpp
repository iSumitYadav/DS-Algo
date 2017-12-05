#include<bits/stdc++.h>
using namespace std;

int findPivot(int arr[], int l, int h){
	int pElem = arr[h];
	int i = l;

	for(int j=l; j<h; j++){
		if(arr[j] < pElem){
			if(i != j)
				swap(arr[i], arr[j]);
			i++;
		}
	}
	swap(arr[i], arr[h]);
	return i;
}

//Tail Recursive + Recurse only the Smaller Partition, Iteratively implement Larger Partition
// TC: O(n log n) SC: O(log n)
void quickSort(int arr[], int l, int h){
	while(l < h){
		// Pivot Randomization for Worst Case : O(n log n)
		srand(time(NULL));
		int randIndex = l + (rand() % (h-l+1));
		swap(arr[randIndex], arr[h]);

		int pivot = findPivot(arr, l, h);

		if(pivot - l < h - pivot){
			quickSort(arr, l, pivot-1);
			l = pivot + 1;
		}else{
			quickSort(arr, pivot +1, h);
			h = pivot - 1;
		}
	}
}

int main(){
	int arr[] = {9,8,-97,6,55,4,3,27,1,0};
	int n = sizeof(arr)/sizeof(arr[0]);

	quickSort(arr, 0, n-1);

	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << endl;

	return 0;
}