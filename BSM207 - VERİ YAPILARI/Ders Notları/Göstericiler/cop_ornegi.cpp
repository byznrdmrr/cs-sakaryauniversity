#include <iostream>
using namespace std;
class Sayi{
        private:
              int deger;
        public:
              Sayi():deger(0) {  }
			  Sayi(int dgr):deger(dgr) {  }
};
int main(){
	for(int i=0;i<10;i++){
	  Sayi *s = new Sayi(125);
	  cout<<s<<endl;
	  delete s;  // Bu satır silinirse 10 adet çöp oluşur.
	}
	return 0;
}