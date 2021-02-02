#include "Hash.hpp"

int main(){
	Hash *hash = new Hash();	
	hash->Ekle(100);
	hash->Ekle(55);
	hash->Ekle(1235);
	hash->Ekle(10000);
	hash->Ekle(1);
	hash->Ekle(102);
	hash->Ekle(102);
	hash->Ekle(102);
	hash->Yaz();
	delete hash;
	
	return 0;
}