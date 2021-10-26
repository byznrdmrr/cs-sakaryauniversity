
public class Hungarian {
    int[] rows; 
    int[] occupiedCols; 
    private int[][] originalValues; // Girilen değerler
    private int[][] values; // Girilen değerlerin klonu
    private int[][] lines; // Çizilen çizgileri tutacak array
    private int numLines; // Çizilen çizgi sayısı

    public Hungarian(int[][] matrix) {
        // ilk değer atamaları
        originalValues = matrix; 
        values = cloneMatrix(matrix); 
        rows = new int[values.length];
        occupiedCols = new int[values.length];

        //Algoritma
        subtractRowMinimal();                // Adım 1
        subtractColMinimal();                // Adım 2
        coverZeros();                        // Adım 3
        while (numLines < values.length) {
            createAdditionalZeros();        // Adım 4 (Duruma bağlı)
            coverZeros();                    // Adım 3 (Duruma bağlı)
        }
        optimization();                        // Optimizasyon
    }

    /**
     * Adım1 -Satır indirgeme
     * Her satırın min değeri satır elemanlarından çıkartılır.
     */
    public void subtractRowMinimal() {
        int[] rowMinValue = new int[values.length];
        //Her satır için min değer rowMinValue[] array'i içerisinde saklanır.
        for (int row = 0; row < values.length; row++) {
            rowMinValue[row] = values[row][0];
            for (int col = 1; col < values.length; col++) {
                if (values[row][col] < rowMinValue[row])
                    rowMinValue[row] = values[row][col];
            }
        }

        //rowMinValue[] array'i kullanılarak her satırdan min değer çıkartılır.
        for (int row = 0; row < values.length; row++) {
            for (int col = 0; col < values.length; col++) {
                values[row][col] -= rowMinValue[row];
            }
        }
    } 

    /**
     * Adım2 -Sütun indirgeme
     * Her sütunun min değeri sütun elemanlarından çıkartılıyor.
     */
    public void subtractColMinimal() {
        int colMinValue[] = new int[values.length];
        //Her sütun için min değer colMinValue[] array'i içerisinde saklanır.
        for (int col = 0; col < values.length; col++) {
            colMinValue[col] = values[0][col];
            for (int row = 1; row < values.length; row++) {
                if (values[row][col] < colMinValue[col])
                    colMinValue[col] = values[row][col];
            }
        }

        //colMinValue[] array'i kullanılarak her sütundan min değer çıkartılır. 
        for (int col = 0; col < values.length; col++) {
            for (int row = 0; row < values.length; row++) {
                values[row][col] -= colMinValue[col];
            }
        }
    } 

    /**
     * Step 3.1
     * Matris elemanları bir döngü ile gezilir ve ardından sıfıra eşit elamanlar için colorNeighbors fonksiyonu çalışır.
     */
    public void coverZeros() {
        numLines = 0;
        lines = new int[values.length][values.length];

        for (int row = 0; row < values.length; row++) {
            for (int col = 0; col < values.length; col++) {
                if (values[row][col] == 0)
                    colorNeighbors(row, col, maxVH(row, col));
            }
        }
    }

    /**
     * Adım 3.2
     * Tüm sıfırlar kapanacak şekilde min sayıda satır ve sütun çigileri çizilir.
     * Hangi yönde daha fazla sıfır içerdiği kontrol edilir. Dikey olarak bulunan sıfırlarda sonuç arttırılır, yatay olarak bulunanlarda sonuç azaltılır.    
     *
     * @param row İlgili hücrenin satır indeksi
     * @param col İlgili hücrenin sütun indeksi
     * @return Pozitif ise dikey, sıfır veya negatif ise yatay çizilmesi gerektiği anlamına gelir
     */
    private int maxVH(int row, int col) {
        int result = 0;
        for (int i = 0; i < values.length; i++) {
            if (values[i][col] == 0)
                result++;
            if (values[row][i] == 0)
                result--;
        }
        return result;
    }

    /**
     * Adım 3.3
     * [row][col] indekslerine göre hücre komşularının üzerleri çizilir.
     *
     * @param row   İlgili hücrenin satır indeksi
     * @param col   İlgili hücrenin sütun indeksi
     * @param maxVH Çizgilerin hani yönde çizileceğini bulmak için.Pozitif ise çizgi dikey, negatif ve 0 ise çizgi yatay çizilir.
     */
    private void colorNeighbors(int row, int col, int maxVH) {
        //Kontroller yapılıyor
        if (lines[row][col] == 2) // Kesişim noktası üzerinden daha önce 2 kez geçilmişse tekrardan çizme
            return;

        if (maxVH > 0 && lines[row][col] == 1) // Kesişim noktası daha önce dikey olarak çizilmişse tekrardan çizilmesin yoksa satır sayısı artar
            return;

        if (maxVH <= 0 && lines[row][col] == -1) // Kesişim noktası daha önce yatay olarak çizilmişse tekrardan çizilmesin
            return;

        for (int i = 0; i < values.length; i++) { 
            if (maxVH > 0)    //  maxVH pozitif ise dikey çiz
                lines[i][col] = lines[i][col] == -1 || lines[i][col] == 2 ? 2 : 1; //Hücre önceden yatay(-1) olarak çizilmişse ve şu an dikey(1) olarak çizilmesi gerekiyor ise kesişim(2) olur, değer daha önce çizilmemişse ise dikey olarak çizilir.
            else            // maxVH negatif veya 0 ise yatay çiz
                lines[row][i] = lines[row][i] == 1 || lines[row][i] == 2 ? 2 : -1; //Hücre önceden dikey(1) olarak çizilmişse ve şu an yatay(1) olarak çizilmesi gerekiyor ise kesişim(2) olur, değer daha önce çizilmemişse ise yatay olarak çizilir.
        }

        // çizilen çizgi sayısını arttır.
        numLines++;
//		printMatrix(lines); 
    }

    /**
     * Adım 4 (Ek adım)
     * Bu adım her zaman çalışmayacak.(Aynı işi birden fazla kişinin yapması gerektiği durum)
     * Üzeri çizilmemeiş hücrelerin min değerleri belirlenerek, ek sıfırlar elde edilecek.
     */
    public void createAdditionalZeros() {
        int minUncoveredValue = 0; //İlk değeri 0 olarak atadık

        // Üzeri çizilmemiş hücreler için min değer bulunur
        for (int row = 0; row < values.length; row++) {
            for (int col = 0; col < values.length; col++) {
                if (lines[row][col] == 0 && (values[row][col] < minUncoveredValue || minUncoveredValue == 0))
                    minUncoveredValue = values[row][col];
            }
        }

        // Üzeri çizili olmayan elemanlardan min değer çıkartılır, kesişim noktalarına ise min değer eklenir.
        for (int row = 0; row < values.length; row++) {
            for (int col = 0; col < values.length; col++) {
                if (lines[row][col] == 0) // Üzeri çizilmemiş nokta, çıkar
                    values[row][col] -= minUncoveredValue;

                else if (lines[row][col] == 2) // Kesişim noktası, ekle
                    values[row][col] += minUncoveredValue;
            }
        }
    } 

    /**
     * Oluşan matriste atamalar yapılırken aynı sütundan en fazla bir eleman seçilmeli, Bunu sağlayabilmek için Brute Force kullanıldı.
     *
     * @param row
     * @return true
     **/
    private boolean optimization(int row) {
        if (row == rows.length) // Tüm satırlara bir hücre atanmışsa
            return true;

        for (int col = 0; col < values.length; col++) { // Tüm sütunlar gezilir
            // Geçerli hücre sıfır değerine sahipse ve bulunulan sütun önceki satır(lar) tarafından ayrılmış/kullanılmış ise
            if (values[row][col] == 0 && occupiedCols[col] == 0) { 
                rows[row] = col; // Geçerli sütunu ata
                occupiedCols[col] = 1; // Sütunu ayrılmış/kullanılmış olarak işaretle
                if (optimization(row + 1)) // Sonraki satırlara farklı sütunlardan hüce ataması yapıldıysa, true
                    return true;
                // Sonraki satırlara herhangi bir atama yapılamadıysa geri dön ve önceki satırlar için başka bir sütundan başka bir hücre denensin
                occupiedCols[col] = 0; 
            }
        }
        // Geçerli satır için hiçbir hücre atanmamışsa, başka bir sütundan başka bir hücreye atamayı denemek için bir satır geri gitmek üzere false değeri döner
        return false; 
    }
    
    public boolean optimization() {
        return optimization(0);
    } 

    /**
     * Her satırdan seçilen hücreyi içeren diziyi döndürür
     * 
     * @return Dizinin index değeri satır numarasını, dizinin o indexdeki değeri ise o satırın işaretli hücresini verir
     */
    public int[] getResult() {
        return rows;
    }

    /**
     * Satır dizisini kullanarak tüm satırlar için seçilen hücrelerin değerlerinin toplamı öğrenilir 
     *
     * @return Toplam değer
     */
    public int getTotal() {
        int total = 0;
        for (int row = 0; row < values.length; row++)
            total += originalValues[row][rows[row]];
        return total;
    }

    /**
     * 2 boyutlu matris klonlanır
     *
     * @return 2 boyutlu matrisin kopyası
     */
    public int[][] cloneMatrix(int[][] matrix) {
        int[][] tmp = new int[matrix.length][matrix.length];
        for (int row = 0; row < matrix.length; row++) {
            tmp[row] = matrix[row].clone();
        }
        return tmp;
    }

    /**
     * 2 boyutu matris yazdırlırır
     *
     * @param matrix Hedef 2 boyutlu dizi
     */
    public void printMatrix(int[][] matrix) {
        for (int row = 0; row < matrix.length; row++) {
            for (int col = 0; col < matrix.length; col++) {
                System.out.print(matrix[row][col] + "\t");
            }
            System.out.println();
        }
        System.out.println();
    }
}