// PROGRAM TRAFFIC LIGHT 
// RISKY DAVID KASYANTO (19201038)
// D3TT07A

int m1= 3; int m2= 6; int m3= 9; // m = merah
int k1= 4; int k2= 7; int k3= 10; // k = kuning
int h1= 5; int h2= 8; int h3= 11; // h = hijau

void setup()
{
  pinMode(m1,OUTPUT);
  pinMode(k1,OUTPUT);
  pinMode(h1,OUTPUT);
  pinMode(m2,OUTPUT);
  pinMode(k2,OUTPUT);
  pinMode(h2,OUTPUT);
  pinMode(m3,OUTPUT);
  pinMode(k3,OUTPUT);
  pinMode(h3,OUTPUT);
} 

void loop()
{
  //Traffic Light 1
   digitalWrite(h1,HIGH);
   digitalWrite(k1,LOW);
   digitalWrite(m1,LOW);
   delay(2000); // Lampu Hijau (X + 2) = (0 + 2) = 2 s
   digitalWrite(h1,LOW);
   digitalWrite(k1,HIGH);
   digitalWrite(m1,LOW);
   delay(1000); // Lampu Kuning 1 s
   digitalWrite(h1,LOW);
   digitalWrite(k1,LOW);
   digitalWrite(m1,HIGH);
   delay(1000); // Lampu Merah 1 s
  
  //Traffic Light 2
   digitalWrite(h2,HIGH);
   digitalWrite(k2,LOW);
   digitalWrite(m2,LOW);
   delay(5000); // Lampu Hijau (Y + 2) = (3 + 2) = 5 s
   digitalWrite(h2,LOW);
   digitalWrite(k2,HIGH);
   digitalWrite(m2,LOW);
   delay(1000); // Lampu Kuning 1 s
   digitalWrite(h2,LOW);
   digitalWrite(k2,LOW);
   digitalWrite(m2,HIGH);
   delay(1000); // Lampu Merah 1 s

  //Traffic Light 3
   digitalWrite(h3,HIGH);
   digitalWrite(k3,LOW);
   digitalWrite(m3,LOW);
   delay(10000); // Lampu Hijau (Z + 2) = (8 + 2) = 10 s
   digitalWrite(h3,LOW);
   digitalWrite(k3,HIGH);
   digitalWrite(m3,LOW);
   delay(1000); // Lampu Kuning 1 s
   digitalWrite(h3,LOW);
   digitalWrite(k3,LOW);
   digitalWrite(m3,HIGH);
   delay(1000); // Lampu Merah 1 s
}
