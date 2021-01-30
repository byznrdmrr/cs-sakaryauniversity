#include <iostream> 
using namespace std; 

template <typename Nesne> 
void Karsilastir(Nesne x,Nesne y) {
	if(x>y)cout<<"Buyuk"; 
	else if(x<y)cout<<"Kucuk"; 
	else cout<<"Esit"; 
}

int main() {
	string s="5",v="12";
	Karsilastir(s,v); 
	return 0;
}