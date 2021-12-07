//Percobaan-Akses Sensor Suhu LM35 dan LCD I2C
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
float temp;
int tempPin = 0;

void setup() {
  Serial.begin(9600);
  lcd.begin ();
  lcd.setCursor (0,0);
  lcd.print ("Termometer");
  lcd.setCursor (0,1);
  lcd.print ("Canggih");

  delay(1000);
  lcd.clear();
}

void loop() {
   temp = analogRead(tempPin);
   // baca voltase analog dari sensor dan simpan ke variabel suhu
   temp = temp * 0.48828125;
   // ubah volt analog ke suhu yang sama
   Serial.print("TEMPERATURE = ");
   Serial.print(temp); // menampilkan nilai suhu di Serial Monitor
   Serial.print("*Celcius");
   Serial.println();
   
   lcd.setCursor(0,0);
   lcd.print("TEMPERATURE = ");
   lcd.setCursor(1,1);
   lcd.print(temp); // menampilkan nilai suhu di LCD
   lcd.setCursor(7,1);
   lcd.print("*Celcius");
   delay(1000); // memperbarui pembacaan sensor setiap satu detik
}
