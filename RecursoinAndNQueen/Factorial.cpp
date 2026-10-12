#include <iostream>
using namespace std;

int Fac(int n){
	if(n == 1){
		return 1;
	}
	
	return n*Fac(n-1);
}

int main(){
	int f = Fac(5);
	cout <<f;
	return 0;
}