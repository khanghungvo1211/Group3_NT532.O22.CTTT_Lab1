int pinA = 6;
int pinB = 5;
int pinC = 12;
int pinD = 10;
int pinE = 9;
int pinF = 7;
int pinG = 8;
int greenLED = 2;
int yellowLED = 3;
int redLED = 4;

void setup() {
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
}

void displayNumber(int number) {
  // Turn off all segments initially
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);

  // Turn on the segments needed for each number
  switch (number) {
    case 0:
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, LOW);
      digitalWrite(pinC, LOW);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
digitalWrite(pinF, LOW);
      break;
    case 1:
      digitalWrite(pinB, LOW);
      digitalWrite(pinC, LOW);
      break;
    case 2:
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, LOW);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinG, LOW);
      break;
    case 3:
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, LOW);
      digitalWrite(pinC, LOW);
      digitalWrite(pinD, LOW);
      digitalWrite(pinG, LOW);
      break;
    case 4:
      digitalWrite(pinB, LOW);
      digitalWrite(pinC, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, LOW);
      break;
    case 5:
      digitalWrite(pinA, LOW);
      digitalWrite(pinC, LOW);
      digitalWrite(pinD, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, LOW);
      break;
    case 6:
      digitalWrite(pinA, LOW);
      digitalWrite(pinC, LOW);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, LOW);
      break;
    case 7:
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, LOW);
      digitalWrite(pinC, LOW);
      break;
    case 8:
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, LOW);
      digitalWrite(pinC, LOW);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, LOW);
      break;
    case 9:
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, LOW);
      digitalWrite(pinC, LOW);
      digitalWrite(pinD, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, LOW);
      break;
  }
}

void lightSequence(int ledPin, int duration) {
  digitalWrite(ledPin, HIGH); // Turn on the current LED
  for (int number = duration; number >= 0; --number) {
    displayNumber(number); // Display countdown number
    delay(1000); // Wait for a second
  }
  digitalWrite(ledPin, LOW); // Turn off the LED after the countdown
}

void loop() {
  lightSequence(greenLED, 7); // Green light for 7 seconds
  lightSequence(yellowLED, 2); // Yellow light for 2 seconds
  lightSequence(redLED, 9); // Red light for 9 seconds
}