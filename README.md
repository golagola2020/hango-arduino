# hango-arduino (행고 아두이노)
> 주의 : [GitHub Pages](https://pages.github.com/)에 대해서 충분히 숙지할 것.  
주의 : [Collaborating with issues and pull requests](https://docs.github.com/en/github/collaborating-with-issues-and-pull-requests)을 정독할 것

## 안내
#### 하드웨어
   1. [아두이노 시작하기](https://github.com/golagola2020/hango-arduino)를 통해 사물을 감지하고, 라즈베리파이로 감지 데이터를 송신할 수 있습니다.
   2. [라즈베리파이 시작하기](https://github.com/golagola2020/hango-raspberry-pi)를 통해 아두이노의 감지 데이터를 수신하고, 데이터를 가공하여 스피커로 출력할 수 있습니다.
   
#### 모바일
   1. [안드로이드 시작하기](https://github.com/golagola2020/hango-mobile)를 통해 hango 자판기를 관리하고, 음료 잔량을 파악하는 등의 데이터를 제공받을 수 있습니다.
   
#### 웹서버
   1. [웹서버 시작하기](https://github.com/golagola2020/hango-server)를 통해 hango-server와 hango-mysql을 구축하고, API 서버를 통해 클라이언트에게 데이터를 제공하며, 고객 관리 시스템을 이용할 수 있습니다.
   
## 시작하기에 앞서
[hango-arduino](https://github.com/golagola2020/hango-arduino) 프로젝트를 실행시키기 위한 프로그램 설치
   1. 이용하고있는 환경에서 최신버전의 [Arduiono IDE](https://www.arduino.cc/en/main/software)가 설치되어있는지 확인.

   1-1. 이미 $ sudo apt-get install arduino로 깔려있다면 아래의 명령어를 통해 제거 
   ```
   $ sudo apt-get --purge remove arduino
   $ sudo apt-get autoremove
   $ sudo apt-get clean
   ```
   2. www.arduino.cc를 방문해 Linux ARM 버전의 설치파일 다운
   (사진)
   3. 압축 해제 및 설치
   ```
   $ cd ~
   $ mkdir Programs
   $ cd ~/Downloads
   $ cp ./arduino-1.8.13-linuxarm.tar.xz ~/arduinoIDE
   $ cd ~/arduinoIDE
   $ tar xvf arduino-1.8.13-linuxarm.tar.xz
   $ cd arduino-1.8.13
   $ ./install.sh
   ```

## 설치(로컬)

* https://github.com/golagola2020/hango-client 에 push 권한이 있다면 :  
   * git fetch or pull or clone
   ```
   $ git clone https://github.com/golagola2020/hango-client.git
   $ cd hango-client/hardware/arduino
   ```

* https://github.com/golagola2020/hango-client 에 push 권한이 없다면 :  
   1. https://github.com/golagola2020/hango-client 에서 ```Fork```버튼 클릭하고,
   2. 포크 저장소 계정(maybe 개인 계정) 선택
   3. git fetch or pull or clone
   ```
   # 포크한 저장소 clone
   $ git clone https://github.com:YOUR_GITHUB_ACCOUNT/hango-raspberry-pi.git
   $ cd hango-server

   # hango-server 레포지터리를 upstream으로 리모트 설정
   $ git remote add upstream https://github.com/golagola2020/hango-raspberry-pi.git
   
   # 로컬 코드와 hango-server 동기화
   $ git fetch upstream
   $ git checkout master
   $ git merge upstream/master
   ```

## 실행(로컬)
> 주의 : 코드가 제대로 실행이 되지 않는다면 각 부품의 연결을 확인해 주세요.
> 주의 : 아두이노 2개를 RX,TX 핀을 통해 UART 통신을 하기 때문에 파일을 실행할 때 적절한 포트로 실행되었는지 확인해 주세요.  
   1. 푸시 버튼 연결
   * 초소형 브레드보드를 이용해 원하는 위치에 맞춰 푸시버튼을 배치한 뒤 연결해줍니다.

   [연결방법](https://github.com/golagola2020/hango-arduino/tree/master/arduino/pushButton)
   ```c++
   #define PIN_COUNT 8   //푸시 버튼의 수
   ```

   2. 터치 센서 연결
   * 쿠킹 호일을 이용한 터치센서 연결

   [연결방법](https://github.com/golagola2020/hango-arduino/tree/master/arduino/capacitive) 
   ```c++
   #include <CapacitiveSensor.h>   

   #define COMMON_PIN      2    // 모든 key에 대한 공통적인'send' pin
   #define NUM_OF_SAMPLES  10   // 읽어들이는 최소 횟수(숫자가 크면 정확도 up)
   #define NUM_OF_KEYS     8    // capacitive sensor의 수
   ```
   3. pushButton.ino와 capacitive.ino 실행
   > 주의 : 두 .ino 파일을 실행 시키기전에 RX,TX가 연결되어 있으면 오류 발생. 
   * .ino 파일을 각각 실행한 뒤 아두이노의 GND를 연결하고 푸시 버튼을 연결한 아두이노의 TX, 터치 센서를 연결한 아두이노의 RX를 연결한다.
    
   

## 배포(발행)

* https://github.com/golagola2020/hango-client 에 push 권한이 있다면 :
```
$ git checkout -b 'features to develop'
$ git commit -m '[features to develop] message...'
$ git push origin 'features to develop'
```

* https://github.com/golagola2020/hango-client 에 push 권한이 없다면 :
   1. 포크 동기화 [Syncing a fork](https://docs.github.com/en/github/collaborating-with-issues-and-pull-requests/syncing-a-fork)
   2. Pull Request 보내기 [Creating a pull request](https://docs.github.com/en/github/collaborating-with-issues-and-pull-requests/creating-a-pull-request) 

## 데모
#### 클라이언트 데모
> v1.0 : https://youtu.be/D2CXURqW8qs
#### 모바일 데모
> v1.0 : https://youtu.be/K7cLH89WKPQ


## 개발 환경

   * Arduino IDE @1.8.13

## 기여하기

[CONTRIBUTING.md](https://github.com/golagola2020/hango-arduino/blob/master/CONTRIBUTING.md) 를 읽으신 후 기여를 해주십시오.     
자세한 Pull Request 절차와 행동 규칙을 확인하실 수 있습니다.

## 개발자

 - **안혜수** [shehdn](https://github.com/suehdn)   

[기여자 목록](https://github.com/golagola2020/hango-client/graphs/contributors)을 확인하여 이 프로젝트에 참가하신 분들을 보실 수 있습니다.
