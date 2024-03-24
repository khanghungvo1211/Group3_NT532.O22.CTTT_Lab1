// Define LED pins
const int ledPins[] = {5,6,7};
const int numLeds = sizeof(ledPins) / sizeof(ledPins[0]);

// Define analog input pin for the variable resistor
const int potPin = A0;

void setup() {
    // Initialize LED pins as OUTPUT
    for (int i = 0; i < numLeds; i++) {
        pinMode(ledPins[i], OUTPUT);
    }
    // Initialize Serial communication
    Serial.begin(9600);
}

void loop() {
    // Read the value from the variable resistor
    int potValue = analogRead(potPin);

    // Map the potentiometer value to LED delay (speed)
    int delayTime = map(potValue, 0, 1023, 500, 2000); // Adjust the range as needed

    // Sequentially light up LEDs
    for (int i = 0; i < numLeds; i++) {
        digitalWrite(ledPins[i], HIGH);
        delay(delayTime);
        digitalWrite(ledPins[i], LOW);
    }

    // Display the potentiometer value on Serial Monitor
    Serial.print("Potentiometer value: ");
    Serial.println(potValue);

    // Determine if it's high or low
    if (potValue < 300) {
        Serial.println("Status: Low");
    } else if (potValue >= 300 && potValue < 700) {
        Serial.println("Status: Medium");
    } else {
        Serial.println("Status: High");
    }

    delay(100); // Small delay to avoid flickering
}
