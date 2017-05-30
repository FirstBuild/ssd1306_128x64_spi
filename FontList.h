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

#endif // FONT_LIST_H
 
