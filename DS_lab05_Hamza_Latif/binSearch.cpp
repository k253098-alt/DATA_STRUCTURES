#include <iostream>
using namespace std;

int binSearch(int arr[], int n, int target){
	int high = n-1;
	int low = 0;
	
	while (low <= high){
		
		int mid = (high+low)/2;
		
		if(arr[mid] == target){
			return mid;
		}
		else if(target > arr[mid]){
			low = mid + 1;
		} else {
			high = mid -1;
		}
	}
	return -1;
}


int main(){
	int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14};
	int n = 14;
	
	int target = 13;
	
	cout << binSearch(arr, n, target);
}