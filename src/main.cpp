#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
int count = 0;

void setup()
{
	Serial.begin(115200);
	display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
	display.clearDisplay();
	display.setTextSize(1);
	display.setTextColor(SSD1306_WHITE);
	display.setCursor(0, 0);
}

void loop()
{
	if (count == 8)
	{
		display.clearDisplay();
		display.setCursor(0, 0);
		display.display();
		count = 0;
	}

	display.println("Hello World!");
	display.display();
	++count;
	delay(500);
}
