#include <iostream>
using namespace std;

class Kisi{
	private:
		string adi;
	public:
		Kisi(string ad):adi(ad){ }
};
class Arac{
	private:
		Kisi *surucu;
		float hiz;
		
	public:
		Arac(string surucuAdi,float hz){    // Yapýcý fonksiyon 
				surucu = new Kisi(surucuAdi);
				hiz=hz;
			}
		~Arac()   // Yýkýcý fonksiyon.
		{
			delete surucu;
		}
};

int main()
{
	Arac *a = new Arac("Mehmet",75);
	delete a;
	return 0;
}
