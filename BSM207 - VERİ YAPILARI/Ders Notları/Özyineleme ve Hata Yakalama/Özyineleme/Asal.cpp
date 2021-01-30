#include <iostream>
using namespace std;

bool Asal(int sayi, int bolen=2){
	if(sayi == bolen || sayi == 1) return true;
	if(sayi % bolen == 0) return false;
	return Asal(sayi,bolen+1);
}

int main()
{
	int x;
	cout<<"x:";
	cin>>x;
	cout<<"Asal(x)="<<(Asal(x) == true ? " Asaldir" : " Asal degildir.");
	return 0;
}