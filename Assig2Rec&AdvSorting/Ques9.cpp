#include <iostream>
using namespace std;

bool isSafe(string grid[6][8], string course, int row, int col){
	
	
	bool found = false;
	if(row > 0){
		for(int i=0; i< 8; i++){
			if(grid[0][i] == "Progr") found = true;
		}
		if(!found){
			return false;
		}
	}
	
	for(int i =0; i<8; i++){   // check row
		if(grid[row][i] == course) return false;
	}
	
	for(int i =0; i<6; i++){   // check column
		if(grid[i][col] == course) return false;
	}
	
	for(int i=row-1,j=col-1; i>=0 && j>=0; i--,j--){  //upper left diagonal
		if(grid[i][j] == course) return false;
	}
	
	for(int i=row-1,j=col+1; i>=0 && j<8; i--,j++){  //upper right diagonal
		if(grid[i][j] == course) return false;
	}
	
	return true;
}

void display(string grid[6][8]){
	for(int i = 0; i<6 ;i++){
		for(int j=0; j<8; j++){
			cout<<grid[i][j] <<"  ";
		}
		cout<<endl;
	}
	
	cout<<endl<<endl;
}

void assignSeats(string grid[6][8], int row, int col){
	if(row == 6){
		display(grid);
		return;
	}
	
	if(row == 3 && col == 3){
		assignSeats(grid, row, col+1);
	    return;
	}
	    
	
	if(col == 8){
		assignSeats(grid, row+1, 0);
	    return;
	}
	
	if(isSafe(grid, "Progr", row, col)){
		grid[row][col] = "Progr";
		assignSeats(grid, row, col+1);
		grid[row][col] = "";
	}
	
	if(isSafe(grid, "DataS", row, col)){
		grid[row][col] = "DataS";
		assignSeats(grid, row, col+1);
		grid[row][col] = "";
	}
	
	if(isSafe(grid, "OpSys", row, col)){
		grid[row][col] = "OpSys";
		assignSeats(grid, row, col+1);
		grid[row][col] = "";
	}
	
	if(isSafe(grid, "CompN", row, col)){
		grid[row][col] = "CompN";
		assignSeats(grid, row, col+1);
		grid[row][col] = "";
	}
	
}


int main(){
	
	string grid[6][8] = {""};
	assignSeats(grid, 0, 0);
	
	return 0;
}
