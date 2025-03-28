String voice;

void setup() {
  Serial.begin(9600);
  pinMode(5, OUTPUT);
}

void loop() {
  while (Serial.available()) {
    delay(30); // Increase delay for better data reception
    char c = Serial.read();
    voice += c;
  }

  if (voice.length() > 0) {
    voice.trim();  // Remove unwanted spaces/newlines
    Serial.println("Received: " + voice); // Debugging output

    if (voice == "turn on light") {
      digitalWrite(5, HIGH);
      Serial.println("Light ON");
    }
    else if (voice == "turn off light") {
      digitalWrite(5, LOW);
      Serial.println("Light OFF");
    }
    
    else {
      Serial.println("Invalid Command!"); // Handle unknown commands
    }
    
    voice = ""; // Clear the string for the next command
  }
}
