// Control de motores en L298
// Pines enable deben estar en positivo en el L298
class Controller298 {
  private:
    bool state = false;
    int vel = 0;
    int right_1 = 3;
    int right_2 = 5;
    int left_1 = 6;
    int left_2 = 9;

  public:
    bool getState() {
      Serial.println(state);
      return state;
    }
    
    void setOutputPins(int r1, int r2, int l1, int l2) {
      right_1 = r1;
      right_2 = r2;
      left_1 = l1;
      left_2 = l2;
    }
    
    void setState(bool s) {
      state = s;
      if (s == false) {
        analogWrite(right_1, 0);
        analogWrite(right_2, 0);
        analogWrite(left_1, 0);
        analogWrite(left_2, 0);
      }
    }
    
    void setVel(int v) {
      vel = v/4;
      //Serial.println(vel);
    }
  
    void Forward() {
      if (state == false) return;
      analogWrite(right_1, vel);
      analogWrite(right_2, 0);
      analogWrite(left_1, vel);
      analogWrite(left_2, 0);
    }
    
    void Backward() {
      if (state == false) return;
      analogWrite(right_1, 0);
      analogWrite(right_2, vel);
      analogWrite(left_1, 0);
      analogWrite(left_2, vel);
    }
    
    void Left() {
      if (state == false) return;
      analogWrite(right_1, 0);
      analogWrite(right_2, 0);
      analogWrite(left_1, vel);
      analogWrite(left_2, 0);
    }
    
    void Right() {
      if (state == false) return;
      analogWrite(right_1, vel);
      analogWrite(right_2, 0);
      analogWrite(left_1, 0);
      analogWrite(left_2, 0);
    }
};

bool readedState = HIGH;
bool lastState = HIGH;

bool readedSentido = HIGH;
bool lastSentido = HIGH;

bool sentido = false;
Controller298 control;

void setup() {
  Serial.begin(9600);
  pinMode(12, INPUT);
  pinMode(11, INPUT);
  pinMode(9, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(3, OUTPUT);

  control.setState(false);
}

void loop() {
  readedState = digitalRead(12);
  if (readedState == LOW && lastState == HIGH) {
    control.setState(!control.getState());
  }
  lastState = readedState;

  readedSentido = digitalRead(11);
  if (readedSentido == LOW && lastSentido == HIGH) {
    sentido = !sentido;
  }
  lastSentido = readedSentido;

  if (sentido == false) {
      control.Forward();
  } else {
    control.Backward();
  }
  control.setVel(analogRead(A0));
}


  
