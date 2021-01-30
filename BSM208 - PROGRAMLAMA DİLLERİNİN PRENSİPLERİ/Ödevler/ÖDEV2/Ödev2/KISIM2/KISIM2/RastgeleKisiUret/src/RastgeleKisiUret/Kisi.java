/**
 *
 * @authors Beyzanur DEMİR, Fatmanur DEMİR
 * @since 26.04.2020
 * <p>
 *  Bu sınıfta Imei Algoritması kurallarına uygun olarak Imei üretilip return ediliyor. Imei Kontrol kısmında ise gelen Imei parametresine göre geçerlilik kontrolü yapılmaktadır.
 * </p>
 */

package RastgeleKisiUret;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Kisi {
    protected TCNo TCNo;
    private String isimSoyisim;
    private int yas;
    protected Telefon telefonNo;
    
    public void createKisi(TCNo TCNo, Telefon telefonNo){
        this.TCNo = TCNo;
        this.yas = createYas();
        this.telefonNo = telefonNo;
        this.isimSoyisim = createIsimSoyisim();
    }
    
    private String createIsimSoyisim(){
        Rastgele random = new Rastgele();
        
        String text = null;
        String isimDizi[] = new String[3000];
        
        int satir = 0;
        
        try{
            File dosya = new File("random_isimler.txt");
            
            try(Scanner scan = new Scanner(dosya)){
                
                while(scan.hasNextLine()){
                    text = scan.nextLine();
                    isimDizi[satir] = text;
                    satir++;
                }
                this.isimSoyisim = isimDizi[random.rastG(3000)];
            }
        }
        catch(FileNotFoundException ex){
            System.out.println("Dosya Bulunamadi" + ex);
        }
        return isimSoyisim;
    }
    
    public String getIsimSoyisim(){
        return isimSoyisim;
    }
    
    private int createYas(){
        Rastgele random = new Rastgele();
        return random.rastG(100);
    }
    
    public int getYas(){
        return yas;
    }
}
