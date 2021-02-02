#include <iostream>
using namespace std;

int DegerArttir(){
    static int sayac=0; // Statik bellek bölgesinde
    return ++sayac;
}
int topla(int a,int b){
      int sonuc = a+b;  // Çalýþma aný yýðýnýnda
      return sonuc;
}
int main(){
     cout<<DegerArttir()<<endl;
     cout<<DegerArttir()<<endl;
     cout<<topla(21,10)<<endl;
	 cout<<topla(5,7)<<endl;
     return 0;
}
