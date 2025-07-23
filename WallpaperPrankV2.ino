#include "DigiKeyboard.h"

// CHANGE THIS URL TO YOUR DESIRED WALLPAPER
const char* URL = "https://picsum.photos/1920/1080";

void setup() {
  pinMode(1, OUTPUT);
}

void loop() {
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(3000);

  // Method 1: Terminal
  DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.println("terminal");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);

  DigiKeyboard.print("curl -o ~/w.jpg '");
  DigiKeyboard.print(URL);
  DigiKeyboard.println("';osascript -e 'tell app \"System Events\" to set picture of every desktop to \"~/w.jpg\"';exit");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(5000);

  // Method 2: Script Editor fallback
  DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.println("script");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1500);

  DigiKeyboard.print("do shell script \"curl -o ~/w.jpg '");
  DigiKeyboard.print(URL);
  DigiKeyboard.println("'\"");
  DigiKeyboard.println("tell app \"System Events\" to set picture of every desktop to \"~/w.jpg\"");
  
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(4000);
  DigiKeyboard.sendKeyStroke(KEY_Q, MOD_GUI_LEFT);

  digitalWrite(1, HIGH);
  DigiKeyboard.delay(90000);
  digitalWrite(1, LOW);
  DigiKeyboard.delay(5000);
}
