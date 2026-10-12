#include <iostream>
using namespace std;
const int N = 4;

bool isSafe(char board[N][N], int row, int col){
	
	// column check
	for(int i = 0; i < row; i++){
		if(board[i][col] == 'Q') return false;
	}
	
	// upper left diagonal
	for(int i = row-1, j = col-1; j >= 0 && i >= 0; i--,j--){
		if(board[i][j] == 'Q') return false;
	}
	
	// upper right diagonal
	for(int i = row-1, j = col+1; j < N && i >= 0; i--,j++){
		if(board[i][j] == 'Q') return false;
	}
	
	return true;
}

bool NQueens(char board[N][N], int row){
	if(row == N) return true; //all queens placed
	
	for(int j = 0; j < N; j++){
		if(isSafe(board, row, j)){
			board[row][j] = 'Q';
			if(NQueens(board, row+1)) return true;
			board[row][j] = '.';
		}
	}
	
	return false;
}

int main(){
	char board[N][N];
	
	for(int i = 0; i< N; i++){
			for(int j = 0; j < N; j++){
				board[i][j] = '.';
			}
		}
	
	if(NQueens(board, 0)){
		for(int i = 0; i< N; i++){
			for(int j = 0; j < N; j++){
				cout<<board[i][j] << " ";
			}
			cout <<endl;
		}
	} else {
		cout <<"No solution exist.\n";
	}
	
	return 0;
}