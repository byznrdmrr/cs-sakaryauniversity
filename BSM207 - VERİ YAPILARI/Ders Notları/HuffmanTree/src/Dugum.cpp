#include "Dugum.hpp"

Dugum::Dugum(const char ch,int tkr,Dugum *L,Dugum *R)
{
	karakter=ch;
	tekrarlanma = tkr;
	left=L;
	right=R;
}
ostream& operator<<(ostream &ekran,Dugum *dugum){
	ekran<<dugum->karakter<<":"<<dugum->tekrarlanma<<" ";
	return ekran;
}