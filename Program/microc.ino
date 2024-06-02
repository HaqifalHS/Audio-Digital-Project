#include <avr/io.h>
#include <util/delay.h>
#include <avr/pgmspace.h>
#include "audio1.h"
#include "audio2.h"

#define AUDIO_PIN PG5
#define BUTTON1_PIN PE4
#define BUTTON2_PIN PE5

void setupPWM() {
  // Set AUDIO_PIN as output
  DDRG |= _BV(AUDIO_PIN);
  
  // Configure Timer1 for PWM
  // Fast PWM mode, 8-bit
  TCCR1A = (1 << COM1A1) | (1 << WGM10);
  TCCR1B = (1 << WGM12) | (1 << CS10); // No prescaling
}

void playAudio(const unsigned char* audioData, int dataSize) {
  for (int i = 0; i < dataSize; i++) {
    // Read the audio sample from flash memory
    unsigned char sample = pgm_read_byte(&audioData[i]);
    // Set the PWM duty cycle
    OCR1A = sample;
    // Delay to control sample rate (e.g., 8kHz)
    _delay_us(125); // Adjust this value based on the desired sample rate
  }
}

int main(void) {
  // Set up buttons as input with pull-up resistors
  DDRE &= ~(_BV(BUTTON1_PIN) | _BV(BUTTON2_PIN));
  PORTE |= (_BV(BUTTON1_PIN) | (_BV(BUTTON2_PIN)));

  // Set up PWM for audio output
  setupPWM();

  while (1) {
    // Check if button 1 is pressed
    if (!(PINE & _BV(BUTTON1_PIN))) {
      playAudio(audio1, sizeof(audio1));
    }
    // Check if button 2 is pressed
    if (!(PINE & _BV(BUTTON2_PIN))) {
      playAudio(audio2, sizeof(audio2));
    }
  }
}