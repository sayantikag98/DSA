#include<iostream>
using namespace std;

int main(){
	// creating a memory space for storing integer value in heap
	// heap memory allocated space can be accessed via a pointer only
	// access is lost when the stack frame is removed but the memory space is still persistent till the program is running
	int* ptr = new int(10);
	int** dptr = &ptr;
	cout<<*ptr<<" "<<**dptr<<endl;
	delete(ptr);
	cout<<*ptr<<endl;

}