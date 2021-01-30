#include <iostream>
using namespace std;

class Sayi{
        private:
              int deger;
        public:
              Sayi():deger(0) {  }
			  Sayi(int dgr):deger(dgr) {  }
};

class Ogrenci{
       private:
             string isim;
             Sayi *notu;
       public:
             Ogrenci(string ad,int nt){
                    isim=ad;
                    notu=new Sayi(nt);
             }
            ~Ogrenci(){ // Yýkýcý metot
                     delete notu;
             }
};

int main(){
  Ogrenci *ogr = new Ogrenci("Ali",90);
  delete ogr;
  return 0;
}
