#include <Char2Int.h>
#include <CapacitiveSensor.h>


#define COMMON_PIN      2    // 모든 key에 대한 공통적인'send' pin
#define NUM_OF_SAMPLES  10   // 읽어들이는 최소 횟수(숫자가 크면 정확도 up)
#define NUM_OF_KEYS     8    // capacitive sensor의 수

#define CS(Y) CapacitiveSensor(2, Y) //각 터치 센서에의 키 지정 

CapacitiveSensor keys[] = {CS(11), CS(10), CS(9), CS(8), CS(6), CS(5), CS(4), CS(3)};

bool hand_exist = false;     //손의 인식 상태

int sold_position;           //음료수 판매 위치(푸시 버튼이 눌린 곳)
int sensed_position = -1;         //인식된 터치 센서 위치
char serial_touch[3] = {0};  //char형으로 받아진 시리얼을 99까지 처리하기 위한 array
int overlap=0;               //감지된 터치 센서의 수 
int duplicate = 0;           //overlap이 0 혹은 1이면 true, 그렇지않으면 false

 
void setup()
{
  // Turn off autocalibrate on all channels:
  for (int i = 0; i < NUM_OF_KEYS; ++i) {
    keys[i].set_CS_AutocaL_Millis(0xFFFFFFFF);
  }
 
  Serial.begin(9600);
 
}

void loop()
{

  for (int i = 0; i < NUM_OF_KEYS; ++i) {

    // 만약 capacitance가 지정한 문턱전압보다 커지면 if문 실행
    if (keys[i].capacitiveSensor(NUM_OF_SAMPLES) > 5000 ) {
      sensed_position = i;    //capacitive sensor가 눌렸을 때
      overlap += 1;
    } 
  }
  if (overlap == 1 || overlap == 0) 
    duplicate = false;
  if (overlap > 1) 
    duplicate = true;

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

  sold_position = char2int(serial_touch[1]) * 10 + char2int(serial_touch[0]) - 1 ;
  
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


  //변수 초기화 
  for (int i = 0; i < 3 ; i++) {  //serial_touch 초기화 
    serial_touch[i] = 0;
  }
  overlap = 0;
  sensed_position = -1;

  delay(500);                             // arbitrary delay to limit data to serial port
}
