#ifndef LISTE_HPP
#define LISTE_HPP

#include <iostream>
using namespace std;

#include "ElemanYok.hpp"
#include "Tasma.hpp"

template <typename Nesne>
struct Dugum{
	Nesne veri;
	Dugum *ileri;
	/**
		Düðüm sýnýfýnýn yapýcý fonksiyonu.
		@param düðümün taþýyacaðý veri, verilmez ise boþ bir veri oluþturulur.
		@param düðümün göstereceði düðüm, verilmez ise NULL'ý gösterir.
	*/
	Dugum(const Nesne &vr=Nesne(),Dugum *ilr=NULL){
		veri = vr;
		ileri = ilr;
	}
};

template <typename Nesne>
class Liste{
	private:
		Dugum<Nesne> *bas; // Listede baþtaki düðümü tutar.
	public:
		/**
			Yapýcý Fonksiyon
		*/
		Liste(){
			bas = NULL;
		}
		
		/**
			Listenin baþýný gösteren gösterici NULL'ý gösteriyorsa liste boþtur.
		*/
		bool Bosmu() const {
			return bas == NULL;
		}
		
		/**
			Listedeki eleman sayisini döndürür.
		*/
		int Uzunluk() const{
			int uzunluk = 0;
			Dugum<Nesne> *simdiki = bas;
			while(simdiki != NULL){
				simdiki = simdiki->ileri;
				uzunluk++;
			}
			return uzunluk;
		}
		
		/**
			Belirtilen konumdaki düðümü gösteren düðümü bulur.
			@param Ýstenen düðümün konumu
		*/
		Dugum<Nesne>* OncekininKonumuileBul(int konum) const throw(Tasma){
			if(konum < 0 || konum > Uzunluk()) throw Tasma("Konum sinirlar disinda!"); 
			int indeks=1;
			Dugum<Nesne> *simdiki = bas;
			while(simdiki->ileri != NULL && konum!=indeks++) simdiki = simdiki->ileri;
			
			return simdiki;
		}
		
		/**
			Verilen elemaný barýndýran düðümden bir öncekini bulur.
			@param Düðümün içerdiði veri
			@return Bir önceki düðüm
		*/
		Dugum<Nesne>* OncekiniBul(const Nesne& eleman) const throw(ElemanYok){
			Dugum<Nesne> *simdiki = bas;
			while(simdiki->ileri != NULL && simdiki->ileri->veri != eleman) simdiki = simdiki->ileri;
			if(simdiki->ileri->veri != eleman) throw ElemanYok("Eleman bulunamadi"); 
			return simdiki;
		}
		
		/**
			Verilen eleman sona eklenir.
		*/
		void Ekle(const Nesne& yeni)
		{
			int konum = (Bosmu() ? 0 : this->Uzunluk());
			Ekle(yeni,konum);
		}
		
		/**
			Verilen eleman belirtilen konuma eklenir.
		*/
		void Ekle(const Nesne& yeni,int konum) throw(Tasma)
		{
			int indeks=0;
			if(konum == 0) // Baþa ekle
			{
				Dugum<Nesne> *yeniBas = new Dugum<Nesne>(yeni,bas);
				bas=yeniBas;
				return;
			}
			
			try{
				Dugum<Nesne>* onceki = OncekininKonumuileBul(konum);
				// Eklenen konumdan sonraki listenin devamý yeni düðümün ilerisine eklenecek
				onceki->ileri = new Dugum<Nesne>(yeni,onceki->ileri);
			}
			catch(Tasma &tsm){
				throw Tasma("Konum sinirlar disinda!");
			}
		}
		
		/**
			Listenin tüm düðümlerini ekrana yazar
		*/
		void Yaz() const{
			for(Dugum<Nesne> *simdiki=bas;simdiki!=NULL;simdiki = simdiki->ileri){
				cout<<"|"<<simdiki->veri<<"|->";
			}
			cout<<"NULL"<<endl;
		}
		/**
			Verilen elemaný siler.
			@param Silinecek eleman
		*/
		void Sil(const Nesne &eleman) throw(ElemanYok)
		{
			if(bas->veri == eleman) // baþý sil.
			{
				Dugum<Nesne> *eskiBas = bas;
				bas = bas->ileri;
				delete eskiBas;
				return;
			}
		
			try{
				Dugum<Nesne> *onceki = OncekiniBul(eleman);
				Dugum<Nesne> *tmp = onceki->ileri;
				onceki->ileri = onceki->ileri->ileri; // silinen elemaný es geç.
				delete tmp; // Çöp oluþmamasý için.
			}
			catch(ElemanYok &elm){
				throw ElemanYok("Eleman bulunamadi"); 
			}		
		}
		
		/**
			Listenin sonundaki düðümü siler.
		*/
		void SondanSil() throw(ElemanYok){
			if(Bosmu()) throw ElemanYok("Listede eleman yok.");
			if(this->Uzunluk() == 1) Bosalt(); // Baþý sil.
			
			Dugum<Nesne> *onceki = OncekininKonumuileBul(this->Uzunluk()-1);
			Dugum<Nesne> *tmp = onceki->ileri;
			onceki->ileri = NULL;
			delete tmp;
		}
		
		/**
			Listenin baþýndaki düðümü siler.
		*/
		void BastanSil() throw(ElemanYok){
			if(Bosmu()) throw ElemanYok("Listede eleman yok.");
			Dugum<Nesne> *tmp = bas;
			bas = bas->ileri;
			delete tmp;
		}
		
		/**
			Listedki tüm düðümleri belleðe iade eder.
		*/
		void Bosalt()
		{
			while(!Bosmu())
				BastanSil();
		}
		
		/**
			Yýkýcý metot. Tüm düðümleri silmek için Bosalt metodunu çaðýrýr.
		*/
		~Liste()
		{
			Bosalt();
		}
};
#endif