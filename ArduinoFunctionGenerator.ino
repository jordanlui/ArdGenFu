/*
 * Function Generator Sketch
 * Generates a square wave (duty cycle 50%).
 * === Limitation - lowest frequency ===
 * This function uses, delayMicroseconds(), which is reportedly limited to a largest value 16383, which corresponds to about 30.5 Hz.  
 * If you want slower, you can just use the regular delay() function.

 * === Setting a Frequency ===
 * This script can read a voltage from an analog pin and use this to set the output frequency.
 * Reading from analog pin gives you 1024 levels.
 * For my demo purpose I decided on a simple mapping from 32 Hz to 1055 Hz.
 * 
 * 
 * Notes
 * 
 * 
 * === Pin Addressing ===
 * Pin 12 is B010000. 13 is B100000. Both pin 12&13 on would be B110000
 * Both pins go off at B000000
 * 
 * === Frequency outputs ===
 * f = 1/(2T), where T is the delay time in microseconds
 * Examples
 * T = 56, f = 9 kHz
 * T = 50,000 gives f=10 Hz, but largest working delay is 16383
 * T = 5,000 gives f=100 Hz
 * T = 16383 gives f = 30.5 Hz
 * 
 * 
 */


// Parameters
int T = 16383;   // Delay time in microseconds
bool staticT = false; // Set this boolean to True if you want to just set a constant frequency, and don't want to poll our analog pin.
int fpin = 3; // Read from Analog pin3. 
int Tmax = 16383;
int Tmin = 0;
int count = 0;
int countmax = 100; // number of periods we go before re-acquiring a new frequency
int freqmin = 32; // This is the lowest frequency we'll map too

void setup()
{ 
  DDRB = DDRB | B110000; // Set digital pins 12 and 13 to outputs
  Serial.begin(9600);
} 



int looptiming(int fpin){
  // Read from the chosen analog pin. Get a digtal value from 0-1023 and use this to set the loop timing, aka frequency
  int fpinval = analogRead(fpin); // Read analog pin. This will represent our frequency in Hz.
  int T2 = 1 / (2 * (freqmin + fpinval)  * 1e-6); // The path to convert a desired frequency into a half period value, in microseconds. 
  if (T2 > Tmax) T2 = Tmax; // Check for frequencies outside of the known operating ranges
  if (T2 < Tmin) T2 = Tmin;
  return T2;
}
void loop()
{  

  PORTB = B100000;        // Digital Pin 13 high
  delayMicroseconds(T);  // microsecond delay
  PORTB = B000000;        // Digital pins low 
  delayMicroseconds(T);   // microsecond delay
  
  if (count > countmax) // Use a coutner and if loop to decide when we poll for a new loop timing value
  {
    count = 0;  // Reset count
    T = looptiming(fpin); // Get a new timing value
//    Serial.println(T); // Print the value. Useful for debugging
  }
  else
  {
    count++;
  }
   
}
