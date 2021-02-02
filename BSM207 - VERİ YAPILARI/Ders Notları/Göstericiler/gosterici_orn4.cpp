#include <iostream>
using namespace std;

int main(){
	int x=3,y=4;
	int *xp,*yp;
	xp=&x;
	yp=&y;
	x=y;
	cout<<*xp<<endl;
	cout<<*yp<<endl;
}