/******************************************************************************************************************************************/
//                                               SAKARYA ÜNÝVERSÝTESÝ
//                                    BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
//                                         BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
//                                            PROGRAMLAMAYA GÝRÝÞ DERSÝ 
//                                                    G161210045
//                                                  BEYZANUR DEMÝR
//                                                    1. ÖDEV
//                                                     D GRUBU
/******************************************************************************************************************************************/
#include<iostream>
using namespace std;
int main()
{
	int girilena, girilenb;
	cout << "1 ile 20 arasinda bir a tam sayi degeri giriniz=";
	cin >> girilena;
	cout << "1 ile 20 arasinda a dan kucuk olacak sekilde bir b tam sayi degeri giriniz=";
	cin >> girilenb;

	{
		for (int x = 1;x <= 20;x++)  //ilk satýr için döngü dönüyor.20 deðer atanýyr
		{
			if (x <= (girilenb - 1) + (girilena - girilenb + 1))  //ilk satýrda 2. ve 3. satýrdaki yýldýz sayýsý deðerince boþluk basýlýyor
			{
				cout << " ";
			}
			else     //kalan durumlarda yýldýz basýlýyor
				cout << "*";
		}
		cout << endl;
		for (int x = 1;x <= 20;x++) //ikinci satýr için döngü dönüyor

			if (x <= girilenb - 1) //3. satýrdaki yýldýz deðerince boþluk bas
			{
				cout << " ";
			}

			else if (x > girilenb - 1 && x <= girilena)  //girilenb-1 deðerinden büyükse ve girilena deðerinden küçük eþitse yýldýz bas
				cout << "*";


		cout << endl;
		for (int x = 1;x <= 20;x++)   //3.satýr için döngü dönüyor
		{
			if (x <= girilenb - 1)   //girilenb deðerinden küçük sayýlar için yýldýz basýlýyor
			{
				cout << "*";
			}
			else      //1. ve 2. satýrdaki yýldýz sayýsý kadar boþluk býrakýlýyor
				cout << " ";
		}

	}

	system("pause");
	return 0;
}
