#include <avr/pgmspace.h>
#include <Arduino.h>
#include <avr/io.h>
#include <util/delay.h>
#include "audio1.h"
#include "audio2.h"

const int audioDataSize1 = sizeof(audioData1);
const int audioDataSize2 = sizeof(audioData2);
const int speakerPin = 9; // Pin speaker

void setup() {
    // Mengatur PB1 (pin 9) sebagai output untuk buzzer
    pinMode(speakerPin, OUTPUT);
    
    // Mengatur PD2 (pin 2) sebagai input dengan pull-up resistor
    pinMode(2, INPUT_PULLUP);
    
    // Mengatur PD3 (pin 3) sebagai input dengan pull-up resistor
    pinMode(3, INPUT_PULLUP);
    
    // Inisialisasi komunikasi serial untuk debugging
    Serial.begin(9600);
}

void playAudio(const byte* audioData, int audioDataSize) {
    for (int i = 0; i < audioDataSize; i++) {
        byte audioSample = pgm_read_byte_near(audioData + i);
        analogWrite(speakerPin, audioSample);
        delayMicroseconds(125);  // Delay untuk frekuensi sampling 8 kHz
    }
}

void loop() {
    // Memeriksa tombol di PD2 (pin 2)
    if (digitalRead(2) == LOW) {
        Serial.println("Button 1 pressed");
        playAudio(audioData1, audioDataSize1);
    }
    // Memeriksa tombol di PD3 (pin 3)
    else if (digitalRead(3) == LOW) {
        Serial.println("Button 2 pressed");
        playAudio(audioData2, audioDataSize2);
    }
}

int main(void) {
    init(); // Inisialisasi Arduino core
    setup();
    while (1) {
        loop();
    }
    return 0;
}
