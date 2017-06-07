/*
 * FontList.h
 * 
 * A place to keep the fonts
 * 
 * Author: Rob Bultman
 * Copyright 2017 by FirstBuild
 */

#ifndef FONT_LIST_H
#define FONT_LIST_H

#include <Adafruit_GFX.h>

typedef struct FontRec {
  const GFXfont * font;
  char name[64];
} FontRec;

extern const FontRec fontList[];

extern const uint8_t fontListCount;

extern const GFXfont ter_u12n12pt7b;
extern const GFXfont ter_u12b12pt7b;
extern const GFXfont ter_u14n14pt7b;
extern const GFXfont ter_u14b14pt7b;
extern const GFXfont ter_u16n16pt7b;
extern const GFXfont ter_u16b16pt7b;
extern const GFXfont ter_u18n18pt7b;
extern const GFXfont ter_u18b18pt7b;
extern const GFXfont ter_u20n20pt7b;
extern const GFXfont ter_u20b20pt7b;
extern const GFXfont ter_u22n22pt7b;
extern const GFXfont ter_u22b22pt7b;
extern const GFXfont ter_u24n24pt7b;
extern const GFXfont ter_u24b24pt7b;
extern const GFXfont ter_u28n28pt7b;
extern const GFXfont ter_u28b28pt7b;

#endif // FONT_LIST_H
 
