#ifndef KUYRUK_HPP
#define KUYRUK_HPP

#include <iostream>
using namespace std;

#include "Tasma.hpp"
#include "KuyrukBos.hpp"

#define BOYUT 100

template <typename Nesne>
class Kuyruk
{
  private:
     Nesne Dizi[BOYUT];
	 int uzunluk;
	 int on;
	 int arka;
	 
	 void arttir(int &indeks)
	 {
		if(++indeks == BOYUT) indeks=0;
	 }
	 
  public:
	Kuyruk()
	{
		makeEmpty(); // Boþ bir kuyruk oluþturmak için
	}
	bool bosmu() const
	{
		return uzunluk == 0;
	}
	bool dolumu() const
	{
		return uzunluk == BOYUT;
	}
	const Nesne& ondekiniGetir() const throw(KuyrukBos)
	{
		if(bosmu()) throw KuyrukBos("Kuyruk Bos");
		
		return Dizi[on];
	}
	int ElemanSayisi() const{
		return arka-on+1;
	}
	void makeEmpty()
	{
		uzunluk=0;
		on=0;
		arka=-1;
	}
	Nesne dequeue() throw(KuyrukBos)
	{
		if(bosmu()) throw KuyrukBos("Kuyruk Bos");
		
		uzunluk--;
		Nesne enOn = Dizi[on];
		arttir(on);
		return enOn;
	}
	void enqueue(const Nesne& yeni) throw(Tasma)
	{
		if(dolumu()) throw Tasma("Kuyruk dolu.");
		
		arttir(arka);
		Dizi[arka]=yeni;
		uzunluk++;
	}
};
#endif