
#include <iostream>
using namespace std;

int total = 0;
string courses[4] = {"Progr", "DataS", "OpSys", "CompN"};

bool isSafe(string grid[6][8], int row, int col){
    if(row == 3 && col == 3) return false;
    
    for(int i =0; i<6; i++){
        for(int j=0; j<8; j++){
            if(grid[i][j] != ""){
            	
                if(i == row) return false;  // check row
                if(j == col) return false;  // check column
                if(i-row == j-col || i-row == col-j) return false;  // check diagonal
            }
        }
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

void assignSeats(string grid[6][8], int course){

    if(course == 4){
        display(grid);
        total++;
        return;
    }

    int startRow = 0;
    int endRow = 6;

    if(course == 0){
        endRow = 1;
    }

    for(int row = startRow; row<endRow; row++){
        for(int col = 0; col<8; col++){

            if(isSafe(grid, row, col)){
                grid[row][col] = courses[course];
                assignSeats(grid, course+1);
                grid[row][col] = "";
            }
        }
    }
}

int main(){

    string grid[6][8] = {""};
    assignSeats(grid, 0);
    cout<<"Total valid arrangements: "<<total;
    
    
    
    return 0;
}
