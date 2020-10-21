#include <CapacitiveSensor.h>

<<<<<<< HEAD
#define COMMON_PIN      2    // 모든 key에 대한 공통적인'send' pin
#define NUM_OF_SAMPLES  10   // 읽어들이는 최소 횟수(숫자가 크면 정확도 up)
#define NUM_OF_KEYS     8    // capacitive sensor의 수

// 각 터치센서에 키 지정
=======
#define COMMON_PIN      2    // The common 'send' pin for all keys
#define NUM_OF_SAMPLES  10   // Higher number whens more delay but more consistent readings
#define NUM_OF_KEYS     8    // Number of keys that are on the keyboard

 // This macro creates a capacitance "key" sensor object for each key on the piano keyboard:
>>>>>>> master
#define CS(Y) CapacitiveSensor(2, Y)
/*
   CapitiveSense Library Demo Sketch
   Paul Badger 2008
   Uses a high value resistor e.g. 10M between send pin and receive pin
   Resistor effects sensitivity, experiment with values, 50K - 50M. Larger resistor values yield larger sensor values.
   Receive pin is the sensor pin - try different amounts of foil/metal on this pin
*/
<<<<<<< HEAD
CapacitiveSensor keys[] = {CS(3), CS(4), CS(5), CS(6), CS(8), CS(9), CS(10), CS(11)};

bool hand_exist = false;   //손의 인식 상태

int sold_position;
int sensed_position;
char serial_touch[3] = {0};
int digit = 1;
int touch;                 //손으로 터치한 capacitive sensor의 위치
int duplicate = 0;               //hand's number counting that touch sensor is sensed
int overlap=0;

void setup()
{
  // 자동으로 수치를 보정해 계산하는 주기를 설정
  for (int i = 0; i < NUM_OF_KEYS; ++i) {
    keys[i].set_CS_AutocaL_Millis(0xFFFFFFFF);
  }

  Serial.begin(9600);

=======
CapacitiveSensor keys[] = {CS(3), CS(4), CS(5), CS(6), CS(7), CS(8), CS(9), CS(10)};
char hand;
bool hand_exist = false;
 
void setup()
{
  // Turn off autocalibrate on all channels:
  for (int i = 0; i < 8; ++i) {
    keys[i].set_CS_AutocaL_Millis(0xFFFFFFFF);
  }
 
  Serial.begin(9600);
 
>>>>>>> master
}

void loop()
{
<<<<<<< HEAD

  for (int i = 0; i < NUM_OF_KEYS; ++i) {

    // 만약 capacitance가 지정한 문턱전압보다 커지면 if문 실행
    if (keys[i].capacitiveSensor(NUM_OF_SAMPLES) > 3000 ) {
      sensed_position = i;    //capacitive sensor가 눌렸을 때
      overlap += 1;
    } 
  }
  if (overlap == 1 || overlap == 0) duplicate = false;
  if (overlap > 1) duplicate = true;

  // rx,tx 통신을 통해 받아오는 push button 값
  for (int i = 0; i < 3 ; i++) { //십의자리 수 까지만 받아옴. (최대 99)

    if (Serial.available()) {                // 배열에 각 자리수의 값을 입력 (char)
      serial_touch[i] = Serial.read();

      if (serial_touch[i] == 'E') {
        serial_touch[i] = 0;
        break;
      }
    }
  }

  sold_position = char_to_int(serial_touch[1]) * 10 + char_to_int(serial_touch[0]) - 1 ;
  
  if (sensed_position >= -1 && sensed_position < NUM_OF_KEYS && sold_position >= -1 && sold_position < NUM_OF_KEYS) {
    Serial.print("success ");
    Serial.println(true);
    Serial.print("duplicate ");
    Serial.println(duplicate);
    Serial.print("sensed_position ");
    Serial.println(sensed_position);
    Serial.print("sold_position ");
    Serial.println(sold_position);
  }

  else {
    Serial.print("success ");
    Serial.println(false);
  }


  for (int i = 0; i < 3 ; i++) {  //serial_touch 초기화 
    serial_touch[i] = 0;
  }
  overlap = 0;
  sensed_position = -1;

=======
  // Loop through each key:
  for (int i = 0; i < 8; ++i) {
    // If the capacitance reading is greater than the threshold, play a note:
    //Serial.print(keys[i].capacitiveSensor(NUM_OF_SAMPLES));
 
    if (keys[i].capacitiveSensor(NUM_OF_SAMPLES) > 2000 ){
        hand = i+49;
        hand = char(hand); //Uart only recognize ascii values.
        hand_exist = true;
      
        Serial.print(hand);
        break;
       }
  }

  hand_exist = false;
  
>>>>>>> master
  delay(500);                             // arbitrary delay to limit data to serial port
}
