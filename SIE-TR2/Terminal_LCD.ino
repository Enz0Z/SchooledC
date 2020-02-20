#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Inicializando...");
  delay(1000);
  lcd.clear();
}

void loop() {
  if (Serial.available()) {
    lcd.clear();
    while (Serial.available() > 0) {
      String string = Serial.readString();
      if (string.equals("p")) {
          lcd.setCursor(0, 0);
          lcd.print(analogRead(0));
          lcd.print("");
      } else if (string.equals("b")) {
          lcd.setCursor(0, 0);
          lcd.write(digitalRead(8) ? "HIGH" : "LOW");
          lcd.setCursor(0, 1);
          lcd.write(digitalRead(9) ? "HIGH" : "LOW");
      } else if (string.equals("l")) {
          digitalWrite(13, !digitalRead(13));
      } else {
          lcd.print(string);
          lcd.print("");
      }
    }
  }
}
