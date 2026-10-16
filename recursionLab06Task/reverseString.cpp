#include <iostream>
using namespace std;

void reverseSt(string st, int size){
	if(size < 0){
		return;
	}
	cout<<st[size];
	reverseSt(st, size-1);
	
}

int main(){
	string st = "hello";
	reverseSt(st, st.length());
}