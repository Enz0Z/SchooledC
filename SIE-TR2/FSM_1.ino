typedef enum {
  STATE_INIT = 0,
  STATE_ON,
  STATE_OFF,
  NUMBER_OF_STATES
} state_t;

typedef enum {
  EVENT_INIT = 0,
  EVENT_BUTTON_PUSHED
} event_t;

typedef struct {
  event_t transitionEvent;
  state_t nextState;
  int timeout;
  void (*stateFunction)(void);
} stateTable_t;

static volatile state_t currentState;

void stateMachine();
void setON();
void setOFF();
void startTimer(int tiempo);

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  stateMachine(EVENT_INIT);
}

void loop() {
  if ((char) Serial.read() == '1') {
    stateMachine(EVENT_BUTTON_PUSHED);
  }
}

static stateTable_t stateTable[NUMBER_OF_STATES] = {
  {EVENT_INIT,            STATE_ON,      500, setOFF},
  {EVENT_BUTTON_PUSHED,   STATE_OFF,     500, setON},
  {EVENT_BUTTON_PUSHED,   STATE_ON,      500, setOFF},
};

static void stateMachine(event_t event) {
  if (stateTable[currentState].transitionEvent == event) {
    currentState = stateTable[currentState].nextState;
  }
  if (stateTable[currentState].stateFunction != NULL)
    stateTable[currentState].stateFunction();
}

void setON() {
  delay(stateTable[currentState].timeout);
  digitalWrite(13, HIGH);
}

void setOFF() {
  delay(stateTable[currentState].timeout);
  digitalWrite(13, LOW);
}
