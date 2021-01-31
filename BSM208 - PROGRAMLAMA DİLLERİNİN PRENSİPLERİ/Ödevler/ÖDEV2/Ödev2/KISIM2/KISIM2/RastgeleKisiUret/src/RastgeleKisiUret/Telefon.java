/**
 *
 * @authors Beyzanur DEMİR, Fatmanur DEMİR
 * @since 26.04.2020
 * <p>
 *  Bu sınıfta Imei Algoritması kurallarına uygun olarak Imei üretilip return ediliyor. Imei Kontrol kısmında ise gelen Imei parametresine göre geçerlilik kontrolü yapılmaktadır.
 * </p>
 */

package RastgeleKisiUret;


public class Telefon {
    
    private String TelNo;
    protected IMEI imei;
    
    public void createTelefon(IMEI imei){
        Rastgele random = new Rastgele();
        
        TelNo = "";
        int number[] = new int[11];
        number[0] = 0;
        number[1] = 5;
        number[2] = random.rastG(5) + 2;
        while(number[2] < 3 || number[2] > 5){
            number[2] = random.rastG(5) + 2;
        }
        for(int i = 3; i < 11; i++){
            number[i] = random.rastG(9);
        }
        for (int i = 0; i < 11; i++) {
            TelNo += number[i];
        }
        this.imei = imei;
    }
    
    public String getTelefon(){
        return this.TelNo;
    }
}
