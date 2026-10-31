
#include <iostream>
using namespace std;

int digits[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int N = 3;
int S = 12;
int code[3];
int total = 0;

void generate(int index, int start, int sum){

    if(index == N){
        if(sum == S){
            for(int i = 0; i < N; i++){
                cout << code[i] << " ";
            }
            cout << endl;
            total++;
        }
        return;
    }

    for(int i = start; i < 9; i++){

        if(sum + digits[i] <= S){
            code[index] = digits[i];
            generate(index + 1, i + 1, sum + digits[i]);
            code[index] = 0;
        }
    }
}

int main(){
    generate(0, 0, 0);

    if(total == 0){
        cout << "No valid access code exists.";
    }
    else{
        cout << "Total valid combinations: " << total;
    }

    return 0;
}
