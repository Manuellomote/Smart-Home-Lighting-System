Voice-Controlled LED with PIR Motion Sensor Using ESP32, Blynk, and LCD

Overview

This project integrates an ESP32 microcontroller, a PIR motion sensor, and an I2C LCD screen to create a system where:

>>>>An LED can be controlled via voice commands using Siri Shortcuts linked to Blynk.

>>>>A PIR motion sensor can turn the LED on when motion is detected
The LCD provides real-time feedback on system activity.

>>>>The LCD provides real-time feedback on system activity displaying the LED state and whether motion was detected.

Hardware Components

To build this project, you'll need:

1. ESP Development Board - Handles Wi-Fi connectivity and processes inputs/outputs.
2. LED - Indicates motion detection and is controlled via voice or sensor logic
3. PIR Motion Sensor - Detects motion to trigger the LED.
4. 16x2 I2C LCD Display - Provides feedback on the system state (motion and LED status).
5. Resistor (1kohm) - Current-limiting resistor for LED.
6. Connecting Wires - For electrical connections
7. Breadboard - For assembling the components.
8. Power Supply - A USB cable connected to the ESP32 external power source.

Hardware Connections
1. ESP32 Pins
> LED: Connect the positive leg of the LED to GPIO 2 (via a resistor) and the negative leg to GND

> PIR Motion Sensor:
	>VCC: Connect to the ESP32's 5V
	>GND: Connect to the ESP32's GND
	>OUT: Connect to GPIO 7
>I2C LCD:
	>SDA: Connect to GPIO 21.
	>SCL: Connect to GPIO 22.
	>



Voice-Controlled LED with PIR Motion Sensor Using ESP32, Blynk, and LCD
Overview
This project integrates an ESP32 microcontroller, a PIR motion sensor, and an I2C LCD screen to create a system where:
•	An LED can be controlled via voice commands using Siri Shortcuts linked to Blynk.
•	A PIR motion sensor can turn the LED on when motion is detected.
•	The LCD provides real-time feedback on system activity, displaying the LED state and whether motion was detected.



________________________________________
Hardware Components
To build this project, you'll need:
1.	ESP32 Development Board - Handles Wi-Fi connectivity and processes inputs/outputs.
2.	LED - Indicates motion detection and is controlled via voice or sensor logic.
3.	PIR Motion Sensor - Detects motion to trigger the LED.
4.	16x2 I2C LCD Display - Provides feedback on the system state (motion and LED status).
5.	Resistor (220Ω) - Current-limiting resistor for the LED.
6.	Connecting Wires - For electrical connections.
7.	Breadboard - For assembling the components.
8.	Power Supply - A USB cable connected to the ESP32 or an external power source.



________________________________________
Hardware Connections
1. ESP32 Pins
•	LED: Connect the positive leg of the LED to GPIO 2 (via a resistor) and the negative leg to GND.
•	PIR Motion Sensor: 
o	VCC: Connect to the ESP32's 3.3V or 5V (depending on the sensor specs).
o	GND: Connect to the ESP32's GND.
o	OUT: Connect to GPIO 7.
•	I2C LCD: 
o	SDA: Connect to GPIO 21.
o	SCL: Connect to GPIO 22.
o	VCC: Connect to the ESP32's 5V pin.
o	GND: Connect to the ESP32's GND.



________________________________________
Code Explanation
Includes and Definitions
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
These libraries are used for:
•	LiquidCrystal_I2C: Communicating with the LCD display.
•	Wi-Fi and BlynkSimpleEsp32: Connecting to Wi-Fi and interacting with Blynk’s cloud servers.

LED and PIR Setup
bool ledState = false;  // Tracks LED state
int pirPin = 13;   // Motion sensor pin
int led = 18;            // LED pin
•	ledState keeps track of whether the LED is ON or OFF.
•	The PIR sensor is connected to GPIO 13, and the LED is connected to GPIO 18.
LCD Initialization
LiquidCrystal_I2C lcd(0x27, 16, 2); // LCD setup
This initializes the LCD at I2C address 0x27 with dimensions 16x2.
Wi-Fi and Blynk
char auth[] = "YourAuthToken";
char ssid[] = "YourSSID";
char pass[] = "YourPassword";
These variables store the Blynk authentication token and Wi-Fi credentials.



________________________________________
Setup Function
void setup() {
  pinMode(led, OUTPUT);        // Set LED pin as output
  pinMode(pirPin, INPUT);      // Set PIR pin as input
  lcd.init();                  // Initialize LCD
  lcd.backlight();             // Turn on LCD backlight
  
  WiFi.begin("YourSSID", "YourPassword"); // Connect to Wi-Fi
  Blynk.begin(auth, ssid, pass);          // Connect to Blynk servers
}
This function initializes the components, connects to Wi-Fi, and sets up Blynk.



________________________________________
Motion Detection
int motionState = digitalRead(pirPin);

if (motionState == HIGH && !ledState) {
  digitalWrite(led, HIGH);
  lcd.clear();
  lcd.print("Motion Detected!");
}
When motion is detected, the PIR sensor outputs HIGH, turning on the LED and displaying "Motion Detected!" on the LCD.



________________________________________
Voice Control
BLYNK_WRITE(V0) {
  ledState = param.asInt();       // Read the LED state from Blynk virtual pin V0
  digitalWrite(led, ledState);    // Update the LED based on voice command
  lcd.clear();
  lcd.print(ledState ? "LED: ON" : "LED: OFF");
}
Voice control is managed via Blynk’s virtual pin V0(activated by a webhook through Siri shorcuts), which updates the LED state and shows it on the LCD.



________________________________________
Loop Function
void loop() {
  Blynk.run();                   // Keep Blynk connected
}
The loop function ensures continuous communication with Blynk servers.

Conclusion
This project demonstrates the seamless integration of voice control, motion sensing, and real-time feedback using an ESP32 microcontroller. It’s a perfect example of blending hardware and software to create a smart, interactive system.





