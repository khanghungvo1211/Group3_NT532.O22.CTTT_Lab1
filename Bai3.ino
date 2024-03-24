// Define LED pins
const int ledPins[] = {2, 3, 4, 5, 6, 7};
const int numOfLeds = 6;

// Define the button pin
const int buttonPin = 8;

// Variable to store the last button state
bool lastButtonState = LOW;

void setup() {
  // Initialize LED pins as output
  for(int i = 0; i < numOfLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  
  // Initialize the button pin as an input
  pinMode(buttonPin, INPUT);
}

void loop() {
  // Read the current state of the pushbutton
  bool currentButtonState = digitalRead(buttonPin);

  // Check if the button is pressed and was previously released
  if (currentButtonState == HIGH && lastButtonState == LOW) {
    // Simulate rolling the die
    for(int i = 0; i < numOfLeds; i++) {
      digitalWrite(ledPins[i], HIGH);
      delay(100); // Delay for a bit for rolling effect
      digitalWrite(ledPins[i], LOW);
    }
    
    // Generate a random number between 1 and 6 (inclusive)
    int rolledNumber = random(1, 7);
    
    // Display the result by lighting up LEDs
    for(int i = 0; i < rolledNumber; i++) {
      digitalWrite(ledPins[i], HIGH);
    }
    
    delay(1000); // Pause to observe the result

    // Blink all LEDs up to the rolled number 6 times
    for(int j = 0; j <= 6; j++) {
      for(int i = 0; i < rolledNumber; i++) {
        digitalWrite(ledPins[i], HIGH);
      }
      delay(250);
      for(int i = 0; i < rolledNumber; i++) {
        digitalWrite(ledPins[i], LOW);
      }
      delay(250);
    }

    // Ensure all LEDs are turned off after the sequence
    for(int i = 0; i < numOfLeds; i++) {
      digitalWrite(ledPins[i], LOW);
    }

    // Wait a bit before allowing another roll
    delay(500);
  }

  // Update lastButtonState
  lastButtonState = currentButtonState;

  // Add a small delay to debounce the push button
  delay(50);
}
