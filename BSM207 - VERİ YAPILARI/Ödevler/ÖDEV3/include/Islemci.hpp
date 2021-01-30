#ifndef ISLEMCI_HPP
#define ISLEMCI_HPP

#include "Islem.hpp"

class Islemci
{
	public:
		Islemci();
		void calistir();
		void islemciyeEkle(Islem* islem);
		Islem* islemcidenGonder();
		void yazdir();
		~Islemci();
	private:
		Islem* islemciIslem;
		bool bosYazdir;
};


#endif