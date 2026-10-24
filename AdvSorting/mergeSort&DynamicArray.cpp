#include <iostream>
using namespace std;

int calls=0, merges=0, comparisons=0;

void merge(int arr[],int left,int mid,int right){
    int size=right-left+1;
    int *temp=new int[size];

    int i=left,j=mid+1,k=0;

    while(i<=mid && j<=right){
        comparisons++;
        if(arr[i]<=arr[j])
            temp[k++]=arr[i++];
        else
            temp[k++]=arr[j++];
    }

    while(i<=mid)
        temp[k++]=arr[i++];

    while(j<=right)
        temp[k++]=arr[j++];

    for(int x=0;x<size;x++)
        arr[left+x]=temp[x];

    merges++;
    delete[] temp;
}

void mergeSort(int arr[],int left,int right){
    calls++;

    if(left>=right)
        return;

    int mid=(left+right)/2;
    mergeSort(arr,left,mid);
    mergeSort(arr,mid+1,right);
    merge(arr,left,mid,right);
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;

    if(n<=0){
        cout<<"Invalid size";
        return 0;
    }

    int *arr=new int[n];

    cout<<"Enter elements: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];

    mergeSort(arr,0,n-1);

    cout<<"Sorted array: ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    cout<<"\nRecursive calls: "<<calls;
    cout<<"\nMerge operations: "<<merges;
    cout<<"\nComparisons: "<<comparisons;

    delete[] arr;
    return 0;
}
