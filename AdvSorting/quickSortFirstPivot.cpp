#include <iostream>
using namespace std;

int arr[]={55,25,75,15,65,35,45};
int n=7,comparisons=0;

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
    int pivot=arr[low];
    int i=low;

    cout<<"Pivot: "<<pivot<<endl;

    for(int j=low+1;j<=high;j++){
        comparisons++;
        if(arr[j]<pivot){
            i++;
            swapNum(arr[i],arr[j]);
        }
    }

    swapNum(arr[low],arr[i]);

    cout<<"After partition: ";
    display();

    return i;
}

void quickSort(int low,int high){
    if(low<high){
        int p=partition(low,high);
        quickSort(low,p-1);
        quickSort(p+1,high);
    }
}

int main(){
    quickSort(0,n-1);

    cout<<"Sorted array: ";
    display();
    cout<<"Total comparisons: "<<comparisons;
    return 0;
}
