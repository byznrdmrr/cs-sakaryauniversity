/************************************************************************************************************************************/
/*                                                SAKARYA ÜNÝVERSÝTESÝ  */
/*                                       BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLER FAKÜLTESÝ*/
/*                                            BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ*/
/*                                                PROGRAMLAMAYA GÝRÝÞ DERSÝ*/
/*                                                       G161210045*/
/*                                                     BEYZANUR DEMÝR*/
/*                                                       D GRUBU*/
/*                                                    PROJE ÖDEVÝ*/
/*************************************************************************************************************************************/
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>

using namespace std;
int main()
{
	int secim = 1;

	do
	{
		cout << "OTEL ISLEMLERÝ" << endl;
		cout << "--------------------" << endl;
		cout << "1)Oda Islemleri" << endl;
		cout << "2)Musteri Islemleri" << endl;
		cout << "3)Oda kayit Islemleri" << endl;
		cout << "99)Cikis" << endl;
		cout << "Seciminiz:  " << endl;
		cin >> secim;

	} while (secim != 1 && secim != 2 && secim != 3 && secim != 99);

	if (secim == 1)
	{
		do {
			system("cls");
			cout << "Oda Islemleri" << endl;
			cout << "---------------------" << endl;
			cout << "1)Oda ekle" << endl;
			cout << "2)Oda sil" << endl;
			cout << "3)Odalari listele" << endl;
			cout << "99)Ust menu" << endl;
			cout << "seciminiz:" << endl;
			cin >> secim;

		} while (secim != 1 && secim != 2 && secim != 3 && secim != 99);
		if (secim == 1) //neden çalýþmýyor hocam bu kýsým :(
		{
			class musteri
			{
			public:
				string Ad;
				string Soyad;
				string Numara;
				char TC[11];
				
				fstream dosya;
				musteri() //kurucu dosya
				{ 
					dosya.open("Müþteri Bilgisi.txt", ios::in | ios::out | ios::app);
					dosya.setf(ios::left);
				}
				
				void odaEkle(string Numara)
				{
					
					musteri A;
					dosya >> A.Ad;
					dosya >> A.Soyad;
					dosya >> A.Numara;
					dosya >> A.TC;

					cout << "müþteri numarasý: " << endl;
					cin >> Numara;
					if (A.Numara == Numara)
					{
						cout.setf(ios::right);
						cout << setw(20) << "musteri adi:  " << Ad << endl;
						cout << setw(20) << "musteri soyadi:  " << Soyad << endl;
						cout << setw(20) << "musteri numarasi:   " << Numara << endl;
						cout << setw(20) << "musteri TC:    " << TC << endl;
					}
			    }
				int main()
				{
					musteri Musteri;
					Musteri.odaEkle(Numara);
				}
			};
		}
		if (secim == 2)
		{
				//ODA SÝL
		}
	
		if (secim == 3)
		{
			//ODALARI LÝSTELE
		}
		if (secim == 99)
		{
			do {
				system("cls");
				cout << "Oda Islemleri" << endl;
				cout << "---------------------" << endl;
				cout << "1)Oda ekle" << endl;
				cout << "2)Oda sil" << endl;
				cout << "3)Odalari listele" << endl;
				cout << "99)Ust menu" << endl;
				cout << "seciminiz:" << endl;
				cin >> secim;

			} while (secim != 1 && secim != 2 && secim != 3 && secim != 99);
	    }

	if (secim == 2) //müþteri kaydý için
	{
		do
		{
			system("cls");
			cout << "Musteri Ýslemleri" << endl;
			cout << "--------------------------" << endl;
			cout << "1)Musteri kaydet" << endl;
			cout << "2)Musteri sil" << endl;
			cout << "seciminiz" << endl;
			cin >> secim;

		} while (secim != 1 && secim != 2);

		if (secim == 1)
		{
			class musteri
			{
			public:
				string Ad;
				string Soyad;
				string Numara;
				char TC [11];
				int cevap = 'e';
		

				void BilgiGir()
				{
						cout << "MÜSTERÝ BÝLGÝSÝ" << endl;
						cout << "----------------------------" << endl;

						cout.setf(ios::right);   //saða yatýk yazmayý saðlýyor.

						cout << setw(20) << "musteri adi:  ";
						cin >> Ad;

						cout << setw(20) << "musteri soyadi:  ";
						cin >> Soyad;

						cout << setw(20) << "musteri numarasi:   ";
						cin >> Numara;

						cout << setw(10) << "musteri TC no:    ";
						cin >> TC;
		    	}

				void BilgiYazdýr()
				{
						cout.setf(ios::right);
						cout << setw(20) << "musteri adi:  " << Ad << endl;
						cout << setw(20) << "musteri soyadi:  " << Soyad << endl;
						cout << setw(20) << "musteri numarasi:   " << Numara << endl;
						cout << setw(20) << "musteri TC:    " << TC << endl;
				}
			};

			class Otel
			{
			public:
				musteri Musteriler[100];
				int MustrSayisi;  //Müþteri sayýsýný tutacak bir deðiþkene ihtiyaç var
				fstream dosya; //Otel bir dosyaya yazý yazmak ister bu yüzden bir nesneye ihtiyacýmýz var 



				Otel() //kurucu fonksiyon açtýk
				{
					int MustrSayisi = 0;
					dosya.open("Müþteri Bilgisi.txt", ios::out | ios::in | ios::app); //kurucu fonksiyon içinde dosya açtýk

					dosya.setf(ios::left);
				}

				void MusteriEkle()
				{

					Musteriler[MustrSayisi].BilgiGir(); //fonksiyon çaðrýldýðý nesnenin deðiþkenlerine etki eder.
					musteri k = Musteriler[MustrSayisi];

					dosya << "Müsteri Adi:" << setw(20) << k.Ad
						<< "Müsteri Soyadý:" << setw(20) << k.Soyad
						<< "Müsteri Numarasý:" << setw(20) << k.Numara
						<< setw(2) << "Müsreri TC:" << setw(20) << k.TC
						<< endl;
				}
			};


			int main();
			{
				Otel SAU;
				SAU.MusteriEkle();
				system("pause");
			}
		}
		if (secim == 2) //müþteri kaydý silmek için
		{
			class musteri
			{
			public:
				string Ad;
				string Soyad;
				string Numara;
				char TC[11];
				fstream dosya;

				musteri() //kurucu fonksiyon
				{
					dosya.open("Müþteri Bilgisi.txt", ios::in); //okuma modunda açýldý
					dosya.open("Müþteri Bilgisi.tmp", ios::in | ios::out | ios::app ); //geçici dosyaya yazma modunda açýldý
					dosya.setf(ios::left);
				}
				void MusteriSil()
				{
					musteri A;

					while (dosya.eof() != true) //dosyanýn sonunu kontrol ediyor, bu fonk true dönüyorsa dosya bitmiþ demektir.
					{
						dosya >> A.Ad;
						dosya >> A.Soyad;
						dosya >> A.Numara;
						dosya >> A.TC;
						if (A.TC == TC)
						{
							//silinecek kayýdý göster ve yedek dosyaya kaydetme
							cout.setf(ios::right);
							cout << "Silinecek kayýdý göster" << endl;
							cout << setw(20) << "musteri adi:  " << Ad << endl;
							cout << setw(20) << "musteri soyadi:  " << Soyad << endl;
							cout << setw(20) << "musteri numarasi:   " << Numara << endl;
							cout << setw(20) << "musteri TC:    " << TC << endl;
						}
						else
						{
							//silinmeyecek kayýtlarý yedek dosyaya kaydet
							dosya << setw(20) << Ad << setw(20) << Soyad << setw(20) << Numara << setw(20) << TC;
						}
					}
					dosya.close();
					dosya.close();
					//asýl veri dosyasýný diskten sil
					remove("Müþteri Bilgisi.txt");

					//yedek dosyanýn ismini asýl dosyanýn ismi olarak deðiþtir
					rename("Müþteri Bilgisi.tmp", "müþteri Bilgisi.txt");
				}
				int main()
				{ 
				
					musteri Musteri;
					Musteri.MusteriSil();
				}
			};
		}

		if (secim == 3)
		{
			//oda kayýt iþlemleri
		}

		if (secim == 99)
		{
			exit(99);
		}

		system("pause");
	}
}



	



