const int mqxPin = A0;  // pin A0 MQ2 dikoneksikan ke pin analog A0 Arduino
int redLed = 12;  // LED dihubungkan dengan pin 12 Arduino
int buzzer = 10;  // Buzzer dihubungkan dengan pin 10 Arduino 
int sensorThres = 400; // Tegangan threshold Sensor yg kita inginkan

void setup()
{
    pinMode(mqxPin, INPUT);
    pinMode(redLed, OUTPUT);
    pinMode(buzzer, OUTPUT);
    Serial.begin(9600); // Inisialisasi Serial Monitor pd Baudrate = 9600 
}

void loop()
{
    int analogSensor = analogRead(mqxPin);
    Serial.print("Output MQ-2 : ");
    Serial.println(analogSensor);
// Cek apakah lebih besar dari tegangan threshold 
   if (analogSensor > sensorThres)
   {
     digitalWrite(redLed, HIGH);
     tone(buzzer, 1000, 200);
   }
   else
   {
     digitalWrite(redLed, LOW);
     noTone(buzzer);
   }
   delay(1000);  // Jeda Waktu 1 detik u/ pembacaan berikutnya
}
