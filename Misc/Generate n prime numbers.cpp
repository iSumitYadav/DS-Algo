#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, count=2, c, i = 3;
	cin >> n;

	if(n < 2)
		cout << "No prime Numbers less than 2\n";
	else{
		cout << "2 ";

		while(count <= n){
			for(c=2; c<= sqrt(i-1); c++){
				if(i%c == 0)
					break;
			}

			if(c == i){
				cout << c << " ";
				count++;
			}
			i++;
		}
	}

	return 0;
}