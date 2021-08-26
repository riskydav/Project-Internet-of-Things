#include "DHT.h" // Library DHT
#define DHTPIN 2 // deklarasi pin yang digunakan untuk sensor DHT11
#define DHTTYPE DHT11 // definisi tipe DHT yang digunakan
DHT dht(DHTPIN, DHTTYPE); // deklarasi untuk mengenalkan pin DHT dan tipe DHT yang digunakan 
#include <Servo.h> // Library Servo
Servo motorServo; // membuat variabel servo untuk dikendalikan
#define RELAY_ON 1 
#define RELAY_OFF 0 
#define RELAY_1  13   
#define RELAY_2  7   
#include <LiquidCrystal.h> //Library LCD
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5); 

void setup() {
  Serial.begin(9600); 
  Serial.println("DHT11 test!"); 
  dht.begin();
  
 // Set pin keluaran.
  pinMode(RELAY_1, OUTPUT);
  pinMode(RELAY_2, OUTPUT);
   
 // Inisialisasi relay satu mati sehingga saat reset akan mati secara default.
  digitalWrite(RELAY_1, RELAY_OFF);

  lcd.begin(16, 2); 
  lcd.setCursor(0,0); 
  lcd.print("SISTEM"); 
  lcd.setCursor(1,1); 
  lcd.print("INKUBATOR TELUR"); 
  delay(2000); 
  lcd.clear(); 
    
 // Set pin keluaran.
  motorServo.attach(8); // servo Pada Pin digital 8 
}

void loop() {
  // Baca humidity (kelembaban) dan temperature (suhu)
  float h = dht.readHumidity(); // pembaca Humidity/Kelembaban
  float t = dht.readTemperature(); // pembaca Temperatur/Suhu

  // Cek hasil pembacaan, dan tampilkan bila ok
  if (isnan(t) || isnan(h)) // isnan adalah type data yang digunakan oleh dht
  {
    Serial.println("Failed to read from DHT"); 
    return;
  }

  if (t<37.77) // inisialisasi jika suhu kurang dari 37.77 Relay 1 akan ON
{
  digitalWrite(RELAY_1, RELAY_ON);
}
 else if (t>38.33) // inisialisasi jika suhu lebih dari 38.33 Relay 1 akan OFF
{
  digitalWrite(RELAY_1, RELAY_OFF);
}

  if (h<50.00) // inisialisasi jika kelembaban kurang dari 50 Relay 2 akan ON
{
  digitalWrite(RELAY_2, RELAY_ON);
}
 else if (h>60.00) // inisialisasi jika kelembaban lebih dari 60 Relay 2 akan OFF
{
  digitalWrite(RELAY_2, RELAY_OFF);
}
    
    Serial.print("Humidity: ");
    Serial.print(h);
    Serial.print(" %t");
    
    Serial.print("Temperature: "); 
    Serial.print(t);
    Serial.println(" *C");

  lcd.setCursor(0,0);
  lcd.print("Humi: "); 
  lcd.print(h);
  lcd.print(" %      ");
  lcd.setCursor(0,1);
  lcd.print("Temp: "); 
  lcd.print(t);
  lcd.print(" C      ");
        
   motorServo.write(180);  // Memutar Servo ke kiri 180 derajat
   delay(5000);   
   motorServo.write(0);   // Memutar Servo ke kanan kembali ke 0 derajat
   delay(5000);
   
}
