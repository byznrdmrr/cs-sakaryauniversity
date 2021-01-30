/*******************************************************************************************************************************************************/
/*                                                          SAKARYA ÜNÝVERSÝTESÝ */
/*                                                 BÝLGÝSYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ*/
/*                                                       BÝLGÝSAYAR MÜHENDSÝLÝÐÝ BÖLÜMÜ*/
/*                                                          PROGRAMLAMAYA GÝRÝÞ DERSÝ*/
/*                                                                   2. ÖDEV*/
/*                                                                BEYZANUR DEMÝR  */
/*                                                                  G161210045*/
/*                                                                  C GURUBU*/
/*******************************************************************************************************************************************************/



#include<iostream
#include<time.h>
using namespace std;
int main()
{
	int diziBoyut;
	char karakter = 0;
	int sira = 0;
	int*dizi;

	cout << "Dizi boyutunu giriniz: ";
	cin >> diziBoyut;
	dizi = new int[diziBoyut];
	do      //dizinin devamlýlýðýný saðlýyor
	{
		system("cls"); //ekranýn temzilenmesini saðlýyor
		for (int i = 0; i < diziBoyut; i++)
		{
			int bosluk = 4;
			if (sira == i)
			{
				cout << "--->";
				bosluk = 0;
			}
			srand(time(0);
			dizi[i] = rand() % 10;   //diziye rastgele eleman atanýyor
			for (int j = 0; j < bosluk; j++)
			{
				cout << " ";
			}

			cout << dizi[i] << endl;

			if (karakter == 'a' || karakter == 'A') //karakter kontrolü yapýlyor
			{
				i++;
			}

			else if (karakter == 'd' || karakter == 'D')
			{
				i--;
			}
			
		}
		

		
	} while (karakter == 'c');

	system("pause");
	return 0;
}