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

int main(){
	int arr[] = {1, 2, 3, 4, 5};
	int n = sizeof(arr)/sizeof(arr[0]);

	printf("%s\n", pythagoreanTriplet(arr, n) ? "Pythagorean Triplet Found" : "NO Pythagorean Triplet Found");

	return 0;
}