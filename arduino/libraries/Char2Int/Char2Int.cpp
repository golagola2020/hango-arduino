/*
 * hango-arduino
 * Copyright (c) 2020 Golagola
 * MIT License
*/

#include "Arduino.h" 
#include "Char2Int.h"

int char2int(int data){
int sensed_position = 0;
  if (data >= 48 && data <= 58 ) {
        sensed_position = int(data - 48);
      }
  return sensed_position;
}
