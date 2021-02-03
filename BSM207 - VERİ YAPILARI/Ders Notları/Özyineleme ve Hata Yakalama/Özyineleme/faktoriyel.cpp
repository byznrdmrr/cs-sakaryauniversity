#include <iostream>
using namespace std;

int Fakt(unsigned int sayi){
	if(sayi == 0) return 1;
	return sayi * Fakt(sayi-1);
}

int main()
{
	unsigned int x;
	cout<<"x:";
	cin>>x;
	cout<<"x!="<<Fakt(x);
	return 0;
}