#include <iostream>
using namespace std;

class Sayi{
        private:
              int deger;
        public:
              Sayi():deger(0) {  }
};

int main(){
	Sayi *s = new Sayi();
	delete s;
	return 0;
}
