/*
 * Function Generator Sketch
 * Notes
 * delayMicroseconds(), Currently, the largest value that will produce an accurate delay is 16383
 * 
 * 100 Hz has period 10k us or 5k us for our loop delay times
 * 9kHz would have 56 loop delay times
 */

void setup()
{ 
  DDRB = DDRB | B110000; // Set digital pins 12 and 13 to outputs
} 
int T = 56;


//tone(13,2);
void loop()
{  
  
    
  PORTB = B100000;         // Digital pin 13 high
  delayMicroseconds(T);  //30 microsecond delay
  PORTB = B000000;        // Digital pin 13 low 
  delayMicroseconds(T);   //30 microsecond delay

  // Currently tone() function works to generate a tone
//  tone(13,10,2000);
//  noTone(13);
//  delay(10);
   
}
