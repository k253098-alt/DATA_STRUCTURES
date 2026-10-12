#include <iostream>
using namespace std;

int total(int num){
	if(num == 0){
		return 0;
	}
	
	return num%10 + total(num/10);
}

int main(){
	int T = total(3256);
	cout<<T;
	return 0;
}