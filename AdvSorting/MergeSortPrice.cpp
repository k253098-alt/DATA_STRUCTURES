#include <iostream>
using namespace std;

int arr[]={1299,499,2499,799,499,1599,999,299};
int n=8;
int comparisons=0;

void display(){
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void merge(int left,int mid,int right){
    int temp[8];
    int i=left;
	int j=mid+1;
	int k=left;

    cout<<"Left: ";
    for(int x=left;x<=mid;x++)
        cout<<arr[x]<<" ";

    cout<<"\nRight: ";
    for(int x=mid+1;x<=right;x++)
        cout<<arr[x]<<" ";
    
	cout<<endl;

    while(i<=mid && j<=right){
        comparisons++;
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
        temp[k++]=arr[i++];
    }
    while(j<=right){
        temp[k++]=arr[j++];
    }

    for(int x=left;x<=right;x++)
        arr[x]=temp[x];

    cout<<"After merge: ";
    display();
}

void mergeSort(int left,int right){
    if(left>=right)
        return;

    int mid=(left+right)/2;
    mergeSort(left,mid);
    mergeSort(mid+1,right);
    merge(left,mid,right);
}

int main(){
    mergeSort(0,n-1);

    cout<<"\nSorted prices: ";
    display();
    cout<<"Total comparisons: "<<comparisons;
    return 0;
}
