#ifndef DUGUM_HPP
#define DUGUM_HPP

#include <iostream>
using namespace std;

class Dugum
{
public:
	Dugum *left;
	Dugum *right;
	int tekrarlanma;
	char karakter;
	Dugum(const char ch,int tkr,Dugum *L=NULL,Dugum *R=NULL);
	friend ostream& operator<<(ostream &ekran,Dugum *dugum);
};
#endif