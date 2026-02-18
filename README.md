so_long - Küçük Bir 2D Oyun Projesi
📝 Proje Hakkında
Bu proje, MiniLibX kütüphanesini kullanarak C dilinde geliştirilmiş temel bir 2D oyun uygulamasıdır. Projenin amacı, pencere yönetimi, grafik işleme, olay (event) yönetimi ve harita okuma gibi oyun geliştirme temellerini kavramaktır.

Oyunda temel amaç, oyuncunun haritadaki tüm nesneleri toplayarak en az hamleyle çıkışa ulaşmasını sağlamaktır.

🛠️ Teknik Özellikler
Grafik Kütüphanesi: Proje, pencereleri yönetmek ve görüntüleri işlemek için 42'nin dahili grafik kütüphanesi olan MiniLibX'i kullanır.

Harita Formatı: Oyun, .ber uzantılı dosyaları okur ve doğrular. Harita duvarlar ('1'), boş alanlar ('0'), toplanabilir eşyalar ('C'), çıkış ('E') ve oyuncu başlangıç pozisyonu ('P') karakterlerinden oluşur.

Doğrulama: Program, haritanın dikdörtgen olup olmadığını, duvarlarla çevrili olduğunu ve tüm öğelere (çıkış ve nesneler) ulaşılabilir bir yol (pathfinding) olduğunu kontrol eder.

🚀 Kullanım
Derleme
Oyunu derlemek için terminalde proje dizinine giderek şu komutu çalıştırın:

Bash

make
Çalıştırma
Derleme tamamlandıktan sonra, maps klasöründeki bir haritayı parametre olarak vererek oyunu başlatabilirsiniz:

Bash

./so_long maps/map.ber
Kontroller
W / Yukarı Ok: Yukarı hareket.

A / Sol Ok: Sola hareket.

S / Aşağı Ok: Aşağı hareket.

D / Sağ Ok: Sağa hareket.

ESC: Oyunu kapatır.

📂 Proje Yapısı
check_map.c: Harita dosyasının kurallara uygunluğunu ve geçerliliğini kontrol eder.

render_utils.c: XPM dokularını ekrana çizen ve görselleri işleyen fonksiyonları içerir.

movement_utils.c: Oyuncunun hareket mantığını ve hamle sayacını yönetir.

textures/: Oyunda kullanılan karakter, duvar, eşya ve çıkış kapısı için .xpm formatındaki görseller.

free_all.c: Program sonlandığında ayrılan tüm belleği (bellek sızıntısı olmaması için) temizler.

📌 Özellikler
Gerçek zamanlı hamle sayısı takibi (Terminal üzerinden).

Gelişmiş hata yönetimi ve bilgilendirme mesajları.

Bellek sızıntısı içermeyen optimize edilmiş yapı.