
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        int n;
        System.out.print("Matris Boyutu(nxn) için n değeri giriniz: ");
        Scanner sc = new Scanner(System.in);        
        n = sc.nextInt();      
        int[][] dm = new int[n][n];
        
        System.out.println("Matrisi Giriniz: ");
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dm[i][j] = sc.nextInt();
        sc.close();


        long time = System.currentTimeMillis(); 
        Hungarian hungarian = new Hungarian(dm);
        System.out.println(String.format("Total time: %dms\n", System.currentTimeMillis() - time)); 

        int[] result = hungarian.getResult();
        for (int i = 0; i < result.length; i++)
            System.out.println(String.format("Row%d => Col%d (%d)", i + 1, result[i] + 1, dm[i][result[i]])); // Rowi => Colj (value)

        System.out.println(String.format("\nTotal: %d", hungarian.getTotal())); 
    }
}