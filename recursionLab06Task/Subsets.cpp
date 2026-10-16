#include <iostream>
using namespace std;
const int n = 5;
int arr[] = {2, 3, 5, 6, 8};
int set[n];

void display(int j){
	for(int i =0; i<j; i++){
		cout<<set[i] <<" ";
	}
	cout <<endl;
}

void printSubset(int i, int j){
	if(i == n){
		int sum =0;
		for(int n =0; n<j; n++){
			sum += set[n];
		}
		if(sum == 9){
			display(j);
		    return;
		} else {
			return;
		}
		
	}
	
	set[j] = arr[i];
	printSubset(i+1, j+1); //include
	
	printSubset(i+1, j);  //exclude
}

int main(){
	
	printSubset(0, 0);
	cout<<"All subsets printed";
	return 0;
}