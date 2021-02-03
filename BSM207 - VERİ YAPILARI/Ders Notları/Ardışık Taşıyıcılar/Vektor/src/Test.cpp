#include "Vektor.hpp"
#include "Tasma.hpp"

int main(){
	Vektor<int> *vektor = new Vektor<int>();
	int x=32,y=54,z=35;
	try
	{
		vektor->insert(0,x);
		vektor->insert(0,y);
		vektor->insert(2,z);
		vektor->erase(1);
		cout<<vektor->at(1)<<endl;
	}
	catch(Tasma &tsm)
	{
		cout<<tsm.Mesaj()<<endl;
	}
	delete vektor;
	return 0;
}