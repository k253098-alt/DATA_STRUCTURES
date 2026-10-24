#include <iostream>
using namespace std;

int arr[]={4721,305,472,89,3005,721,1000,305,9999,42,870,100};
int n=12;

void display(int a[],int size){
    for(int i=0;i<size;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

void countingSort(int exp){
    int count[10]={0};
    int output[12];

    for(int i=0;i<n;i++){
        int digit=(arr[i]/exp)%10;
        count[digit]++;
    }

    cout<<"Frequency: ";
    display(count,10);

    for(int i=1;i<10;i++)
        count[i]+=count[i-1];

    cout<<"Cumulative: ";
    display(count,10);

    for(int i=n-1;i>=0;i--){
        int digit=(arr[i]/exp)%10;
        output[count[digit]-1]=arr[i];
        count[digit]--;
    }

    cout<<"Output array: ";
    display(output,n);

    for(int i=0;i<n;i++)
        arr[i]=output[i];

    cout<<"Copied back: ";
    display(arr,n);
}

void radixSort(){
    int max=arr[0];

    for(int i=1;i<n;i++){
        if(arr[i]>max)
            max=arr[i];
    }

    int pass=0;
    for(int exp=1;max/exp>0;){
        pass++;
        cout<<"\nPass "<<pass<<endl;
        countingSort(exp);
        if(exp>max/10)
            break;
        exp*=10;
    }

    cout<<"\nTotal passes: "<<pass<<endl;
}

int main(){
    cout<<"Original array: ";
    display(arr,n);

    radixSort();

    cout<<"Final sorted array: ";
    display(arr,n);
    return 0;
}
