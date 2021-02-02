#include <iostream>
using namespace std;

int main(){
	int x=10;
	int *p,*r;
	p=&x; 
	r=p;
	cout<<*r; // Ekrana 10 yazar.

}