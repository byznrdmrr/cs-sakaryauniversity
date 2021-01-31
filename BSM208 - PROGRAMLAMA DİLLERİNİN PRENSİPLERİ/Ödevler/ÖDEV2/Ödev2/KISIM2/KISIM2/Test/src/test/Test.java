/**
 *
 * @authors Beyzanur DEMİR, Fatmanur DEMİR
 * @since 26.04.2020
 * <p>
 *  Bu sınıfta Imei Algoritması kurallarına uygun olarak Imei üretilip return ediliyor. Imei Kontrol kısmında ise gelen Imei parametresine göre geçerlilik kontrolü yapılmaktadır.
 * </p>
 */

package test;

import RastgeleKisiUret.*;
import java.io.IOException;
import java.util.Scanner;

public class Test {

    
    public static void main(String[] args) throws IOException {
        RastgeleKisi rastKisi = new RastgeleKisi();
        
        Scanner value = new Scanner(System.in);
        
        int choise;
        
        while(true){
            System.out.println("1- Rastgele Kisi Üret");
            System.out.println("2- Üretilmiş Dosya Kontrol Et");
            System.out.println("3- Çıkış");
            System.out.println("Seçim : ");
            
            choise = value.nextInt();
            
            if(choise == 1){
                System.out.println("Kac Kisi Ureteceksin : ");
                int kisiNum = value.nextInt();
                
                for(int i = 0; i < kisiNum; i++){
                    rastKisi.createRastgeleKisi();
                    rastKisi.save();
                }
                continue;
            }
            else if(choise == 2){
                rastKisi.checkIt();
                continue;
            }
            else if(choise == 3){
                break;
            }
            else{
                System.out.println("Hatali Secim !!! \n");
                continue;
            }
        }
    }
}
