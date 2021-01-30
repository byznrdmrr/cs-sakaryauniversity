#include "Liste.hpp"

int main()
{
	Liste<int> *liste = new Liste<int>();
	liste->ekle(25,1);
	liste->ekle(45,0);
	liste->ekle(100,0);
	cout<<liste->Son().getir();
	delete liste;
	return 0;
}