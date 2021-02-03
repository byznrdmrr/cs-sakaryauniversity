/**
 *
 * @authors Beyzanur DEMİR, Fatmanur DEMİR
 * @since 26.04.2020
 * <p>
 *  Bu sınıfta Imei Algoritması kurallarına uygun olarak Imei üretilip return ediliyor. Imei Kontrol kısmında ise gelen Imei parametresine göre geçerlilik kontrolü yapılmaktadır.
 * </p>
 */

package RastgeleKisiUret;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class RastgeleKisi {
    private final TCNo TCNo;
    private final IMEI imei;
    private final Telefon telefon;
    private final Kisi kisi;
    
    public RastgeleKisi(){
        TCNo = new TCNo();
        imei = new IMEI();
        telefon = new Telefon();
        kisi = new Kisi();
    }
    
    public void createRastgeleKisi(){
        TCNo.createTCNo();
        imei.createIMEI();
        telefon.createTelefon(imei);
        kisi.createKisi(TCNo, telefon);
    }
    
    public void save() throws IOException{
        File file = new File("kisiler.txt");
        
        try{
            PrintWriter pw;
            pw = new PrintWriter(new BufferedWriter(new FileWriter(file,true)));
            pw.println(kisi.TCNo.getTCNo() + " " + kisi.getIsimSoyisim() + " " + kisi.getYas() + " "
                     + kisi.telefonNo.getTelefon() + " " + '(' + kisi.telefonNo.imei.getIMEI() + ')' );
            pw.flush();
            pw.close();
        }
        
        catch(IOException ex){
            System.out.println("Sistem Hatasi : " + ex);
        }
    }
    
    public void checkIt() throws FileNotFoundException{
        try{
            String row = null;
            int cTotalTC = 0;
            int wTotalTC = 0;
            int cTotalIMEI = 0;
            int wTotalIMEI = 0;
            int rowNum = 0;
            
            ArrayList<String> text = new ArrayList<>();
            
            File file = new File("kisiler.txt");
            
            try{
                file.createNewFile();
            }
            catch(IOException ex){
                System.out.println("Dosya Okuma Isleminde Bir Hata Olustu : " + ex);
            }
            
            try(Scanner scan = new Scanner(file)){
                while(scan.hasNextLine()){
                    row = scan.nextLine();
                    text.add(row);
                    rowNum++;
                }
                
                if(rowNum > 0){
                    for(int i = 0; i < rowNum; i++){
                        String str = text.get(i);
                        
                        if(TCNo.controlTC(str.substring(0, 11)))
                            cTotalTC++;
                        else
                            wTotalTC++;
                        
                        int p1 = text.get(i).indexOf("(");
                        int p2 = text.get(i).indexOf(")");
                        
                        if(imei.controlIMEI(str.substring(p1 + 1, p2)))
                            cTotalIMEI++;
                        else
                            wTotalIMEI++;
                    }
                    
                    System.out.println("\nT.C. Kimlik Kontrol");
                    System.out.println(cTotalTC + " Gecerli");
                    System.out.println(wTotalTC + " Gecersiz\n");
                    System.out.println("IMEI Kontrol");
                    System.out.println(cTotalIMEI + " Gecerli");
                    System.out.println(wTotalIMEI + " Gecersiz\n");
                }
                
                else
                    System.out.println("Olusturulmus Kisi Bulunamadı !!!");
            }
        }
        catch(FileNotFoundException ex){
            System.out.println("Dosya Bulunmadi veya Olusturulmadi : " + ex);
        }
    }
}
