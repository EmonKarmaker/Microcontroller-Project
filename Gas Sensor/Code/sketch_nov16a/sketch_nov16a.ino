#include <LiquidCrystal.h>

// Initialize the LCD library with the pins connected to the LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Pin definitions
int gasSensorPin = A0;  // MQ-2 sensor connected to A0
int buzzerPin = 10;     // Buzzer connected to D10

// Gas threshold value
int gasThreshold = 300; // Adjust based on your sensor's output

// State tracking variables
int previousGasValue = -1; // Tracks the last gas value displayed
bool gasDetected = false;  // Tracks whether gas has been detected

void setup() {
  // Initialize the LCD
  lcd.begin(16, 2);        // Set LCD size to 16x2
  lcd.print("Gas Detection"); // Display a welcome message

  // Setup pin modes
  pinMode(gasSensorPin, INPUT);  // MQ-2 sensor pin
  pinMode(buzzerPin, OUTPUT);    // Buzzer pin

  // Ensure the buzzer is OFF initially
  digitalWrite(buzzerPin, LOW);

  // Delay to display the welcome message
  delay(2000);
  lcd.clear(); // Clear the LCD after 2 seconds
}

void loop() {
  // Read the gas sensor value
  int gasValue = analogRead(gasSensorPin);

  // Only update the LCD if the gas value changes
  if (gasValue != previousGasValue) {
    lcd.setCursor(0, 0);
    lcd.print("Gas Value: ");
    lcd.print(gasValue);
    previousGasValue = gasValue;
  }

  // Check if the gas value exceeds the threshold
  if (gasValue > gasThreshold && !gasDetected) {
    // Gas detected - activate buzzer and update LCD
    lcd.setCursor(0, 1);
    lcd.print("Gas Detected! ");
    digitalWrite(buzzerPin, HIGH); // Turn ON the buzzer
    gasDetected = true; // Update detection state
  } else if (gasValue <= gasThreshold && gasDetected) {
    // No gas detected - deactivate buzzer and update LCD
    lcd.setCursor(0, 1);
    lcd.print("No Gas        "); // Clear the message
    digitalWrite(buzzerPin, LOW); // Turn OFF the buzzer
    gasDetected = false; // Update detection state
  }

  delay(500); // Refresh every 500 milliseconds
}
