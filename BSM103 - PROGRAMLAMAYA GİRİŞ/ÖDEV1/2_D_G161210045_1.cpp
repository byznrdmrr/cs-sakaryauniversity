/******************************************************************************************************************************************/
/**                                           SAKARYA ÜNÝVERSÝTESÝ                                                                        
/** 								BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
/** 								    BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
/** 										PROGRAMLAMAYA GÝRÝÞ DERSÝ
/** 											  G161210045
/** 											BEYZANUR DEMÝR
/** 											   1.ÖDEV
/** 											   D GRUBU
/******************************************************************************************************************************************/
#include<iostream>
using namespace std;
int main()
{
	for (int i = 0; i < 24; i++) // en üst kýsýmdaki yýldýzlar bastýrýlýyor
	{
		cout << " * ";
	}
	cout << "\n";
	cout << " *  S  A  U     B  I  L  G  I  S  A  Y  A  R                          *\n";
	for (int k = 0; k < 24; k++) // 3. satýr bastýrýlýyor
	{
		if (k == 0 || k == 23) cout << " * ";  // 3. satýrýn birinci sütunundaysan ya da son sütunundaysan yýldýz bas
		else cout << "   ";    //arada kalan diðer sütunlarda boþluk bas
	}
	cout << "\n";
	int buyukUcgenBosluk = 5; // 4. satýr için iki üçgen de 5 boþluk 1 yýldýz þeklinde baþlýyor
	for (int i = 0; i < 6; i++) //Üçgeni oluþturmak için döngüyü 6 defa döndürür
	{
		cout << " * ";
		for (int j = 0; j < 11; j++) // üst sol büyük üçgen için döngü dönüyor
		{
			if (j >= buyukUcgenBosluk && j < (11 - buyukUcgenBosluk)) // Her satýr için birer azalan boþluk sayýsndan büyük veya eþitse ve 11-azalan boþluk sayýsý deðerinden küçükse
			{
				cout << " * "; //Yýldýz bas
			}
			else  //kalan durumlar için boþluk bas
				cout << "   ";
		}
		for (int j = 0; j < 11; j++) // üst sað büyük üçgen için dönüyor
		{
			if (j >= buyukUcgenBosluk && j < (11 - buyukUcgenBosluk))
			{
				cout << " * ";
			}
			else if (i == 0 && j >= 8) // büyük üçgenin içindeki küçük üçgenin üst kýsmý için 
				cout << " * ";
			else if (i == 1 && j == 9) // büyük üçgenin içindeki küçük üçgenin alt kýsmý için
				cout << " * ";
			else
				cout << "   ";
		}
		cout << " * ";
		cout << "\n";
		buyukUcgenBosluk -= 1;
	}
	for (int k = 0; k < 24; k++) //10. satýr için döngü dönüyor
	{
		if (k == 0 || k == 23)    //10. satýrýn baþýnda ve sonundaysan yýldýz bas
			cout << " * ";
		else    //aradaki sütunlarda boþluk bas
			cout << "   ";
	}
	cout << "\n";
	cout << " *  M  U  H  E  N  D  I  S  L  I  G  I     B  O  L  U  M  U           *\n";
	for (int k = 0; k < 24; k++)     // 12. satýr için döngü dönüyor
	{
		if (k == 0 || k == 23)   //12. satýrýn 1.sütununda ya da son sütununda isen yýldýz bas
			cout << " * ";
		else                   //diðer sütünlarda boþluk bas
			cout << "   ";
	}
	cout << "\n";
	buyukUcgenBosluk = 5;
	for (int i = 0; i < 6; i++)
	{
		cout << " * ";
		for (int j = 0; j < 11; j++) // Sol alt büyük üçgen için
		{
			if (j >= buyukUcgenBosluk && j < (11 - buyukUcgenBosluk)) // Her satýr için birer azalan boþluk sayýsndan büyük veya eþitse ve 11-azalan boþluk sayýsý deðerinden küçükse
			{
				cout << " * ";  //yýldýz bas
			}
			else if (i == 0 && j >= 8)  // büyük üçgenin içindeki küçük üçgenin üst kýsmý 
				cout << " * ";
			else if (i == 1 && j == 9) // büyük üçgenin içindeki küçük üçgenin alt kýsmý
				cout << " * ";
			else
				cout << "   ";
		}
		for (int j = 0; j < 11; j++) // Sað alt büyük üçgen için
		{
			if (j >= buyukUcgenBosluk && j < (11 - buyukUcgenBosluk)) // Her satýr için birer azalan boþluk sayýsndan büyük veya eþitse ve 11-azalan boþluk sayýsý deðerinden küçükse
			{
				cout << " * ";  //yýldýz bas
			}
			else  //diðer durumlarda boþluk bas
				cout << "   ";
		}
		cout << " * ";
		cout << "\n";
		buyukUcgenBosluk -= 1;
	}
	for (int k = 0; k < 24; k++) // 19. satýr için döngü dönüyor
	{
		if (k == 0 || k == 23)  //19. satýrýn baþýnda veya sonunda isen yýldýz bas
			cout << " * ";
		else  //aradaki sütunlarda boþluk bas
			cout << "   ";
	}
	cout << "\n";
	for (int i = 0; i < 24; i++) // en alt kýsýmdaki yýldýzlarýn basýmý için döngü dönüyor
	{
		cout << " * ";
	}
	system("pause");
	return 0;
}
