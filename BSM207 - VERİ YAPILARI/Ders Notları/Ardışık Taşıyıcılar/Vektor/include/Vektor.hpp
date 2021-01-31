#ifndef VEKTOR_HPP
#define VEKTOR_HPP

#include "Tasma.hpp"
#define boyut 100
template <typename Nesne>
class Vektor{
	private:
		Nesne *elemanlar;
		int elemanSayisi;
	public:
		Vektor()
		{
			elemanSayisi = 0;
			elemanlar = new Nesne[boyut];
		}
		Vektor(const Vektor &sag) // Copy constructor
		{
			elemanSayisi = 0;
			elemanlar = new Nesne[boyut];
			for(int i=0;i<sag.size();i++){
				insert(i,sag.at(i));
			}
		}
		int size() const
		{
			return elemanSayisi;
		}
		bool isEmpty() const
		{
			return size() == 0;
		}
		const Nesne& at(int i) const throw(Tasma)
		{
			if(i<0 || i>=elemanSayisi) throw Tasma("indeks sinirlar disinda!"); 
			return elemanlar[i]; 
		}
		void erase(int i) throw(Tasma)
		{
			if(i<0 || i>=elemanSayisi) throw Tasma("indeks sinirlar disinda!"); 
			for(int j=i+1;j<elemanSayisi;j++) elemanlar[j - 1] = elemanlar[j];
			elemanSayisi--;
		}
		void insert(int i,const Nesne& yeni) throw(Tasma)
		{
			if(i<0 || i>elemanSayisi) throw Tasma("indeks sinirlar disinda!"); 
			for(int j=elemanSayisi-1;j>=i;j--) elemanlar[j + 1] = elemanlar[j];
			elemanlar[i] = yeni;
			elemanSayisi++;					
		}
		void set(int i,const Nesne& yeni) throw(Tasma)
		{
			if(i<0 || i>=elemanSayisi) throw Tasma("indeks sinirlar disinda!");
			elemanlar[i] = yeni;
		}
		~Vektor()
		{
			delete [] elemanlar;
		}
};
#endif