/* *********************************************************************************
 * ESP8266 QRcode
 * dependency library :
 * ESP8266 TFT Driver for ili9341 SPI display 
 *
 * LCD_SCK --> D5
 * LCD_CS  --> D2
 * LCD_SDI --> D7
 * LCD_SDO --> D6
 * LCD_DC  --> D1
 * LCD_RST --> RST
***********************************************************************************/

#include <SPI.h>
#include <ILI9341_QRCODE.h>
#include <Adafruit_GFX.h>

// #include <Adafruit_ILI9341.h>
#include "TFT_eSPI.h"

// Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);
TFT_eSPI tft = TFT_eSPI();
#define TFT_DC D1
#define TFT_CS D2

ILI9341_QRcode tftqrcode(&tft);

void setup() 
{
    Serial.begin(115200);
    Serial.println("");
    Serial.println("Starting...");

    tft.begin();
    tft.fillScreen(ILI9341_WHITE);

    // 5 fits maximum to a 240x320 ILI9341
    tftqrcode.setPixelSize(5);

    // calculate space of centered QR code
    uint16_t xPosition = (tft.width() - tftqrcode.getQrSize()) / 2;
    uint16_t yPosition = (tft.height() - tftqrcode.getQrSize()) / 2;
    tftqrcode.QR_Code_create("https://github.com/brainelectronics", xPosition, yPosition);
}

void loop() 
{
  
}
