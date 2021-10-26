    
            
package javaapplication1;

import java.io.*;
import java.util.regex.Pattern;
import java.util.ArrayList;
import java.util.regex.Matcher;
import java.io.IOException;

/**
*
* @author Beyzanur DEMİR G161210045 beyzanur.demir@ogr.sakarya.ed.tr Fatmanur DEMİR G171210072 fatmanur.demir@ogr.sakarya.edu.tr
* @since 08.03.2020
* <p>
* PDP_ODEV1
* </p>
*/

public class JavaApplication1 {
    
    

    public static void main(String[] args) throws IOException
    {  
        // Dosya adi
        String dosyaadi = "icerik.txt";
        
        // Dosyadaki satir icin degisken
        String satirlar = null;
        
        //istenenlerin tutulacagi listeler
        ArrayList<String> sesli_harf_sayisi = new ArrayList<String>();
        ArrayList<String> kelime_sayisi  = new ArrayList<String>();
        ArrayList<String> cumle_sayisi  = new ArrayList<String>();
        ArrayList<String> mail_sayisi  = new ArrayList<String>();
        ArrayList<String> web_sitesi_sayisi  = new ArrayList<String>();
        
        //Pattern tanımlamaları
        Pattern website = Pattern.compile ("(https?:\\/\\/)?(www\\.)[-a-zA-Z0-9@:%._\\+~#=]{2,256}\\.[a-z]{2,4}\\b([-a-zA-Z0-9@:%_\\+.~#?&//=]*)|(https?:\\/\\/)?(www\\.)?(?!ww)[-a-zA-Z0-9:%._\\+~#=]{2,256}\\.[a-z]{2,4}\\b([-a-zA-Z0-9@:%_\\+.~#?&//=]*)");
        Pattern mail=Pattern.compile("[A-z0-9.-]+@[A-z0-9.-]+\\.[A-z]{2,3}+[$||\\s]");
        Pattern cumle  = Pattern.compile("\\.+\\s");
        Pattern kelime  = Pattern.compile("\\b((?!=|\\,|\\ .).)+\\b");
        Pattern sesliharf=Pattern.compile("a|e|ı|i|o|ö|u|ü|A|E|I|İ|O|Ö|U|Ü");
  
        try
        {
          //dosya okuma 
          FileReader dosyayioku = new FileReader(dosyaadi);
          
          BufferedReader okuyucu = new BufferedReader(dosyayioku);
          
          // Dosyayi satir satir okuma
            while ((satirlar = okuyucu.readLine()) != null) 
            {
                
                // matcher tanımları
                Matcher website_matcher = website.matcher(satirlar);
                Matcher mail_matcher = mail.matcher(satirlar);
                Matcher cumle_matcher = cumle.matcher(satirlar);
                Matcher kelime_matcher = kelime.matcher(satirlar);
                Matcher sesliharf_matcher = sesliharf.matcher(satirlar);
   
                //Esleyenleri bulmak için

                
                //web sitesi bulma
                while(website_matcher.find())
                {
                    
                    String gecici1 = website_matcher.group();
                    if (gecici1.length() != 0)
                    {     
                            web_sitesi_sayisi.add(gecici1); 
                    }
                }
                
                //mail bulma
                while (mail_matcher.find()) 
                {
                   
                   String gecici2 = mail_matcher.group();
                   if (gecici2.length() != 0)
                    { 
                             mail_sayisi.add(gecici2);   
                    }
                }
                
                
             while (cumle_matcher.find()) 
                {
                    
                    String gecici3 = cumle_matcher.group();
                    if (gecici3.length() != 0)
                    {
                            cumle_sayisi.add(gecici3);
                    }
                }
                
                //kelime bulma
                while (kelime_matcher.find()) 
                {
                    
                    String gecici4 = kelime_matcher.group();
                    if (gecici4.length() != 0)
                    {
                        if (!kelime_sayisi.contains(gecici4)) 
                        {
                            kelime_sayisi.add(gecici4);
                        }
                    }
                }
                
                //sesli harf bulma
                while (sesliharf_matcher.find()) 
                {
                    //System.out.println(sesliharf_matcher.group());
                    String gecici5 = sesliharf_matcher.group();
                    if (gecici5.length() != 0)
                    {
                        sesli_harf_sayisi.add(gecici5);
                    }
                }      
            }
            
            
            //WEB sitesi sayisini ekrana yazdirma
            System.out.println("Web Sitesi Sayısı:" + web_sitesi_sayisi.size());
            
            //Mail sayisini ekrana yazdirma
            System.out.println("Mail Sayısı:" + mail_sayisi.size());
            
            //Cümle sayisini ekrana yazdirma
            System.out.println("Cümle Sayısı:" + cumle_sayisi.size());
            
            //Sesli harf sayisini ekrana yazdirma
            System.out.println("Sesli Harf Sayısı:" + sesli_harf_sayisi.size());
            
            //Kelime sayisini ekrana yazdirma
            System.out.println("Kelime Sayısı:" + kelime_sayisi.size());
            
            
            //Dosya kapatmak
            okuyucu.close();
        }
        catch (FileNotFoundException ex) 
        {
            System.out.println("Dosya bulunamadi.");
        }       
    }                
}
    

