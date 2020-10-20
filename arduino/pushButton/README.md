# hango-arduino/arduino/pushButton
   * 이 리드미 파일은 푸시 버튼을 설치하고 실행하는데 도움을 주기 위해 작성되었습니다.
  
   1. 준비물   
   푸시 버튼 8개, 1k옴 저항 8개, 전선 24개

   2. 푸시 버튼 설치
   ```c++
   #define PIN_COUNT 8         // 푸시 버튼의 수

   const int PIN[PIN_COUNT] = {2, 3, 4, 5, 6, 7, 8, 9}; 
   ```
   현재 코드에서 사용하는 푸시 버튼은 총 8개로 각각 2,3,4,5,6,7,8,9핀에 연결되어있습니다. 
   
   사진을 참고해 연결하세요.

![푸시버튼](https://user-images.githubusercontent.com/67812466/96615971-f1c33600-133c-11eb-92f4-07f6f6062b95.PNG)
    
   3. pushButton.ino 실행

   푸시버튼을 눌렀을 때 1E, 2E, 3E, 4E, 5E, 6E, 7E, 8E의 숫자가 나오면 정상 작동 입니다. 
