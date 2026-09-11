#include <iostream >
#include <utility>
using namespace std;

void display(int arr[], int n, int x){
	cout << "After Pass " << x << ": ";
	
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
			bool isSwapped = false;
		for (int j= 0; j< n-i-1; j++){
		
			compare++;
			
			if (arr[j] > arr[j+1]){
				swap(arr[j], arr[j+1]);
				swaped++;
				isSwapped = true;
			}
			
		}
		
		display(arr, n, i+1);
		if(!isSwapped)
		break;
		
	}
	cout <<"\nArray sorted after " << pass << " passes" << endl;
	cout <<"Total comparisons performed are: " << compare << endl;
	cout <<"Total swappings performed are: " << swaped << endl;
	cout <<"Standard bubble sort will perform " << n-1 << " passes to sort this array" << endl;
	cout <<"Standard bubble sort will have (size-1)! comparisons";
	
}



int main(){
	int arr[] = {55, 61, 67,72, 78, 81, 80, 85};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	bubbleSort(arr, size);

	return 0;
}