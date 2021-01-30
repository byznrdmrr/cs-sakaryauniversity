#include <iostream>
using namespace std;

int Toplam(unsigned int sayi){
	if(sayi == 0) return 0;
	return sayi + Toplam(sayi-1);
}

int main()
{
	unsigned int x;
	cout<<"x:";
	cin>>x;
	cout<<Toplam(x);
	return 0;
}