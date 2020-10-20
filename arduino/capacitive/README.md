# hango-arduino/arduino/capacitive
   * 이 리드미 파일은 터치 센서를 설치하고 실행하는데 도움을 주기 위해 작성되었습니다.

   1. 준비물
   쿠킹 호일(적당한 크기로 8등분), 4.7MΩ 저항 8개, 전선 16개
     -저항은 1 MΩ 에서 4.7 MΩ 사이의 어떤 저항이던 사용 가능.
   
   arduino IDE에서 '라이브러리포함하기'를 통해 CapacitiveSensor.h를 다운로드 받아 놓습니다.
  
   2. 터치 센서 설치
   ```c++
   #include <CapacitiveSensor.h>

   #define COMMON_PIN      2    // 모든 key에 대한 공통적인'send' pin
   #define NUM_OF_SAMPLES  10   // 읽어들이는 최소 횟수(숫자가 크면 정확도 up)
   #define NUM_OF_KEYS     8    // capacitive sensor의 수

   // 각 터치센서에 키 지정
   #define CS(Y) CapacitiveSensor(2, Y)

   CapacitiveSensor keys[] = {CS(3), CS(4), CS(5), CS(6), CS(8), CS(9), CS(10), CS(11)};
   ```
   현재 코드에서 사용하는 터치 센서는 총 8개로 각각 3,4,5,6,8,9,10,11핀에 연결되어 있습니다.
   모든 터치 센서에 대한 공통적인 전송핀은 2번핀에 연결됩니다.

- 전체적인 구조
![터치센서](https://user-images.githubusercontent.com/67812466/96615979-f4259000-133c-11eb-9b72-0a9786593e91.PNG)
- X 모양의 부위는 서로 연결되었다는 뜻(납땜)

- 납땜 방식
![납땜](https://user-images.githubusercontent.com/67812466/96612452-ba528a80-1338-11eb-9885-7bc12c7d2b5c.png)

- 터치센서 쿠킹 호일과 연결하는 법
![터치센서만들기](https://user-images.githubusercontent.com/67812466/96615124-dd326e00-133b-11eb-84cb-f929c6f1a710.PNG)
   
   1) 쿠킹호일을 3,4,5,6,8,9,10,11번 핀과 연결하는 전선중 하나와 연결된 저항의 다리로 통과시킨다.
 
   2) 쿠킹호일과 통과시킨 저항을 밀착시킨다.(밀착되지 않으면 제대로 동작 x)

   3) 쿠킹호일을 절연테이프로 고정한다.

   완성된 모습은 위의 '전체적인 구조' 사진과 같습니다.

   3. captest.ino 파일 실행을 통한 정상 동작 확인

   captest.ino를 통해 터치센서가 제대로 동작하는지 확인할 수 있습니다.
   
   Tool의 Serial Moniter를 켜면
![캡처1](https://user-images.githubusercontent.com/67812466/96619551-449eec80-1341-11eb-98f3-4e6ba00486ea.PNG)
터치센서를 누르지 않았을 때
![캡처2](https://user-images.githubusercontent.com/67812466/96619556-47014680-1341-11eb-9586-329a28cd106f.PNG)
터치센서를 눌렀을 때 
두가지 상황을 쉽게 볼 수 있습니다.

   4. Uart통신 준비

   [pushButton](https://github.com/golagola2020/hango-arduino/tree/arduino/readme/arduino/pushButton)의 README.md를 참고해 설치해놓았던
   푸시 버튼과 RX,TX핀으로 통신을 할 것입니다.

    pushButton의 아두이노의 TX핀과 Capacitive의 아두이노의 RX핀을 연결할 준비를 합니다. (아직 연결하지마세요)

   5. capacitive.ino 실행 
   
   capacitive.ino와 pushButton.ino가 모두 정상적으로 실행되었다면 이제 아두이노의 TX핀과 Capacitive의 아두이노의 RX핀을 연결합니다.

   시리얼 모니터에 출력이 아래의 방식처럼 나오게 됩니다.
   ```c++
   success 1
   duplicate 0
   sensed_position -1
   sold_position -1
   ```
 
   푸시 버튼을 눌렀을 때는 sold_position이 변하고, 터치 센서를 눌렀을 때는 sensed_position이 변하게 됩니다.
   두 변수 모두 -1 ~ 7 사이의 값으로 나옵니다.

   각 버튼을 눌러보며 정상 작동하는지 확인해주세요. 
  
