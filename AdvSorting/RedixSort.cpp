#include <iostream>
using namespace std;

int arr[]={329,457,657,839,436,720,355};
int n=7;

void display(int a[],int size){
    for(int i=0;i<size;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

void countingSort(int exp){
    int count[10]={0};
    int output[7];

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

    cout<<"Output: ";
    display(output,n);

    for(int i=0;i<n;i++)
        arr[i]=output[i];
}

void radixSort(){
    int max = arr[0];

    for(int i=1; i<n;i++){
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
}

int main(){
    cout<<"Original: ";
    display(arr,n);

    radixSort();

    cout<<"\nSorted array: ";
    display(arr,n);
    return 0;
}
