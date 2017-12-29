#include<bits/stdc++.h>
using namespace std;

// O(n^3)
int pythagoreanTriplet(int arr[], int n){
	for(int i=0; i<n-2; i++){
		for(int j=i+1; j<n-1; j++){
			for(int k=j+1; k<n; k++){
				int x = arr[i]*arr[i], y = arr[j]*arr[j], z = arr[k]*arr[k];

				if(x + y == z || y + z == x || z + x == y)
					return 1;
			}
		}
	}

	return 0;
}

// O(n^2)
int pythagoreanTripletImproved(int arr[], int n){
	// Squaring is necessary coz of negative elements
	for(int i=0; i<n; i++)
		arr[i] = arr[i] * arr[i];

	sort(arr, arr+n);

	for(int i=n-1; i>=2; i--){
		int l=0, r=i-1;

		while(l < r){
			if(arr[i] == arr[l] + arr[r])
				return 1;

			(arr[i] > arr[l] + arr[r]) ? l++ : r--;
		}
	}

	return 0;
}

int main(){
	int arr[] = {1, 2, 3, 4, 5};
	int n = sizeof(arr)/sizeof(arr[0]);

	printf("%s\n", pythagoreanTriplet(arr, n) ? "Pythagorean Triplet Found" : "NO Pythagorean Triplet Found");

	printf("\n%s\n", pythagoreanTripletImproved(arr, n) ? "Pythagorean Triplet Found" : "NO Pythagorean Triplet Found");

	return 0;
}