#include <iostream>
#include <utility>
using namespace std;


void display(int arr[], int n, int gap){
	if(gap >=1 ){
		cout << "Gap: " << gap << endl;
	    for (int i=0; i<n; i++){
	    	cout << arr[i] << " ";
	    }
	
	    cout << endl;
	}
	
}

void combSort(int arr[], int n){
	
	int gap =n;
	bool isSwapped = true;
	
	while(gap > 1 || isSwapped) {
		
		gap = (gap * 10)/13;
		
		isSwapped = false;
		
		for(int i =0; i + gap <n; i++){
			if(arr[i] > arr[i +gap]){
				swap(arr[i], arr[i+gap]);
				isSwapped = true;
			}
		}
		
		display(arr, n, gap);
	}
}

int main(){
	int arr[] = {10, 20, 30, 40, 5, 50, 60, 70};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	combSort(arr, size);
	return 0;
	
}