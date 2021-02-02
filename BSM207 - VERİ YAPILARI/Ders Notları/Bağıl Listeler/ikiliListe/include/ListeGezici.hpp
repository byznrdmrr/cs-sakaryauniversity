#ifndef LISTEGEZICI_HPP
#define LISTEGEZICI_HPP

#include "Node.hpp"

template <typename Nesne>
class ListeGezici
{	
	public:
		Node<Nesne> *current;  // Listede o anki konum.
		ListeGezici()
		{
			current=NULL;
		}
		
		ListeGezici(Node<Nesne> *yeni):current(yeni) { }
		
		bool isPastEnd() const
		{
			return current == NULL;
		}
		
		/// ilerleme metodu
		void advance()
		{
			if(!isPastEnd()) current=current->next;
		}
		
		// geriye doðru ilerleme metodu.
		void reverse()
		{
			if(!isPastEnd()) current=current->prev;
		}
		
		const Nesne& retrieve() const
		{
			//if(isPastEnd()) return NULL; // Hata oluþur.
			
			return current->eleman;
		}
};
#endif