#include <iostream >
#include <utility>
using namespace std;

void display(int arr[], int n, int x){
	cout<< "\nArray after " << x << " passes: " << endl;
	
	for(int i =0; i< n; i++){
		
		cout << arr[i] << " " ;
	}
	cout << endl;
}

void bubbleSort(int arr[], int n){
	int pass = 0;
	int compare = 0;
	int swaped = 0;
	for (int i =0; i < n-1; i++){
			pass++;
		for (int j= 0; j< n-i-1; j++){
		
			compare++;
			
			if (arr[j] > arr[j+1]){
				swap(arr[j], arr[j+1]);
				swaped++;
			}
		}
		display(arr, n, i+1);
		
	}
	cout <<"\nPasses: " << pass << endl;
	cout <<"Comparisons: " << compare << endl;
	cout <<"Swappings: " << swaped << endl;
	
	
}



int main(){
	int arr[] = {45, 12, 78, 34, 23, 90};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	bubbleSort(arr, size);

	return 0;
}