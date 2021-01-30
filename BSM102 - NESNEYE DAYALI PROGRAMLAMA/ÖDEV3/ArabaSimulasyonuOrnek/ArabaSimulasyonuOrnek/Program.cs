using System;

namespace ArabaSimulasyonuOrnek
{
    class Program
    {
        static void Main(string[] args)
        {
            /* Bu program sınıfları test etmek için yazılmıştır ve
             * ödeve dâhil değildir.
             * Ödevde sadece sınıflar ve arayüzler istenmektedir. */
            
            var kontakAnahtari = new KontakAnahtari();
            var motor = new BenzinliMotor();

            var elektronikBeyin = new ElektronikBeyin(kontakAnahtari, motor);

            // Kontak anahtarı açılıyor
            // Bu durum elektronik beyne otomatik iletilir,
            // beyin de otomatik olarak motoru çalıştırır.
            kontakAnahtari.Ac();

            Console.ReadKey();
        }
    }
}
