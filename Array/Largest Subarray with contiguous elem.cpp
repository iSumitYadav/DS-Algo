// https://www.geeksforgeeks.org/length-largest-subarray-contiguous-elements-set-1/
#include<bits/stdc++.h>
using namespace std;

int func(int *arr, int n){
	int max_len = 1;

	for(int i=0; i<n-1; i++){
		int min_elem = arr[i];
		int max_elem = arr[i];

		for(int j=i+1; j<n; j++){
			min_elem = min(min_elem, arr[j]);
			max_elem = max(max_elem, arr[j]);

			if(max_elem - min_elem == j - i)
				max_len = max(max_len, max_elem - min_elem + 1);
		}
	}
	return max_len;
}

int main(){
	while(1){
		int n;
		scanf("%d", &n);

		if(n < 1)
			break;

		int *arr = new int[n];
		for(int i=0; i<n; i++)
			scanf("%d", &arr[i]);

		printf("Length of Largest SubArray with contiguous Elements: %d\n\n", func(arr, n));
	}
	return 0;
}