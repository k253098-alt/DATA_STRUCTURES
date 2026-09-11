#include <iostream>
using namespace std;

void display(int arr[], int n){
	cout <<"Array: ";
	for(int i =0; i<n; i++){
		
		cout << arr[i] <<" ";
	}
	cout <<endl;
}

void shellSort(int arr[], int n){
	int tShifts = 0;
	int tCompare = 0;
	
	for(int gap = n/2; gap > 0; gap = gap/2){
		
		cout <<"Gap: " << gap << endl;
		int compare =0;
		int shift = 0;
		
		for(int i=gap; i<n; i++){
			int temp = arr[i];
			int j =i;
			
			while(j >= gap){
				compare++;
				
				if(arr[j-gap] > temp){
					arr[j] = arr[j-gap];
				    j = j-gap;
				
				    shift++;
				} else {
					break;
				}
				
				
			}
			arr[j] = temp;
		}
		display(arr, n);
		cout <<"Shifts in this gap: " << shift << endl;
		cout <<"Comparisons in this gap: " << compare << endl;
		cout << endl;
		tShifts += shift;
		tCompare += compare;
		
	}
	cout <<"Total Shifts in this sort: " << tShifts << endl;
	cout <<"Total Comparisons in this sort: " << tCompare << endl;
	
}

int main(){
	int arr[] = {90, 20, 80, 30, 70, 40, 60, 50, 10};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	shellSort(arr, size);

	return 0;
}

