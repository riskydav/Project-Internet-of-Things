#include "DHT.h"

#define DHTPIN 2 // definisikan pin yang digunakan utk sensor DHT11

// Tentukan jenis DHT yang digunakan (pilih salah satu)
// Saat ini yang dipilih adalah DHT11
#define DHTTYPE DHT11 // DHT 11 


DHT dht(DHTPIN, DHTTYPE);

#define RELAY_ON 1
#define RELAY_OFF 0
#define RELAY_1  13   // pin yang digunakan yaitu pin 13
#define RELAY_2  7    // pin yang digunakan yaitu pin 7

#include <LiquidCrystal.h>
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);



void setup() {
  Serial.begin(9600); 
  Serial.println("DHT11 test!");
  dht.begin();
  
 // Set pin as output.
  pinMode(RELAY_1, OUTPUT);
  pinMode(RELAY_2, OUTPUT);
   
 // Initialize relay one as off so that on reset it would be off by default
  digitalWrite(RELAY_1, RELAY_OFF);

  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("PRAK ELEKTRE 2");
  lcd.setCursor(3,1);
  lcd.print("PENETAS TELUR");
  delay(1000);
  lcd.clear();

  lcd.setCursor(2,0);
  lcd.print("Di Buat Oleh");
  lcd.setCursor(2,1);
  lcd.print("NAUFAL NR");
  delay(1000);
  lcd.clear();
}

void loop() {
  // Baca humidity dan temperature
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Cek hasil pembacaan, dan tampilkan bila ok
  if (isnan(t) || isnan(h)) {
    Serial.println("Failed to read from DHT");
    return;
  }

  if (t<37.77)// ON
{
  digitalWrite(RELAY_1, RELAY_ON);
}
 else if (t>38.33)//OFF
{
  digitalWrite(RELAY_1, RELAY_OFF);
}

  if (h<50.00)// ON
{
  digitalWrite(RELAY_2, RELAY_ON);
}
 else if (h>60.00)//OFF
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
}
