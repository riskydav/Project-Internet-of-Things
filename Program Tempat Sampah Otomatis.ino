#include <HCSR04.h>
#include <Servo.h>

HCSR04 hc(5,6);//initialisation class HCSR04 (trig pin , echo pin)
Servo myservo;

int jarak = 0;
bool buka = true;

void setup() {
  myservo.attach(10);
}

void loop() {
  jarak = hc.dist();
  if(jarak <= 10){
    if(buka == true){
      for(int i = 90; i>=0; i--){
        myservo.write(i); 
        delay(15);
      }
    }
    delay(200);
    buka = false;
  }
  else{
    buka = true;
    myservo.write(90);
    delay(1000);
  }
}
