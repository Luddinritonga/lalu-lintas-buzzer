# 🚦 Simulasi Lampu Lalu Lintas dengan Deteksi Pelanggaran 🚨

Proyek ini adalah sistem simulasi **lampu lalu lintas otomatis berbasis Arduino** yang dilengkapi dengan:

- 🚗 **Deteksi pelanggaran lampu merah**
- 📏 **Sensor ultrasonik** untuk mendeteksi kendaraan
- 🔊 **Alarm buzzer** jika terjadi pelanggaran
- 💡 Tiga lampu indikator: **Merah**, **Kuning**, **Hijau**

Sistem ini cocok untuk edukasi, pameran proyek, maupun pengembangan sistem kontrol lalu lintas skala kecil.

---

## 🎯 Fitur Utama

- ✅ Siklus otomatis lampu hijau, kuning, merah
- ✅ Deteksi kendaraan menggunakan sensor HC-SR04
- ✅ Buzzer aktif saat kendaraan melanggar lampu merah
- ✅ Serial Monitor untuk debug dan informasi jarak
- ✅ Deteksi halangan umum kapan saja dengan notifikasi buzzer singkat

---

## 🧰 Komponen yang Digunakan

| Komponen               | Jumlah | Fungsi                                   |
|------------------------|--------|------------------------------------------|
| Arduino Uno / Nano     | 1      | Mikrokontroler utama                     |
| LED Merah (🔴)          | 1      | Indikator lampu merah (D2)               |
| LED Kuning (🟡)         | 1      | Indikator lampu kuning (D3)              |
| LED Hijau (🟢)          | 1      | Indikator lampu hijau (D4)               |
| Buzzer                 | 1      | Alarm pelanggaran (D5)                   |
| Sensor Ultrasonik HC-SR04 | 1   | Deteksi kendaraan (Trig: D6, Echo: D7)   |
| Breadboard & jumper    | -      | Rangkaian prototipe                      |

---

## 🔌 Wiring (Skema Pin)

| Komponen       | Pin Arduino |
|----------------|-------------|
| LED Merah      | D2          |
| LED Kuning     | D3          |
| LED Hijau      | D4          |
| Buzzer         | D5          |
| Ultrasonik Trig| D6          |
| Ultrasonik Echo| D7          |
| Power (VCC)    | 5V          |
| Ground (GND)   | GND         |

> Anda dapat melihat wiring diagram visual<br>
![skema lalu lintas buzzer](https://github.com/Luddinritonga/lalu-lintas-buzzer/blob/main/skema%20lalu%20lintas%20buzzer.png)

---

## 💻 Cara Kerja Program

### Siklus Lampu:
1. 🟢 **Hijau** → 5 detik
2. 🟡 **Kuning** → 2 detik
3. 🔴 **Merah** → 10 detik + deteksi pelanggaran

### Deteksi Pelanggaran:
- Jika kendaraan berada **< 10cm** saat lampu merah → buzzer berbunyi 2 detik
- Selama siklus merah (10 detik), sensor aktif setiap 1 detik

### Deteksi Halangan Umum:
- Kapan saja jika jarak **< 30 cm** → buzzer berbunyi singkat (peringatan)

---

## ▶️ Cara Menggunakan

1. Hubungkan semua komponen sesuai pin.
2. Upload kode ke Arduino melalui Arduino IDE.
3. Buka Serial Monitor untuk melihat output jarak dan status.
4. Amati LED dan buzzer bekerja secara otomatis sesuai alur lalu lintas.

---
## 📦 Library yang Digunakan

Library bawaan Arduino:
- `Arduino.h`
- `Serial`
- Tidak perlu install library eksternal

---
## 🧠 Pengembangan Lanjutan (Opsional)

- Tambahkan **LCD I2C** untuk status visual
- Simpan data pelanggaran ke SD Card / EEPROM
- Tambahkan kamera / modul ESP32 untuk upload online
- Gunakan traffic light asli untuk proyek outdoor

---
## Author<br>
**Luddin ritonga**  <br>
[![Website](https://img.shields.io/badge/Website-000000?style=for-the-badge&logo=about-dot-me&logoColor=white)](https://yourwebsite.com)
[![Email](https://img.shields.io/badge/Email-D14836?style=for-the-badge&logo=gmail&logoColor=white)](mailto:luddinritonga03email.com)
[![GitHub](https://img.shields.io/badge/GitHub-181717?style=for-the-badge&logo=github&logoColor=white)](https://github.com/luddinritonga)
[![YouTube](https://img.shields.io/badge/YouTube-FF0000?style=for-the-badge&logo=youtube&logoColor=white)](https://youtube.com/@nama_channel_anda)
[![LinkedIn](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white)](https://linkedin.com/in/username)
[![Instagram](https://img.shields.io/badge/Instagram-E4405F?style=for-the-badge&logo=instagram&logoColor=white)](https://instagram.com/username)
[![Facebook](https://img.shields.io/badge/Facebook-1877F2?style=for-the-badge&logo=facebook&logoColor=white)](https://facebook.com/username)
[![Twitter/X](https://img.shields.io/badge/Twitter-000000?style=for-the-badge&logo=x&logoColor=white)](https://twitter.com/username)
[![Telegram](https://img.shields.io/badge/Telegram-0088cc?style=for-the-badge&logo=telegram&logoColor=white)](https://t.me/yourusername)


## 📄 Lisensi

Proyek ini dilisensikan di bawah [MIT License](LICENSE)  
Anda bebas menggunakan, memodifikasi, dan mendistribusikan dengan mencantumkan atribusi.

