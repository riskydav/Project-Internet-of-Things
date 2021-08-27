// PROGRAM RUNNING TEXT
// RISKY DAVID KASYANTO (19201038)
// D3TT07A
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup()
{
  lcd.begin(16,2);
}
void loop()
{
  int i;
  lcd.setCursor(0, 0);
  lcd.print("Nama : Risky David Kasyanto");
  lcd.setCursor(0, 1);
  lcd.print("NIM  : 19201038");
  for (;;)
  {
  lcd.scrollDisplayLeft();
  delay(1000);
  }
}
