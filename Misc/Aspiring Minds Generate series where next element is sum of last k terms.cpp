#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k, i, sum=0;
	cin >> n >> k;
	int arr[n] = {0};
	
	for(i=0;i<k;i++){
	    cin >> arr[i];
	    sum += arr[i];
	}
	
	int frst = 0;
	for(i=k;i<n;i++){
	    arr[i] = sum;
	    sum = sum - arr[frst] + arr[i];
	    frst++;
	}
	
	for(i=0;i<n;i++)
	    cout << arr[i] << " ";
	
	return 0;
}