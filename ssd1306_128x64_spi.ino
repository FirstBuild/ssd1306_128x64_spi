/*
 * This Font explorer program is modified from the example SSD1306
 * progam from Adafruit.  It was built for and tested with the 
 * Teensy 3.1.
 * 
 * Author: Rob Bultman
 * Copyright 2017 by FirstBuild
 */
 
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Encoder.h>
#include "FontList.h"
#include "ScreenExamples.h"

// Define the SPI pins:
#define OLED_MOSI   11
#define OLED_CLK   13
#define OLED_DC    15
#define OLED_CS    10
#define OLED_RESET 14
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

// Define the encoder pins
#define PHA 6
#define PHB 9
Encoder enc(PHA, PHB);

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

void setup()   {                
  Serial.begin(9600);

  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC);
  // init done

  // Clear the buffer.
  display.clearDisplay();
}

static void showFontExample(uint8_t index) {
  static const char msg[] = "NEW YORK";
  char buf[64];
  int16_t x1, y1;
  uint16_t w, h;
  int8_t yOffset = fontList[index].font->glyph[0].yOffset;
  int16_t baseline=32 - yOffset/2;

  display.clearDisplay();

  // print name
  display.setFont(NULL);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  sprintf(buf, "%s", fontList[index].name);
  display.getTextBounds(buf, 0, 24, &x1, &y1, &w, &h);
  display.setCursor(64 - w/2, 0);
  display.println(buf);

  // print message
  strcpy((char *)&buf[0], msg);
  display.setFont(fontList[index].font);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.getTextBounds(buf, 0, 24, &x1, &y1, &w, &h);
  display.setCursor(64 - w/2, baseline);
  display.println(buf);

  display.display();  
}

void loop() {
  static int32_t oldPosition = -99999999;
  // Read the encoder position.  The encoder used generates 4 pulses per
  // step of the encoder
  int32_t newPosition = enc.read()/4;

  // Look for a change in the encider position
  if (oldPosition != newPosition) {
    // Clamp the envcoder logical position and "save" it back
    if (newPosition < 0) newPosition = 0;
    if (newPosition >= (int32_t)fontListCount) newPosition = fontListCount - 1;
    enc.write(newPosition*4);

    // Store the position so we can detect future changes
    oldPosition = newPosition;

    // Show the new font
    //showFontExample(newPosition);
    showScreenExample(newPosition, display);
    
    Serial.println(newPosition);
  }
}

