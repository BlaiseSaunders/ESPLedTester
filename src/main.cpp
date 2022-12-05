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
	//Serial.begin(9600);
//	FastLED.addLeds<WS2811, DATA_PIN_2, RGB>(leds, NUM_LEDS);
}



void lowPulse()
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
			leds[i] = CHSV((i+j)%256, 255, 64);
		FastLED.show();
		delay(32);
	}
}

void rainbowStrobe()
{
	int spot_brightness = 0;

	for (int j = 0; j < 2048; j++)
	{
		for (int i = 0; i < NUM_LEDS; i++)
		{
			//This needs fixing up, while the colours step once per cycle,
			//The brighness will make multiple steps.
			//There's no reason why the brighness can't change, for example,
			//four times faster than the colour does, but I'm lazy so here we are
			spot_brightness = (i+(j))%256;
			if (spot_brightness > 128)
				spot_brightness = 128 - (spot_brightness - 128);
			if (spot_brightness < 32)
				spot_brightness = 32;
			leds[i] = CHSV((i+(j/8))%256, 255, spot_brightness);			
		}
		FastLED.show();
		delay(32);
	}
}


void loop()
{
	rainbowStrobe();
}