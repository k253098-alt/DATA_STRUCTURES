#include <iostream>
using namespace std;

int arr[]={7314,314,731,34,3147,147,47,7314,4,314};
int n=10;

void display(){
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void countingSort(int exp){
    int count[10]={0};
    int output[10];

    for(int i=0;i<n;i++){
        int digit=(arr[i]/exp)%10;
        count[digit]++;
    }

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

    cout<<"Total passes: "<<pass<<endl;
}

int main(){
    cout<<"Original array: ";
    display();

    radixSort();

    cout<<"Sorted array: ";
    display();

    return 0;
}
