#include <iostream>
using namespace std;
int const n = 4;

bool isSafe(char board[n][n], int r, int c){
	// row check
	for(int i=0; i<c ;i++){
		if(board[r][i] == 'Q') return false;
	}
	
	// column check
	for(int i=0; i<r ;i++){
		if(board[i][c] == 'Q') return false;
	}
	
	//upper left diagonal
	for(int i=r-1, j=c-1; i>=0 && j>=0; i--,j--){
		if(board[i][j] == 'Q') return false;
	}
	
	//upper right diagonal
	for(int i=r-1, j=c+1; i>=0 && j<n; i--,j++){
		if(board[i][j] == 'Q') return false;
	}
	
	return true;
}

bool NQueens(char board[n][n], int row){
	if(row == n) return true; // all queens placed
	
	for(int i=0; i<n; i++){
		if(isSafe(board, row, i)){
			board[row][i] = 'Q';
			if(NQueens(board, row+1)) return true;
			board[row][i] = '.';
		}
	}
	
	return false;
}

int main(){
	char board[n][n];
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			board[i][j] = '.';
		}
	}
	
	if(NQueens(board, 0)){
		for(int i=0; i<n; i++){
		    for(int j=0; j<n; j++){
		    	cout<<board[i][j] <<" ";
		    }
		    
		    cout <<endl;
	    }
	}  else {
		cout <<"No solution exist.\n";
	}
	
	return 0;
}