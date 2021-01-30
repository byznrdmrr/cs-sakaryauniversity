#include <iostream>
using namespace std;

int Fib(unsigned int sayi){
	if(sayi == 1 || sayi == 2) return 1;
	return Fib(sayi-1) + Fib(sayi-2);
}

int main()
{
	unsigned int x;
	cout<<"x:";
	cin>>x;
	cout<<"Fib(x)="<<Fib(x);
	return 0;
}