#include <iostream>
using namespace std;

void Yaz(int sayi){
	if(sayi==0)return;
	Yaz(sayi-1);
	cout<<sayi<<" ";
}

int main()
{
	int x;
	cout<<"x:";
	cin>>x;
	Yaz(x);
	return 0;
}