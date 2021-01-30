
package RASTGELEKISIURET;

/**
 *
 * @authors
 * @since 
 * <p>
 * Yas sınıfında 0-100 aralığında yaş üretilmektedir.
 * </p>
 */
public class Yas{
    
    Rastgele rakamuret=new Rastgele();
    
    public int Yas()
    {
        return rakamuret.Sayi_Olustur(100);
    }
}

