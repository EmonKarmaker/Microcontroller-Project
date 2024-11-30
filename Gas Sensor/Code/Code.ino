// Include the library for LCD
#include <LiquidCrystal.h> 

// Initialize the library with the numbers of the interface pins
LiquidCrystal lcd(13, 12, 11, 10, 9, 8); 

// Define pin connections
const int SensorPin = 2;    // MQ-2 sensor digital output pin
const int LEDPin = 7;       // LED pin for visual alert
const int BuzzerPin = 6;    // Buzzer pin
const int FanPin = 5;       // Fan relay pin

void setup() {
  // Set pin modes
  pinMode(SensorPin, INPUT);    // Gas sensor as input
  pinMode(LEDPin, OUTPUT);      // LED as output
  pinMode(BuzzerPin, OUTPUT);   // Buzzer as output
  pinMode(FanPin, OUTPUT);      // Fan relay as output
  
  // Turn off outputs initially
  digitalWrite(LEDPin, LOW);
  digitalWrite(BuzzerPin, LOW);
  digitalWrite(FanPin, LOW);

  // Initialize the LCD
  lcd.begin(20, 4);  // Set up the LCD (20 columns, 4 rows)
  lcd.setCursor(0, 0);
  lcd.print("  THE BRIGHT LIGHT  ");
  lcd.setCursor(0, 1);
  lcd.print(" GAS DETECTION SYS  ");
  delay(2000);  // Display welcome message for 2 seconds
  lcd.clear();
}

void loop() {
  // Read gas sensor digital output
  if (digitalRead(SensorPin) == HIGH) {  
    // Gas detected
    digitalWrite(LEDPin, HIGH);       // Turn on LED
    digitalWrite(BuzzerPin, HIGH);    // Turn on Buzzer
    digitalWrite(FanPin, HIGH);       // Turn on Fan

    // Display "Gas Detected" with animation
    lcd.setCursor(0, 2);
    lcd.print("   Gas Detected    ");
    delay(100);
    lcd.setCursor(0, 2);
    lcd.print("   Gas Detected.   ");
    delay(100);
    lcd.setCursor(0, 2);
    lcd.print("   Gas Detected..  ");
    delay(100);
    lcd.setCursor(0, 2);
    lcd.print("   Gas Detected... ");
    delay(100);
  } else {
    // No gas detected
    digitalWrite(LEDPin, LOW);        // Turn off LED
    digitalWrite(BuzzerPin, LOW);     // Turn off Buzzer
    digitalWrite(FanPin, LOW);        // Turn off Fan

    // Display "No Gas" on LCD
    lcd.setCursor(0, 2);
    lcd.print("       No Gas      ");
    delay(500);  // Refresh display every 500ms
  }
}
