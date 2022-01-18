#include<iostream>
using namespace std;

void func1(){
	int x = 10, y = 20;
	// in below syntax we can update the value of the memory address stored by ptr
	// and also can make ptr point to a different memory location because there is no const 
	int* ptr = &x;
	*ptr = 100; // possible
	cout<<*ptr<<endl;
	ptr = &y; // possible
	cout<<*ptr<<endl;
}

void func2(){
	int x = 10, y = 20;
	// in below syntax we cannot update the value of the memory address stored by ptr
	// but can make ptr point to a different memory location
	const int* ptr = &x;
	// *ptr = 100; // not possible
	cout<<*ptr<<endl;
	ptr = &y; // possible
	cout<<*ptr<<endl;
}

void func3(){
	int x = 10, y = 20;
	// in the below syntax the value stored by the memory address pointer by ptr can be updated 
	// but ptr now cannot point to a different memory location
	int* const ptr = &x;
	*ptr = 100; // possible
	cout<<*ptr<<endl;
	// ptr = &y; // not possible
	cout<<*ptr<<endl;
}

void func4(){
	int x = 10, y = 20;
	// in below syntax we cannot update the value of the memory address stored by ptr
	// and also cannot make ptr point to a different memory location
	const int* const ptr = &x;
	// *ptr = 100; // not possible
	cout<<*ptr<<endl;
	// ptr = &y; // not possible
	cout<<*ptr<<endl;
}

void func5(){
	const int x = 10, y = 20;
	// int* ptr = &x; // throws error because the pointer should be const int* but it is here int*
	// *ptr = 100; // 
	// cout<<*ptr<<endl;
	// ptr = &y; 
	// cout<<*ptr<<endl;
}

void func6(){
	const int x = 10, y = 20;
	// in below syntax we cannot update the value of the memory address stored by ptr
	// but can make ptr point to a different memory location
	const int* ptr = &x; // syntax is ok because it is const int* pointer
	// *ptr = 100; // not possible
	cout<<*ptr<<endl;
	ptr = &y; // possible
	cout<<*ptr<<endl;
}

void func7(){
	const int x = 10, y = 20;
	// int* const ptr = &x; // throws error because it is not const int* but int* pointer
	// *ptr = 100; 
	// cout<<*ptr<<endl;
	// ptr = &y;
	// cout<<*ptr<<endl;
}

void func8(){
	const int x = 10, y = 20;
	// in below syntax we cannot update the value of the memory address stored by ptr
	// and also cannot make ptr point to a different memory location
	const int* const ptr = &x; // syntax is ok because it is const int* pointer
	// *ptr = 100; // not possible
	cout<<*ptr<<endl;
	// ptr = &y; // not possible
	cout<<*ptr<<endl;
}



int main(){
	func1();
	func2();
	func3();
	func4(); 
	func5();
	func6();
	func7();
	func8();
}