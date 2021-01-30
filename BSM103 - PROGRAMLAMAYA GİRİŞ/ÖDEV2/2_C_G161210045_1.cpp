/**********************************************************************************************************************************************************************/
/*                                                           SAKARYA ÜNÝVERSÝTESÝ                                                                                     */
/*                                                BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ                                                                           */
/*                                                     BÝLGÝSAYAR MÜHENDÝSÝLÝÐÝ BÖLÜMÜ                                                                                */
/*                                                          PROGRAMLAMAYA GÝRÝÞ DERSÝ                                                                                 */
/*                                                                 2.ÖDEV                                                                                             */
/*                                                             BEYZANUR DEMÝR                                                                                         */
/*                                                               G161210045                                                                                           */
/*                                                                C GRUBU                                                                                           */
/**********************************************************************************************************************************************************************/
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int vize,odev1,vizenot, odev, quiz, odev2, quiz1, quiz2, final, finalnot, vizeyuzde, odevyuzde, quizyuzde, yilicipyuzde, toplamp, yilicinot, yilsonup;

	do  // 100'den büyük bir vize notu girilmemesini kontrol etmek için 
	{
		cout << "vize notunuzu giriniz";
		cin >> vizenot;
	} while (vizenot > 100);
	
	do  //100 den büyük bir  odev notu girilmemesini kontrol etmek için 
	{
		cout << "1.odev notunuzu giriniz";
		cin >> odev1;
	} while (odev1 > 100);

	do //100 den büyük bir  odev notu girilmemesini kontrol etmek için 
	{
		cout << "2.odev notunuzu giriniz";
		cin >> odev2;
	} while (odev2 > 100);

	do //100 den büyük bir quiz notu girilmemesini kontrol etmek için 
	{
		cout << "1.quiz notunuzu giriniz";
		cin >> quiz1;
	} while (quiz1 > 100);

	do //100 den büyük bir quiz notu girilmemesini kontrol etmek için 
	{
		cout << "2.quiz notunuzu giriniz";
		cin >> quiz2;
	} while (quiz2 > 100);

	do //100 den büyük bir final notu girilmemesini kontrol etmek için 
	{
		cout << "final sinavi notunuzu giriniz";
		cin >> finalnot;
	} while (finalnot > 100);

	do  /*100 den büyük bir vize yüzdesi girilmemesini kontrol etmek için ve
	    yil içine yüzde toplamýnýn 100'den büyük olmamasýný kontrol etmek için*/
	{
		cout << "vizenin yil icine etkisi yuzde kac olacaktir?";
		cin >> vizeyuzde;
	} while (vizeyuzde > 100);

	do /*100 den büyük bir ödev yüzdesi girilmemesini kontrol etmek için ve
	    yil içine yüzde toplamýnýn 100'den büyük olmamasýný kontrol etmek için*/
	{
		cout << "Odevlerin yil icine etkisi yuzde kac olacaktir?";
		cin >> odevyuzde;
	} while (odevyuzde > 100-vizeyuzde || odevyuzde==100-vizeyuzde);

	do /*100 den büyük bir quiz yüzdesi girilmemesini kontrol etmek için ve
	    yil içine yüzde toplamýnýn 100'den büyük olmamasýný kontrol etmek için*/
	{
		cout << "quizlerin yil icine etkisi yuzde kac olacaktir";
		cin >> quizyuzde;
	} while (quizyuzde > 100-(vizeyuzde+odevyuzde));

	do  //100'den büyük bir yil içi puan yüzdsi girilmemesini kontrol etmek için
	{
		cout << "Yil ici puaninin etkisi yuzde kac olacaktir?";
		cin >> yilicipyuzde;
	} while (yilicipyuzde > 100);
	


	
	vize = (vizenot*vizeyuzde) / 100;
	odev = ((odev1 + odev2)/ 2)*odevyuzde / 100;
	quiz = ((quiz1 + quiz2)/ 2)*quizyuzde / 100;
	toplamp = vize + odev + quiz;
	yilicinot = (toplamp*yilicipyuzde) / 100;
	final = (100 - yilicipyuzde)*finalnot / 100;
	yilsonup = yilicinot + final;



	if (yilsonup >= 90)  //alýnan notlara göre harf aralýklarý belirlendi.
	{
		cout << "AA aldiniz" << setw(5)<< yilsonup << endl;
	}

	else if (yilsonup >= 85)
	{
		cout << "BA aldiniz" << setw(5) << yilsonup << endl;
	}
	else if (yilsonup >= 80)
	{
		cout << "BB aldiniz" << setw(5) << yilsonup << endl;
	}
	else if (yilsonup >= 75)
	{
		cout << "CB aldiniz" << setw(5) << yilsonup << endl;
	}
	else if (yilsonup >= 65)
	{
		cout << "CC aldiniz" << setw(5) << yilsonup << endl;
	}
	else if (yilsonup >= 58)
	{
		cout << "DC aldiniz" << setw(5) << yilsonup << endl;
	}
	else if (yilsonup >=50)
	{
		cout << "DD aldiniz" << setw(5) << yilsonup << endl;
	}
	else
	{
		cout << "FF aldiniz" << setw(5) << yilsonup << endl;
	}

	system("pause");
	return 0;


}