#ifndef DUGUM_HPP
#define DUGUM_HPP

#include <iostream>
using namespace std;

template <typename Nesne>
class Dugum
{
	public:
		Dugum(const Nesne& yeni=Nesne(),Dugum<Nesne> *n=NULL)
		{
			eleman=yeni;
			ileri=n;
		}
		Nesne eleman;
		Dugum *ileri;
};
#endif