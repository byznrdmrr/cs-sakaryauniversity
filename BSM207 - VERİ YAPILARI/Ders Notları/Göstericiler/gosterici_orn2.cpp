#include <iostream>
using namespace std;

int main(){
	int *p;
	int a=12;
	p=&a;

	cout<<*p<<endl;        // Gösterdiği yerdeki değeri yaz
	cout<<p<<endl;          // Gösterdiği yerin bellek adresi
	cout<<&p<<endl;      // Göstericinin kendi bulunduğu adres
	cout<<&a<<endl;      // a değişkenin bulunduğu adres.
}
