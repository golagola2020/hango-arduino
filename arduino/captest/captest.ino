/*
 * hango-arduino
 * Copyright (c) 2020 Golagola
 * MIT License
 * 
 * 이 코드는 capacitive.ino를 하기 전 터치 센서의 작동을 확인하기 위한 코드입니다.
*/

#include <CapacitiveSensor.h>
 
#define COMMON_PIN      2    // The common 'send' pin for all keys
#define NUM_OF_SAMPLES  10   // Higher number whens more delay but more consistent readings
#define CAP_THRESHOLD   150  // Capactive reading that triggers a note (adjust to fit your needs)
#define NUM_OF_KEYS     8    // Number of keys that are on the keyboard
 
// This macro creates a capacitance "key" sensor object for each key on the piano keyboard:
#define CS(Y) CapacitiveSensor(2, Y)
 
// Defines the pins that the keys are connected to:
CapacitiveSensor keys[] = {CS(3), CS(4), CS(5), CS(6), CS(8), CS(9), CS(10), CS(11)};
 
void setup() {
  // Turn off autocalibrate on all channels:
  for (int i = 0; i < NUM_OF_KEYS ; ++i) {
    keys[i].set_CS_AutocaL_Millis(0xFFFFFFFF);
  }
 
  Serial.begin(9600);
}
 
void loop() {
  
  // Loop through each key:
  for (int i = 0; i < NUM_OF_KEYS ; ++i) {
    // If the capacitance reading is greater than the threshold, play a note:
    Serial.print(keys[i].capacitiveSensor(NUM_OF_SAMPLES));
    if (i != NUM_OF_KEYS -1) {
      Serial.print(",");
    } else {
      Serial.println();
    }
  }
}
