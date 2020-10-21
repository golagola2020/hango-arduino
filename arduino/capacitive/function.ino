//char -> int 범위 : 0 ~ 9
//Uart only recognize ascii values
int char_to_int(char data){
  int sensed_position = 0;
  if (data >= 48 && data <= 58 ) {
        sensed_position = int(data - 48);
      }
  return sensed_position;
}
