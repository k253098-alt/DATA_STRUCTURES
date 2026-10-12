#include <iostream>
using namespace std;
static int n =1;
static int sum = 0;
int saving(int day){
	if(day == 1){
		
		return 10;
	}
	
	
	
	return 2*saving(day-1);
}

int main(){
	int n = saving(4);
	cout<<n;
	return 0;
}