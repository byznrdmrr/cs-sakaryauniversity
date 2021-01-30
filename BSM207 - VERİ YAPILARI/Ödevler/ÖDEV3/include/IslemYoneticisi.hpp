#ifndef ISLEMYONETICISI_HPP
#define ISLEMYONETICISI_HPP

#include "Islemci.hpp"
#include "IslemKuyrugu.hpp"

class IslemYoneticisi
{
	public:
		void baslat();
		
	private:
		void secenekMenu();
		bool cikisYap;
		int secenek;
		Islemci islemci;
		IslemKuyrugu islemKuyrugu;
};


#endif