package RASTGELEKISIURET;

/**
 *
 * @authors Beyzanur DEMİR, Fatmanur DEMİR
 * @since 26.04.2020
 * <p>
 *  Diğer sınıflardan gelen bilgiler kisi sınıfında birleştirilip(yeni kişi oluşturulup) return ediyoruz.
 * </p>
 */
public class Kisi {
    private final RastgeleKisi YeniKisi = new RastgeleKisi();
    private final Yas YeniYas = new Yas();
    private final Telefon YeniTelefon = new Telefon();
    private final ImeiNu YeniImei = new ImeiNu();
    private final KimlikNu YeniKimlik = new KimlikNu();
    private String Gonder;

    public String KisiOlustur() {
        Gonder = YeniKimlik.KimlikNu() + " " + YeniKisi.RastgeleKisi() + " " + YeniYas.Yas() + " " + YeniTelefon.Telefon() + " (" + YeniImei.IMEINo() + ")";
        return Gonder;
    }

    public String KimlikKontrol(String Kimlik) {

        KimlikNu Tckontrol = new KimlikNu();
        return Tckontrol.KimlikNuKontrol(Kimlik);
    }

    public String ImeiKontrol(String Imei) {
        ImeiNu ImeiKontrol = new ImeiNu();
        return ImeiKontrol.ImeiKontrol(Imei);
    }
}
    

