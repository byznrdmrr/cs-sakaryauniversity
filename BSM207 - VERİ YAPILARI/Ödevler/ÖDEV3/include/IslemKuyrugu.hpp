#ifndef ISLEMKUYRUGU_HPP
#define ISLEMKUYRUGU_HPP

#include "Islem.hpp"

class IslemKuyrugu
{
	public:
		IslemKuyrugu();
		void ekranCiktisi();
		void olustur();
		bool dolu();
		void sirala(int indeks);
		void kuyruguOtele();
		void kuyrugaEkle(Islem* islem);
		Islem* islemGetir();
		Islem* degistir(Islem* islemciIslem);
		int baslangicKimlik;
		~IslemKuyrugu();
		
	private:
		Islem** kuyruk;
		int islemSayisi;
};


#endif