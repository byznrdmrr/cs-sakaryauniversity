#ifndef LISTE_HPP
#define LISTE_HPP

#include "Node.hpp"
#include "ListeGezici.hpp"

template <typename Nesne>
class Liste
{
	private:
		Node<Nesne> *header;  // içinde eleman olmayan sadece baþ tarafý tutan Node.
	public:
		Liste()
		{
			header = new Node<Nesne>();
		}
		
		bool isEmpty() const
		{
			return header->next == NULL;
		}
		
		// Liste gezici þeklinde listenin baþýný döndürür. Eleman deðilde boþ bir Node döner.
		ListeGezici<Nesne> zeroth() const
		{
			return ListeGezici<Nesne>(header);
		}
		
		// Liste gezici þeklinde listenin ilk elemanýný döndürür
		ListeGezici<Nesne> first() const
		{
			return ListeGezici<Nesne>(header->next);
		}
		
		// Liste gezici þeklinde listenin son elemanýný döndürür
		ListeGezici<Nesne> last() const
		{
			//if(this->isEmpty())  Hata oluþur.
			Node<Nesne> *son = new Node<Nesne>();
			
			for(ListeGezici<Nesne> itr = this->first();!itr.isPastEnd();itr.advance())son->eleman=itr.retrieve();
			
			return ListeGezici<Nesne>(son);
		}
		
		void print()
		{
			if(this->isEmpty())
				cout<<"Liste bos."<<endl;
			else
			{
				ListeGezici<Nesne> itr = this->first();
				for( ; !itr.isPastEnd(); itr.advance())
					cout<<itr.retrieve()<<" ";
			}
			
			cout<<endl;
		}
		
		ListeGezici<Nesne> find(const Nesne& aranan) const
		{
			Node<Nesne> *itr = header;
			while(itr != NULL && itr->eleman != aranan) itr=itr->next;
			
			return ListeGezici<Nesne>(itr);
		}
		
		// belirtilen elemandan ilk gördüðü yerde listeden çýkarýr.
		void remove(const Nesne& aranan)
		{
			ListeGezici<Nesne> p = find(aranan);  // Aranan listede yoksa hata oluþur.
			Node<Nesne> *eskiNode = p.current;
			
			p.current->prev->next = p.current->next;
			if(p.current->next != NULL) p.current->next->prev = p.current->prev;
			delete eskiNode;			
		}
		
		// belirtilen konumdan eleman çýkarýr.
		void removeAt(int konum)
		{
			//if(this->isEmpty())  Hata oluþur.
			
			int indeks=0;
			Node<Nesne> *eskiNode = header->next;
			while(eskiNode->next != NULL && konum!=indeks++) eskiNode = eskiNode->next;
			
			eskiNode->prev->next = eskiNode->next;
			if(eskiNode->next != NULL) eskiNode->next->prev = eskiNode->prev;
			delete eskiNode;
		}
		
		// belirtilen konumdaki elemaný getirir.
		ListeGezici<Nesne> elementAt(int konum)
		{
			ListeGezici<Nesne> p = findPreviousByPosition(konum);
			
			if(p.current->next != NULL)
			{
				Node<Nesne> *istenenNode = p.current->next;
				return ListeGezici<Nesne>(istenenNode);
			}
			
			return NULL;
		}
		
		// Aranan node'un bir öncesini getirir.
		ListeGezici<Nesne> findPrevious(const Nesne& aranan) const
		{
			ListeGezici<Nesne> p = find(aranan);
			
			return ListeGezici<Nesne>(p.current->prev);
		}
		
		// Aranan konumun bir öncesini getirir.
		ListeGezici<Nesne> findPreviousByPosition(int konum) const
		{
			int indeks=0;
			Node<Nesne> *itr = header;
			while(itr->next != NULL && konum!=indeks++) itr = itr->next;
			
			return ListeGezici<Nesne>(itr);
		}
		
		// yeni elemaný belirtilen konuma ekler.
		void insert(const Nesne& yeni,int konum)
		{
			int indeks=0;
			ListeGezici<Nesne> itr = findPreviousByPosition(konum);
			
			Node<Nesne> *prevTemp = itr.current->next;
			itr.current->next = new Node<Nesne>(yeni,itr.current->next,itr.current);
			if(prevTemp != NULL) prevTemp->prev = itr.current->next;
		}
		
		// yeni elemaný listede p'den sonrasýna ekler.
		void insert(const Nesne& yeni,const ListeGezici<Nesne>& p)
		{
			if(p.current != NULL)
			{
				Node<Nesne> *prevTemp = p.current->next;
				p.current->next = new Node<Nesne>(yeni,p.current->next,p.current);
				if(prevTemp != NULL) prevTemp->prev = p.current->next;
			}
		}	
		
		// Listeyi boþaltýr.
		void makeEmpty()
		{
			while(!isEmpty())
				remove(first().retrieve());
		}
		// Yýkýcý metot
		~Liste()
		{
			makeEmpty();
			delete header;
		}
};
#endif