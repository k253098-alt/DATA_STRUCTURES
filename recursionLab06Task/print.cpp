#include<iostream>
using namespace std;

void print(int n){
	if(n == 0){
		cout <<n <<" ";
		return;
	}
	
	print(n-1);
	cout<<n <<" ";
}

int main(){
	int n;
	cout<<"Enter value of n: ";
	cin>> n;
	cout<<endl;
	print(n);
}