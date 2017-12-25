#include<bits/stdc++.h>
using namespace std;

int modExpo(int x, int y, int p){
	if(y == 0)
		return 1;

	/*int x_pow_y = x;
	for(int i=2; i<=y; i++)
		x_pow_y = x_pow_y*x;*/

	int x_pow_y = 1;

	// O(log y)
	while(y > 0){
		if(y & 1)
			x_pow_y = x_pow_y * x;

		y = y>>1; // y = y/2
		x = x*x;
	}

	// cout<< x_pow_y << endl;

	return x_pow_y % p;
}

int main(){
	int x, y, p;
	cin >> x >> y >> p;

	cout << modExpo(x, y, p);

	return 0;
}