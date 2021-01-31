#include <cstdlib>
#include "ArrayList.hpp"

int main()
{
	ArrayList<string> *isimler = new ArrayList<string>();
	int sec=0;
	string isim;
	do{
		system("CLS");
		cout<<"1.Isim Ekle"<<endl;
		cout<<"2.Isim Sil"<<endl;
		cout<<"3.Konumdan Isim Sil"<<endl;
		cout<<"4.Konuma Isim Ekle"<<endl;
		cout<<"5.Konum Bul"<<endl;
		cout<<"6.Isim Sayisi"<<endl;
		cout<<"7.Ilk Isim"<<endl;
		cout<<"8.Son Isim"<<endl;
		cout<<"9.Isimleri Listele"<<endl;
		cout<<"10.Isimleri Temizle"<<endl;
		cout<<"Secim:";
		cin>>sec;
		system("CLS");
		switch(sec){
			case 1:
				cout<<"Isim:";
				cin.ignore();
				getline(cin,isim);
				isimler->add(isim);
			break;
			case 2:
				cout<<"Isim:";
				cin.ignore();
				getline(cin,isim);
				try{
					isimler->remove(isim);				
				}
				catch(ElemanYok &elemanYok){
					cout<<endl<<elemanYok.Mesaj()<<endl;
					cin.get();
				}
			break;
			case 3:
				try{
					int konum;
					cout<<"Konum:";
					cin>>konum;
					isimler->removeAt(konum);				
				}
				catch(ElemanYok &elemanYok){
					cout<<endl<<elemanYok.Mesaj()<<endl;
					cin.ignore();
					cin.get();
				}
			break;
			case 4:
				try{
					string isim;
					int konum;
					cout<<"Konum:";
					cin>>konum;
					cout<<"Isim:";
					cin.ignore();
					getline(cin,isim);
					isimler->add(konum,isim);
				}
				catch(Tasma &tasma){
					cout<<endl<<tasma.Mesaj()<<endl;
					cin.get();
				}
			break;
			case 5:
				try{
					string isim;
					cout<<"Isim:";
					cin.ignore();
					getline(cin,isim);
					cout<<"Konum:"<<isimler->indexOf(isim);
					cin.get();
				}
				catch(ElemanYok &elemanYok){
					cout<<endl<<elemanYok.Mesaj()<<endl;
					cin.get();
				}
			break;
			case 6:			
				cout<<"Isim Sayisi:"<<isimler->length()<<endl;
				cin.ignore();
				cin.get();
			break;	
			case 7:
				try{
					cout<<"Ilk Isim:"<<isimler->first()<<endl;
					cin.ignore();
					cin.get();
				}
				catch(ListeBos &listeBos){
					cout<<endl<<listeBos.Mesaj()<<endl;
					cin.get();
				}
			break;	
			case 8:
				try{
					cout<<"Son Isim:"<<isimler->last()<<endl;
					cin.ignore();
					cin.get();
				}
				catch(ListeBos &listeBos){
					cout<<endl<<listeBos.Mesaj()<<endl;
					cin.get();
				}
			break;	
			case 9:			
				cout<<"ISIMLER";
				cout<<*isimler<<endl;
				cin.ignore();
				cin.get();
			break;	
			case 10:
				isimler->clear();
				cout<<endl<<"Tum isimler silindi."<<endl;
				cin.ignore();
				cin.get();
			break;
			case 0:
			break;
			default:
				cout<<endl<<"Yanlis tercih!"<<endl;
				cin.ignore();
				cin.get();
			break;
		}
		system("CLS");
	}while(sec != 0);
	delete isimler;
}