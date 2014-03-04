// Define these at the top of your sketch.
#define LEDBLINK_PIN    13    // I/O pin connected to the LED.
#define LEDBLINK_MS     1000  // Blink rate (in milliseconds).

void setup()
{
  // For ledBlink(), set LEDBLINK_PIN to output.
  pinMode(LEDBLINK_PIN, OUTPUT);
}

void loop()
{
  // Blink the LED to let the user know we are still alive.
  ledBlink();

  // Do something. 
}

//
// LED Heartbeat routine by Allen C. Huffman (www.appleause.com)
//
void ledBlink()
{
  static unsigned int  ledStatus = LOW;  // Last set LED mode.
  static unsigned long ledBlinkTime = 0; // LED blink time.

  // LED blinking heartbeat. Yes, we are alive.
  // For explanation, see:
  // http://playground.arduino.cc/Code/TimingRollover
  if ( (long)(millis()-ledBlinkTime) >= 0 )
  {
    // Toggle LED.
    ledStatus = (ledStatus==HIGH ? LOW : HIGH);

    // Set LED pin status.
    digitalWrite(LEDBLINK_PIN, ledStatus);

    // Reset "next time to toggle" time.
    ledBlinkTime = millis()+LEDBLINK_MS;
  }
} // End of ledBlink()
