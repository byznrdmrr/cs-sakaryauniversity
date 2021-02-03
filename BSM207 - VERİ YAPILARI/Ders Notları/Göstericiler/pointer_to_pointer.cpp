#include <iostream>
using namespace std;

int main(){
	int a=10;
	int *p = &a;
	int **pp = &p;
	cout<<*p<<endl;  // 10 yazar
	cout<<**pp<<endl; // 10 yazar
	cout<<*pp<<endl; // a’nın adresi
	cout<<pp<<endl;  // p’nin adresi
	cout<<&pp<<endl; // pp’nin adresi
	return 0;
}