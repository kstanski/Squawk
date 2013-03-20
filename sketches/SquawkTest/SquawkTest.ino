#include <Squawk.h>

/*
Since Timer0 is used for Arduino functionality, such as delay() it is not
recommended to use a pin that relies on this timer for output, as Squawk
needs to reconfigure the timer for higher-speed, which modifies how these
Arduino internals behave. Uncomment the correct line below, depending on
which Arduino you intend to run the code on.

Note: You CAN use any pin, if you do not rely on Timer0 related things.
      This sketch uses delay() so we need to steer clear of Timer0.

Leonardo
  use SQUAWK_PWM_PIN5 (it's on Timer3)
  
Uno, Due(milanove), Diecimila, Nano, Mini or LilyPad
  use SQUAWK_PWM_PIN11
  or  SQUAWK_PWM_PIN3 (both are on Timer2)
  
Others
  not yet supported, you'll have to try and see what happens ;)
*/

// Configure Squawk for PWM output, and construct suitable ISR
//SQUAWK_CONSTRUCT_ISR(SQUAWK_PWM_PIN3)
//SQUAWK_CONSTRUCT_ISR(SQUAWK_PWM_PIN5)
//SQUAWK_CONSTRUCT_ISR(SQUAWK_PWM_PIN11)

// Declare type of melody_data, so we can put it AFTER the code
// Using this declaration, you could also put the code in a separate .cpp
// or .c file in the same folder as the sketch, for maximum cleanliness!
extern const uint8_t melody_data[];

void setup() {
  // Set up Squawk to generate samples at 44.1kHz
  // Squawk always steals Timer1 for sample crunching
  Squawk.begin(44100);
  // Begin playback of melody_data
  Squawk.play(melody_data);
}

void loop() {
  // It's up to the user to call Squawk.advance() periodically in order to
  // advance playback. We want to do this roughly 50 timer per second.
  Squawk.advance();
  delay(20);
}

// The Original Squawk by Philip Linde
const uint8_t melody_data[] PROGMEM = {
  0x0E, 0x01, 0x02, 0x03, 0x0A, 0x0B, 0x04, 0x05, 0x04, 0x08, 0x06, 0x07, 0x06, 0x09, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xCC, 0x00, 0x00, 0xEF, 0x04, 0xC1, 0xFF, 0xDD, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xDD, 0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFF, 0xD9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFF, 0xDD, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xAC, 0x00, 0x07, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFF, 0xE7, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFF, 0xE7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xE3, 0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFF, 0xDD, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFF, 0xE3, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFF, 0xE3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xDD, 0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xEC, 0x00, 0xC1, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFF, 0xDD, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xDD, 0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFF, 0xD9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFF, 0xDD, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xAC, 0x00, 0x07, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFF, 0xE7, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFF, 0xE7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xD9, 0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFF, 0xF1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFF, 0xDB, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFF, 0xF3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xFB, 0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFF, 0xF5, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xEF, 0x04, 0xC1, 0xFF, 0xDD, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xDD, 0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFF, 0xD9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFF, 0xDD, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xAC, 0x00, 0x07, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFF, 0xE7, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFF, 0xE7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xE3, 0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFF, 0xDD, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFF, 0xE3, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFF, 0xE3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xDD, 0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xEC, 0x00, 0xC1, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xEF, 0x04, 0xC1, 0xFF, 0xDD, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xC2,
  0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0xFF, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xC2, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xC2, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xF4, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0xFF, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xEF, 0x04, 0xC1, 0xFF, 0xDD, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xF8, 0xBF, 0xC0, 0x00, 0x00, 0x0C, 0x00, 0x00, 0xFF, 0xFE,
  0xE0, 0x00, 0xC2, 0xA0, 0x00, 0x07, 0xFB, 0x9D, 0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xF8, 0xBF, 0xC0, 0x00, 0x00, 0x0C, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xF8, 0x19, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xF8, 0x9D, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xF9, 0x7F, 0xC0, 0x00, 0x00, 0xAC, 0x00, 0x07, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xF9, 0xE7, 0xC0, 0x00, 0x00, 0x0C, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE, 0xE0, 0x00, 0xD3, 0x00, 0x00, 0x00, 0xF9, 0x7E,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xF9, 0xE7, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xF9, 0x63, 0xC0, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xF8, 0x9D, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xF9, 0x63, 0xC0, 0x00, 0x00, 0x0C, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFA, 0x63, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xDD, 0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xEC, 0x00, 0xC1, 0xF8, 0xBF, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xEF, 0x04, 0xC1, 0xFF, 0xDD, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xF8, 0xBF, 0xC0, 0x00, 0x00, 0x0C, 0x00, 0x00, 0xFF, 0xFE,
  0xE0, 0x00, 0xC2, 0xA0, 0x00, 0x07, 0xFB, 0x9D, 0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xF8, 0xBF, 0xC0, 0x00, 0x00, 0x0C, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xF8, 0x19, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xF8, 0x9D, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xF9, 0x7F, 0xC0, 0x00, 0x00, 0xAC, 0x00, 0x07, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xF9, 0xE7, 0xC0, 0x00, 0x00, 0x0C, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE, 0xE0, 0x00, 0xD3, 0x00, 0x00, 0x00, 0xF9, 0x7E,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xF9, 0xE7, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFB, 0x19, 0xC0, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xFE,
  0xC0, 0x00, 0x18, 0xE0, 0x00, 0xC1, 0xFC, 0x71, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xF9, 0xDB, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xF8, 0x73, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFA, 0x7B, 0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFF, 0xF5, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xEF, 0x04, 0xC1, 0xF9, 0x5D, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xF8, 0xBF, 0xC0, 0x00, 0x00, 0x0C, 0x00, 0x00, 0xFF, 0xFE,
  0xE0, 0x00, 0xC2, 0xA0, 0x00, 0x07, 0xFB, 0x9D, 0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xF8, 0xBF, 0xC0, 0x00, 0x00, 0x0C, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xF8, 0x19, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xF8, 0x9D, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xF9, 0x7F, 0xC0, 0x00, 0x00, 0xAC, 0x00, 0x07, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xF9, 0xE7, 0xC0, 0x00, 0x00, 0x0C, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE, 0xE0, 0x00, 0xD3, 0x00, 0x00, 0x00, 0xF9, 0x7E,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xF9, 0xE7, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xF9, 0x63, 0xC0, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xF8, 0x9D, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xF9, 0x63, 0xC0, 0x00, 0x00, 0x0C, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFA, 0x63, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0xE0, 0x00, 0xC2, 0xA0, 0x00, 0x07, 0xFB, 0x9D, 0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xEC, 0x00, 0xC1, 0xF8, 0xBF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFA, 0x5D, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xF9, 0x7F, 0xC0, 0x00, 0x00, 0x0C, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xF9, 0x5D, 0xC0, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xF8, 0xBF, 0xC0, 0x00, 0x00, 0x0C, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xF9, 0x59, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFD, 0x5D, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFB, 0x3F, 0xC0, 0x00, 0x00, 0xAC, 0x00, 0x07, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFA, 0xE7, 0xC0, 0x00, 0x00, 0x0C, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFF, 0xE7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xD9, 0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFF, 0xF1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x0E, 0xC1, 0x00, 0xE0, 0x00, 0xC1, 0x77, 0xDB, 0x0E, 0xC1, 0x00, 0x00, 0x00, 0x00, 0x8F, 0xFE,
  0x0E, 0xC1, 0x00, 0xE0, 0x00, 0xC1, 0xAF, 0xF3, 0x0E, 0xC1, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x0E, 0xC1, 0x00, 0xA0, 0x00, 0x07, 0x8F, 0xFB, 0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xFE,
  0x0E, 0xC1, 0x00, 0xE0, 0x00, 0xC1, 0x8F, 0xF5, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xEF, 0x04, 0xC1, 0x3F, 0xDD, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4F, 0xFE,
  0xCC, 0x00, 0x10, 0xE0, 0x00, 0xC1, 0xFB, 0x3F, 0xC0, 0x00, 0x00, 0x0C, 0x00, 0x00, 0xFF, 0xFE,
  0xC0, 0x00, 0x10, 0xA0, 0x00, 0x07, 0x4B, 0x9D, 0xCC, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xFE,
  0xC0, 0x00, 0x10, 0xE0, 0x00, 0xC1, 0x39, 0xFF, 0xC0, 0x00, 0x00, 0x0C, 0x00, 0x00, 0xFF, 0xFE,
  0xC0, 0x00, 0x10, 0xE0, 0x00, 0xC1, 0xFB, 0x19, 0xCC, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0xC0, 0x00, 0x10, 0xE0, 0x00, 0xC1, 0x2B, 0x9D, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0xCC, 0x08, 0x10, 0xA0, 0x00, 0x07, 0xFB, 0x3F, 0xC0, 0x00, 0x00, 0xAC, 0x00, 0x07, 0xFF, 0xFE,
  0xCE, 0xC2, 0x10, 0xE0, 0x00, 0xC1, 0x01, 0xE7, 0xCE, 0xC2, 0x00, 0x0C, 0x00, 0x00, 0x17, 0xFE,
  0xC0, 0x00, 0x10, 0x00, 0x00, 0x00, 0x14, 0x7E, 0xCC, 0x10, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0xC0, 0x00, 0x10, 0xE0, 0x00, 0xC1, 0x03, 0xA7, 0xCC, 0x08, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0xC0, 0x00, 0x10, 0xA0, 0x00, 0x07, 0x14, 0x63, 0xCC, 0x08, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xFE,
  0xC0, 0x00, 0x10, 0xE0, 0x00, 0xC1, 0x2B, 0x9D, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x0C, 0x08, 0x00, 0xE0, 0x00, 0xC1, 0xFF, 0xE3, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0xFF, 0xFE,
  0xC0, 0x00, 0x10, 0xE0, 0x00, 0xC1, 0x63, 0x23, 0xCC, 0x10, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x0C, 0x08, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xDD, 0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xFE,
  0x0E, 0xC2, 0x00, 0xEC, 0x00, 0xC1, 0x2F, 0xFF, 0x0E, 0xC2, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xFE,
  0x00, 0x00, 0x00, 0xEF, 0x04, 0xC1, 0x3F, 0xDD, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4F, 0xFE,
  0xC0, 0x00, 0x10, 0xE0, 0x00, 0xC1, 0x3B, 0x3F, 0xCC, 0x00, 0x00, 0x0C, 0x00, 0x00, 0xFF, 0xFE,
  0xC0, 0x00, 0x10, 0xA0, 0x00, 0x07, 0x2B, 0x9D, 0xCC, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xFE,
  0xC0, 0x00, 0x10, 0xE0, 0x00, 0xC1, 0x39, 0xFF, 0xC0, 0x00, 0x00, 0x0C, 0x00, 0x00, 0xFF, 0xFE,
  0xCC, 0x08, 0x10, 0xE0, 0x00, 0xC1, 0xFB, 0x19, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0xC0, 0x00, 0x10, 0xE0, 0x00, 0xC1, 0x63, 0x9D, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0xCC, 0x08, 0x10, 0xA0, 0x00, 0x07, 0xFB, 0x3F, 0xC0, 0x00, 0x00, 0xAC, 0x00, 0x07, 0xFF, 0xFE,
  0xC0, 0x00, 0x10, 0xE0, 0x00, 0xC1, 0x49, 0xE7, 0xC0, 0x00, 0x00, 0x0C, 0x00, 0x00, 0xFF, 0xFE,
  0xC0, 0x00, 0x10, 0x00, 0x00, 0x00, 0xFC, 0x7E, 0xCC, 0x08, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0xCC, 0x00, 0x10, 0xE0, 0x00, 0xC1, 0xFB, 0xA7, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFC, 0x59, 0xC0, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFB, 0xB1, 0xC0, 0x00, 0x08, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFB, 0x1B, 0xC0, 0x00, 0x08, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xF9, 0xF3, 0xC0, 0x00, 0x08, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFA, 0x7B, 0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xFE,
  0xC0, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFF, 0xF5, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xEF, 0x04, 0xC1, 0x3F, 0xDD, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4F, 0xFE,
  0xCC, 0x00, 0x10, 0xE0, 0x00, 0xC1, 0xFB, 0x3F, 0xC0, 0x00, 0x00, 0x0C, 0x00, 0x00, 0xFF, 0xFE,
  0xC0, 0x00, 0x10, 0xA0, 0x00, 0x07, 0x63, 0x9D, 0xCC, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xFE,
  0xC0, 0x00, 0x10, 0xE0, 0x00, 0xC1, 0x49, 0xFF, 0xC0, 0x00, 0x00, 0x0C, 0x00, 0x00, 0xFF, 0xFE,
  0xC0, 0x00, 0x10, 0xE0, 0x00, 0xC1, 0xFB, 0x19, 0xCC, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0xC0, 0x00, 0x10, 0xE0, 0x00, 0xC1, 0x3B, 0x9D, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0xCC, 0x08, 0x10, 0xA0, 0x00, 0x07, 0xFB, 0x3F, 0xC0, 0x00, 0x00, 0xAC, 0x00, 0x07, 0xFF, 0xFE,
  0xCE, 0xC2, 0x10, 0xE0, 0x00, 0xC1, 0x01, 0xE7, 0xCE, 0xC2, 0x00, 0x0C, 0x00, 0x00, 0x17, 0xFE,
  0xC0, 0x00, 0x10, 0x00, 0x00, 0x00, 0x2C, 0x7E, 0xCC, 0x10, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0xC0, 0x00, 0x10, 0xE0, 0x00, 0xC1, 0x3B, 0xA7, 0xCC, 0x08, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0xC0, 0x00, 0x10, 0xA0, 0x00, 0x07, 0x4C, 0x63, 0xCC, 0x08, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xFE,
  0xC0, 0x00, 0x10, 0xE0, 0x00, 0xC1, 0x63, 0x9D, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x0C, 0x08, 0x00, 0xE0, 0x00, 0xC1, 0xFF, 0xE3, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0xFF, 0xFE,
  0xC0, 0x00, 0x10, 0xE0, 0x00, 0xC1, 0x4B, 0x23, 0xCC, 0x10, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x0C, 0x08, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xDD, 0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xFE,
  0x0E, 0xC2, 0x00, 0xEC, 0x00, 0xC1, 0x2F, 0xFF, 0x0E, 0xC2, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0x3F, 0xDD, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4F, 0xFE,
  0xC0, 0x00, 0x10, 0xE0, 0x00, 0xC1, 0x63, 0x3F, 0xCC, 0x00, 0x00, 0x0C, 0x00, 0x00, 0xFF, 0xFE,
  0xC0, 0x00, 0x10, 0xA0, 0x00, 0x07, 0x4B, 0x9D, 0xCC, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xFE,
  0xC0, 0x00, 0x10, 0xE0, 0x00, 0xC1, 0x61, 0xFF, 0xC0, 0x00, 0x00, 0x0C, 0x00, 0x00, 0xFF, 0xFE,
  0xCC, 0x08, 0x10, 0xE0, 0x00, 0xC1, 0xFB, 0x19, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0xC0, 0x00, 0x10, 0xE0, 0x00, 0xC1, 0x73, 0x9D, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0xCC, 0x08, 0x10, 0xA0, 0x00, 0x07, 0xFB, 0x3F, 0xC0, 0x00, 0x00, 0xAC, 0x00, 0x07, 0xFF, 0xFE,
  0xC0, 0x00, 0x10, 0xE0, 0x00, 0xC1, 0x61, 0xE7, 0xC0, 0x00, 0x00, 0x0C, 0x00, 0x00, 0xFF, 0xFE,
  0xC0, 0x00, 0x10, 0x00, 0x00, 0x00, 0xFC, 0x7E, 0xCC, 0x08, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0xCC, 0x00, 0x10, 0xE0, 0x00, 0xC1, 0xFB, 0xA7, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFB, 0x99, 0xC0, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFC, 0x71, 0xC0, 0x00, 0x08, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFD, 0x5B, 0xC0, 0x00, 0x08, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFC, 0x73, 0xC0, 0x00, 0x08, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFB, 0x3B, 0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xFE,
  0xC0, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFF, 0xF5, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0xAC, 0x10, 0x04, 0xE0, 0x00, 0xC1, 0x62, 0x63, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0xA0, 0x00, 0x04, 0xE0, 0x00, 0xC1, 0xF8, 0xBF, 0x00, 0x00, 0x00, 0xEC, 0x00, 0xC1, 0xFF, 0xFF,
  0xA0, 0x00, 0x04, 0xA0, 0x00, 0x07, 0xFA, 0x7B, 0x00, 0x00, 0x00, 0xAC, 0x00, 0x07, 0xFF, 0xFE,
  0xAC, 0x10, 0x04, 0xE0, 0x00, 0xC1, 0x72, 0xE3, 0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFF, 0xFF,
  0xA0, 0x00, 0x04, 0xEC, 0x00, 0xC1, 0xFA, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0xA0, 0x00, 0x04, 0xE0, 0x00, 0xC1, 0xFA, 0xE3, 0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFF, 0xFF,
  0xAC, 0x10, 0x04, 0xA0, 0x00, 0x07, 0x83, 0x31, 0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xFE,
  0xA0, 0x00, 0x04, 0xE0, 0x00, 0xC1, 0xF9, 0xFB, 0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFF, 0xFF,
  0xAC, 0x10, 0x04, 0x00, 0x00, 0x00, 0x72, 0xE6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0xA0, 0x00, 0x04, 0xEC, 0x00, 0xC1, 0xFB, 0x3F, 0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFF, 0xFF,
  0xA0, 0x00, 0x04, 0xA0, 0x00, 0x07, 0xFA, 0xE7, 0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xFE,
  0xAC, 0x10, 0x04, 0xE0, 0x00, 0xC1, 0x83, 0x3F, 0x00, 0x00, 0x00, 0xEC, 0x00, 0xC1, 0xFF, 0xFF,
  0xA0, 0x00, 0x04, 0xE0, 0x00, 0xC1, 0xF9, 0xE7, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0xFF, 0xFE,
  0xA0, 0x00, 0x04, 0xE0, 0x00, 0xC1, 0xF9, 0x23, 0x00, 0x00, 0x00, 0xEC, 0x00, 0xC1, 0xFF, 0xFF,
  0xAC, 0x10, 0x04, 0xA0, 0x00, 0x07, 0x8B, 0x9D, 0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xFE,
  0xA0, 0x00, 0x04, 0xE0, 0x00, 0xC1, 0xF9, 0xFF, 0x00, 0x00, 0x00, 0xEC, 0x00, 0xC1, 0xFF, 0xFF,
  0xAC, 0x10, 0x04, 0xE0, 0x00, 0xC1, 0x9C, 0x19, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0xA0, 0x00, 0x04, 0xE0, 0x00, 0xC1, 0xFC, 0x7F, 0x00, 0x00, 0x00, 0xEC, 0x00, 0xC1, 0xFF, 0xFF,
  0xA0, 0x00, 0x04, 0xA0, 0x00, 0x07, 0xFC, 0x19, 0x00, 0x00, 0x00, 0xAC, 0x00, 0x07, 0xFF, 0xFE,
  0xAC, 0x10, 0x04, 0xE0, 0x00, 0xC1, 0x8B, 0xB1, 0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFF, 0xFF,
  0xA0, 0x00, 0x04, 0xE0, 0x00, 0xC1, 0xF9, 0xFF, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0xFF, 0xFE,
  0xA0, 0x00, 0x04, 0xE0, 0x00, 0xC1, 0xF9, 0x19, 0x00, 0x00, 0x00, 0xEC, 0x00, 0xC1, 0xFF, 0xFF,
  0xAC, 0x10, 0x04, 0xA0, 0x00, 0x07, 0x83, 0x27, 0x00, 0x00, 0x00, 0xAC, 0x00, 0x07, 0xFF, 0xFE,
  0xA0, 0x00, 0x04, 0xE0, 0x00, 0xC1, 0xFA, 0xE7, 0x00, 0x00, 0x00, 0xEC, 0x00, 0xC1, 0xFF, 0xFF,
  0xAC, 0x10, 0x04, 0x00, 0x00, 0x00, 0x62, 0x62, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xEC, 0x00, 0xC1, 0xFF, 0xFF,
  0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xE3, 0x00, 0x00, 0x00, 0xAC, 0x00, 0x07, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFF, 0xFB, 0x00, 0x00, 0x00, 0xEC, 0x00, 0xC1, 0xFF, 0xFF,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFF, 0xE3, 0x00, 0x00, 0x00, 0xEC, 0x00, 0xC1, 0xFF, 0xFF,
  0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xE1, 0x00, 0x00, 0x00, 0xAC, 0x00, 0x07, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFF, 0xE3, 0x00, 0x00, 0x00, 0xEC, 0x00, 0xC1, 0xFF, 0xFF,
  0xAC, 0x10, 0x04, 0xE0, 0x00, 0xC1, 0x62, 0x63, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0xA0, 0x00, 0x04, 0xE0, 0x00, 0xC1, 0xF8, 0xBF, 0x00, 0x00, 0x00, 0xEC, 0x00, 0xC1, 0xFF, 0xFF,
  0xA0, 0x00, 0x04, 0xA0, 0x00, 0x07, 0xFA, 0x7B, 0x00, 0x00, 0x00, 0xAC, 0x00, 0x07, 0xFF, 0xFE,
  0xAC, 0x10, 0x04, 0xE0, 0x00, 0xC1, 0x72, 0xE3, 0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFF, 0xFF,
  0xA0, 0x00, 0x04, 0xEC, 0x00, 0xC1, 0xFA, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0xA0, 0x00, 0x04, 0xE0, 0x00, 0xC1, 0xFA, 0xE3, 0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFF, 0xFF,
  0xAC, 0x10, 0x04, 0xA0, 0x00, 0x07, 0x83, 0x31, 0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xFE,
  0xA0, 0x00, 0x04, 0xE0, 0x00, 0xC1, 0xF9, 0xFB, 0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFF, 0xFF,
  0xAC, 0x10, 0x04, 0x00, 0x00, 0x00, 0x72, 0xE6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0xA0, 0x00, 0x04, 0xEC, 0x00, 0xC1, 0xFB, 0x3F, 0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFF, 0xFF,
  0xA0, 0x00, 0x04, 0xA0, 0x00, 0x07, 0xFA, 0xE7, 0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xFE,
  0xAC, 0x10, 0x04, 0xE0, 0x00, 0xC1, 0x83, 0x3F, 0x00, 0x00, 0x00, 0xEC, 0x00, 0xC1, 0xFF, 0xFF,
  0xA0, 0x00, 0x04, 0xE0, 0x00, 0xC1, 0xF9, 0xE7, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0xFF, 0xFE,
  0xA0, 0x00, 0x04, 0xE0, 0x00, 0xC1, 0xF9, 0x23, 0x00, 0x00, 0x00, 0xEC, 0x00, 0xC1, 0xFF, 0xFF,
  0xAC, 0x10, 0x04, 0xA0, 0x00, 0x07, 0x8B, 0x9D, 0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xFE,
  0xA0, 0x00, 0x04, 0xE0, 0x00, 0xC1, 0xF9, 0xFF, 0x00, 0x00, 0x00, 0xEC, 0x00, 0xC1, 0xFF, 0xFF,
  0xAC, 0x10, 0x04, 0xE0, 0x00, 0xC1, 0x9C, 0x19, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0xA0, 0x00, 0x04, 0xE0, 0x00, 0xC1, 0xFB, 0xBF, 0x00, 0x00, 0x00, 0xEC, 0x00, 0xC1, 0xFF, 0xFF,
  0xA0, 0x00, 0x04, 0xA0, 0x00, 0x07, 0xF9, 0xD9, 0x00, 0x00, 0x00, 0xAC, 0x00, 0x07, 0xFF, 0xFE,
  0xA0, 0x00, 0x04, 0xE0, 0x00, 0xC1, 0xFC, 0x31, 0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFF, 0xFF,
  0xA0, 0x00, 0x04, 0xE0, 0x00, 0xC1, 0xF9, 0x3F, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0xFF, 0xFE,
  0xA0, 0x00, 0x04, 0xE0, 0x00, 0xC1, 0xFB, 0x99, 0x00, 0x00, 0x00, 0xEC, 0x00, 0xC1, 0xFF, 0xFF,
  0xA0, 0x00, 0x04, 0xA0, 0x00, 0x07, 0xF9, 0xE7, 0x00, 0x00, 0x00, 0xAC, 0x00, 0x07, 0xFF, 0xFE,
  0xA0, 0x00, 0x04, 0xE0, 0x00, 0xC1, 0xFC, 0x27, 0x00, 0x00, 0x00, 0xEC, 0x00, 0xC1, 0xFF, 0xFF,
  0xA0, 0x00, 0x04, 0x00, 0x00, 0x00, 0xF9, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0xA0, 0x00, 0x04, 0xE0, 0x00, 0xC1, 0xFB, 0xBF, 0x00, 0x00, 0x00, 0xEC, 0x00, 0xC1, 0xFF, 0xFF,
  0xA0, 0x00, 0x04, 0xA0, 0x00, 0x07, 0xF9, 0xD9, 0x00, 0x00, 0x00, 0xAC, 0x00, 0x07, 0xFF, 0xFE,
  0xA0, 0x00, 0x04, 0xE0, 0x00, 0xC1, 0xFC, 0x31, 0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0xFF, 0xFF,
  0xA0, 0x00, 0x04, 0xE0, 0x00, 0xC1, 0xF9, 0x3F, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0xFF, 0xFE,
  0xA0, 0x00, 0x04, 0xE0, 0x00, 0xC1, 0xFB, 0x99, 0x00, 0x00, 0x00, 0xEC, 0x00, 0xC1, 0xFF, 0xFF,
  0xA0, 0x00, 0x04, 0xA0, 0x00, 0x07, 0xFA, 0xE7, 0x00, 0x00, 0x00, 0xAC, 0x00, 0x07, 0xFF, 0xFE,
  0xA0, 0x00, 0x04, 0xE0, 0x00, 0xC1, 0xFB, 0x27, 0x00, 0x00, 0x00, 0xEC, 0x00, 0xC1, 0xFF, 0xFF,
  0x00, 0x00, 0x00, 0xEF, 0x04, 0xC1, 0x3F, 0xDD, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4F, 0xFE,
  0xCC, 0x00, 0x10, 0xE0, 0x00, 0xC1, 0xFB, 0x3F, 0xC0, 0x00, 0x00, 0x0C, 0x00, 0x00, 0xFF, 0xFE,
  0xC0, 0x00, 0x10, 0xA0, 0x00, 0x07, 0x63, 0x9D, 0xCC, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xFE,
  0xC0, 0x00, 0x10, 0xE0, 0x00, 0xC1, 0x49, 0xFF, 0xC0, 0x00, 0x00, 0x0C, 0x00, 0x00, 0xFF, 0xFE,
  0xC0, 0x00, 0x10, 0xE0, 0x00, 0xC1, 0xFB, 0x19, 0xCC, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0xC0, 0x00, 0x10, 0xE0, 0x00, 0xC1, 0x3B, 0x9D, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0xCC, 0x08, 0x10, 0xA0, 0x00, 0x07, 0xFB, 0x3F, 0xC0, 0x00, 0x00, 0xAC, 0x00, 0x07, 0xFF, 0xFE,
  0xCE, 0xC2, 0x10, 0xE0, 0x00, 0xC1, 0x01, 0xE7, 0xCE, 0xC2, 0x00, 0x0C, 0x00, 0x00, 0x17, 0xFE,
  0xC0, 0x00, 0x10, 0x00, 0x00, 0x00, 0x2C, 0x7E, 0xCC, 0x10, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0xC0, 0x00, 0x10, 0xE0, 0x00, 0xC1, 0x3B, 0xA7, 0xCC, 0x08, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0xC0, 0x00, 0x10, 0xA0, 0x00, 0x07, 0x4C, 0x63, 0xCC, 0x08, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xFE,
  0xC0, 0x00, 0x10, 0xE0, 0x00, 0xC1, 0x63, 0x9D, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x0C, 0x08, 0x00, 0xE0, 0x00, 0xC1, 0xFF, 0xE3, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0xFF, 0xFE,
  0xC0, 0x00, 0x10, 0xE0, 0x00, 0xC1, 0x4B, 0x23, 0xCC, 0x10, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0x0C, 0x08, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xDD, 0x00, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xFE,
  0x0E, 0xC2, 0x00, 0xEC, 0x00, 0xC1, 0x2F, 0xFF, 0x0E, 0xC2, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xFE,
  0x00, 0x00, 0x00, 0xE0, 0x00, 0xC1, 0x3F, 0xDD, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4F, 0xFE,
  0xC0, 0x00, 0x10, 0xE0, 0x00, 0xC1, 0x63, 0x3F, 0xCC, 0x00, 0x00, 0x0C, 0x00, 0x00, 0xFF, 0xFE,
  0xC0, 0x00, 0x10, 0xA0, 0x00, 0x07, 0x4B, 0x9D, 0xCC, 0x00, 0x00, 0xA0, 0x00, 0x07, 0xFF, 0xFE,
  0xC0, 0x00, 0x10, 0xE0, 0x00, 0xC1, 0x61, 0xFF, 0xC0, 0x00, 0x00, 0x0C, 0x00, 0x00, 0xFF, 0xFE,
  0xCC, 0x08, 0x10, 0xE0, 0x00, 0xC1, 0xFB, 0x19, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0xC0, 0x00, 0x10, 0xE0, 0x00, 0xC1, 0x73, 0x9D, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE,
  0xCC, 0x08, 0x10, 0xA0, 0x00, 0x07, 0xFB, 0x3F, 0xC0, 0x00, 0x00, 0xAC, 0x00, 0x07, 0xFF, 0xFE,
  0xC0, 0x00, 0x10, 0xE0, 0x00, 0xC1, 0x61, 0xE7, 0xC0, 0x00, 0x00, 0x0C, 0x00, 0x00, 0xFF, 0xFE,
};
