#include <iostream>
#include "top.h"
#include "yapi.h"

using namespace std;


int main()
{
	
		system("cls");
		int ans;
		int arraysize=0;
		int sayi;
		char gulucuk=2;
		
		int indisBir=0;
		int indisIki=0;
		
		cout<<"dizi boyutu..:";
		cin>>arraysize;
		
		yapi *nesne = new yapi();
		top **dizi=new top*[arraysize];
		//cout<<top[arraysize]<<endl;
		for(int i=1;i<arraysize+1;i++){
			sayi=rand()%15+1;
			dizi[i-1]=new top(sayi,gulucuk);
		}
		
		cout<<"Dizi Basariyla Olusturuldu"<<endl<<endl;
		
		do{
		cout<<"1-)Diziyi Yazdir"<<endl;
		cout<<"2-)Yer Degistir"<<endl;
		cout<<"3-)Cikis"<<endl;
		cin>>ans;
		
		if(ans==2){
			top **yeniDizi=new top*[arraysize];
			top **kontrolDizi= new top*[arraysize];
			
			cout << "Ilk indisi giriniz  :   ";
			cin  >> indisBir;
			while(indisBir<0 || arraysize<indisBir){
				cout << "Dizi boyutundan buyuk veya kucuk sayi giremezsiniz. Tekrar giriniz.  :   ";
				cin  >> indisBir;				
			};
			cout << "Ikinci indisi giriniz  :   ";
			cin >> indisIki;
			while(indisIki<0 || arraysize<indisIki){
				cout << "Dizi boyutundan buyuk veya kucuk sayi giremezsiniz. Tekrar giriniz.  :   ";
				cin  >> indisIki;
			};
			
			for(int i=0;i<arraysize;i++){
				yeniDizi[i]=dizi[i];
			}
			
			kontrolDizi[0] = yeniDizi[indisBir];
			kontrolDizi[1] = yeniDizi[indisIki];
			
			yeniDizi[indisBir] = kontrolDizi[1];
			yeniDizi[indisIki] = kontrolDizi[0];
			
			
			delete[] dizi;
			delete[] kontrolDizi;
			
			dizi=yeniDizi;
			/*
			for(int i = 0;i<arraysize;i++){
				cout<<dizi[i]->renk<<"   "<<&(dizi)+i<<endl;
			}*/
			
			cout<< " Degistirme Islemi Basariyla Tamamlandi  " <<endl;
			
		}
		
		if(ans==1){
			nesne->yazdir(arraysize,dizi);
		}
		
		}while(ans!=3);
	
	delete dizi;
}