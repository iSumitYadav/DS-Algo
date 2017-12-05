#include<bits/stdc++.h>
using namespace std;

int *closestSumPairBruteForce(int arr[], int n, int sum){
	int diff = INT_MAX;
	int p1, p2;

	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			int currDiff = abs(arr[i] + arr[j] - sum);
			if(currDiff < diff){
				p1 = i;
				p2 = j;
				diff = currDiff;
			}
		}
	}

	cout << "closest Sum Pair for sum=" << sum << " : " << arr[p1] << " and " << arr[p2] << endl;

	static int response[2] = {arr[p1], arr[p2]};
	return response;
}

void closestSumPair(int arr[], int n, int sum, int result[]){
	int diff = INT_MAX;
	int p1, p2, i=0, j=n-1;

	while(i <= j){
		int currSum = arr[i] + arr[j];
		int currDiff = abs(currSum - sum);
		if(currDiff < diff){
			p1 = i;
			p2 = j;
			diff = currDiff;
		}
		if(currSum > sum)
			j--;
		else if(currSum < sum)
			i++;
		else{
			result[0] = arr[i];
			result[1] = arr[j];
			return;
		}
	}

	result[0] = arr[p1];
	result[1] = arr[p2];
	return;
}

int main(){
	int arr[] = {10, 22, 28, 29, 30, 40};
	int n = sizeof(arr)/sizeof(arr[0]);

	int sum;
	cin >> sum;

	int *result = closestSumPairBruteForce(arr, n, sum);
	for(int i=0; i<2; i++)
		cout << result[i] << " ";

	cout << endl;

	result[2];
	closestSumPair(arr, n, sum, result);
	for(int i=0; i<2; i++)
		cout << result[i] << " ";

	return 0;
}