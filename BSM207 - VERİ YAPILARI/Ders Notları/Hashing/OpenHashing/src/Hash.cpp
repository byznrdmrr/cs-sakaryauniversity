#include "Hash.hpp"

Hash::Hash(){
	for(int i=0;i<MAX;i++)
		Dizi[i] = NULL;
}

void Hash::Ekle(int sayi){
	if(Bul(sayi)) return;
	int indeks = HashCode(sayi);
	Dizi[indeks] = new Dugum(sayi,Dizi[indeks]);
}
bool Hash::Bul(int sayi) {
	int indeks = HashCode(sayi);
	Dugum *tmp = Dizi[indeks];
	while(tmp != NULL){
		if(tmp->veri == sayi)return true;
		tmp=tmp->ileri;
	}
	return false;
}
bool Hash::Cikar(int sayi){
	int indeks = HashCode(sayi);
	if(Dizi[indeks] == NULL) return false;
	if(Dizi[indeks]->veri == sayi){
		Dugum *sil = Dizi[indeks];
		Dizi[indeks] = Dizi[indeks]->ileri;
		delete sil;
		return true;
	}
	Dugum *onceki = Dizi[indeks];
	while(onceki->ileri != NULL){
		if(onceki->ileri->veri == sayi){
			Dugum *sil = onceki->ileri;
			onceki->ileri = sil->ileri;
			delete sil;
			return true;
		}
		onceki = onceki->ileri;
	}
	return false;
}

bool Hash::Bosmu() const{
	for(int i=0;i<MAX;i++){
		if(Dizi[i] != NULL) return false;
	}
	return true;
}

int Hash::HashCode(int sayi){
	return sayi%MAX;
}

void Hash::Temizle(){
	for(int i=0;i<MAX;i++){
		Dugum *tmp = Dizi[i];
		while(tmp != NULL){
			Dugum* sil = tmp;
			tmp=tmp->ileri;
			delete sil;
		}
		Dizi[i] = NULL;
	}
}
Hash::~Hash(){
	Temizle();
}

void Hash::Yaz() const{
	for(int i=0;i<MAX;i++){
		if(Dizi[i] != NULL){
			cout<<"Dizi["<<i<<"]=";
			for(Dugum *tmp = Dizi[i];tmp != NULL;tmp=tmp->ileri){
				cout<<tmp->veri<<"->";
			}
			cout<<"NULL"<<endl;
		}
	}
}