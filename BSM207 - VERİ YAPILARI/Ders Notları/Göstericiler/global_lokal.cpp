#include <iostream>
using namespace std;

int sayi = 0;

int Arttir(int x){
	return ++x;
}
int main()
{
	cout<<Arttir(sayi)<<endl;
	cout<<sayi<<endl;
	return 0;
}
