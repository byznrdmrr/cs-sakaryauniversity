// Þablon düðüm sýnýfý
#ifndef DUGUM_HPP
#define DUGUM_HPP

#include <iostream>
using namespace std;

template <typename Nesne>
class Dugum{
	public:	
		Nesne eleman;
		Dugum<Nesne> *ileri;
		Dugum(const Nesne& eleman=Nesne(),Dugum<Nesne> *ilr=NULL){
			this->eleman=eleman;
			ileri=ilr;
		}
};
#endif