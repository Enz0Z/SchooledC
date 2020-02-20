#include <LiquidCrystal.h>
#define tam 18
//                 Rs  En  d4 d5 d6 d7
LiquidCrystal lcd (12, 11, 5, 4, 3, 2); 

typedef enum {
  STATE_INIT = 0,
  STATE_CHECKING,
  STATE_WAITING,
  NUMBER_OF_STATES
} state_t;

typedef enum {
  EVENT_INIT = 0,
  EVENT
} event_t;

typedef struct {
  event_t transitionEvent;
  state_t nextState;
  void (*stateFunction)(void);
} stateTable_t;

static volatile state_t currentState;

void stateMachine();
void setWAIT();
void setMOVE();
boolean r(int pin);

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(10, INPUT);
  pinMode(9, INPUT);
  pinMode(8, INPUT);
  pinMode(7, INPUT);
  lcd.begin(16,2);
}

void loop() {
  stateMachine(EVENT_INIT);
  while(1) {
    stateMachine(EVENT);
  }
}

static stateTable_t stateTable[NUMBER_OF_STATES] = {
  {EVENT_INIT, STATE_CHECKING, setWAIT},
  {EVENT, STATE_WAITING, setMOVE},
  {EVENT, STATE_CHECKING, setWAIT}
};

static void stateMachine(event_t event) {
  if (stateTable[currentState].transitionEvent == event) {
    currentState = stateTable[currentState].nextState;
  }
  if (stateTable[currentState].stateFunction != NULL)
    stateTable[currentState].stateFunction();
}

void setWAIT() {
  delay(100);
  lcd.setCursor(0, 0);
  lcd.print("WAITING");
  //Serial.println("WAITING");
}

void setMOVE() {
  lcd.setCursor(0, 0);
  if (r(10) == false && r(9) == true && r(8) == true && r(7) == false) {
    Serial.println("FORWARD");
    lcd.print("FORWARD");

  } else if (r(10) == true && r(9) == true && r(8) == true && r(7) == true) {
    Serial.println("SEARCHING LINE");
    
  } else if (r(10) == false && r(9) == true && r(8) == true && r(7) == true) {
    Serial.println("RIGHT x2");
    lcd.print("RIGHT");
  } else if (r(10) == false && r(9) == false && r(8) == true && r(7) == true) {
    Serial.println("RIGHT x4");
    lcd.print("RIGHT");
  } else if (r(10) == false && r(9) == false && r(8) == false && r(7) == true) {
    Serial.println("RIGHT x6");
    lcd.print("RIGHT");

    
  } else if (r(10) == true && r(9) == true && r(8) == true && r(7) == false) {
    Serial.println("LEFT x2");
    lcd.print("LEFT");
  } else if (r(10) == true && r(9) == true && r(8) == false && r(7) == false) {
    Serial.println("LEFT x4");
    lcd.print("LEFT");
  } else if (r(10) == true && r(9) == false && r(8) == false && r(7) == false) {
    Serial.println("LEFT x6");
    lcd.print("LEFT");

    
  } else {
    Serial.println("STOPPED");
    lcd.print("STOPPED");
  }
}

boolean r(int pin) {
  return digitalRead(pin); 
}

