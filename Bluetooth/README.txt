
# **Arduino Voice-Controlled Light System**

## **Overview**
This Arduino project allows you to control an LED (or any connected device) using text commands sent via the Serial Monitor. The system listens for commands like "turn on light" or "turn off light," processes the input, and executes the appropriate action. It’s a simple but powerful demonstration of text-based control for automation.

---

## **Hardware Components**
To build this project, you will need:
1. **Arduino Board** (e.g., Arduino Uno): The microcontroller to execute the code and handle inputs/outputs.
2. **LED or Relay Module**: Visual feedback or control of external devices.
3. **Resistor (220Ω)**: Current-limiting resistor to protect the LED (if used).
4. **Computer with Arduino IDE**: To upload the sketch and interface with the Serial Monitor.
5. **Serial Communication Interface**:
   - Direct Serial Monitor input (via USB).
   - Optional: **Bluetooth module (e.g., HC-05)** for wireless communication.

---

## **Pin Configuration**
The following table outlines the pin connections for this project:

| **Pin** | **Description**        |
|---------|------------------------|
| 5       | Controls the LED or external device |

---

## **Code Walkthrough**

### **1. Global Variables**
The code starts by declaring a global string variable:
```cpp
String voice;
```
- **Purpose**: Stores the command received through Serial communication.

---

### **2. setup() Function**
The `setup()` function initializes the Serial communication and configures the LED pin:
```cpp
void setup() {
  Serial.begin(9600);   // Start serial communication at 9600 baud rate
  pinMode(5, OUTPUT);   // Set pin 5 as output for the LED
}
```
- **Serial.begin(9600)**: Enables communication with the Serial Monitor at the specified baud rate.
- **pinMode(5, OUTPUT)**: Sets pin 5 as an output to control the LED.

---

### **3. loop() Function**
The `loop()` function is where the main logic resides:
```cpp
void loop() {
  while (Serial.available()) {    // Check if Serial input is available
    delay(30);                    // Allow data reception
    char c = Serial.read();       // Read one character from Serial
    voice += c;                   // Append the character to the 'voice' string
  }

  if (voice.length() > 0) {       // Process the command once input is complete
    voice.trim();                 // Remove extra spaces or newline characters
    Serial.println("Received: " + voice);
  }
}
```
- **Data Reception**: Reads the input characters and appends them to the `voice` string.
- **Command Debugging**: Prints the received command to the Serial Monitor for debugging.

---

### **4. Command Processing**
The code processes specific commands and controls the LED:
```cpp
    if (voice == "turn on light") {  // If the command is "turn on light"
      digitalWrite(5, HIGH);         // Turn the LED ON
      Serial.println("Light ON");
    }
    else if (voice == "turn off light") {  // If the command is "turn off light"
      digitalWrite(5, LOW);                // Turn the LED OFF
      Serial.println("Light OFF");
    }
    else {                                // If the command is invalid
      Serial.println("Invalid Command!");
    }
    voice = ""; // Clear the 'voice' string for the next command
```
- **Predefined Commands**:
  - **"turn on light"**: Turns the LED ON (pin 5 set HIGH).
  - **"turn off light"**: Turns the LED OFF (pin 5 set LOW).
- **Error Handling**: Displays "Invalid Command!" if the input doesn’t match any predefined commands.

---

## **How to Use**

The base.apk file is used for the voice control


1. Connect the hardware components as described in the pin configuration.
2. Open the Arduino IDE and upload the sketch to your Arduino board.
3. Open the Serial Monitor (set baud rate to 9600).
4. Enter the following commands:
   - `"turn on light"`: Turns the LED ON.
   - `"turn off light"`: Turns the LED OFF.
5. If an unrecognized command is entered, you’ll see the message "Invalid Command!".

---

## **Possible Enhancements**
- **Add Wireless Control**: Use a Bluetooth module like HC-05 to allow commands via a smartphone.
- **Expand Commands**: Add functionality for more devices or sensors.
- **Feedback Mechanism**: Use an LCD or additional LEDs to give visual feedback.
- **Voice Recognition**: Integrate a voice recognition module for direct spoken commands.

---

## **Conclusion**
This Arduino sketch provides a simple yet effective solution for controlling devices using serial communication. It's a great starting point for exploring text- and voice-based automation systems and can be expanded to include wireless control and additional features.

---
