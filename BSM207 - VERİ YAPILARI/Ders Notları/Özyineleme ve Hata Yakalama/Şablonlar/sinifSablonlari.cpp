#include <iostream> 
using namespace std; 

template <typename Nesne>
class Sayi{ 
	private:
		Nesne deger;
	public: 
		Sayi(Nesne s):deger(s){} 
		Nesne Deger(){
			return deger;
		}
};

int main(){
	Sayi<int> *s1 = new Sayi<int>(50);
	Sayi<float> *s2 = new Sayi<float>(21.84);
	
	cout<<s1->Deger()<<endl;
	cout<<s2->Deger();
	return 0;
}