#include <iostream>
using namespace std;

int main(){
	int x[]={10,5,21};
	int *p;
	p=x;
	cout<<*p<<endl;  // 10
	cout<<*(p+1)<<endl;  // 5
	cout<<*(p+2)<<endl;  // 21
	return 0;
}