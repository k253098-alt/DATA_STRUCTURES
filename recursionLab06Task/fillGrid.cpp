#include<iostream>
using namespace std;
const int n =4;
int grid[n][n] = {{1, 0, 0, 4},{0, 4, 1, 0},{0, 1, 4, 0},{4, 0, 0, 1}};


bool isSafe(int row, int col, int num){
    for(int i = 0; i < n; i++){
        if(grid[row][i] == num || grid[i][col] == num){
            return false;
        }
    }

    if(row < 2 && col < 2){
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                if(grid[i][j] == num) return false;
            }
        }
    }

    if(row < 2 && col >= 2){
        for(int i = 0; i < 2; i++){
            for(int j = 2; j < 4; j++){
                if(grid[i][j] == num) return false;
            }
        }
    }

    if(row >= 2 && col < 2){
        for(int i = 2; i < 4; i++){
            for(int j = 0; j < 2; j++){
                if(grid[i][j] == num) return false;
            }
        }
    }

    if(row >= 2 && col >= 2){
        for(int i = 2; i < 4; i++){
            for(int j = 2; j < 4; j++){
                if(grid[i][j] == num) return false;
            }
        }
    }

    return true;
}


bool fillGrid(int row, int col, int num){
    if(row == n){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
        cout<<endl;
        return false;
    }

    if(col == n) return fillGrid(row+1, 0, 1);

    if(grid[row][col] != 0) return fillGrid(row, col+1, 1);

    for(int num = 1; num <= 4; num++){
        if(isSafe(row, col, num)){
            grid[row][col] = num;

            if(fillGrid(row, col+1, 1)) return true;

            grid[row][col] = 0;
        }
    }

    return false;
}


int main(){
	cout<<"All possible solutions:";
	fillGrid(0, 0, 1);
	
	return 0;
}
