#include "DoubleHashing.hpp"

DoubleHashing::DoubleHashing(){
	tablo = new int[MAX];
	Temizle();
}
int DoubleHashing::Hash1(int anahtar){
	return anahtar % MAX;
}
int DoubleHashing::Hash2(int anahtar){
	return YAKINASAL - (anahtar % YAKINASAL);
}
bool DoubleHashing::Dolumu()const{
	return elemanSayisi == MAX;
}
void DoubleHashing::Ekle(int anahtar){
	if(Dolumu()) throw TabloDolu();
			
	int indeks = Hash1(anahtar);
	if(tablo[indeks] != -1){ // Çarpışma Olur
		int adimSayisi = Hash2(anahtar);
		int i=1;
		while(true){
			int yeniIndeks = (indeks + i * adimSayisi) % MAX; 
			if(tablo[yeniIndeks] == -1){ // Çarpışma Yoksa
				tablo[yeniIndeks] = anahtar;
				break;
			}
			i++;
		}
	}
	else{
		tablo[indeks] = anahtar;
	}
	elemanSayisi++;
}
bool DoubleHashing::Ara(int anahtar){
	if(elemanSayisi == 0) return false;
	int indeks = Hash1(anahtar);
	if(tablo[indeks] == anahtar) return true;
	int adimSayisi = Hash2(anahtar);
	int i=1;
	while(i<=elemanSayisi){
		int yeniIndeks = (indeks + i * adimSayisi) % MAX; 
		if(tablo[yeniIndeks] == anahtar) return true;
		i++;
	}
	return false;
}
void DoubleHashing::Cikar(int anahtar){
	if(elemanSayisi == 0) throw ElemanYok();
	int indeks = Hash1(anahtar);
	if(tablo[indeks] == anahtar){
		tablo[indeks] = -1;
		elemanSayisi--;
		return;
	}
	int adimSayisi = Hash2(anahtar);
	int i=1;
	while(i<=elemanSayisi){
		int yeniIndeks = (indeks + i * adimSayisi) % MAX; 
		if(tablo[yeniIndeks] == anahtar){
			tablo[yeniIndeks] = -1;
			elemanSayisi--;
			return;
		}
		i++;
	}
	throw ElemanYok();
}
void DoubleHashing::Temizle(){
	elemanSayisi = 0;
			
	for(int i=0;i<MAX;i++) tablo[i]=-1;			
}
void DoubleHashing::Yaz(){
	for (int i = 0; i < MAX; i++) 
	{ 
		if (tablo[i] != -1) 
			cout<<"["<<i<<"]\t:"<<tablo[i]<<endl; 
		else
			cout<<"["<<i<<"]\t:"<<endl; 
	} 
}
DoubleHashing::~DoubleHashing(){
	delete [] tablo;
}