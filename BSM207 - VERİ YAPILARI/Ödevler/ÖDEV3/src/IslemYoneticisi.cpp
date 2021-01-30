#include "IslemYoneticisi.hpp"

void IslemYoneticisi::baslat()
{
	cikisYap = false;
	
	islemKuyrugu.baslangicKimlik = rand() % 20;
	int indeks = 0;
	while(indeks < 10)
	{
		islemKuyrugu.olustur();
		islemKuyrugu.sirala(indeks);
		indeks++;
	}
	
	//Kullanici cikis yapana kadar dongu surer
	while(!cikisYap)
	{
		islemKuyrugu.ekranCiktisi();
		islemci.yazdir();
		secenekMenu();		
	}
}

//Kullanici secenekleri ekrana verilir
void IslemYoneticisi::secenekMenu()
{
	cout << "\n1.Yeni Islem Al\n";
	cout << "2.Islem Calistir\n";
	cout << "3.Islem Ekle\n";
	cout << "4.Cikis\n";
	
	cin >> secenek;
	
	if(secenek == 1)
	{
		//Islemciye islem eklenip kuyruk duzenlenir
		islemci.islemciyeEkle(islemKuyrugu.degistir(islemci.islemcidenGonder()));
	}
	else if(secenek == 2)
	{
		islemci.calistir();
	}
	else if(secenek == 3)
	{
		islemKuyrugu.olustur();
	}
	else if(secenek == 4)
	{
		cikisYap = true;
	}
}