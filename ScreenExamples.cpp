/*
 * ScreenExamples.cpp
 * 
 * Some example screens
 * 
 * Author: Rob Bultman
 * Copyright 2017 by FirstBuild
 */

#include "FontList.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

typedef void (*exampleScreen)(void);

static void showTime(Adafruit_SSD1306 display) {
  char buf[] = "NEW YORK";
  int16_t x1, y1;
  uint16_t w, h;
  const GFXfont *font = &ter_u28n28pt7b;
  int8_t yOffset = font->glyph[0].yOffset;
  uint8_t height = font->glyph[0].height;
//  int16_t baseline=32 - yOffset/2;
  int16_t baseline=32 - height/2 - yOffset;
  
  display.clearDisplay();

    // print message
  display.setFont(font);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.getTextBounds(buf, 0, 24, &x1, &y1, &w, &h);
  display.setCursor(64 - w/2, baseline);
  display.println(buf);

  // draw the box
  display.drawRect(0, 32-height/2, 128, height, WHITE);

  display.fillTriangle(64, 0, 74, 10, 54, 10, WHITE); 
  display.fillTriangle(64, 63, 74, 53, 54, 53, WHITE); 

  display.display();  
}

void showScreenExample(uint8_t index, Adafruit_SSD1306 display) {
  showTime(display);
}

