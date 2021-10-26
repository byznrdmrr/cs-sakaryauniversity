#include "HeapTree.hpp"

int main()
{
	int sayilar[] = {5,12,4,51,10,9,47,3};
	HeapTree<int> *heapAgac = new HeapTree<int>();
	for(int i=0;i<8;i++)
	{
		heapAgac->Ekle(sayilar[i]);
	}
	cout<<endl<<"Sirali:"<<heapAgac<<endl;
	delete heapAgac;
	return 0;
}