package RASTGELEKISIURET;

/**
 *
 * @authors Beyzanur DEMİR, Fatmanur DEMİR
 * @since 26.04.2020
 * <p>
 *  Telefon sınıfında Türkiyedeki telefon numaralarına uygun üretilmektedir. 
 * </p>
 */

public class Telefon {
    
    
 private final Rastgele rakamuret = new Rastgele();
    private String TelNumarasi = "";

    public String Telefon() {
        TelNumarasi = "";
        int TelDizi[] = new int[11];
        TelDizi[0] = 0;
        TelDizi[1] = 5;
        TelDizi[2] = rakamuret.Sayi_Olustur(5) + 2;
        while (TelDizi[2] < 3 || TelDizi[2] > 5) {
            TelDizi[2] = rakamuret.Sayi_Olustur(5) + 2;
        }
        for (int a = 3; a < 11; a++) {
            TelDizi[a] = rakamuret.Sayi_Olustur(9);
        }
        for (int a = 0; a < 11; a++) {
            TelNumarasi += TelDizi[a];
        }
        return TelNumarasi;
    }
}
