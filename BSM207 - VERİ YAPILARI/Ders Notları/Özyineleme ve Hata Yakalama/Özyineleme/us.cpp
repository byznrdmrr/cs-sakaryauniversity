#include <iostream>
using namespace std;

int Us(int sayi,int us)
{
   if(us==0)return 1;
   return sayi*Us(sayi,us-1);
}

int main()
{
	int x,y;
	cout<<"x:";
	cin>>x;
	cout<<"y:";
	cin>>y;
	cout<<"x^y="<<Us(x,y);
	return 0;
}