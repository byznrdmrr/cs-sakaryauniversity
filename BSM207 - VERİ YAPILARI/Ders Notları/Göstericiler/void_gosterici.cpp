#include <iostream>
using namespace std;

int main(){
	int x=100;
	float a=12.5;
	void* obj;	
	obj=&x;
	cout<<*static_cast<int *>(obj)<<endl;
	obj=&a;
	cout<<*static_cast<float *>(obj)<<endl;	
	return 0;
}