/*
 * FontList.cpp
 * 
 * A place to keep the fonts
 * 
 * Author: Rob Bultman
 * Copyright 2017 by FirstBuild
 */

#include "FontList.h"
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

const FontRec fontList[] = {
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

const uint8_t fontListCount = (sizeof(fontList)/sizeof(FontRec));



