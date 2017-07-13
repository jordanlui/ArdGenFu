/*
 * Function Generator Sketch
 * Notes
 * delayMicroseconds(), Currently, the largest value that will produce an accurate delay is 16383
 * 
 * 100 Hz has period 10k us or 5k us for our loop delay times
 * 9kHz would have 56 loop delay times
 * Reminders on pin addressing. Pin 12 is B010000. 13 is B100000. Both pin 12&13 on would be B110000
 * 
 * Guide on Frequency outuputs
 * f = 1/(2T), where T is the delay time in microseconds
 * Examples
 * T = 56, f = 9 kHz
 * T = 50,000 gives f=10 Hz, but largest working delay is 16383
 * T = 5,000 gives f=100 Hz
 * T = 16383 gives f = 30.5 Hz
 * 
 * 
 */

void setup()
{ 
  DDRB = DDRB | B110000; // Set digital pins 12 and 13 to outputs
} 

//
int T = 16300; // Delay time in microsends
void loop()
{  
  
  PORTB = B010000;         // Digital pin 12 high
  PORTB = B100000;
  delayMicroseconds(T);  // microsecond delay
  PORTB = B000000;        // Digital pin 12 low 
  delayMicroseconds(T);   // microsecond delay

   
}
