#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP

#include "ElemanYok.hpp"
#include "ListeBos.hpp"
#include "Tasma.hpp"

template <typename Nesne>
class ArrayList{
	private:
		Nesne *elemanlar;
		int elemanSayisi;
		int kapasite;
		void reserve(int boyut)
		{
			 if(kapasite>=boyut) return; // O kadar yer zaten var
			 Nesne *tmp = new Nesne[boyut];
			 for(int j=0;j<elemanSayisi;j++) tmp[j]= elemanlar[j];
			 if(elemanlar != NULL) delete [] elemanlar;
			 elemanlar = tmp;
			 kapasite = boyut;
		}
	public:
		ArrayList() //Varsayýlan Yapýcý metot
		{
			elemanSayisi = 0;
			kapasite=0;
			elemanlar = NULL;
		}
		ArrayList(const ArrayList &sag) // Copy constructor
		{
			elemanSayisi = 0;
			elemanlar = new Nesne[sag->length()];
			for(int i=0;i<sag.size();i++){
				insert(i,sag.at(i));
			}
			kapasite=elemanSayisi;
		}
		int length() const
		{
			return elemanSayisi;
		}
		bool isEmpty() const
		{
			return length() == 0;
		}
		int indexOf(const Nesne& eleman) const throw(ElemanYok)
		{
			for(int i=0;i<elemanSayisi;i++){
				if(elemanlar[i] == eleman)return i;
			}
			throw ElemanYok("Eleman bulunamadi"); 
		}
		const Nesne& elementAt(int i) const throw(ElemanYok)
		{
			if(i<0 || i>=elemanSayisi) throw ElemanYok("Eleman bulunamadi"); 
			return elemanlar[i]; 
		}
		void remove(const Nesne& eleman) throw(ElemanYok)
		{
			for(int i=0;i<elemanSayisi;i++){
				if(elemanlar[i] == eleman){
					removeAt(i);
					return;
				}
			}
			throw ElemanYok("Eleman bulunamadi"); 
		}
		void removeAt(int i) throw(ElemanYok)
		{
			if(i<0 || i>=elemanSayisi) throw ElemanYok("Eleman bulunamadi"); 
			for(int j=i+1;j<elemanSayisi;j++) elemanlar[j - 1] = elemanlar[j];
			elemanSayisi--;
		}
		void add(const Nesne& yeni) //En sona ekler
		{			
			add(elemanSayisi,yeni);				
		}
		void add(int i,const Nesne& yeni) throw(Tasma)
		{
			if(i<0 || i>elemanSayisi) throw Tasma("Indeks sinirlar disinda"); 
			if(elemanSayisi >= kapasite) reserve(max(1,2*kapasite)); //Yer yoksa 2 kat yer ayýr.
			for(int j=elemanSayisi-1;j>=i;j--) elemanlar[j + 1] = elemanlar[j];
			elemanlar[i] = yeni;
			elemanSayisi++;					
		}
		const Nesne& first() const throw(ListeBos)
		{
			if(elemanSayisi == 0) throw ListeBos("Liste bos"); 
			return elemanlar[0];
		}
		const Nesne& last() const throw(ListeBos){
			if(elemanSayisi == 0) throw ListeBos("Liste bos"); 
			return elemanlar[elemanSayisi-1];
		}
		void clear()
		{
			elemanSayisi = 0;
		}
		friend ostream& operator<<(ostream& ekran,ArrayList<Nesne>& sag){
			ekran<<endl;
			for(int i=0;i<sag.elemanSayisi;i++){
				ekran<<sag.elemanlar[i];
				if(i+1!=sag.elemanSayisi)ekran<<" || ";
			}
			return ekran;
		}
		~ArrayList()
		{
			delete [] elemanlar;
		}
};

#endif