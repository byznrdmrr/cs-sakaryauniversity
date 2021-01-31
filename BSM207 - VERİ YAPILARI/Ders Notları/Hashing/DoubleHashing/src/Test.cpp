#include "DoubleHashing.hpp"

int main(){
	int dizi[] = {15,9,62,34,59,37,85,42,102,1,135};
	DoubleHashing *tablo = new DoubleHashing();
	for(int i=0;i<11;i++) tablo->Ekle(dizi[i]);
	tablo->Yaz();
	delete tablo;
}