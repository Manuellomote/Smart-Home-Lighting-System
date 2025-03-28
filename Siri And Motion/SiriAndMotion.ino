#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPL24WZo66kj"
#define BLYNK_TEMPLATE_NAME "ifttt"
#define BLYNK_AUTH_TOKEN "Ms2OFe68i4nw3O_vcr2LC-a5oXjY9k8j"

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>



// Blynk auth token, Wi-Fi credentials
char auth[] = "Ms2OFe68i4nw3O_vcr2LC-a5oXjY9k8j"; 
char ssid[] = "Wokwi-GUEST";
char pass[] = ""; // Leave empty for open networks


bool motionDetected = false; // Tracks if motion is detected
bool ledState = false;       // Tracks the current state of the LED
unsigned long startTime;
bool systemStarted = false; // Flag to track if initial delay passed

LiquidCrystal_I2C lcd(0x27, 16, 2); // LCD setup

// Input-output pins
int led = 18;
int pirPin = 13;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(pirPin, INPUT);
  Serial.begin(115200);

  // LCD initialization
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("System Starting...");

  startTime = millis(); // Record startup time

  // Connecting to Wi-Fi
  Serial.println("Connecting to WiFi...");
  WiFi.begin("Wokwi-GUEST", "", 6);
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }
  Serial.println("WiFi Connected!");

  // Connecting to Blynk
  Serial.println("Attempting to connect to Blynk...");
  Blynk.begin(auth, ssid, pass);
  Serial.println("Blynk connection initialized!");

  // Update LCD to "System Ready"
  lcd.clear();
  lcd.print("System Ready");
  delay(1000);
}

BLYNK_WRITE(V0) { // Virtual pin V0 is used for the Blynk app switch
  ledState = param.asInt();  // Read the switch state from the app
  digitalWrite(led, ledState); // Turn LED on/off based on the switch
  lcd.clear();
  lcd.print(ledState ? "LED: ON" : "LED: OFF"); // Update LED state on the LCD
}

void loop() {
  Blynk.run(); // Keep Blynk connected

  int motionState = digitalRead(pirPin); // Read PIR sensor state

  if (motionState == HIGH && !ledState) { // Motion detected AND LED is OFF
    motionDetected = true;
    digitalWrite(led, HIGH); // Turn on LED
    lcd.clear();
    lcd.print("Motion Detected!");
    lcd.setCursor(0, 1);
    lcd.print("LED: ON");
    Serial.println("Motion Detected! LED Turned ON");
  } else if (motionState == LOW && motionDetected) {
    motionDetected = false;
    lcd.clear();
    lcd.print(ledState ? "LED: ON" : "LED: OFF"); // Maintain the LED state on the LCD
    lcd.setCursor(0, 1);
    lcd.print("No Motion");
    Serial.println("No Motion");
  }

  delay(500);
}

