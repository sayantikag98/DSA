#include<iostream>
using namespace std;

void swapByCopy(int a, int b){
	int temp = a;
	a = b;
	b = temp;
}

void swapByPointer(int* c, int* d){
	int temp = *c;
	*c = *d;
	*d = temp;
}

void swapByReference(int& e, int& f){
	int temp = e;
	e = f;
	f = temp;
}

int main(){
	int a = 10, b = 20, c = 30, d = 40, e = 50, f = 60;
	cout<<a<<" "<<b<<endl;
	swapByCopy(a, b);
	cout<<a<<" "<<b<<endl;

	cout<<c<<" "<<d<<endl;
	swapByPointer(&c, &d);
	cout<<c<<" "<<d<<endl;

	cout<<e<<" "<<f<<endl;
	swapByReference(e, f);
	cout<<e<<" "<<f<<endl;
}