#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

const byte ROWS = 4; 
const byte COLS = 4; 

char Keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {2, 3, 4, 5}; 
byte colPins[COLS] = {6, 7, 8, 9}; 

Keypad customKeypad = Keypad( makeKeymap(Keys), rowPins, colPins, ROWS, COLS); 

#define LED 13
char customKey;
int number = 0;
int password = 1379;

void setup() {
  lcd.init ();
  lcd.setBacklight(HIGH);
  pinMode(LED, OUTPUT);
}

void loop() {
  lcd.setCursor(0,0);
  lcd.print("Input Password");
  
  customKey = customKeypad.getKey();

  switch(customKey){
    case '0' ... '9':
      lcd.setCursor(0,1);
      number = number * 10 + (customKey - '0');
      lcd.print(number);
    break;

    case '#':
      if(number == password){
        lcd.setCursor(0,1);
        lcd.print("Access Accepted ");
        digitalWrite(LED, HIGH);
        delay(2000);
        digitalWrite(LED, LOW);
        number = 0;
        lcd.clear(); 
      }
      else{
        lcd.setCursor(0,1);
        lcd.print("Invalid Password");
        delay(2000);
        number = 0;
        lcd.clear();
      }
    break;

    case '*':
      number = 0;
      lcd.clear();
    break;
  }
}
