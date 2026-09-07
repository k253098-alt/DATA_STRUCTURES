#include <iostream>


using namespace std;


void bubbleSort(int arr[], int n){
	
	for(int i =0; i< n-1; i++){
		
		for(int j = 0; j < n-i-1; j++){
			 
			 if(arr[j] > arr[j+1]){
			 	 int temp = arr[j];
			 	 arr[j] = arr[j+1];
			 	 arr[j+1] = temp;
			 	
			    }
		}
	for(int i =0; i< n; i++){
		
		cout << arr[i] << " " ;
	}
}


int main(){
	
	int arr[] = {3,2,5,6,4,6,2,4,2,1,0};
	int n = sizeof(arr)/sizeof(arr[0]);
	bubbleSort(arr, n);
	
	
	return 0;
}