#include "DigiKeyboard.h"

const char* imageURL = "https://apod.nasa.gov/apod/image/2407/MilkyWayBridgePanorama_Perez_2048.jpg";

void setup() {
  pinMode(1, OUTPUT); // Optional LED indicator
}

void loop() {
  DigiKeyboard.update();

  // Open Spotlight
  DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_GUI_LEFT);
  DigiKeyboard.delay(300);

  // Launch Terminal
  DigiKeyboard.println("Terminal");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1500);

  // Build and send commands
  DigiKeyboard.println("bash -c '");
  DigiKeyboard.println("IMG=~/Pictures/wallpaper.jpg;");
  DigiKeyboard.print("curl -L -o \"$IMG\" \"");
  DigiKeyboard.print(imageURL);
  DigiKeyboard.println("\";");
  DigiKeyboard.println("osascript -e \"tell application \\\"System Events\\\" to tell every desktop to set picture to (POSIX file \\\"$IMG\\\")\";");
  DigiKeyboard.println("'"); // End bash
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  // Optional feedback
  blinkLED();

  DigiKeyboard.delay(5000);
  digitalWrite(1, LOW);
}

void blinkLED() {
  digitalWrite(1, HIGH);
  DigiKeyboard.delay(200);
  digitalWrite(1, LOW);
  DigiKeyboard.delay(200);
}
