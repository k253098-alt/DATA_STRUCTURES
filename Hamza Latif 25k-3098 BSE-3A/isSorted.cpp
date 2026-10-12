#include <iostream>
using namespace std;

const int size = 10;

void isSorted(int n, int arr[]){
	if(n == size-1){
		cout <<"Array is sorted \n";
		return;
	}
	
	if(arr[n] > arr[n+1]){
		cout <<"Unsorted\n";
		return;
	}
	isSorted(n+1, arr);
	
}


int main(){
	int arr[size] = {5,8,6,8,1,2,47,8,6,1};
	int arr2[size] = {1,2,3,4,5,6,7,8,9,10};
	isSorted(0, arr);
	isSorted(0, arr2);
}
