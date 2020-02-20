typedef enum {
  STATE_INIT = 0,
  STATE_GO,
  STATE_STANDBY,
  NUMBER_OF_STATES
} state_t;

typedef enum {
  EVENT_INIT = 0,
  EVENT_BUTTON_PUSHED,
  EVENT_BUTTON_PUSHED_2
} event_t;

typedef struct {
  event_t transitionEvent;
  state_t nextState;
  int timeout;
  void (*stateFunction)(void);
} stateTable_t;

static volatile state_t currentState;

void stateMachine();
void setGO();
void setSTANDBY();
void startTimer(int tiempo);

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  stateMachine(EVENT_INIT);
  while(1) {
    if ((char) Serial.read() == '1') {
      stateMachine(EVENT_BUTTON_PUSHED);
    }
    if((char) Serial.read() == '2'){
      stateMachine(EVENT_BUTTON_PUSHED_2);
    }
  }
}

static stateTable_t stateTable[NUMBER_OF_STATES] = {
  {EVENT_INIT,            STATE_GO,          500, setSTANDBY},
  {EVENT_BUTTON_PUSHED_2,   STATE_STANDBY,     500, setGO},
  {EVENT_BUTTON_PUSHED,   STATE_GO,          500, setSTANDBY},
};

static void stateMachine(event_t event) {
  if (stateTable[currentState].transitionEvent == event) {
    currentState = stateTable[currentState].nextState;
  }
  if (stateTable[currentState].stateFunction != NULL)
    stateTable[currentState].stateFunction();
}

void setGO() {
  delay(stateTable[currentState].timeout);
  digitalWrite(13, HIGH);
}

void setSTANDBY() {
  delay(stateTable[currentState].timeout);
  digitalWrite(13, LOW);
}
