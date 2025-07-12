#define TRIG 3
#define ECHO 2
#define BUZZER 5

unsigned long previousMillis = 0;

int buzzerState = LOW;

int flickerSpeed = 0;

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(BUZZER, OUTPUT);
}

void loop() {

  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);


  long duration = pulseIn (ECHO, HIGH, 20000); //Timeout 20ms
  int distance = duration * 0.034 / 2;
// define Buzzer speed

  if (distance > 90 || distance <= 0) { // if object not available
  flickerSpeed = 0;
  }
  else if (distance > 70) {
  flickerSpeed = 200; // Slow flicker
} else if (distance > 30) {
  flickerSpeed = 100; // Fast flicker
} else {
  flickerSpeed = 40; // Ultra fast flicker
}

// Buzzer flicker using millis()

if (flickerSpeed > 0) {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= flickerSpeed){
    previousMillis = currentMillis;
    buzzerState = !buzzerState; 
    digitalWrite(BUZZER, buzzerState);
  }
} else {
  digitalWrite(BUZZER, LOW);
  }
}