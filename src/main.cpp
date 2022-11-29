#include <FastLED.h>
#include <vector>

#define NUM_LEDS 300

#define DATA_PIN 1
#define DATA_PIN_2 8

// Define the array of leds
CRGB leds[NUM_LEDS];

int iterateSpeed = 500; // Delay in ms

void setup() 
{ 
	FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
	FastLED.addLeds<WS2811, DATA_PIN_2, RGB>(leds, NUM_LEDS);
}

void loop()
{
	//std::vector<int> codes = {CRGB::Red, CRGB::Green, CRGB::Blue, CRGB::AliceBlue, CRGB::White};
	/*std::vector<int> codes = {CRGB::White};

	// Iterate through colors, displaying with `iterateSpeed` delay
	for (auto color : codes)
	{
		leds[0] = color;
		FastLED.show();
		delay(iterateSpeed);
	}*/

	for (int j = 0; j < 255; j++)
	{
		for (int i = 0; i < NUM_LEDS; i++)
			leds[i] = CHSV((i+j)%254, 254, 254);
		FastLED.show();
		delay(32);
	}
}