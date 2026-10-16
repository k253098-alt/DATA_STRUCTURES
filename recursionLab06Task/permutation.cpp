
#include <iostream>
using namespace std;

const int n = 4;

void permutations(char arr[], int i){
    if(i == n){
        for(int j =0; j <n; j++){
            cout << arr[j];
        }
        cout << endl;
        return;
    }

    for(int j =i; j< n; j++){
        char temp = arr[i];
        arr[i] = arr[j];
        arr[j]= temp;

        permutations(arr, i+1);

        temp = arr[i];
        arr[i]= arr[j];
        arr[j] = temp;
    }
}

int main(){
    char arr[] = {'A', 'B', 'C', 'D'};
    permutations(arr, 0);

    return 0;
}

