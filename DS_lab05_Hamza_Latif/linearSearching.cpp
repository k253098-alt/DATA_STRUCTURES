#include <iostream>
using namespace std;

int search(int arr[], int n, int target){
	for(int i =0; i<n; i++){
		if(arr[i] == target){
			return arr[i];
		}
	}
	
}

int main(){
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int n = 10;
	
	int target = 6;
	
	cout << "Target found: " << endl;
	cout << search(arr, n, target) << endl;
	
}