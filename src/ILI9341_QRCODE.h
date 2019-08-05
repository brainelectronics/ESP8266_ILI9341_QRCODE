#include <Adafruit_GFX.h>
// #include <Adafruit_ILI9341.h>
#include <TFT_eSPI.h>

class ILI9341_QRcode
{
	private:
		// Adafruit_ILI9341 *LCD;
		TFT_eSPI *myLCD;
		//void render(int x, int y, int color);

	public:
		// ILI9341_QRcode(Adafruit_ILI9341 *TFTLCD);
		ILI9341_QRcode(TFT_eSPI *display);

		uint8_t pixel_size;
		void QR_Code_create(String message, int display_x, int display_y );
		uint16_t getQrSize();
		uint8_t getPixelSize();
		uint8_t setPixelSize(uint8_t pixel_size);

		
};