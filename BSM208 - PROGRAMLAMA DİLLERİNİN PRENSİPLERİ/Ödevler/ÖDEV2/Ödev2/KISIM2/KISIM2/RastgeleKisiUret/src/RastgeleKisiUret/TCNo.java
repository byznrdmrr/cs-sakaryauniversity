/**
 *
 * @authors Beyzanur DEMİR, Fatmanur DEMİR
 * @since 26.04.2020
 * <p>
 *  Bu sınıfta Imei Algoritması kurallarına uygun olarak Imei üretilip return ediliyor. Imei Kontrol kısmında ise gelen Imei parametresine göre geçerlilik kontrolü yapılmaktadır.
 * </p>
 */

package RastgeleKisiUret;


public class TCNo {
    private String TCNo;
    
    public String getTCNo(){
        return TCNo;
    }
    
    public void createTCNo(){
        Rastgele random = new Rastgele();
        
        int number[] = new int[11];
        int num;
        int count = 0;
        int oddSum = 0;
        int evenSum = 0;
        int lastSum = 0;
        
        for(int i = 0; i < 9; i++){
            num = random.rastG(10);
            if(i == 0){
                if(num == 0){
                    num++;
                    number[i] = num;
                    continue;
                }
            }
            number[i] = num;
        }
        
        for(int i = 1; i <= 8; i += 2){
            oddSum += number[count];
            evenSum += number[i];
            count += 2;
        }
                
        oddSum *= 7;
        int n10 = (oddSum - evenSum) % 10;
        number[9] = n10;
        
        for(int i = 0; i < 10; i++){
            lastSum += number[i];
        }
        
        int n11 = lastSum % 10;
        number[10] = n11;
        
        TCNo = "";
        
        for(int i = 0; i < 11; i++){
            TCNo += number[i];
        }
    }
    
    public boolean controlTC(String tcNo){
        int oddSum = 0;
        int evenSum = 0;
        int lastSum = 0;
        int count = 0;
        int number[] = new int[11];
               
        for(int i = 0; i < 11; i++){
            char c = tcNo.toCharArray()[i];
            number[i] = Integer.parseInt(String.valueOf(c));
        }
        
        for(int i = 1; i <= 8; i += 2){
            oddSum += number[count];
            evenSum += number[i];
            count += 2;
        }
                
        int n10 = ((oddSum * 7) - evenSum) % 10;
        
        for(int i = 0; i < 10; i++){
            lastSum += number[i];
        }
        
        int n11 = lastSum % 10;
        
        return ((number[9] == n10) && (number[10] == n11));
    }
}
