#include<bits/stdc++.h>
using namespace std;

void generatePrime(int n){
	int arr[n] = {0};

	// for(int i=2; i<=n; i++){
	for(int i=2; i*i<=n; i++) // Optimization
		if(arr[i] != -1){
			for(int j=2*i; j<=n; j+=i)
				arr[j] = -1;
		}
	}

	int i = 1;
	while(i <= n){
		if(arr[i] != -1)
			cout << i << " ";
		i++;
	}
}

int main(){
	int n;
	cin >> n;

	generatePrime(n);

	return 0;
}