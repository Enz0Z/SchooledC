#include <LiquidCrystal.h>
#define tam 18
//                 Rs  En  d4 d5 d6 d7
LiquidCrystal lcd (12, 11, 5, 4, 3, 2); 

typedef enum {
  STATE_INIT = 0,
  STATE_COUNT_1,
  STATE_COUNT_2,
  NUMBER_OF_STATES
} state_t;

typedef enum {
  EVENT_INIT = 0,
  EVENT_COUNT
} event_t;

typedef struct {
  event_t transitionEvent;
  state_t nextState;
  int timeout;
  void (*stateFunction)(void);
} stateTable_t;

static volatile state_t currentState;
int count = 0;
boolean twopoints = true;
int hs = 0;
int ms = 0;
int ss = 0;

void stateMachine();
void setCOUNT1();
void setCOUNT2();
void startTimer(int tiempo);

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  lcd.begin(16,2);
}

void loop() {
  stateMachine(EVENT_INIT);
  while(1) {
    stateMachine(EVENT_COUNT);
  }
}

static stateTable_t stateTable[NUMBER_OF_STATES] = {
  {EVENT_INIT,          STATE_COUNT_1,          500, setCOUNT2},
  {EVENT_COUNT,         STATE_COUNT_2,          500, setCOUNT1},
  {EVENT_COUNT,         STATE_COUNT_1,          500, setCOUNT2}
};

static void stateMachine(event_t event) {
  if (stateTable[currentState].transitionEvent == event) {
    currentState = stateTable[currentState].nextState;
  }
  if (stateTable[currentState].stateFunction != NULL)
    stateTable[currentState].stateFunction();
}

void setCOUNT1() {
  delay(stateTable[currentState].timeout);
  //digitalWrite(13, HIGH);
  secondsToClock();
  lcd.setCursor(0, 0);
  if (twopoints) {
    lcd.print(hs);
    lcd.print(":");
    lcd.print(ms);
    lcd.print(":");
    lcd.print(ss);
  } else {
    lcd.print(hs);
    lcd.print(" ");
    lcd.print(ms);
    lcd.print(" ");
    lcd.print(ss);
  }
  count++;
  //twopoints = !twopoints;
}

void setCOUNT2() {
  delay(stateTable[currentState].timeout);
  //digitalWrite(13, LOW);
  twopoints = !twopoints;
}

void secondsToClock() {
  int t = count;
  ss = t % 60;
  t = (t - ss)/60;
  ms = t % 60;
  t = (t - ms)/60;
  hs = t;
}

