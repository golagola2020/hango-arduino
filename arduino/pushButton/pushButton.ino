#define PIN_COUNT 8

const int PIN[PIN_COUNT] = {2, 3, 4, 5, 6, 7, 8, 9}; //푸시버튼에 할당된 핀

int sold_position;      //음료수 판매 위치(푸시 버튼이 눌린 곳)
int btn[8];             //각 버튼이 눌렸는지 확인 할 수 있는 array


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
      sold_position = i+1;
      Serial.print(sold_position);
      Serial.print("E");         //1과 11 같은 반복되는 숫자 구분을 위해 추가 (END)
      break;
    }
    
  }
  delay(500);

}
