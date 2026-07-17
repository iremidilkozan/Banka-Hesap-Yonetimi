# C++ Bank Account Manager (Banka Hesap Yöneticisi)

Bu proje, **Ziraat Teknoloji** stajım kapsamında C++ programlama dili ve Nesne Yönelimli Programlama (OOP) prensipleri kullanılarak geliştirilmiş güvenli bir banka hesap yönetim simülasyonudur. 

Proje, temel bankacılık işlemlerini (bakiye görüntüleme, para yatırma, para çekme) dinamik bir konsol menüsü üzerinden sunarken, yapılan tüm işlemleri arka planda kalıcı bir log dosyasına kaydeder ve gerektiğinde bu geçmişi kullanıcıya raporlar.

---

## 🚀 Öne Çıkan Özellikler

- **Güvenli Hesap Yönetimi:** Kapsülleme (Encapsulation) sayesinde hesap bakiyesi dış müdahalelere karşı korunur.
- **Dinamik ve Etkileşimli Menü:** Kullanıcı dostu, sürekli açık kalan ve yönlendirmeli konsol arayüzü.
- **İşlem Geçmişi (Loglama):** Başarılı her para çekme ve yatırma işlemi anında tarihsel veri olarak `hesap_ozeti.txt` dosyasına yazılır (File I/O).
- **Hesap Özeti Raporlama:** Kullanıcı istediği an program içinden tüm geçmiş işlemlerini dosyadan okuyarak listeleyebilir.

---

## 🛠️ Kullanılan Teknolojiler ve Yaklaşımlar

- **Dil:** C++ (C++11 ve üzeri)
- **Nesne Yönelimli Programlama (OOP):**
  - **Encapsulation (Kapsülleme):** `bakiye` değişkeni `private` erişim belirleyicisi ile gizlenmiş; veri manipülasyonu `public` metodlar (`paraYatir`, `paraCek`) üzerinden sınırlandırılmıştır.
  - **Constructor (Yapıcı Metod):** Sınıf örneklendiğinde nesnenin güvenli bir başlangıç durumunda (`0.0 TL`) olması garanti edilmiştir.
- **Dosya Akışları (File I/O):**
  - `ofstream` (Output File Stream) ile veri kalıcılığı (data persistence) append modunda sağlanmıştır.
  - `ifstream` (Input File Stream) ile dosya tabanlı log verileri satır satır okunmuştur.

---

## 💻 Kurulum ve Çalıştırma

Projeyi yerel bilgisayarınızda çalıştırmak için aşağıdaki adımları takip edebilirsiniz:

### Gereksinimler
- Herhangi bir C++ derleyicisi (GCC, Clang veya MSVC) veya entegre geliştirme ortamı (Visual Studio önerilir).

### Visual Studio ile Çalıştırma
1. Bu depoyu (repository) bilgisayarınıza indirin veya klonlayın:
   ```bash
   git clone [https://github.com/](https://github.com/)iremidilkozan/Banka-Hesap-Yonetimi.git
