#include "Liste.hpp"

int main(){
	Liste<int> *liste = new Liste<int>();
	liste->Ekle(45);
	liste->Ekle(15,0);
	liste->Ekle(5);
	liste->Yaz();
	liste->BastanSil();
	liste->Ekle(52);
	liste->Yaz();
	liste->SondanSil();
	liste->Yaz();
	liste->Ekle(78,1);
	liste->Yaz();
	delete liste;
	
	Liste<string> *isimListesi = new Liste<string>();
	isimListesi->Ekle("Ahmet");
	isimListesi->Ekle("Veli");
	isimListesi->Ekle("Ali");
	isimListesi->Ekle("Murat");
	isimListesi->Yaz();
	try{
		isimListesi->Sil("Ali");
	}
	catch(ElemanYok &elm){
		cout<<elm.Mesaj();
	}
	isimListesi->Yaz();
	delete liste;
	
	return 0;
}