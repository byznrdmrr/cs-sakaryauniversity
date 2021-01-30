#include <iostream>
using namespace std;
class Sayi{
        private:
              int deger;
        public:
              Sayi():deger(0) {  }
			  Sayi(int dgr):deger(dgr) {  }
			  int Deger() { return deger; }
};

int main(){
	Sayi *s1,*s2;
	s1 = new Sayi(50);
	s2=s1;
	//...
	delete s1;
	// ...  Başka işlemler yapılmış 
	Sayi *s3 = new Sayi(220);
	cout<<"s1'in tuttugu adres: "<<s1<<endl;
	cout<<"s2'in tuttugu adres: "<<s2<<endl;
	cout<<"s3'in tuttugu adres: "<<s3<<endl;
	
	cout<<"s2'in tuttugu deger: "<<s2->Deger()<<endl;
	return 0;
}