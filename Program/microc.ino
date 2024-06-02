#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include "audio1.h"
#include "audio2.h"

#define ADDR(var)({uint32_t a; asm("ldi %A0, lo8(%1)\n ldi %B0, hi8(%1)\n ldi %C0, hlo8(%1)\n ldi %D0, hhi8(%1)": "=d"(a): "p"(&(var))); a;})

uint32_t sd[4];
short sds[] = {sizeof(data1_chunk1), sizeof(data1_chunk2), sizeof(data2_chunk1), sizeof(data2_chunk2)};
volatile uint16_t index = 0;
volatile uint8_t current_chunk = 0;
volatile uint8_t playing = 0;

ISR(INT4_vect) {
  playing = 1;
  current_chunk = 0;
  index = 0;
}

ISR(INT5_vect) {
  playing = 1;
  current_chunk = 2;
  index = 0;
}

ISR(TIMER1_COMPA_vect) {
  if (playing) {
    uint32_t addr = sd[current_chunk];
    uint16_t size = pgm_read_word(&sds[current_chunk]);

    if (index < size) {
      uint8_t sample = pgm_read_byte_far(ADDR + index);
      OCR1A = sample; // Update PWM duty cycle
      index++;
    } else {
      playing = 0; // Stop playing when the chunk ends
    }
  }
}

int main(void) {
  sd[0] = ADDR(data1_chunk1);
  sd[1] = ADDR(data1_chunk2);
  sd[2] = ADDR(data2_chunk1);
  sd[3] = ADDR(data2_chunk2);

  DDRG |= _BV(DDG5); // Set PG5 as output
  PORTE |= _BV(PE4); // Enable pull-up resistor on PE4
  PORTE |= _BV(PE5); // Enable pull-up resistor on PE5

  // Configure Timer1 for PWM
  // Fast PWM mode, 8-bit
  TCCR1A = (1 << COM1A1) | (1 << WGM10);
  TCCR1B = (1 << WGM12) | (1 << CS10); // No prescaling

  // Enable Output Compare Match A Interrupt
  TIMSK1 |= (1 << OCIE1A);

  EIMSK |= _BV(INT4) | _BV(INT5); // Enable external interrupts INT4 and INT5
  EICRB |= _BV(ISC41) | _BV(ISC40) | _BV(ISC51) | _BV(ISC50); // Rising edge triggers interrupt

  sei(); // Enable global interrupts

  while (1) {
    // Main loop does nothing, ISR handles everything
  }
}
