void setup() {
  analogWrite(9, 100);
}

void loop() {
  analogWrite(11, analogRead(A5) / 4);
  analogWrite(10, analogRead(A5) / 4);
}
