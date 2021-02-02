#include "top.h"
#include "yapi.h"
#include <iostream>
#include <windows.h>

using namespace std;


void yapi::renkAta(int yazirenk)
{
	int arkaplan = 0;

	int sonRenk;

	sonRenk = (16 * arkaplan) + yazirenk;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), sonRenk);
}
void yapi::karakterCikar(char karakter, int renk)
{
		renkAta(renk);
		cout<<karakter;
		renkAta(15);
}
void yapi::yazdir(int arraysize,top **dizi){
	
	int renk=0;
	char karakter=1;
	
	for(int i = 0;i<arraysize;i++){
				renkAta(15);
				renk=dizi[i]->rnk;
				karakter=dizi[i]->karakter;
				cout<<"["<<i<<"]->";
				karakterCikar(karakter,renk);
				renkAta(renk);
				cout<<"   "<<*((dizi)+i)<<endl;
				renkAta(15);
			}
}
void renkSifirla()
{
	int renkSifirla = 7;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), renkSifirla);
}
