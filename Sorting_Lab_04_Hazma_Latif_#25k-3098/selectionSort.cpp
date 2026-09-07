#include <iostream>


using namespace std;


void selectionSort(int arr[], int n){
	
	for(int i =0; i< n; i++){
		
		int minIndex = i;
		
		for(int j= i+1; j <n; j++){
			if(arr[j] < arr[minIndex])
			minIndex = j;
		}
		swap (arr[i], arr[minIndex]);
		
	}
	
	for(int i =0; i< n; i++){
		
		cout << arr[i] << " " ;
	}
}


int main(){
	
	int arr[] = {3,2,5,6,4,6,2,4,2,1,0};
	int n = sizeof(arr)/sizeof(arr[0]);
	selectionSort(arr, n);
	
	
	return 0;
}