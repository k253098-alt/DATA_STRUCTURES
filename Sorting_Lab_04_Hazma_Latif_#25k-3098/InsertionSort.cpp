#include <iostream>


using namespace std;


void insertionSort(int arr[], int n){
	
	for(int i =1; i< n; i++){
		
		int temp = arr[i];
		int j = i -1;
		
		while(j >= 0 && arr[j] > temp){
			 
			 arr[j+1] = arr[j];
			 
			j--;
		}
		
		arr[j+1] = temp;
		
	}
	
	for(int i =0; i< n; i++){
		
		cout << arr[i] << " " ;
	}
}


int main(){
	
	int arr[] = {3,2,5,6,4,6,2,4,2,1,0};
	int n = sizeof(arr)/sizeof(arr[0]);
	insertionSort(arr, n);
	
	
	return 0;
}