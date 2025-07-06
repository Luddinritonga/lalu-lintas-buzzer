// Definisi pin
#define ledMerah 2
#define ledKuning 3
#define ledHijau 4
#define buzzer 5
#define trigPin 6
#define echoPin 7

long duration;
int distance;
bool pelanggaran = false;

void setup() {
  pinMode(ledMerah, OUTPUT);
  pinMode(ledKuning, OUTPUT);
  pinMode(ledHijau, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);
}

void loop() {
  // 🔄 Cek sensor setiap loop (untuk halangan umum)
  bacaSensor();

  // 🟢 Lampu Hijau
  digitalWrite(ledHijau, HIGH);
  digitalWrite(ledKuning, LOW);
  digitalWrite(ledMerah, LOW);
  noTone(buzzer); // pastikan buzzer mati
  Serial.println("Lampu Hijau");
  delay(5000);

  // 🟡 Lampu Kuning
  digitalWrite(ledHijau, LOW);
  digitalWrite(ledKuning, HIGH);
  Serial.println("Lampu Kuning");
  delay(2000);

  // 🔴 Lampu Merah
  digitalWrite(ledKuning, LOW);
  digitalWrite(ledMerah, HIGH);
  Serial.println("Lampu Merah");

  pelanggaran = false;

  // Cek pelanggaran selama 10 detik
  for (int i = 0; i < 10; i++) {
    bacaSensor();
    if (distance < 10) {
      pelanggaran = true;
    }
    delay(1000);
  }

  // Bunyikan buzzer jika ada pelanggaran saat lampu merah
  if (pelanggaran) {
    tone(buzzer, 2000); // bunyi 2000 Hz
    Serial.println("🚨 Pelanggaran lampu merah!");
    delay(2000);
    noTone(buzzer);
  }

  digitalWrite(ledMerah, LOW);
}

// 🔎 Fungsi untuk membaca jarak dari sensor
void bacaSensor() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.println(" cm");

  // 🛑 Jika ada halangan kapan saja → buzzer langsung bunyi
  if (distance < 30) {
    tone(buzzer, 1500);         // nada 1500 Hz
    Serial.println("🚧 Halangan terdeteksi - buzzer aktif");
    delay(500);
    noTone(buzzer);
  }
}
