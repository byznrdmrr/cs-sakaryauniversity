#include "HeapTree.hpp"
#include <cstdlib>

int main(){
	HeapTree *heapAgaci = new HeapTree(100);
	int *dizi = new int[25];
	
	cout<<"Dizi ilk Hali:"<<endl;
	for(int i=0;i<25;i++){
		dizi[i] = rand()%100 + 1;
		heapAgaci->Ekle(dizi[i]);
		cout<<dizi[i]<<" ";
	}
	int indeks=0;
	while(!heapAgaci->Bosmu()) dizi[indeks++]=heapAgaci->EnKucuguCikar();
	
	cout<<endl<<"Dizi Siralanmis Hali:"<<endl;
	for(int i=0;i<25;i++){
		cout<<dizi[i]<<" ";
	}
	cout<<endl;
	delete [] dizi;
	delete heapAgaci;
	return 0;
}