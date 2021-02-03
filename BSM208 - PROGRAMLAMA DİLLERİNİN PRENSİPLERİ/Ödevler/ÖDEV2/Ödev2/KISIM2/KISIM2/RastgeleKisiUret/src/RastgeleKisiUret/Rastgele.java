/**
 *
 * @authors Beyzanur DEMİR, Fatmanur DEMİR
 * @since 26.04.2020
 * <p>
 *  Bu sınıfta Imei Algoritması kurallarına uygun olarak Imei üretilip return ediliyor. Imei Kontrol kısmında ise gelen Imei parametresine göre geçerlilik kontrolü yapılmaktadır.
 * </p>
 */
package RastgeleKisiUret;


public class Rastgele {
    
    private long sayi(){
        long sayi = System.nanoTime();
        return sayi;
    }
    
    public int rastG(int value){
        int sonuc = (int)((sayi())% value);
        return sonuc;
    }
}
