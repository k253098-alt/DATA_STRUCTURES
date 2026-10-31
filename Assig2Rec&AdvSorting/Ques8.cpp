#include <iostream>
using namespace std;

static int count = 0;
int mat[100][100];

void findPath(int n, int row, int col, string path){
	if(row == n-1 && col == n-1){
		cout<<path <<endl;
		count ++;
		return;
	}
	if(row<0 || row>=n || col <0 || col >= n || mat[row][col] == 0 || mat[row][col] == -1){
		return;
	}
	
	mat[row][col] = -1;
	findPath(n, row, col+1, path+"R");
	findPath(n, row+1, col, path+"D");
	findPath(n, row, col-1, path+"L");
	findPath(n, row-1, col, path+"U");
	
	mat[row][col] = 1;
}

int main(){
	int n;
	
	cout <<"Enter number of rows for squre matrix: ";
	cin>>n;
	
	cout<<"Enter elementa of matrix (0 for closed cell while 1 for opened):\n";
	for(int i =0; i<n; i++){
		for(int j = 0; j<n; j++){
			cout<<"index["<<i<<"]["<<j<<"]: ";
			cin>>mat[i][j];
		}
	}
	
	findPath(n, 0, 0, "");
	if(count == 0){
		cout<<"No path found\n";
	} else {
		cout<<"Above are all possible paths";
	}
	
	return 0;
}