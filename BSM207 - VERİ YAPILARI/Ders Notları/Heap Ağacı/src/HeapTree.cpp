#include "HeapTree.hpp"

int HeapTree::SolCocukIndeks(int dugumIndeks){
	return 2*dugumIndeks + 1;
}
int HeapTree::SagCocukIndeks(int dugumIndeks){
	return 2*dugumIndeks + 2;
}
int HeapTree::EbeveynDugumIndeks(int dugumIndeks){
	return (dugumIndeks-1)/2;
}
HeapTree::HeapTree(int kapasite){
	elemanlar = new int[kapasite];
	dugumSayisi = 0;
	this->kapasite = kapasite;
}
bool HeapTree::Bosmu(){
	return (dugumSayisi == 0);
}

void HeapTree::HeapYukari(int dugumIndeks){
	int ebeveynIndeks, tmpVeri;
	if(dugumIndeks != 0){
		ebeveynIndeks = EbeveynDugumIndeks(dugumIndeks);
		if(elemanlar[ebeveynIndeks] > elemanlar[dugumIndeks]){
			tmpVeri = elemanlar[ebeveynIndeks];
			elemanlar[ebeveynIndeks] = elemanlar[dugumIndeks];
			elemanlar[dugumIndeks] = tmpVeri;
			HeapYukari(ebeveynIndeks);
		}
	}
}

void HeapTree::HeapAsagi(int dugumIndeks){
	int solCocukIndeks,sagCocukIndeks, enKucukIndeks, tmpVeri;
	solCocukIndeks = SolCocukIndeks(dugumIndeks);
	sagCocukIndeks = SagCocukIndeks(dugumIndeks);
	
	if(sagCocukIndeks >= dugumSayisi){
		if(solCocukIndeks >= dugumSayisi) return;
		else 
			enKucukIndeks = solCocukIndeks;
	}
	else{
		if(elemanlar[solCocukIndeks] <= elemanlar[sagCocukIndeks])
			enKucukIndeks = solCocukIndeks;
		else	
			enKucukIndeks = sagCocukIndeks;
	}
	if(elemanlar[dugumIndeks] > elemanlar[enKucukIndeks]){
		tmpVeri = elemanlar[enKucukIndeks];
		elemanlar[enKucukIndeks] = elemanlar[dugumIndeks];
		elemanlar[dugumIndeks] = tmpVeri;
		HeapAsagi(enKucukIndeks);
	}
}

void HeapTree::Ekle(int sayi)throw(string){
	if(dugumSayisi == kapasite) throw string("Dizi tasma hatasi");
	elemanlar[dugumSayisi] = sayi;
	dugumSayisi++;
	HeapYukari(dugumSayisi-1);
}

int HeapTree::EnKucuguCikar()throw(string){
	if(Bosmu()) throw string("Heap bos");
	int enKucuk = elemanlar[0];
	elemanlar[0] = elemanlar[dugumSayisi - 1];
	dugumSayisi--;	
	if(dugumSayisi > 0) HeapAsagi(0);
	
	return enKucuk;
}

HeapTree::~HeapTree(){
	delete[] elemanlar;
}