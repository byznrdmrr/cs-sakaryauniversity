#ifndef LISTE_HPP
#define LISTE_HPP

#include "Dugum.hpp"
#include "ListeGezici.hpp"

template <typename Nesne>
class Liste
{
	private:
		Dugum<Nesne> *basDugum;  // içinde eleman olmayan sadece baþ tarafý tutan Dugum.
	public:
		Liste()
		{
			basDugum = new Dugum<Nesne>();
		}
		
		bool Bosmu() const
		{
			return basDugum->ileri == NULL;
		}
		
		// Liste gezici þeklinde listenin baþýný döndürür.
		ListeGezici<Nesne> ListeBasi() const
		{
			return ListeGezici<Nesne>(basDugum);
		}
		
		// Liste gezici þeklinde listenin ilk elemanýný döndürür
		ListeGezici<Nesne> Ilk() const
		{
			return ListeGezici<Nesne>(basDugum->ileri);
		}
		
		// Liste gezici þeklinde listenin son elemanýný döndürür
		ListeGezici<Nesne> Son() const
		{
			//if(this->Bosmu())  Hata oluþur.
			Dugum<Nesne> *son = new Dugum<Nesne>();
			
			for(ListeGezici<Nesne> itr = this->Ilk();!itr.sonaGeldi();itr.ilerle())son->eleman=itr.getir();
			
			return ListeGezici<Nesne>(son);
		}
		
		void yaz()
		{
			if(this->Bosmu())
				cout<<"Liste bos."<<endl;
			else
			{
				ListeGezici<Nesne> itr = this->Ilk();
				for( ; !itr.sonaGeldi(); itr.ilerle())
					cout<<itr.getir()<<" ";
			}
			
			cout<<endl;
		}
		
		ListeGezici<Nesne> bul(const Nesne& aranan) const
		{
			ListeGezici<Nesne> *itr = basDugum->ileri;
			while(itr != NULL && itr->eleman != aranan) itr=itr->ileri;
			
			return ListeGezici<Nesne>(itr);
		}
		
		// belirtilen elemandan ilk gördüðü yerde listeden çýkarýr.
		void sil(const Nesne& aranan)
		{
			ListeGezici<Nesne> p = oncekiniBul(aranan);
			
			if(p.simdiki->ileri != NULL)
			{
				Dugum<Nesne> *eskiDugum = p.simdiki->ileri;
				p.simdiki->ileri = p.simdiki->ileri->ileri; // silinen elemaný es geç.
				delete eskiDugum; // Çöp oluþmamasý için.
			}
		}
		
		// belirtilen konumdan eleman çýkarýr.
		void konumdanCikar(int konum)
		{
			ListeGezici<Nesne> p = oncekiniKonumuIleBul(konum);
			
			if(p.simdiki->ileri != NULL)
			{
				Dugum<Nesne> *eskiNode = p.simdiki->ileri;
				p.simdiki->ileri = p.simdiki->ileri->ileri; // silinen elemaný es geç.
				delete eskiNode; // Çöp oluþmamasý için.
			}
		}
		
		// belirtilen konumdaki elemaný getirir.
		ListeGezici<Nesne> konumdakiniGetir(int konum)
		{
			ListeGezici<Nesne> p = oncekiniKonumuIleBul(konum);
			
			if(p.simdiki->ileri != NULL)
			{
				Dugum<Nesne> *istenenNode = p.simdiki->ileri;
				return ListeGezici<Nesne>(istenenNode);
			}
			
			return NULL;
		}
		
		// Aranan Dugum'un bir öncesini getirir.
		ListeGezici<Nesne> oncekiniBul(const Nesne& aranan) const
		{
			Dugum<Nesne> *itr = basDugum;
			while(itr->ileri != NULL && itr->ileri->eleman != aranan) itr = itr->ileri;
			
			return ListeGezici<Nesne>(itr);
		}
		
		// Aranan konumun bir öncesini getirir.
		ListeGezici<Nesne> oncekiniKonumuIleBul(int konum) const
		{
			int indeks=0;
			Dugum<Nesne> *itr = basDugum;
			while(itr->ileri != NULL && konum!=indeks++) itr = itr->ileri;
			
			return ListeGezici<Nesne>(itr);
		}
		
		// yeni elemaný belirtilen konuma ekler.
		void ekle(const Nesne& yeni,int konum)
		{
			int indeks=0;
			ListeGezici<Nesne> itr = oncekiniKonumuIleBul(konum);
			
			itr.simdiki->ileri = new Dugum<Nesne>(yeni,itr.simdiki->ileri);
		}
		
		// yeni elemaný listede p'den sonrasýna ekler.
		void ekle(const Nesne& yeni,const ListeGezici<Nesne>& p)
		{
			if(p.simdiki != NULL)
				p.simdiki->ileri = new Dugum<Nesne>(yeni,p.simdiki->ileri);
		}
		
		// Listeyi boþaltýr.
		void bosalt()
		{
			while(!Bosmu())
				sil(Ilk().getir());
		}
		// Yýkýcý metot
		~Liste()
		{
			bosalt();
			delete basDugum;
		}
};
#endif