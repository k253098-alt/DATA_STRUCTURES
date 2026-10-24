#include <iostream>
using namespace std;

int arr[]={91,8,1024,56,305,7,120};
int n=7;

void display(){
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void countingSort(int exp){
    int output[7];
    int count[10]={0};

    for(int i=0;i<n;i++)
        count[(arr[i]/exp)%10]++;

    for(int i=1;i<10;i++)
        count[i]+=count[i-1];

    for(int i=n-1;i>=0;i--){
        int digit=(arr[i]/exp)%10;
        output[count[digit]-1]=arr[i];
        count[digit]--;
    }

    for(int i=0;i<n;i++)
        arr[i]=output[i];
}

void radixSort(){
    int max=arr[0];

    for(int i=1;i<n;i++){
        if(arr[i]>max)
            max=arr[i];
    }

    int pass=0;
    for(int exp=1;max/exp>0;){
        countingSort(exp);
        pass++;
        cout<<"After pass "<<pass<<": ";
        display();
        if(exp>max/10)
            break;
        exp*=10;
    }
}

int main(){
    cout<<"Original: ";
    display();

    radixSort();

    cout<<"Sorted: ";
    display();
    return 0;
}
