#include <OneWire.h>                //Library komunikasi one wire
#include <DallasTemperature.h>      //Library DS18B20
#define ONE_WIRE_BUS 2              //Inisialisasi pin komunikasi di D2
#define sensor 2                    //Inisialisasi sensor di D2
OneWire oneWire(ONE_WIRE_BUS);      //Mengenalkan pin komunikasi
DallasTemperature Suhu(&oneWire);   //Memasukkan pin sensor

#define Buzzer 8                    //Inisialisasi buzzer pada pin D8
float t;                            //Membuat variabel t (suhu)

void setup() {
  Serial.begin(9600);               //Mulai komunikasi serial
  Suhu.begin();                     //Mulai komunikasi sensor
  pinMode(Buzzer, OUTPUT);          //Setting buzzer sebagai output
}

void loop() {
  Suhu.requestTemperatures();       //Baca suhu
  t =  Suhu.getTempCByIndex(0);     //Masukkan hasil pembacaan ke variabel t
  Serial.print("Suhu : ");          //Tampilkan text
  Serial.println(t);                //Tampilkan suhu
  
  if(t > 35) {                      //Jika suhu > 35 *C
    for(int i = 0; i < 5; i++){     //Ulang prosedur alarm(); sebanyak 5 kali
      alarm();
    }
  }
  else {                           
    delay(1000);                    //Jeda 1000 ms
  }
}

void alarm(){                         //Prosedur alarm
  digitalWrite(Buzzer, HIGH);         //Nyalakan buzzer
  delay(500);                         //Selama 500 ms
  digitalWrite(Buzzer, LOW);          //Matikan buzzer
  delay(500);                         //Selama 500 ms
}
