// PROGRAM ALARM KEBAKARAN
/*
 * Created by Risky David Kasyanto
 *
 * Sample project code is on my GitHub : https://github.com/riskydav
 *
 * Follow my LinkedIn account : https://www.linkedin.com/in/risky-david-kasyanto/
 */

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
float MQ2;
float sensorApi;
int adc;
byte kedip;
byte keluar;
const int relay = 8;

void setup(){
  pinMode(relay, OUTPUT);
  pinMode(1,OUTPUT);
  digitalWrite(1,LOW);
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
  lcd.init();
  lcd.backlight();
  lcd.print("Alarm Kebakaran");
  delay(2000);
  lcd.clear();
  lcd.print(" Tunggu Sensor");
  lcd.setCursor(0, 1);
  lcd.print(" Siap...");
  delay(2000);
  do{
   adc=(analogRead(A0));
   MQ2 = adc * (5.0 / 1023.0);
  }
  while(MQ2 > 1.5);
    lcd.clear();
}

void loop(){
  adc=(analogRead(A0));
  MQ2 = adc * (5.0 / 1023.0);
  adc=(analogRead(A1));
  sensorApi = adc * (5.0 / 1023.0);
  lcd.setCursor(0,0);
  lcd.print("Api :");
  lcd.print(sensorApi);
  lcd.print(" ");
  lcd.setCursor(0,1);
  lcd.print("Asap:");
  lcd.print(MQ2);
  lcd.print(" ");
  
  if (MQ2 > 1 || sensorApi<3){
    lcd.setCursor(0,0);
    lcd.print("Ada Kebakaran");
    digitalWrite(relay, HIGH);
    digitalWrite(1,HIGH);
    digitalWrite(13,HIGH);
    delay(1000);
  }
  do{
    adc=(analogRead(A0));
    MQ2 = adc * (5.0 / 1023.0);
    adc=(analogRead(A1));
    sensorApi = adc * (5.0 / 1023.0);
    if(sensorApi>4 && MQ2<1)keluar=0;
    digitalWrite(relay, LOW);
    }
  while(keluar);
    digitalWrite(1,LOW);
    digitalWrite(13,LOW);
    digitalWrite(relay, LOW);
    lcd.clear();
    
delay(100);
}
