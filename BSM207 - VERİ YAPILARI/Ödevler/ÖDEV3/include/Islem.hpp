#ifndef ISLEM_HPP
#define ISLEM_HPP

#include<iostream>
#include <windows.h>
#include <stdlib.h>
using namespace std;

class Islem
{
	public:
		Islem();
		int kimlikEkle(int numara);
		int oncelikEkle(int numara);
		void sureEksilt();
		int kimlikGonder();
		int oncelikGonder();
		int sureGonder();	
	private:
		int kimlikNo;
		int oncelik;
		int kalanIslemSuresi;
};


#endif