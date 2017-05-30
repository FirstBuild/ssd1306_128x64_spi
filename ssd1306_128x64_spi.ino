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
#include "Fonts/ter_u12n12pt7b.h"
#include "Fonts/ter_u12b12pt7b.h"
#include "Fonts/ter_u14n14pt7b.h"
#include "Fonts/ter_u14b14pt7b.h"
#include "Fonts/ter_u16n16pt7b.h"
#include "Fonts/ter_u16b16pt7b.h"
#include "Fonts/ter_u18n18pt7b.h"
#include "Fonts/ter_u18b18pt7b.h"
#include "Fonts/ter_u20n20pt7b.h"
#include "Fonts/ter_u20b20pt7b.h"
#include "Fonts/ter_u22n22pt7b.h"
#include "Fonts/ter_u22b22pt7b.h"
#include "Fonts/ter_u24n24pt7b.h"
#include "Fonts/ter_u24b24pt7b.h"
#include "Fonts/ter_u28n28pt7b.h"
#include "Fonts/ter_u28b28pt7b.h"
#include <Encoder.h>

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

typedef struct FontRec {
  const GFXfont * font;
  char name[64];
} FontRec;

static const FontRec aFont[] = {
 {&ter_u12n12pt7b, "ter_u12n12pt7b"},
 {&ter_u12b12pt7b, "ter_u12b12pt7b"},
 {&ter_u14n14pt7b, "ter_u14n14pt7b"},
 {&ter_u14b14pt7b, "ter_u14b14pt7b"},
 {&ter_u16n16pt7b, "ter_u16n16pt7b"},
 {&ter_u16b16pt7b, "ter_u16b16pt7b"},
 {&ter_u18n18pt7b, "ter_u18n18pt7b"},
 {&ter_u18b18pt7b, "ter_u18b18pt7b"},
 {&ter_u20n20pt7b, "ter_u20n20pt7b"},
 {&ter_u20b20pt7b, "ter_u20b20pt7b"},
 {&ter_u22n22pt7b, "ter_u22n22pt7b"},
 {&ter_u22b22pt7b, "ter_u22b22pt7b"},
 {&ter_u24n24pt7b, "ter_u24n24pt7b"},
 {&ter_u24b24pt7b, "ter_u24b24pt7b"},
 {&ter_u28n28pt7b, "ter_u28n28pt7b"},
 {&ter_u28b28pt7b, "ter_u28b28pt7b"}
};

#define NUM_FONTS (sizeof(aFont)/sizeof(FontRec))

void showFontExample(const GFXfont *font, const char *pName) {
  static const char msg[] PROGMEM = "NEW YORK";
  char buf[64];
  int16_t x1, y1;
  uint16_t w, h;
  int8_t yOffset = font->glyph[0].yOffset;
  int16_t baseline=32 - yOffset/2;

  display.clearDisplay();

  // print name
  display.setFont(NULL);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  sprintf(buf, "%s", pName);
  display.getTextBounds(buf, 0, 24, &x1, &y1, &w, &h);
  display.setCursor(64 - w/2, 0);
  display.println(buf);

  // print message
  strcpy((char *)&buf[0], msg);
  display.setFont(font);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.getTextBounds(buf, 0, 24, &x1, &y1, &w, &h);
  display.setCursor(64 - w/2, baseline);
  display.println(buf);

  display.display();  
}

#define DELAY_TIME 2000

void loop() {
  static int32_t oldPosition = -99999999;
  // Read the encoder position.  The encoder used generates 4 pulses per
  // step of the encoder
  int32_t newPosition = enc.read()/4;

  // Look for a change in the encider position
  if (oldPosition != newPosition) {
    // Clamp the envcoder logical position and "save" it back
    if (newPosition < 0) newPosition = 0;
    if (newPosition >= (int32_t)NUM_FONTS) newPosition = NUM_FONTS - 1;
    enc.write(newPosition*4);

    // Store the position so we can detect future changes
    oldPosition = newPosition;

    // Show the new font
    showFontExample(aFont[newPosition].font, aFont[newPosition].name);
    Serial.println(newPosition);
  }
}

