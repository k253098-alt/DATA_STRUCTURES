
#include <iostream>
using namespace std;

int arr[]={40,20,70,10,60,30,50};
int n=7,countPartition=0;

void display(){
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void swapNum(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

int partition(int low,int high){
    int pivot=arr[high];
    int i=low-1;

    cout<<"Pivot: "<<pivot;
    cout<<" Low: "<<low<<" High: "<<high<<endl;

    for(int j=low;j<high;j++){
        if(arr[j]<=pivot){
            i++;
            swapNum(arr[i],arr[j]);
        }
    }

    swapNum(arr[i+1],arr[high]);
    countPartition++;

    cout<<"After partition: ";
    display();

    return i+1;
}

void quickSort(int low,int high){
    if(low<high){
        int p = partition(low,high);
        quickSort(low,p-1);
        quickSort(p+1,high);
    }
}

int main(){
    quickSort(0,n-1);

    cout<<"Sorted array: ";
    display();
    cout<<"Total partitions: "<<countPartition;
    return 0;
}
