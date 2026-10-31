#include<iostream>
using namespace std;

class Student{
public:	
	string name;
	string id;
	string depart;
	double CGPA;
	string award;
	
	Student(){}
	
	Student(string nam, string Id, string dep, double cgpa){
		name = nam;
		id = Id;
		depart = dep;
		CGPA = cgpa;
		award = "No award";
	}
	
};

void merge(Student arr[], int st, int mid, int end){
	int i = st;
	int j = mid+1;
	Student temp[end - st +1];
	int x=0;
	
	while(i <= mid && j <= end){
		if(arr[i].CGPA >= arr[j].CGPA){
			temp[x] = arr[i];
			i++;
		} else {
			temp[x] = arr[j];
			j++;
		}
		
		x++;
	}
	
	while(i <= mid){
		temp[x] = arr[i];
		i++;
		x++;
	}
	
	while(j <= end){
		temp[x] = arr[j];
		j++;
		x++;
	}
	
	for(int k =0; k< x; k++){
		arr[st+k] = temp[k];
	}
}

void mergeSort(Student arr[], int st, int end){
	if(st >= end) return;
	
	int mid = st + (end - st)/2;
	
	mergeSort(arr, st, mid);
	mergeSort(arr, mid+1, end);
	
	merge(arr, st, mid, end);
}

void assignAwards(Student arr[], int n){
	for(int i =0; i<n; i++){
		if(arr[i].CGPA >= 4.0){
			arr[i].award = "Rector List";
		} else if(arr[i].CGPA >= 3.50){
			arr[i].award = "Dean's List";
		}
	}
}

int main(){
	int n = 30;
	
	Student s[n] = {Student("Hamza", "25K-3098", "SE", 3.60),
        Student("Ali", "25K-3001", "CS", 3.20),
        Student("Ahmed", "25K-3002", "AI", 4.00),
        Student("Usman", "25K-3003", "SE", 3.80),
        Student("Bilal", "25K-3004", "CS", 2.90),

        Student("Hassan", "25K-3005", "AI", 3.50),
        Student("Zain", "25K-3006", "SE", 3.90),
        Student("Umar", "25K-3007", "CS", 3.60),
        Student("Saad", "25K-3008", "AI", 3.10),
        Student("Ahsan", "25K-3009", "SE", 4.00),

        Student("Daniyal", "25K-3010", "CS", 3.40),
        Student("Farhan", "25K-3011", "AI", 3.70),
        Student("Hamid", "25K-3012", "SE", 3.50),
        Student("Talha", "25K-3013", "CS", 2.80),
        Student("Shahzaib", "25K-3014", "AI", 3.90),

        Student("Waleed", "25K-3015", "SE", 3.20),
        Student("Arham", "25K-3016", "CS", 4.00),
        Student("Sameer", "25K-3017", "AI", 3.60),
        Student("Raza", "25K-3018", "SE", 3.30),
        Student("Fahad", "25K-3019", "CS", 3.80),

        Student("Ibrahim", "25K-3020", "AI", 3.50),
        Student("Shayan", "25K-3021", "SE", 2.70),
        Student("Rehan", "25K-3022", "CS", 3.70),
        Student("Adeel", "25K-3023", "AI", 3.90),
        Student("Muneeb", "25K-3024", "SE", 3.10),

        Student("Taha", "25K-3025", "CS", 3.60),
        Student("Noman", "25K-3026", "AI", 3.40),
        Student("Asad", "25K-3027", "SE", 4.00),
        Student("Danish", "25K-3028", "CS", 3.50),
        Student("Saif", "25K-3029", "AI", 2.50)
    };
	
	mergeSort(s, 0, n-1);
	assignAwards(s, n);
	
	cout<<"\nFinal merit List\n";
	
	for(int i =0; i<n; i++){
		cout<< s[i].id << "\t"
		<<s[i].name << "\t"
		<<s[i].depart <<"\t"
		<<s[i].CGPA <<"\t"
		<<s[i].award << endl;
		
	}
	
	return 0;
}



