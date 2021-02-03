#include "Islem.hpp"

Islem::Islem()
{
	kalanIslemSuresi = rand() %10;
	oncelik = rand() %10;
	kalanIslemSuresi += 5;
}

//Kimlik gonderilir
int Islem::kimlikGonder()
{
	return kimlikNo;
}

//Kimlik eklenir
int Islem::kimlikEkle(int numara)
{
	kimlikNo = numara;
}

//Oncelik eklenir
int Islem::oncelikEkle(int numara)
{
	oncelik = numara;
}

//Kalan sure eksiltilir
void Islem::sureEksilt()
{
	kalanIslemSuresi = kalanIslemSuresi - 5;
	
	//Sure eksi degerlikteyse sifira esitlenir
	if(kalanIslemSuresi < 0)
		kalanIslemSuresi = 0;
}

//Oncelik gonderilir
int Islem::oncelikGonder()
{
	return oncelik;
}

//Sure gonderilir
int Islem::sureGonder()
{
	return kalanIslemSuresi;
}