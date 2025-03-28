# **Voice-Controlled LED Automation System**

## **Overview**
This project uses an ESP32 to control an LED through voice commands, with both **online** (Blynk + Siri) and **offline** (Bluetooth) capabilities. Motion detection adds automation, while an I2C LCD provides real-time feedback.

---

## **Features**
- **Online Mode**: Siri Shortcuts trigger webhooks via Blynk for remote control.
- **Offline Mode**: Bluetooth commands provide local voice control.
- **Motion Detection**: PIR sensor turns the LED on when movement is detected.
- **LCD Feedback**: Displays motion status and LED state.

---

## **Hardware**
- ESP32 Development Board  
- PIR Motion Sensor  
- LED  
- I2C LCD (16x2)  
- Optional Bluetooth Module (e.g., HC-05)

---

## **How It Works**
1. Online voice control via Siri and webhooks toggles the LED.
2. Offline Bluetooth voice commands control the LED without internet.
3. PIR sensor automates LED activation on motion detection.
4. LCD displays updates like "Motion Detected" and "LED ON/OFF."

---

## **Advantages**
- Works with or without internet.  
- Combines voice control, motion sensing, and feedback seamlessly.  
- Cost-effective, scalable, and beginner-friendly.

---
