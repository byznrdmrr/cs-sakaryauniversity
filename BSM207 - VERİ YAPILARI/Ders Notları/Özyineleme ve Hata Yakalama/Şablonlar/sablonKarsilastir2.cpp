#include <iostream> 
using namespace std; 

template <typename Nesne> 
void Karsilastir(Nesne &x,Nesne &y) {
	if(x>y)cout<<"Buyuk"; 
	else if(x<y)cout<<"Kucuk"; 
	else cout<<"Esit"; 
}

class Sayi{ 
	private:
		int deger;
	public: 
		Sayi(int s):deger(s){} 
		int Deger(){
			return deger;
		}
		bool operator>(Sayi &s)
		{
			return (deger > s.Deger());
		} 
		bool operator<(Sayi &s){
			return (deger < s.Deger());
		}
};

int main() {
	Sayi *s1 = new Sayi(100);
	Sayi *s2 = new Sayi(25);
	
	Karsilastir(*s1,*s2); 
	delete s1;
	delete s2;
	return 0;
}