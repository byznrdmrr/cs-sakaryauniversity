#include "IslemKuyrugu.hpp"

IslemKuyrugu::IslemKuyrugu()
{	
	islemSayisi= -1;
	kuyruk = (struct Islem**) malloc(sizeof(struct Islem*) * 10);
}

//Kuyruga eklenmek icin islem olusturulur
void IslemKuyrugu::olustur()
{
	if(dolu())
		return;
	else
	{
		Islem* olusturulan = new Islem();
		olusturulan->kimlikEkle(baslangicKimlik);
		kuyrugaEkle(olusturulan);
		baslangicKimlik++;
	}
	
}

//Kuyruga islem eklenir
void IslemKuyrugu::kuyrugaEkle(Islem* islem)
{
	if(dolu())
		return;
	else
	{
		islemSayisi++;
		kuyruk[islemSayisi] = islem;
	}
}

//Oncelikli islem gonderilir
Islem* IslemKuyrugu::islemGetir()
{
	return kuyruk[0];
}

//Kuyrugun dolulugu kontrol edilir
bool IslemKuyrugu::dolu()
{
	return islemSayisi == 9 ? true : false;
}

//Kuyruktaki indeksli islem siralanir
void IslemKuyrugu::sirala(int indeks)
{
	if(indeks == 0)
		return;

	
	else if(kuyruk[indeks]->oncelikGonder() > kuyruk[indeks-1]->oncelikGonder())
	{
		Islem* islem = kuyruk[indeks-1];
		kuyruk[indeks-1] = kuyruk[indeks];
		kuyruk[indeks] = islem;
		sirala(indeks-1);
		return;
	}
	
	if(indeks == islemSayisi)
	{
		return;
	}

	else if(kuyruk[indeks]->oncelikGonder() < kuyruk[indeks+1]->oncelikGonder())
	{
		Islem* islem = kuyruk[indeks+1];
		kuyruk[indeks+1] = kuyruk[indeks];
		kuyruk[indeks] = islem;
		sirala(indeks+1);
		return;
	}
}

//Kuyruktaki islem ile disaridan gonderilen islem degistirilir
Islem* IslemKuyrugu::degistir(Islem* islemciIslem)
{
	if(dolu())
	{
		Islem* islem = islemGetir();
		kuyruguOtele();
		if(islemciIslem != NULL)
		{
			if(islemciIslem->sureGonder() > 0)
			{
			 kuyrugaEkle(islemciIslem);
			 sirala(islemSayisi);
			}
		}
		return islem;
	}
	else
	{	
		if(islemciIslem != NULL)
		{
			if(islemciIslem->sureGonder() > 0)
			{
				kuyrugaEkle(islemciIslem);
				Islem* islem = islemGetir();
				kuyruguOtele();
				sirala(islemSayisi);
				return islem;
			}
		}
		Islem* islem = islemGetir();
		kuyruguOtele();
		sirala(islemSayisi);
		return islem;
	}
}

//Kuyruk duzenlenir
void IslemKuyrugu::kuyruguOtele()
{
	for(int i = 0; i < islemSayisi+1; i++)
	{
		Islem* islem;
		islem = kuyruk[i+1];
		kuyruk[i] = islem;
	}
	islemSayisi--;
}

//Ekrana islemler gonderilir
void IslemKuyrugu::ekranCiktisi()
{
	system("CLS");
	
	int sayi = 0;
		
	COORD konum;
	
	konum.X = 0;
	konum.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), konum);
	
	while(sayi < islemSayisi + 1)
	{
		int konumYatay = sayi * 7;
		
		konum.X = konumYatay;
		konum.Y = 0;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), konum);
		cout << "******";
		
		konum.X = konumYatay;
		konum.Y = 1;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), konum);
		cout << "* " << kuyruk[sayi]->kimlikGonder();
		konum.X += 5;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), konum);
		cout << "*";
		
		konum.X = konumYatay;
		konum.Y = 2;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), konum);
		cout << "******";
		
		konum.X = konumYatay;
		konum.Y = 3;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), konum);
		cout << "* " << kuyruk[sayi]->oncelikGonder();
		konum.X += 5;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), konum);
		cout << "*";
		
		konum.X = konumYatay;
		konum.Y = 4;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), konum);
		cout << "******";
	
		konum.X = konumYatay;
		konum.Y = 5;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), konum);
		cout << "* " << kuyruk[sayi]->sureGonder();
		konum.X += 5;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), konum);
		cout << "*";
	
		konum.X = konumYatay;
		konum.Y = 6;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), konum);
		cout << "******";
		sayi++;
	}
}

//Kuyruk heap bolgesinden temizlenir
IslemKuyrugu::~IslemKuyrugu()
{
	delete[] kuyruk;
}