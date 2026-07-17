#include <iostream>
#include <fstream>
#include <string> // Hatayı çözen kütüphane

using namespace std;

class Hesap {
private:
    double bakiye;

    // Dosyaya işlem detaylarını kaydeden gizli fonksiyon
    void islemKaydet(string islemDetayi) {
        ofstream dosya("hesap_ozeti.txt", ios::app);
        if (dosya.is_open()) {
            dosya << islemDetayi << endl;
            dosya.close();
        }
    }

public:
    // Yapıcı Metod (Constructor)
    Hesap() {
        bakiye = 0.0;
    }

    // Para Yatırma Fonksiyonu
    void paraYatir(double miktar) {
        if (miktar > 0) {
            bakiye += miktar;
            cout << miktar << " TL basariyla yatirildi." << endl;
            islemKaydet("Para Yatirildi: +" + to_string(miktar) + " TL. Guncel Bakiye: " + to_string(bakiye) + " TL.");
        }
        else {
            cout << "Gecersiz miktar!" << endl;
        }
    }

    // Para Çekme Fonksiyonu
    void paraCek(double miktar) {
        if (miktar <= 0) {
            cout << "Gecersiz miktar!" << endl;
        }
        else if (bakiye >= miktar) {
            bakiye -= miktar;
            cout << miktar << " TL basariyla cekildi." << endl;
            islemKaydet("Para Cekildi: -" + to_string(miktar) + " TL. Guncel Bakiye: " + to_string(bakiye) + " TL.");
        }
        else {
            cout << "Yetersiz bakiye! Mevcut bakiye: " << bakiye << " TL" << endl;
        }
    }

    // Bakiye Gösterme Fonksiyonu
    void bakiyeGoster() {
        cout << "Guncel Bakiyeniz: " << bakiye << " TL" << endl;
    }
    // Hesap Özetini Dosyadan Okuyup Ekrana Yazdıran Fonksiyon
    void hesapOzetiGoster() {
        // Dosyayı okuma modunda (ifstream) açıyoruz
        ifstream dosya("hesap_ozeti.txt");
        string satir;

        cout << "\n=== GECMIS ISLEMLER (HESAP OZETI) ===" << endl;

        // Dosya başarıyla açıldı mı kontrol ediyoruz
        if (dosya.is_open()) {
            // Dosyanın sonuna gelene kadar satır satır okuyup ekrana yazdırıyoruz
            while (getline(dosya, satir)) {
                cout << satir << endl;
            }
            dosya.close(); // İşimiz bitince dosyayı kapatıyoruz
        }
        else {
            // Eğer henüz hiç işlem yapılmadıysa dosya oluşmamıştır, bu uyarıyı veririz
            cout << "Henuz yapilmis bir islem kaydi bulunamadi." << endl;
        }
        cout << "=====================================" << endl;
    }
};

int main() {
    Hesap benimHesabim;
    int secim = 0;
    double miktar = 0.0;

    // Çıkış seçeneğini 5 yaptığımız için döngü 5 olana kadar dönecek
    while (secim != 5) {
        cout << "\n=== BANKA HESAP YONETICISI ===" << endl;
        cout << "1. Bakiye Goruntule" << endl;
        cout << "2. Para Yatir" << endl;
        cout << "3. Para Cek" << endl;
        cout << "4. Hesap Ozetini Goruntule" << endl; // Yeni Seçenek
        cout << "5. Cikis" << endl;
        cout << "Seciminiz (1-5): ";
        cin >> secim;

        switch (secim) {
        case 1:
            benimHesabim.bakiyeGoster();
            break;
        case 2:
            cout << "Yatirmak istediginiz miktar: ";
            cin >> miktar;
            benimHesabim.paraYatir(miktar);
            break;
        case 3:
            cout << "Cekmek istediginiz miktar: ";
            cin >> miktar;
            benimHesabim.paraCek(miktar);
            break;
        case 4:
            benimHesabim.hesapOzetiGoster(); // Yeni Fonksiyonu Çağırıyoruz
            break;
        case 5:
            cout << "Sistemden cikiliyor. Iyi gunler dileriz!" << endl;
            break;
        default:
            cout << "Gecersiz secim! Lutfen tekrar deneyin." << endl;
        }
    }

    return 0;
}




Staj defterine yazarken akademik ve mühendislik dilini kullanmak önemlidir.Aşağıdaki taslağı doğrudan defterine(tarihleri ve günleri kendine göre ayarlayarak) yazabilirsin:Konu: C++ ve Nesne Yönelimli Programlama(OOP) ile Güvenli Banka Hesap Yönetim SistemiYapılan Çalışmalar : Bu çalışmada, bankacılık sistemlerinin temelini oluşturan hesap yönetimi ve işlem geçmişi(loglama) mimarisi C++ programlama dili kullanılarak simüle edilmiştir.Proje geliştirilirken Nesne Yönelimli Programlama(OOP) prensipleri ve Dosya Akışları(File I / O) aktif olarak kullanılmıştır.Sınıf Tasarımı ve Kapsülleme(Encapsulation) : Hesap adında bir sınıf(class) oluşturulmuştur.Güvenlik gereği, hesap bakiyesi(bakiye) private erişim belirleyicisi ile dış müdahalelere kapatılmıştır.Bakiyeye erişim ve güncelleme işlemleri yalnızca sınıf içindeki public metodlar(paraYatir, paraCek) aracılığıyla güvenli bir şekilde gerçekleştirilmiştir.Yapıcı Metod(Constructor) : Sınıftan yeni bir nesne türetildiğinde bakiyenin güvenli bir başlangıç değerine(0.0 TL) sahip olması için varsayılan yapıcı metod(default constructor) tanımlanmıştır.Dosya İşlemleri ve İşlem Geçmişi(File I / O) : Yapılan her başarılı para çekme ve para yatırma işlemi, dinamik olarak hesap_ozeti.txt dosyasına ofstream(output file stream) kullanılarak append(ekleme) modunda kaydedilmiştir.Böylece veri kalıcılığı(data persistence) sağlanmıştır.Dosya Okuma ve Raporlama : Kullanıcının geçmiş işlemlerini görebilmesi için ifstream(input file stream) kullanılarak ilgili.txt dosyası satır satır okunmuş ve konsol ekranına yazdırılmıştır.Kullanıcı Arayüzü : while döngüsü ve switch - case yapısıyla dinamik, kullanıcı dostu ve etkileşimli bir konsol menüsü tasarlanmıştır.2.Staj Yöneticilerine Nasıl Sunacaksın ? Yöneticilerine projeyi sunarken sadece "kod yazdım" demek yerine, bir mühendis gibi yaklaşıp hangi problemi nasıl çözdüğünü anlatmalısın.Sunumunu yaparken şu akışı takip edebilirsin : 1.Bağlamı Kur(Ziraat Teknoloji Vurgusu) : 1 - 2 Dakika."Ziraat Teknoloji bünyesinde staj yaparken, bankacılık sistemlerinin en kritik iki unsuru olan güvenlik (veri gizliliği) ve işlem geçmişinin (logların) tutulması konularına odaklanmak istedim. Bu yüzden C++'ın performansını ve OOP gücünü kullanan bir proje tasarladım."2.Mühendislik Kararlarını Anlat : 2 Dakika.Kodu açmadan önce mantığını anlat : "Bakiyeyi doğrudan değiştirilebilir yapmadım (Encapsulation kullandım). Çünkü gerçek hayatta da kimse veri tabanına doğrudan ulaşıp bakiyesini değiştirememeli, mutlaka bir işlem sürecinden (paraYatir/paraCek fonksiyonlarından) geçmeli."3.Canlı Demo Yap : 2 Dakika.Projeyi Visual Studio'da çalıştır. Önce para yatır, sonra para çek. Ardından bilerek yetersiz bakiye uyarısı alacağın bir miktar gir (bu, sisteminin hata yönetimini bildiğini gösterir). En son Hesap Özetini göstererek işlemi tamamla.4.Arka Planı Göster (TXT Dosyası):1 Dakika.Oluşan hesap_ozeti.txt dosyasını açıp göster: "Yaptığımız tüm işlemler arka planda bu dosyaya kalıcı olarak yazıldı. Programı kapatıp açsak bile verilerimiz güvende."Küçük bir sunum tüyosu: Yöneticilerin sana "Peki bu projeyi daha da geliştirmek istesen ne eklerdin?" diye sorabilir. Bu soruya önceden hazırlıklı olmak seni çok profesyonel gösterir. "Birden fazla kullanıcı hesabı ekleyip aralarında havale/EFT yapılmasını sağlayabilirdim" veya "Verileri şifreleyerek (encryption) dosyaya yazabilirdim" gibi yanıtlar verebilirsin.