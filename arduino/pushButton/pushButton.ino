#define PIN_COUNT 8

const int PIN[PIN_COUNT] = {2, 3, 4, 5, 6, 7, 8, 9};

int sold_position;
int sensed_position;
int btn[8];
char serial_touch[2] = {0};
int digit = 1;
int touch;



void setup() {
  //시리얼 통신을 설정(전송속도 9600bps)
  Serial.begin(9600);
  for (int i = 0; i < PIN_COUNT; i++) {
    pinMode(PIN[i] , INPUT);
  }
}

void loop() {
  
  // push button의 상태를 나타내는 for문
  for (int i = 0; i < PIN_COUNT; i++) {
    btn[i] = digitalRead(PIN[i]);
    if (btn[i] == 0) {        // push button이 눌렸을때
      sold_position = i;
      break;
    }
    else sold_position = -1;  // push button이 눌리지 않았을 때
  } 

  // rx,tx 통신을 통해 받아오는 터치센서 값 
  if ( digit == -1 ) digit = 1;
  if (Serial.available()) {                // 배열에 각 자리수의 값을 입력 (char)
    serial_touch[digit] = Serial.read();
    Serial.println(digit);
    Serial.println(int (serial_touch[digit]));
    digit--;
  }

  touch = char_to_int(serial_touch[1])*10 + char_to_int(serial_touch[0]);
  Serial.print (" touch :");
  Serial.println(touch);
    /*
    if (data >= 49 && data <= 56 ) {
      sensed_position = int(data - 49);
    }
    */
  
/*
  else {
    sensed_position = -1;
  }


  Serial.print("success ");
  Serial.println(true);
  Serial.print("sensed_position ");
  Serial.println(sensed_position);
  Serial.print("sold_position ");
  Serial.println(sold_position);
  */
  touch = 0;
  delay(500);

}
