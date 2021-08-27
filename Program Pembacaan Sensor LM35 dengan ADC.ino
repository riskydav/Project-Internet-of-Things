// Program Pembacaan Sensor LM35 dengan ADC 
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#define sensorsuhu A0
void setup()
{
  lcd.begin (16, 2);
}
void loop()
{
  int vref = 5;
  int adc = analogRead (sensorsuhu);
  float mv = (adc / 1024.0) * (vref * 1000);
  float cel = mv / 10;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp:");
  lcd.print(cel);
  lcd.print(char(223));
  lcd.print("C");
  lcd.setCursor(0, 1);
  lcd.print("ADC:");
  lcd.print(adc);
  lcd.setCursor(7, 1);
  lcd.print("mV:");
  lcd.print(mv);
  delay(500);
}
