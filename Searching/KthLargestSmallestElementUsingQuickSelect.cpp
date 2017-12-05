#include<bits/stdc++.h>
using namespace std;

int findPivot(int arr[], int l, int h){
	int pivot = arr[h];
	int j = l;

	for(int i=l; i<h; i++){
		if(arr[i] < pivot){
			if(i != j){
				swap(arr[i], arr[j]);
			}
			j++;
		}
	}

	swap(arr[j], arr[h]);
	return j;
}

int quickSelect(int arr[], int l, int h, int k){
	if(l > h)
		return -1;

	//optimization for existing method: Pick Random element as pivot
	//Impl: get a random index and replace with last element
	srand(time(NULL));
	int randIndex = (rand() % (h-l+1)) + l;
	//cout << randIndex << endl;
	swap(arr[randIndex], arr[h]);

	int pos = findPivot(arr, l, h);
	if(pos+1 == k)//coz pos is indexing starting from 0 and k from 1
		return arr[pos];

	if(pos+1 > k)
		quickSelect(arr, l, pos-1, k);
	else
		quickSelect(arr, pos+1, h, k);
}

int kthSmallestElement(int arr[], int n, int k){
	return quickSelect(arr, 0, n-1, k);
}

int main(){
	int arr[] = {12, 3, 5, -7, 4, 19, 26};//{4,2,1,5,3,6,7,9,8,10};
	int n = sizeof(arr)/sizeof(arr[0]);

	int k = 2;
	for(k=1;k<=n; k++)
		cout << k << " Smallest Element: " << kthSmallestElement(arr, n, k) << endl;

	return 0;
}