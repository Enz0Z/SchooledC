bool state = false;
bool fast = false;

bool readed = HIGH;
bool last = HIGH;

void setup() {
  Serial.begin(9600);
  pinMode(7, OUTPUT);
  pinMode(6, INPUT_PULLUP);
  pinMode(9, INPUT);
  digitalWrite(7, LOW);
}

void loop() {
  readed = digitalRead(6);
  if (readed == LOW && last == HIGH) {
    state = !state;
    if (state == false) {
      digitalWrite(7, LOW);
    }
  }
  last = readed;
  
  if (state == true) {
    Serial.print("Actual ");
    Serial.print(state);
    Serial.println(" ");
    if (fast == true) {
      digitalWrite(7, !digitalRead(7));
      delay(250);
    } else {
      digitalWrite(7, !digitalRead(7));
      delay(500);
    }
  }
}
