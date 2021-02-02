#ifndef LISTEGEZICI_HPP
#define LISTEGEZICI_HPP

#include "Dugum.hpp"

template <typename Nesne>
class ListeGezici
{	
	public:
		Dugum<Nesne> *simdiki;  // Listede o anki konum.
		ListeGezici()
		{
			simdiki=NULL;
		}
		ListeGezici(Dugum<Nesne> *yeni):simdiki(yeni) { }
		bool sonaGeldi() const
		{
			return simdiki == NULL;
		}
		/// ilerleme metodu
		void ilerle()
		{
			if(!sonaGeldi()) simdiki=simdiki->ileri;
		}
		const Nesne& getir() const
		{
			//if(sonaGeldi()) return NULL; // Hata oluþur.
			
			return simdiki->eleman;
		}
};
#endif