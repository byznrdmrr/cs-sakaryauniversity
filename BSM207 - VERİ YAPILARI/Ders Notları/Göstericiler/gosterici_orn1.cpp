#include <iostream>
using namespace std;

int main(){
	int x=10;
	int *p;
	p=&x;  // x deðiþkenin adresini tut
	x++;
	cout<<*p; 
}
