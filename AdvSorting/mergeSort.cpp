#include <iostream>
using namespace std;

int arr[] = {78,45,92,63,45,88,51,70};
int n = 8;
int countMerge = 0;

void display(){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void merge(int left,int mid,int right){
    int temp[8];
    int i=left,j=mid+1,k=left;

    while(i<=mid && j<=right){
        if(arr[i]<=arr[j]){
            temp[k]=arr[i];
            i++;
        }
        else{
            temp[k]=arr[j];
            j++;
        }
        k++;
    }

    while(i<=mid){
        temp[k]=arr[i];
        i++;
        k++;
    }

    while(j<=right){
        temp[k]=arr[j];
        j++;
        k++;
    }

    for(int x=left;x<=right;x++){
        arr[x]=temp[x];
    }

    countMerge++;
    cout<<"After merge "<<countMerge<<": ";
    display();
}

void mergeSort(int left,int right){
    if(left>=right) return;

    int mid=(left+right)/2;

    mergeSort(left,mid);
    mergeSort(mid+1,right);
    merge(left,mid,right);
}

int main(){
    cout<<"Original array: ";
    display();

    mergeSort(0,n-1);

    cout<<"Sorted array: ";
    display();

    cout<<"Total merge operations: "<<countMerge;

    return 0;
}
