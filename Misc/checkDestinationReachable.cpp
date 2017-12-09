// http://www.geeksforgeeks.org/check-destination-reachable-source-two-movements-allowed/
#include<bits/stdc++.h>
using namespace std;

bool isDestReachable(int source_x, int source_y, int dest_x, int dest_y){
	if(source_x > dest_x || source_y > dest_y)
		return false;

	if(source_x == dest_x && source_y == dest_y)
		return true;

	return isDestReachable(source_x, source_y+source_x, dest_x, dest_y) || isDestReachable(source_x+source_y, source_y, dest_x, dest_y);
}

int main(){
	int source_x = 2, source_y = 10;
    int dest_x = 26, dest_y = 12;
    if (isDestReachable(source_x, source_y, dest_x, dest_y))
        cout << "True\n";
    else
        cout << "False\n";
    return 0;
}