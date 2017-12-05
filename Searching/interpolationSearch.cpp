// Avg. case complexity is O(log(log(n)))[elements must be uniformly distributed] better than Binary Search O(log(n))
#include<bits/stdc++.h>
using namespace std;

int interpolationSearch(int *arr, int size, int key){
	int lo = 0, hi = size-1;

	while(lo <= hi && key >= arr[lo] && key <= arr[hi]){
		int pos = lo + (key - arr[lo])*((double)(hi - lo)/(arr[hi] - arr[lo]));

		if(key == *(arr+pos))
			return pos;

		if(key > arr[pos])
			lo = pos + 1;
		else
			hi = pos - 1;
	}
	return -1;
}

int main(){
	int i, n;
	cin >> n;

	int *arr = new int[n];
	for(i=0; i<n; i++){
		cin >> arr[i];
		cout << arr[i] << " ";
	}cout << endl;

	int key;
	cout << "Enter Key to search: ";
	cin >> key;

	cout << "Key " << key << " found at pos: " << interpolationSearch(arr, n, key) << endl;

	return 0;
}