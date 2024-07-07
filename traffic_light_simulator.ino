const int buttonPin = 8; // Assume the button is connected to pin 4
const int greenLED = 3;  // Green LED connected to pin 3
const int yellowLED = 2; // Yellow LED connected to pin 2
const int redLED = 1;    // Red LED connected to pin 1

int buttonState = 0;        // Variable for reading the push button status
int lastButtonState = LOW;  // Previous state of the button
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setup() {
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buttonPin, INPUT);
  
  digitalWrite(greenLED, HIGH); // Start with green light on
  digitalWrite(yellowLED, LOW);
  digitalWrite(redLED, LOW);
}

void loop() {
  int reading = digitalRead(buttonPin);
  
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }
  
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;
      
      // only toggle the light if the new button state is HIGH
      if (buttonState == HIGH) {
        // Change lights
        if (digitalRead(greenLED) == HIGH) {
          digitalWrite(greenLED, LOW);
          digitalWrite(yellowLED, HIGH);
        } else if (digitalRead(yellowLED) == HIGH) {
          digitalWrite(yellowLED, LOW);
          digitalWrite(redLED, HIGH);
        } else if (digitalRead(redLED) == HIGH) {
          digitalWrite(redLED, LOW);
          digitalWrite(greenLED, HIGH);
        }
      }
    }
  }

  lastButtonState = reading;
}
