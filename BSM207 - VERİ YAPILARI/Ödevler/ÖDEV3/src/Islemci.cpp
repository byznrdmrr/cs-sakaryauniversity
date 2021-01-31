#include "Islemci.hpp"

Islemci::Islemci()
{	
	islemciIslem = NULL;
	bosYazdir = false;
}

//Islem islemcide calistirilir
void Islemci::calistir(){
	
	//Islemin suresi eksiltilir
	islemciIslem->sureEksilt();
	
	if(islemciIslem == NULL)
	{
		return;
	}
	else if(bosYazdir)
	{
		delete islemciIslem;
		islemciIslem = NULL;
	}
	else if(islemciIslem->sureGonder() == 0)
	{
		bosYazdir = true;
	}
	else
	{
		//Yeni oncelik degeri girilir
		int yeniOncelik = rand() %10;
		islemciIslem->oncelikEkle(yeniOncelik); 
	}
}

//Islemcideki islem gonderilir
Islem* Islemci::islemcidenGonder()
{
	return islemciIslem;
}

//Islemciye islem eklenir
void Islemci::islemciyeEkle(Islem* islem)
{
	//Ekrandan silinmemesi icin bosYazdir degistirilir
	bosYazdir = false;
	
	islemciIslem = islem;
}

//Islemci ekrana yazdirilir
void Islemci::yazdir()
{
	cout << "\n";
	cout << " ___________________\n";
	for(int y = 0; y < 10; y++)
	{
		cout << "|";
		for(int x = 0; x < 6; x++)
			cout << "   ";
		cout << " |";
		cout << "\n";
	}
	cout << "|___________________|";
	
	
	COORD konum;
	konum.X = 7;
	konum.Y = 10;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), konum);
	cout << "******";
	konum.Y = 11;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), konum);
	cout << "*    *";
	konum.Y = 12;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), konum);
	cout << "******";
	konum.Y = 13;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), konum);
	cout << "*    *";
	konum.Y = 14;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), konum);
	cout << "******";
	konum.Y = 15;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), konum);
	cout << "*    *";
	konum.Y = 16;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), konum);
	cout << "******";	
	
	if(islemciIslem == NULL)
	{
		konum.Y = 18;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), konum);
		return;
	}
	
	if(bosYazdir)
	{
		COORD konum;
		konum.X = 9;
		konum.Y = 11;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), konum);
		cout << islemciIslem->kimlikGonder();		
		konum.Y = 13;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), konum);
		cout << islemciIslem->oncelikGonder();
		konum.Y = 15;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), konum);
		cout << islemciIslem->sureGonder();
		cout << "\n";
	}
	else
	{
		COORD konum;
		konum.X = 9;
		konum.Y = 11;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), konum);
		cout << islemciIslem->kimlikGonder();		
		konum.Y = 13;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), konum);
		cout << islemciIslem->oncelikGonder();
		konum.Y = 15;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), konum);
		cout << islemciIslem->sureGonder();
		cout << "\n";
	}
	cout << "\n\n";
}

Islemci::~Islemci()
{
	delete islemciIslem;
}