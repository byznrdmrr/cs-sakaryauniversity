
package RASTGELEKISIURET;

/**
 *
 * @authors Beyzanur DEMİR, Fatmanur DEMİR
 * @since 26.04.2020
 */
public class Rastgele {
    
    
    public static int R_Gele;
    
//    public Rastgele(int R_Gele)
//    {
//        this.R_Gele=R_Gele;
//           
//    }
       
    public static long Zaman() {
        long zaman;
        zaman = System.nanoTime();
        
        return zaman;
        
    }
        public static int Sayi_Olustur(int x) 
        {
        int sayi;

        while (true) {
            R_Gele = (int) ((Zaman()) % 997);
            break;
            
        }

        sayi = (int) R_Gele;
        return sayi;
        }
    }
    
    
    
    
    
    

