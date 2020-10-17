#include <CapacitiveSensor.h>

#define COMMON_PIN      2    // 모든 key에 대한 공통적인'send' pin
#define NUM_OF_SAMPLES  10   // 읽어들이는 최소 횟수(숫자가 크면 정확도 up)
#define NUM_OF_KEYS     8    // 터치 센서의 수

 // 각 터치센서에 키 지정
#define CS(Y) CapacitiveSensor(2, Y)
/*
   CapitiveSense Library Demo Sketch
   Paul Badger 2008
   Uses a high value resistor e.g. 10M between send pin and receive pin
   Resistor effects sensitivity, experiment with values, 50K - 50M. Larger resistor values yield larger sensor values.
   Receive pin is the sensor pin - try different amounts of foil/metal on this pin
*/
CapacitiveSensor keys[] = {CS(3), CS(4), CS(5), CS(6)}; //CS(7), CS(8), CS(9), CS(10)};
int touch;                 //손으로 터치한 터치센서의 위치
bool hand_exist = false;   //손의 인식 상태
 
void setup()
{
  // 자동으로 수치를 보정해 계산하는 주기를 설정
  for (int i = 0; i < 4; ++i) {
    keys[i].set_CS_AutocaL_Millis(0xFFFFFFFF);
  }
 
  Serial.begin(9600);
 
}

void loop()
{

  for (int i = 0; i < 4; ++i) {
    
    // 만약 capacitance가 지정한 문턱전압보다 커지면 if문 실행
    if (keys[i].capacitiveSensor(NUM_OF_SAMPLES) > 500 ){
        touch = i;        
        /*
         * Uart 통신은 char 형식의 데이터인 
         */
        //hand = char(hand); //Uart only recognize ascii values.
        
        hand_exist = true;
      
        Serial.print(touch);
        break;
       }
  }

  hand_exist = false;
  
  delay(500);                             // arbitrary delay to limit data to serial port
}
