// Define the LED pins
const int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
const int numLeds = sizeof(ledPins) / sizeof(ledPins[0]);

// Define the analog input pin for the variable resistor
const int potentiometerPin = A0;

// Define the pin for the push button
const int buttonPin = 2;

void setup() {
  // Initialize LED pins as outputs
  for (int i = 0; i < numLeds; ++i) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW); // Turn off all LEDs initially
  }

  // Initialize the button pin as input with pull-up resistor
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  // Read the value from the potentiometer (0-1023)
  int analogValue = analogRead(potentiometerPin);

  // Map the analog value to the LED count (0-12)
  int numLitLeds = map(analogValue, 0, 1023, 0, numLeds);

  // Check if the button is pressed
  if (digitalRead(buttonPin) == LOW) {
    // Turn on LEDs manually based on button press
    for (int i = 0; i < numLeds; ++i) {
      digitalWrite(ledPins[i], i < numLitLeds ? HIGH : LOW);
    }
  } else {
    // Turn on the appropriate number of LEDs
    for (int i = 0; i < numLeds; ++i) {
      digitalWrite(ledPins[i], i < numLitLeds ? HIGH : LOW);
    }
  }

  // Add a small delay to avoid flickering
  delay(50);
}