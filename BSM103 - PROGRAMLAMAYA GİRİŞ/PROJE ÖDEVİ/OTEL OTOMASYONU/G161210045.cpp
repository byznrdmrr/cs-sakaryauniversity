/****************************************************************************
**					         SAKARYA ÜNİVERSİTESİ
**			     BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				        BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				          PROGRAMLAMAYA GİRİŞ DERSİ
**                              PROJE ÖDEVİ
**				
**				ÖĞRENCİ ADI:BEYZANUR DEMİR
**				ÖĞRENCİ NUMARASI:G161210045
**				DERS GRUBU:D
****************************************************************************/
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<stdio.h>
#include<dos.h>
using namespace std;

class Otel // Otel isimli class açtım.
{
private: //Fonksiyonlarda kullandığım değerleri tanımladım.

	char ad[50];
	char soyad[50];
	char oda_türü[80];
	char tc_no[11];
	int müsteri_no;
	int oda_numarasi;
	int tutar;
	int müsteri_sayısı;
	int büyüklük;
	int yatak_sayısı;
	int kapasite;
	int gün_sayisi;


public: // 9 tane fonksiyon yazdım.

    void menü() // İlk olarak menüyü gösteren fonksiyonu yazdım.
	{
		int secim = 0; 
		while (secim != 99) //Menü içinde seçim yapmamızı sağlayacak.
		{
			system("cls"); //Ekran yenilenir ve aşağıdaki yazılar ekranda belirir.
			cout << "OTEL ISLEMLERI" << endl;
			cout << "********************" << endl;
			cout << "1.Oda islemleri" << endl;
			cout << "2.Musteri islemleri" << endl;
			cout << "3.Oda kayit islemleri" << endl;
			cout << "99.Cikis" << endl;
			cout << "Seciminiz:";
			cin >> secim;

			switch (secim) //Seçtiğin seçime göre diğer fonksiyonlara yönlendirir.
			{
			case 1: oda_islemi(); // 1. seçimde oda işlemlerini gösteren fonksiyona gider.
				break;
			case 2:	müsteri_islemleri(); // 2. seçimde müşteri işlemlerini gösteren fonksiyona gider.
				break;
            case 3: odaya_kayit(); // 3. seçimde oda kaydını gösteren fonksiyona gider.
				break;
			case 99: exit(1); // 99. seçimde pogramdan çıkar.
				break;
			default: // Bu seçimlerden farklı seçim yaparsan hatalı seçim diye ekrana yazdırır.
			{
				system("cls"); //Ekran yenilenir.
				cout << "Hatali Secim " << endl;
				cout << "Devam etmek icin tiklayiniz" << endl;
				system("pause");
			}

			}
		}

     system("pause");

	} //Menü fonksiyonu sonu.
	void oda_islemi() //Oda işlemlerini yapan fonksiyon başlangıcı.
	{
		int secim = 0;
		while (secim != 99)  //Oda işlemleri içinde seçim yapmamızı sağlayacak.
		{
			system("cls"); //Ekranı yeniler ve aşağıdaki yazılar ekranda belirir.
			cout << "ODA ISLEMLERI" << endl;
			cout << "--------------------" << endl;
			cout << "1.Oda ekle" << endl;
			cout << "2.Oda sil" << endl;
			cout << "3.Odalari listele" << endl;
			cout << "99.Ust menu" << endl;
			cout << "Seciminiz:";
			cin >> secim;

			switch (secim) //Seçtiğin seçime göre alt fonksiyonları çağırır.
			{
			case 1: oda_ekle(); // 1. seçim için oda ekle fonksiyonuna gider.
				break;
			case 2:oda_sil(); // 2. seçim için oda sil fonksiyonuna gider.
				break;
			case 3: odaları_listele(); // 3. seçim için odaları listele fonksiyonuna gider.
				break;
			case 99:menü(); // 99. seçimde programdan çıkar.
				break;
			default: // Bu seçimlerden farklı seçim yaparsan hatalı seçim diye ekrana yazdırır.
			{
				system("cls"); //Ekranı yeniler.
				cout << "Hatali Secim " << endl;
				cout << "Devam etmek icin tiklayiniz" << endl;
				system("pause");
			}

			}

		}
	}//Oda işlemleri fonksiyonu sonu.
	void oda_ekle()//Oda ekle fonksiyonu başlangıcı.
	{
		int r; //Müsteri no girmek için bir değişken tanımladım.
		system("cls"); //Ekranı yeniler.
		ofstream dosya1("Otel.txt"); // Otel adlı txt dosyası oluşturdum.
		string cevap = "Hayır";
		cout << "Musteri no:";//Kullanıcıdan müsteri no girilmesini ister.
		cin >> r;
		do
		{
			if (r == müsteri_no) //Girilen değişken müsteri numarasına eşitse sistem açılır.
			{
				system("cls");//Ekranı yeniler.
				cout << "Oda turu:"; //Oda türünü kullanıcıdan girmesini ister.
				cin >> oda_türü;
				cout << "Oda no:"; //Oda numarasını kullanıcıdan girmesini ister.
				cin >> oda_numarasi;
				cout << "Kapasite:"; //Oda içinde kaç kişi olduğunu kullanıcıdan girmesini ister.
				cin >> kapasite;
				cout << endl;
				cout << "Oda kaydedilsin mi?";//Kullanıcıya sorar.
				cin >> cevap;

				dosya1 << oda_türü << "\n" << oda_numarasi << "\n" << kapasite << "\n"; // Girilen verileri kaydeder.
				dosya1.close();//Dosyayı kapatır.
				cout << endl;
				cout << "ODA KAYDEDILDI!!";
				cout << endl;

			}
			else //Girilen değişken müsteri numarasına eşit değilse  "MUSTERI BULUNMAMAKTADIR!!" yazısını ekrana çıkarır.
			{
				cout << "MUSTERI BULUNMAMAKTADIR!!" << endl;
				system("pause");
				break;

			}
		} while (!(cevap == "Evet"));

		system("pause");
	}//Oda ekle fonksiyonu sonu.
	void oda_sil()//Oda sil fonksiyonu başlangıcı.
	{
		system("cls");//Ekranı yeniler.
		int r; //Oda numarasını girmesi için değişken tanımladım.
		cout << "Oda numarasini giriniz:";//Kullanıcıdan oda numarası girmesini ister.
		cin >> r;
		char ch;//Verilecek cevap için değişken tanımladım.
		//Otel  adlı txt ve temp dosyası oluşturdum.
		ifstream dosya1("Otel.txt", ios::in); 
		ofstream dosya2("Otel.temp", ios::out);

		while (!dosya1.eof())
		{

			if (r == oda_numarasi)//Eğer girilen değer oda numarasına eşitse sistem açılır.
			{
				system("cls");//Ekranı yeniler ve müşteri bilgisini ekrana yazdırır.
                cout << "MUSTERI DETAYI" << endl;
				cout << "*********************" << endl;
				cout << "Oda turu:" << oda_türü << endl;
				cout << "Oda no:" << oda_numarasi << endl;
				cout << "Kac kisi kalmaktadir:" << kapasite << endl;
				cout << "Musteri adi:" << ad << endl;
				cout << "Musteri soyadi:" << soyad << endl;

                cout << "\n\n Odayi silmek istiyor musunuz?(e/h): ";//Kullanıcıya silmek isteyip istemediğini sorar.
				cin >> ch;

				if (ch == 'e')//Cevap e ise dosya silinir ve ekrana "KAYIT SILINDI!!" yazısını yazdırır.
				{
					dosya2 << "";
					cout << endl;
					cout << "KAYIT SILINDI!!" << endl;
					system("pause");
					break;

				}

			}
			else // Eğer girilen değer oda numarasına eşit değilse "ODA BULUNMAKTADIR!!" yazısını ekrana çıkartır.
			{
				cout << "ODA BULUNMAKTADIR!!" << endl;
				system("pause");
				break;
			}
		}

		//Dosyalar kapatılır ve txt dosyası silinir ve yeniden adlandırılır.
		dosya1.close();
		dosya2.close();
		remove("Otel.txt");
		rename("Otel.temp", "Otel.txt");


		system("pause");
	}//Oda sil fonksiyonu sonu.
	void odaları_listele()//Odaları listele fonksiyonu başlangıcı.
	{
        ifstream Dosya1("Otel.txt", ios::app); // Otel adlı txt dosyası oluşturdum
		while (!Dosya1.eof())
		{
			system("cls");//Ekranı yeniler ve kaydettiğim müşterinin bilgilerini ekrana yazdırır.
            cout << "ODALARIN LISTESI" << endl;;
			cout << "*********************" << endl;
			cout << "Oda turu:" << oda_türü << endl;
			cout << "Oda no:" << oda_numarasi << endl;
			cout << "Kac kisi kalmaktadir:" << kapasite << endl;
			cout << "Musteri adi:" << ad << endl;
			cout << "Musteri soyadi:" << soyad << endl;

			Dosya1.read((char*)this, sizeof(Otel));//Dosyayı okur.
			system("pause");

		}

		Dosya1.close();//Dosyayı kapatır.
		system("pause");
	}//Odaları listele fonksiyonu sonu.
    void müsteri_islemleri() //Müsteri işlemleri fonksiyonu başlangıcı.
	{
		int secim = 0;
		while (secim != 99)//Müşteri işlemleri içinde seçim yapmamızı sağlayacak.
		{
			system("cls");//Ekranı yeniler ve müsteri işlemleri için aşağıdakileri ekrana yazdırır.
			cout << "MUSTERI ISLEMLERI" << endl;
			cout << "--------------------" << endl;
			cout << "1.Musteri ekle" << endl;
			cout << "2.Musteri sil" << endl;
			cout << "99.Ust menu" << endl;
			cout << "Seciminiz:";
			cin >> secim;

			switch (secim)//Seçtiğiniz seçime göre alt fonksiyonları çağırır.
			{
			case 1: müsteri_ekle();//1. seçim için müşteri ekle fonksiyonunu çağırır.
				break;
			case 2: müsteri_sil();//2. seçim için müşteri sil fonksiyonunu çağırır.
				break;
			case 99: menü();//99. seçimde üst menüye döner.
				break;
			default:// Bu seçimlerden farklı seçim yaparsan hatalı seçim diye ekrana yazdırır.
			{
				system("cls");//Ekranı yeniler.
				cout << "Hatali Secim " << endl;
				cout << "Devam etmek icin tiklayiniz" << endl;
				system("pause");

			}
			}

		}
		system("Pause");

	}//Müsteri işlemleri fonksiyonu sonu.
	void müsteri_ekle()//Müşteri ekle fonksiyonu başlangıcı
	{
		ofstream dosya1("Otel.txt");// Otel adlı txt dosyası oluşturdum.
		char cevap;//Verilecek cevap için değişken tanımladım.

		do
		{
			system("cls"); //Ekranı yeniler ve kullanıcıdan bilgileri girmesini ister.
			cout << "NUSTERI BILGISI" << endl;
			cout << "*********************" << endl;
			cout << "Musteri adi:";//Kulanıcıdan isim girmesini ister.
			cin >> ad;
			cout << "Musteri soyadi:";//Kulanıcıdan soyad girmesini ister.
			cin >> soyad;
			cout << "Musteri TC no:";//Kulanıcıdan TC numarası girmesini ister.
			cin >> tc_no;
			cout << "Musteri no:";//Kulanıcıdan müşteri numarası girmesini ister.
			cin >> müsteri_no;


			dosya1 << ad << "\n" << soyad << "\n" << tc_no << "\n";// Verileri dosyaya kaydeder.

			cout << "Kaydedilsin mi?(e/h)";//Kullanıcıya kaydedilip kaydedilmemesini sorar.
			cin >> cevap;
		} while (!cevap == 'e');

		dosya1.close();//Dosyayı kapat.
		cout << endl;
		cout << "KAYIT YAPILDI!!";
		cout << endl;


		system("pause");
	}//Müşteri ekle fonksiyonu  sonu.
	void müsteri_sil()//Müşteri sil fonksiyonu başlangıcı.
	{
        system("cls");//Ekranı yeniler.
		int r;//Müşteri numarası için değişken tanımladım.
		cout << "Musteri no:";//Müşteri numarası girilmesini ister.
		cin >> r;
		char ch;//Verilen cevap için değişken tanımladım.
		//Otel adlı txt ve temp dosyası açtım.
		ifstream dosya1("Otel.txt", ios::in);
		ofstream dosya2("Otel.temp", ios::out);

		while (!dosya1.eof())
		{

			if (r == müsteri_no)//Müşteri numarası girilen değerle aynı ise sistem açılır.
			{
				dosya1.open("Otel.txt");//Dosya1'i açar.
				cout << "MUSTERI DETAYI" << endl;//Müşteri bilgileri ekrana yazdırır.
				cout << "*********************" << endl;
				cout << "Musteri adi:" << ad << endl;
				cout << "Musteri soyadi:" << soyad << endl;
				cout << "Musteri TC no:" << tc_no;
				cout << "Musteri no:" << müsteri_no << endl;

				dosya1.read((char*)this, sizeof(Otel));//Dosya1 okunur.
				cout << "\n\n Musteriyi silmek istiyor musunuz?(e/h): ";//Kullanıcıya sorar.
				cin >> ch;

				if (ch == 'e')//Cevap e ise dosyayı siler.
				{
					dosya2 << "";
					cout << endl;
					cout << "KAYIT SILINDI" << endl;
					system("pause");
					break;
				}

			}
			else//Girdiği değer, müşteri numarası ile aynı değilse  "MUSTERI BULUNMAKTADIR!!" yazısını ekrana yazdırır.
			{
				cout << "MUSTERI BULUNMAKTADIR!!" << endl;
				system("pause");
				break;
			}
		}//Dosyaları kapatır.
		dosya1.close();
		dosya2.close();
        system("pause");

	}//Müşteri sil fonksiyonu sonu.
	void odaya_kayit()//Odaya kayıt fonksiyonu başlatır.
	{
        int secim = 0;
		while (secim != 99)//Oda seçimi yapamamızı sağlar.
		{
			system("cls");//Ekranı yeniler.
			//Dört çeşit oda tanımladım ve ekrana odaların özelliklerini ve fiyatını ekrana yazdırdım.

			cout << "Odalar" << endl;
			cout << "************" << endl;
			cout << "1.STANDART ODA\n"
				<< "YATAK:2 cift kisilik yatak.\n"
				<< "KAPASITE:5 yetiskin.\n"
				<< "BUYUKLUK:28-32 metrekare\n"
				<< "1 banyo.\n"
				<< "UCRET:90 TL" << endl;
			cout << "************" << endl;
			cout << "2.KOSE ODA\n"
				<< "YATAK:2 cift kisilik yatak.\n"
				<< "KAPASITE:5 yetiskin.\n"
				<< "BUYUKLUK:50 metrekare\n"
				<< "1 banyo.\n"
				<< "UCRET:110 TL" << endl;
			cout << "************" << endl;
			cout << "3.SUIT ODA\n"
				<< "YATAK:2 cift kisilik, 2 tek kisilik yatak.\n"
				<< "KAPASITE:6 yetiskin.\n"
				<< "BUYUKLUK:70 metrekare\n"
				<< "1 banyo.\n"
				<< "UCRET:175 TL" << endl;
			cout << "************" << endl;
			cout << "4.KRAL DAIRESI\n"
				<< "YATAK:1 cift kisilik, 4 tek kisilik yatak.\n"
				<< "KAPASITE:10 yetiskin.\n"
				<< "BUYUKLUK:170  metrekare\n"
				<< "2 banyo, 1 tuvalet.\n"
				<< "UCRET:280 TL" << endl;
			cout << "99.Ust menu" << endl;
			cout << "Seciminiz:";
			cin >> secim;
			cout << endl;

			switch (secim)//Seçilen seçime göre fiyatı hesaplayacak.
			{
			case 1://Standart oda seçimi için.
				cout << "Kac kisi kalicaksiniz:";//Kullanıcıdan kaç kişi kalacaklarının bilgisini ister.
				cin >> müsteri_sayısı;
				cout << endl;
				cout << "Kac gun kalicaksiniz:";//Kullanıcıdan kaç gün kalacaklarının bilgisini ister.
				cin >> gün_sayisi;
				cout << endl;
				tutar = 90 * müsteri_sayısı * gün_sayisi;//Oda fiyatı ile kişi ve gün sayısını çarpar.

				cout << "Tutar:" << tutar << "TL" << endl;//Hesaplanan tutarı ekrana yazar.
				system("pause");
				break;
			case 2://Kose oda seçimi için.
				cout << "Kac kisi kalicaksiniz:";//Kullanıcıdan kaç kişi kalacaklarının bilgisini ister.
				cin >> müsteri_sayısı;
				cout << endl;
				cout << "Kac gun kalicaksiniz:";//Kullanıcıdan kaç gün kalacaklarının bilgisini ister.
				cin >> gün_sayisi;
				cout << endl;
				tutar = 110 * müsteri_sayısı*gün_sayisi;//Oda fiyatı ile kişi ve gün sayısını çarpar.

				cout << "Tutar:" << tutar << "TL" << endl;//Hesaplanan tutarı ekrana yazar.
				system("pause");
				break;
			case 3://Suit oda seçimi için.
				cout << "Kac kisi kalicaksiniz:";//Kullanıcıdan kaç kişi kalacaklarının bilgisini ister.
				cin >> müsteri_sayısı;
				cout << endl;
				cout << "Kac gun kalicaksiniz:";//Kullanıcıdan kaç gün kalacaklarının bilgisini ister.
				cin >> gün_sayisi;
				cout << endl;
				tutar = 175 * müsteri_sayısı*gün_sayisi;//Oda fiyatı ile kişi ve gün sayısını çarpar.

				cout << "Tutar:" << tutar << "TL" << endl;//Hesaplanan tutarı ekrana yazar.
				system("pause");
				break;
			case 4://Kral daire seçimi için.
				cout << "Kac kisi kalicaksiniz:";//Kullanıcıdan kaç kişi kalacaklarının bilgisini ister.
				cin >> müsteri_sayısı;
				cout << endl;
				cout << "Kac gun kalicaksiniz:";//Kullanıcıdan kaç gün kalacaklarının bilgisini ister.
				cin >> gün_sayisi;
				cout << endl;
				tutar = 280 * müsteri_sayısı*gün_sayisi;//Oda fiyatı ile kişi ve gün sayısını çarpar.

				cout << "Tutar:" << tutar << "TL" << endl;//Hesaplanan tutarı ekrana yazar.
				system("pause");
			case 99: menü();//Menüye geri döner.
				break;
			default://Verilen seçimlerin dışında bir seçim yazarsa hatalı seçim diye akrana yazdırır.
				system("cls");//Ekranı yeniler.
				cout << "Hatali Secim " << endl;
				cout << "Devam etmek icin tiklayiniz" << endl;
				system("pause");
				break;
			}

		}
		system("pause");

	}//Odaya kayıt fonksiyonu sonu.
    	
};

int main()//Main fonksiyonu başlangıcı.
{
	Otel rezervasyon;//Classı çağırdım.

	rezervasyon.menü();//Menüyü çağırdım.

	return 0;

}//Main fonksiyonu sonu.