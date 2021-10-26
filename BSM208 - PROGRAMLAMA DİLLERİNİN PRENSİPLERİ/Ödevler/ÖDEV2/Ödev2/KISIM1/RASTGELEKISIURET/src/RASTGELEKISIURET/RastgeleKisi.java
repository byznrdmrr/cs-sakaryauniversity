package RASTGELEKISIURET;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
/**
 * @authors Beyzanur DEMİR, Fatmanur DEMİR
 * @since 26.04.2020
 * <p>
 *  Random_isimler.txt Belgesinde bulunan isimler çekilip rastgele kişiler oluşturuyoruz ve Kisi.java sınıfına yolluyoruz.
 * </p>
 */

public class RastgeleKisi {
    
// Üretilen Kişiler Metin belgesine Kayıt Edilip Üretilen Kişilerdeki TC Imei Numaraları Geçerlimi Diye Kontrol Edilip Ekrana Yazdırılmaktadır.
    private final Rastgele rakamuret = new Rastgele();
    private int SatirSayisi;
    private File file;
    private BufferedReader reader = null;

        public String RastgeleKisi(){
         file = new File("..\\RASTGELEKISIURET\\random_isimler.txt");
         
                
        SatirSayisi = 0;
        try {
            reader = new BufferedReader(new FileReader(file));
            String satir = reader.readLine();
            while (satir != null) {
                if (satir.length() > 0) {
                    SatirSayisi++;
                }
                satir = reader.readLine();
            }
        } catch (final IOException e) {
        }
        
         int sayac = 0;
        String Metin[] = new String[SatirSayisi + 1];
        try {
            reader= new BufferedReader(new InputStreamReader(new FileInputStream(file)));
            Metin[0] = reader.readLine();
            while (Metin[sayac] != null) {
                if (Metin[sayac].length() > 0) {
                    sayac++;
                }
                Metin[sayac] = reader.readLine();
            }
            reader.close();
        } catch (FileNotFoundException ex) {
        } catch (IOException ex) {
        }
        return Metin[rakamuret.Sayi_Olustur(SatirSayisi)];
    
    }
   
    }
