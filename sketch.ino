const int GREEN_LED   = 5;
const int YELLOW_LED  = 6;
const int RED_LED     = 7;
const int BUZZER      = 8;

const int HIGH_SENSOR = 2;   // Green level
const int MED_SENSOR  = 3;   // Yellow level
const int LOW_SENSOR  = 4;   // Red level

int lastPressed = 0;          // 0=none, 1=green, 2=yellow, 3=red
bool redRemainsOn = false;    // Red LED stays on once triggered

void setup() {
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  pinMode(HIGH_SENSOR, INPUT);
  pinMode(MED_SENSOR, INPUT);
  pinMode(LOW_SENSOR, INPUT);

  // Start with all outputs off
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(RED_LED, LOW);
  noTone(BUZZER);
}

void loop() {
  int highVal = digitalRead(HIGH_SENSOR);
  int medVal  = digitalRead(MED_SENSOR);
  int lowVal  = digitalRead(LOW_SENSOR);

  // --- GREEN: 2 quick high-pitch beeps ---
  if (highVal == HIGH) {
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, LOW);
    redRemainsOn = false;

    if (lastPressed != 1) {
      tone(BUZZER, 1000);
      delay(150);
      noTone(BUZZER);
      delay(80);
      tone(BUZZER, 1000);
      delay(150);
      noTone(BUZZER);

      lastPressed = 1;
    }
  }
  // --- YELLOW: 2 medium beeps ---
  else if (medVal == HIGH) {
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, LOW);
    redRemainsOn = false;

    if (lastPressed != 2) {
      tone(BUZZER, 700);
      delay(150);
      noTone(BUZZER);
      delay(80);
      tone(BUZZER, 700);
      delay(150);
      noTone(BUZZER);

      lastPressed = 2;
    }
  }
  // --- RED: 3 alert beeps, LED STAYS ON ---
  else if (lowVal == HIGH) {
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    redRemainsOn = true;

    if (lastPressed != 3) {
      tone(BUZZER, 500);
      delay(200);
      noTone(BUZZER);
      delay(100);
      tone(BUZZER, 500);
      delay(200);
      noTone(BUZZER);
      delay(100);
      tone(BUZZER, 500);
      delay(200);
      noTone(BUZZER);

      lastPressed = 3;
    }
  }
  // --- No sensor touched ---
  else {
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    
    if (redRemainsOn) {
      digitalWrite(RED_LED, HIGH); // Red LED stays on
    } else {
      digitalWrite(RED_LED, LOW);
    }

    noTone(BUZZER);
    lastPressed = 0;
  }
}