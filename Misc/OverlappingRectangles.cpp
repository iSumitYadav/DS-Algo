#include<bits/stdc++.h>
using namespace std;

int areOverlappingRectangles(int ltx1, int lty1, int rbx1, int rby1, int ltx2, int lty2, int rbx2, int rby2){
	// If one rectangle is above or to left of the other rectangle
	if(rbx1 < ltx2 || rby1 > lty2 || rbx2 < ltx1 || rby2 > lty1)
		return 0;

	return 1;
}

int main(){
	int ltx1, lty1, rbx1, rby1, ltx2, lty2, rbx2, rby2;
	cin >> ltx1 >> lty1 >> rbx1 >> rby1 >> ltx2 >> lty2 >> rbx2 >> rby2;

	cout << areOverlappingRectangles(ltx1, lty1, rbx1, rby1, ltx2, lty2, rbx2, rby2);

	return 0;
}