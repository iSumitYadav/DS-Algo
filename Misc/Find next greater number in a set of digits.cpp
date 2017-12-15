// http://www.geeksforgeeks.org/find-next-greater-number-set-digits/
#include<bits/stdc++.h>
using namespace std;

int findNextGreaterUtil(int arr[], int n){
	int i=n-2;

	while(i>=0 && arr[i] >= arr[i+1]){
		i--;
	}

	if(i == -1)
		return -1;

	int smallest_gt_d = i+1;

	for(int j=i+1; j<n; j++){
		if(arr[j] < arr[smallest_gt_d])
			smallest_gt_d = j;
	}

	swap(arr[i], arr[smallest_gt_d]);

	sort(arr+i+1, arr+n);
	int no = arr[0];
	for(int i=1; i<n; i++){
		no = no*10 + arr[i];
	}

	return no;
}

int findNextGreater(int n){
	int *arr = new int[100];
	int dup = n, i=0;

	while(dup){
		arr[i++] = dup%10;
		dup = dup/10;
	}

	int arr_len = i;

	for(int j=0; j<i; j++){
		swap(arr[j], arr[--i]);
	}

	return findNextGreaterUtil(arr, arr_len);
}

int main(){
	int n = 534976;

	cout << "Next Greater No. of same digits as " << n << " is: " << findNextGreater(n) << endl;

	return 0;
}