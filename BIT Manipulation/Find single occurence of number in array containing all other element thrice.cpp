// https://www.geeksforgeeks.org/find-the-element-that-appears-once/

#include<bits/stdc++.h>
using namespace std;

int findElement(int *arr, int n){
	int ones = 0, twos = 0, not_thrice = 0;

	for(int i=0; i<n; i++){
		twos = twos | (ones & arr[i]);

		ones = ones ^ arr[i];

		not_thrice = ~(ones & twos);

		ones = ones & not_thrice;
		twos = twos & not_thrice;
	}

	return ones;
}

int main(){
	int arr[] = {1, 1, 20, 3, 3, 20, 20, 15, 4, 1, 4, 3, 4};
	int size = sizeof(arr)/sizeof(arr[0]);

	cout << "Unique Element is: " << findElement(arr, size) << endl;

	cout << "Unique Element is: " << findElement2(arr, size) << endl;

	return 0;
}