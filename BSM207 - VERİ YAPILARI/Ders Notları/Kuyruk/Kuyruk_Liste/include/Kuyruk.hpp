#ifndef KUYRUK_HPP
#define KUYRUK_HPP

#include <iostream>
using namespace std;

#include "KuyrukBos.hpp"

template <typename Nesne>
class Kuyruk
{
   private:
		struct Dugum{
			Nesne eleman;
			Dugum *ileri;
			Dugum(const Nesne & item,Dugum *ilr=NULL)
			{
				eleman=item;
				ileri=ilr;
			}
		};
		Dugum *arka;
		Dugum *on;
	public:
		Kuyruk()
		{
			arka=NULL;
			on=NULL;
		}
		~Kuyruk()
		{
			makeEmpty();
		}
		bool bosmu()
		{
			return on == NULL;
		}
		
		const Nesne& ondekiniGetir() throw(KuyrukBos)
		{
			if(bosmu()) throw KuyrukBos("Kuyruk Bos");
			
			return on->eleman;
		}
		void enqueue(const Nesne& yeni)
		{
			if(bosmu())
			{
				arka = on = new Dugum(yeni);
			}
			else
			{
				Dugum *eskiArka = arka;
				arka = new Dugum(yeni);
				eskiArka->ileri = arka;
			}
		}
		Nesne dequeue() throw(KuyrukBos)
		{
			if(bosmu()) throw KuyrukBos("Kuyruk Bos");
			Nesne enOn = on->eleman;
			Dugum *eskiOn = on;
			if(on->ileri != NULL) on=on->ileri;
			else{ on=NULL; arka=NULL; }	
			delete eskiOn;
			return enOn;
		}
		void makeEmpty()
		{
			while(!bosmu()) dequeue(); // Tüm kuyruk boþaltýlýyor.
		}
};
#endif