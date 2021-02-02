#include <iostream>
using namespace std;

int main(){
	// Adresi heap bellek bölgesinde
	string *isimp = new string; 

	// Adresi yok.
	string *adp;
	
	cout<<*isimp<<endl;
	cout<<*adp<<endl;  // Çalýþtýktan sonra hata verir çünkü gösterdiði bir yer yok veya anlamsýz bir yeri gösteriyor.
	return 0;
}