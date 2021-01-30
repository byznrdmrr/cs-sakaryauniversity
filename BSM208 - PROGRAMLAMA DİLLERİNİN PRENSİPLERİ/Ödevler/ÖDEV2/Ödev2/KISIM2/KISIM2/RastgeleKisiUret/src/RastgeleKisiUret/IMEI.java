/**
 *
 * @authors Beyzanur DEMİR, Fatmanur DEMİR
 * @since 26.04.2020
 * <p>
 *  Bu sınıfta Imei Algoritması kurallarına uygun olarak Imei üretilip return ediliyor. Imei Kontrol kısmında ise gelen Imei parametresine göre geçerlilik kontrolü yapılmaktadır.
 * </p>
 */

package RastgeleKisiUret;


public class IMEI {
    private String imei;
    
    public void createIMEI(){
        Rastgele random = new Rastgele();
        
        int sum1 = 0;
        int sum2 = 0;
        int count = 0;
        
        int number[] = new int[15];
        
        for(int i = 0; i < 14; i++){
            number[i] = random.rastG(10);
        }
        
        for(int i = 1; i < 14; i += 2){
            sum1 += number[count];
            count++;
            if(number[i]*2 > 9){
                int newNum = (number[i]*2) - 9;
                sum2 += newNum;
                continue;
            }
            sum2 += number[i];
        }
        
        int contNum = sum1 + sum2;
        int tempNum = contNum;
        while(contNum % 10 != 0){
            contNum++;
        }
        number[14] = contNum - tempNum;
        
        imei = "";
        
        for(int i = 0; i < 15; i++){
            imei += number[i];
        }
    }
    
    public boolean controlIMEI(String imei){
        int number[] = new int[15];
        int sum1 = 0;
        int sum2 = 0;
        int count = 0;
        
        for(int i = 0; i < 15; i++){
            char c = imei.toCharArray()[i];
            number[i] = Integer.parseInt(String.valueOf(c));
        }
        
        for(int i = 1; i < 14; i += 2){
            sum1 += number[count];
            count++;
            if(number[i]*2 > 9){
                int newNum = (number[i]*2) - 9;
                sum2 += newNum;
                continue;
            }
            sum2 += number[i];
        }
        
        int contNum = sum1 + sum2;
        int tempNum = contNum;
        while(contNum % 10 != 0){
            contNum++;
        }
        
        return (number[14] == (contNum - tempNum));
    }
    
    public String getIMEI(){
        return imei;
    }
}
