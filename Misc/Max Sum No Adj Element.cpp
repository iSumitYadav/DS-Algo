#include<bits/stdc++.h>
using namespace std;

int maxSum(int arr[], int n){
	int incl_last = arr[0], excl_last=0, incl, excl;

	for(int i=1; i<n; i++){
		incl = excl_last + arr[i];
		excl = max(incl_last, excl_last);

		incl_last = incl;
		excl_last = excl;
	}

	return max(incl, excl);
}

int main(){
	int arr[] = {5, 5, 10, 100, 10, 5};
	int n = sizeof(arr)/sizeof(arr[0]);

	cout << "Max Sum of No Adjacent Elements: " << maxSum(arr, n);

	return 0;
}