using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication10
{
    class Program
    {
        static void Main(string[] args)
        {
            
        }

        public enum SinyalLambalariDurumu { SagSinyal, SolSinyal, Acik, kapali, }
        public enum MotorDurumu { Calisiyor, Calismiyor }
        public enum KontakAnahtariDurumu { Acik, Kapali }
        public enum GazPedalıDurumu {basıldı, basılmadı }
        public enum FrenPedalıDurumu { basıldı, basılmadı}
        public enum direksiyonDurumu {saga_donuk, sola_donuk,duz }
        public enum FarlarDurumu { UzunFar, KisaFar, Acik, Kapali }

        public class ElektronikBeyin
        {
            private readonly KontakAnahtari _kontakAnahtari;
            private readonly Motor _motor;
            
            public ElektronikBeyin(KontakAnahtari kontakAnahtari, Motor motor)
            {
                _kontakAnahtari = kontakAnahtari;
                _motor = motor;
                _kontakAnahtari.KontakAcildiEventHandler += KontakAcildi;
            }

            
            private void KontakAcildi(object sender, EventArgs e)
            {
               
                if (_motor.Durum == MotorDurumu.Calisiyor) return;
                _motor.Calistir();
            }
        }

        public abstract class Motor
        {
            public MotorDurumu Durum { get; private set; }
            public int HizlanmaMiktari { get; set; }

            protected Motor()
            {
                
                Durum = MotorDurumu.Calismiyor;
            }

            public void Calistir()
            {
               
                if (Durum == MotorDurumu.Calisiyor) return;

                Durum = MotorDurumu.Calisiyor;
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
        public class dizelmotor: Motor
        {
            public dizelmotor()
            {
                HizlanmaMiktari = 8;
            }
        }

        public class KontakAnahtari
        {
            
            public KontakAnahtariDurumu Durum { get; private set; }
            public event EventHandler KontakAcildiEventHandler;

            public KontakAnahtari()
            {
                Durum = KontakAnahtariDurumu.Kapali;
            }

            public void Ac()
            {
                if (Durum == KontakAnahtariDurumu.Acik) return;
                Durum = KontakAnahtariDurumu.Acik;

               
                if (KontakAcildiEventHandler == null) return;
                KontakAcildiEventHandler(this, new EventArgs());
            }
        }

        public class gazPedalı
        {
            public GazPedalıDurumu Durum { get; private set; }
            public int HizlanmaMiktari { get; set; }

            public event EventHandler GazaBasildieventHandler;

            public gazPedalı()
            {
                Durum = GazPedalıDurumu.basılmadı;
            }
            public void GazaBas()
            {
                if (Durum == GazPedalıDurumu.basıldı) return;

                Durum = GazPedalıDurumu.basıldı;
                HizlanmaMiktari++;

                if (GazaBasildieventHandler == null) return;
                GazaBasildieventHandler(this, new EventArgs());
            }

        }

        public class frenPedalı
        {
            public FrenPedalıDurumu Durum { get; private set; }
            public int HizlanmaMiktari { get; set; }

            public event EventHandler FreneBasildieventHandler;

            protected frenPedalı()
            {
                Durum = FrenPedalıDurumu.basılmadı;
            }


            public void FreneBas()
            {
                if (Durum == FrenPedalıDurumu.basıldı) return;

                Durum = FrenPedalıDurumu.basıldı;

                HizlanmaMiktari--;

                if (FreneBasildieventHandler == null) return;
                FreneBasildieventHandler(this, new EventArgs());
            }
        }
        public abstract class Direksiyon
        {
            public direksiyonDurumu Durum { get; private set; }
            public int TekerlegiDondur { get; set; }
            public event EventHandler SagadonuldueventHandler;
            public event EventHandler SoladonuldueventHandler;


            protected Direksiyon()
            {
                Durum = direksiyonDurumu.duz;           
            }

            public void SagaDon()
            {
                if (Durum == direksiyonDurumu.saga_donuk) return;

                Durum = direksiyonDurumu.saga_donuk;

                TekerlegiDondur++;

                if (SagadonuldueventHandler == null) return;
                SagadonuldueventHandler(this, new EventArgs());

            }

            public void SolaDon()
            {
                if (Durum == direksiyonDurumu.sola_donuk) return;

                Durum = direksiyonDurumu.sola_donuk;


                TekerlegiDondur++;

                if (SagadonuldueventHandler == null) return;
                SoladonuldueventHandler(this, new EventArgs());

            }

            public class Tekerlekler : Direksiyon
            {

                public Tekerlekler()
                {
                    TekerlegiDondur = 5;
                }
            }
        }


    }
}
