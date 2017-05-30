# ssd1306_128x64_spi
Some font examples for SSD1306-based displays

This project was created to test some different fonts with a 0.96" OLED display
based on the SSD1306 display controller.  It uses the 
[Adafruit GFX](https://github.com/adafruit/Adafruit-GFX-Library) graphics 
library and the [Adafruit SSD1306](https://github.com/adafruit/Adafruit_SSD1306) 
library.

The fonts in the Fonts directory are from the 
[Terminus font](http://terminus-font.sourceforge.net/).  This font was
selected because if the range of sizes available in both normal and bold.  The
font convert utility included with the Adafruit GFX library was used to convert 
the font files from BDF format to the format used by the Adafruit library.

