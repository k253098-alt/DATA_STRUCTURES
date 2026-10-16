#include<iostream>
using namespace std;

const int n = 4;
const string word = "CAT";

char grid[n][n] = {
    {'Q','X','S','E'},
    {'H','C','V','D'},
    {'E','A','E','L'},
    {'J','T','G','E'}
};

bool search(int row, int col, int x){
	if(x == word.length()) return true;
	
    if(row == n) return false;
	if(col == n) return search(row+1, 0, 0);
	
	if(grid[row][col] == word[x]){
		if(search(row, col+1, x+1)) return true;
		if(search(row+1, col, x+1)) return true;	
	}
	
	if(search(row, col+1, 0)) return true;
	return false;
}

int main(){
	if(search(0, 0, 0)){
		cout<<"CAT found in the grid";
	}else {
		cout <<"CAT not found int the grid";
	}
	
	return 0;
}