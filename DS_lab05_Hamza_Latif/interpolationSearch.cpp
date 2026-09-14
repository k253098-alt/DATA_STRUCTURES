#include <iostream>
using namespace std;
int interpolationSearch(int arr[], int n, int target){
   int low = 0;
   int high = n-1;
   while(low <= high && target >=arr[low] && target<=arr[high]) {
     
	  int position = low + ((target-arr[low]) * (high-low))/(arr[high]-arr[low]);
	
	  if(arr[position] == target) {
	  return position; 
    } else if(arr[position]<target){
	      low = position +1;
		} else{
		  high = position -1; 
		} 
	} return -1;
	
} 
		   
int main(){
    int arr[] = {10, 20, 30,40,50,60};
	int n = 6;
	int target = 30;
	int result = interpolationSearch(arr, n, target);
	if (result != -1){
	   cout << "element found at index " << result;
    }
}