#include <iostream>
using namespace std;

class Sayi{
        private:
              int deger;
        public:
              Sayi(int dgr=0):deger(dgr) {  }
              int Deger() { return deger; }
};
int main()
{
  Sayi *s = new Sayi(25);
  int (Sayi::*pdeger)();
  pdeger = &Sayi::Deger;
  cout<<(s->*pdeger)();
}
