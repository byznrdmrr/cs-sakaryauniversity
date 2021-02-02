#include "Kuyruk.hpp"
struct Ogrenci
{
	int no;
	string adSoyad;
	Ogrenci(int numara,string ad)
	{
		no=numara;
		adSoyad=ad;
	}
};
int main()
{
	Kuyruk<Ogrenci*> *kuyruk = new Kuyruk<Ogrenci*>();
	Ogrenci *ali = new Ogrenci(205,"Ali Yilmaz");
	Ogrenci *mehmet = new Ogrenci(205,"Mehmet Korkmaz");
	kuyruk->enqueue(ali);
	kuyruk->enqueue(mehmet);
	cout<<kuyruk->ondekiniGetir()->adSoyad<<endl;
	kuyruk->dequeue();
	kuyruk->dequeue();
	kuyruk->enqueue(ali);
	delete kuyruk;
	delete ali;
	delete mehmet;
	return 0;
}