#include <iostream>
#include <string>
using namespace std;

const int n = 4;

void solveMaze(int maze[n][n], int row, int col, string path){
	if(row<0 || row>=n || col<0 || col>=n || maze[row][col] == -1 || maze[row][col] == 0){
		return;
	}
	
	if(row == n-1 && col == n-1){
		cout<<path << endl;
		return;
	}
	
	maze[row][col] = -1; //visited
	
	solveMaze(maze, row+1, col, path +"D ");
	solveMaze(maze, row, col+1, path +"R ");
	solveMaze(maze, row, col-1, path +"L ");
	solveMaze(maze, row-1, col, path +"U ");	
	
	maze[row][col] = 1;
}

int main(){
	int maze[n][n] = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
	string path = "";
	cout<<"All possible paths:" <<endl;
	solveMaze(maze, 0, 0, path);
	
	return 0;
}