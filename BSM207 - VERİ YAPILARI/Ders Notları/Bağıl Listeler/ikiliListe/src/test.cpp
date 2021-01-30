#include "Liste.hpp"

int main()
{
	Liste<int> *liste = new Liste<int>();
	liste->insert(25,0);
	liste->insert(45,1);
	liste->insert(100,2);
	delete liste;
	return 0;
}