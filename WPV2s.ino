#include "DigiKeyboard.h"

const char* imageURL = "https://i.imgur.com/xFWVbMM.jpeg";

const int ledPin = LED_BUILTIN; // LED pin for feedback

void setup() {
  pinMode(ledPin, OUTPUT); // Optional LED indicator (using the correct variable name)
}

void loop() {
  // Wait a moment for the system to be ready
  DigiKeyboard.delay(2000); // Delay added here to give system time to settle.

  // Open Spotlight (macOS shortcut: Command + Space)
  DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_GUI_LEFT);
  DigiKeyboard.delay(300);
  blinkLED();

  // Launch Terminal
  DigiKeyboard.println("Terminal");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1500);
  blinkLED();

  // Build and send commands to set wallpaper
  DigiKeyboard.println("bash -c '");
  DigiKeyboard.println("IMG=~/Pictures/wallpaper.jpg;");
  DigiKeyboard.print("curl -L -o \"$IMG\" \"");
  DigiKeyboard.print(imageURL);
  DigiKeyboard.println("\";");
  DigiKeyboard.println("osascript -e \"tell application \\\"System Events\\\" to tell every desktop to set picture to (POSIX file \\\"$IMG\\\")\";");
  DigiKeyboard.println("'"); // End bash
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  // Optional LED blink feedback
  digitalWrite(ledPin, HIGH); // Use the correct variable name here
  DigiKeyboard.delay(9000);
  digitalWrite(ledPin, LOW);  // And here too
  DigiKeyboard.delay(200);

}

void blinkLED() {
  digitalWrite(ledPin, HIGH); // Use the correct variable name here
  DigiKeyboard.delay(200);
  digitalWrite(ledPin, LOW);  // And here too
  DigiKeyboard.delay(200);
}
