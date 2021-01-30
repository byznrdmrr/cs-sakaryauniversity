using System;

namespace ArabaSimulasyonuOrnek
{
    public enum MotorDurumu { Calisiyor, Calismiyor }
    public enum KontakAnahtariDurumu { Acik, Kapali }

    public class ElektronikBeyin
    {
        private readonly KontakAnahtari _kontakAnahtari;
        private readonly Motor _motor;

        public ElektronikBeyin(KontakAnahtari kontakAnahtari, Motor motor)
        {
            _kontakAnahtari = kontakAnahtari;
            _motor = motor;

            // Kontağın açılması olayı gerçekleştiğinde KontakAcildi metodu otomatik olarak çalışsın
            _kontakAnahtari.KontakAcildiEventHandler += KontakAcildi;
        }

        // Kontak açıldığında bu metot otomatik olarak çalışacaktır.
        private void KontakAcildi(object sender, EventArgs e)
        {
            // Motor zaten çalışıyorsa devam etme
            if (_motor.Durum == MotorDurumu.Calisiyor) return;

            // Motoru çalıştır
            _motor.Calistir();
        }
    }

    public abstract class Motor
    {
        public MotorDurumu Durum { get; private set; }
        public int HizlanmaMiktari { get; set; }

        protected Motor()
        {
            // Motorun başlangıç durumu çalışmıyor olarak ayarlanıyor
            Durum = MotorDurumu.Calismiyor;
        }

        public void Calistir()
        {
            // Motor zaten çalışıyorsa devam etme
            if (Durum == MotorDurumu.Calisiyor) return;

            Durum = MotorDurumu.Calisiyor;

            // Bu satır test amaçlı olarak yazılmıştır
            Console.WriteLine("Motor çalıştı.");
        }
    }

    public class BenzinliMotor : Motor
    {
        public BenzinliMotor()
        {
            HizlanmaMiktari = 10;
        }
    }

    public class KontakAnahtari
    {
        // Kontak anahtarının durumu için salt okunur (read-only) bir özellik yazılıyor
        public KontakAnahtariDurumu Durum { get; private set; }

        // Kontak açıldığında tetiklenecek olay için event handler tanımlanıyor
        public event EventHandler KontakAcildiEventHandler;

        public KontakAnahtari()
        {
            // Kontak anahtarının başlangıç durumu kapalı olarak ayarlanıyor
            Durum = KontakAnahtariDurumu.Kapali;
        }

        public void Ac()
        {
            // Kontak zaten açıksa devam etme
            if (Durum == KontakAnahtariDurumu.Acik) return;

            // Kontağı açık konuma getir
            Durum = KontakAnahtariDurumu.Acik;

            // Bu satır test amaçlı olarak yazılmıştır
            Console.WriteLine("Kontak açıldı.");

            // Kontağın açılması olayını tetikle
            if (KontakAcildiEventHandler == null) return;
            KontakAcildiEventHandler(this, new EventArgs());
        }
    }
}
