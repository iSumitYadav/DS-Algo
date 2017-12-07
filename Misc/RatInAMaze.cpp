#include<bits/stdc++.h>
using namespace std;

void printPathUtil(int maze[][4], int x, int y, int n, string s){
	if(x > 3 || y > 3 || x < 0 || y < 0)
		return;

	if(x == 3 && y == 3){
		cout << s << endl;
		return;
	}

	if(x+1 <= 3 && maze[x+1][y] == 1){
		s += "D";
		int temp = maze[x][y];
		maze[x][y] = 0;
		printPathUtil(maze, x+1, y, n, s);
		maze[x][y] = temp;
		s.pop_back();
	}

	if(y-1 >= 0 && maze[x][y-1] == 1){
		s += "L";
		int temp = maze[x][y];
		maze[x][y] = 0;
		printPathUtil(maze, x, y-1, n, s);
		maze[x][y] = temp;
		s.pop_back();
	}

	if(y+1 <= 3 && maze[x][y+1] == 1){
		s += "R";
		int temp = maze[x][y];
		maze[x][y] = 0;
		printPathUtil(maze, x, y+1, n, s);
		maze[x][y] = temp;
		s.pop_back();
	}

	if(x-1 >= 0 && maze[x-1][y] == 1){
		s += "U";
		int temp = maze[x][y];
		maze[x][y] = 0;
		printPathUtil(maze, x-1, y, n, s);
		maze[x][y] = temp;
		s.pop_back();
	}
}

void printPath(int maze[4][4], int n){
	if(maze[0][0] == 0)
		return;

	string s = "";

	return printPathUtil(maze, 0, 0, n, s);
}

/*vector<string> v;

void printPathUtil(int maze[MAX][MAX], int x, int y, int n, string s){
	if(x > MAX || y > MAX || x < 0 || y < 0)
		return;

	if(x == MAX && y == MAX){
		v.push_back(s);
		return;
	}

	if(x+1 <= MAX && maze[x+1][y] == 1){
		s += "D";
		int temp = maze[x][y];
		maze[x][y] = 0;
		printPathUtil(maze, x+1, y, n, s);
		maze[x][y] = temp;
		s.pop_back();
	}

	if(y-1 >= 0 && maze[x][y-1] == 1){
		s += "L";
		int temp = maze[x][y];
		maze[x][y] = 0;
		printPathUtil(maze, x, y-1, n, s);
		maze[x][y] = temp;
		s.pop_back();
	}

	if(y+1 <= MAX && maze[x][y+1] == 1){
		s += "R";
		int temp = maze[x][y];
		maze[x][y] = 0;
		printPathUtil(maze, x, y+1, n, s);
		maze[x][y] = temp;
		s.pop_back();
	}

	if(x-1 >= 0 && maze[x-1][y] == 1){
		s += "U";
		int temp = maze[x][y];
		maze[x][y] = 0;
		printPathUtil(maze, x-1, y, n, s);
		maze[x][y] = temp;
		s.pop_back();
	}
}*/

/*vector<string> printPath(int m[MAX][MAX], int n)
{
    v.clear();
    if(m[0][0] == 0)
		return v;

	string s = "";

	printPathUtil(m, 0, 0, n, s);
	return v;
}*/

int main(){
	int maze[4][4] = {{1,0,0,0}, {1,1,0,1}, {0,1,0,0}, {0,1,1,1}};//{{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
	int n = 4;

	printPath(maze, n);

	/*vector<string> v = printPath(maze, n);

	vector<string>::iterator it;
	for(it=v.begin(); it!=v.end(); it++)
		cout << (*it) << endl;*/

	return 0;
}

