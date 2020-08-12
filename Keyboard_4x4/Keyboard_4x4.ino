#include <Keypad.h>
#include <Keyboard.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
//byte rowPins[ROWS] = {3, 2, 1, 0}; //connect to the row pinouts of the keypad
//byte colPins[COLS] = {7, 6, 5, 4}; //connect to the column pinouts of the keypad
byte rowPins[ROWS] = {2, 3, 4, 5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6, 7, 8, 9}; //connect to the column pinouts of the keypad


//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  //Serial.begin(9600);
  Keyboard.begin();
}

void sendMacroNum(uint8_t key) {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(key);
}
void sendMacroChar(uint8_t key) {
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(key);
}

  
void loop(){
  char customKey = customKeypad.getKey();

  switch(customKey){
    case '1':
      sendMacroNum(KEY_F13);
      break;
    case '2':
      sendMacroNum(KEY_F14);
      break;
    case '3':
      sendMacroNum(KEY_F15);
      break;
    case '4':
      sendMacroNum(KEY_F16);
      break;
    case '5':
      sendMacroNum(KEY_F17);
      break;
    case '6':
      sendMacroNum(KEY_F18);
      break;
    case '7':
      sendMacroNum(KEY_F19);
      break;
    case '8':
      sendMacroNum(KEY_F20);
      break;
    case '9':
      sendMacroNum(KEY_F21);
      break;
    case '*':
      sendMacroNum(KEY_F22);
      break;
    case '0':
      sendMacroNum(KEY_F23);
      break;
    case '#':
      sendMacroNum(KEY_F24);
      break;
    case 'A':
      sendMacroChar(KEY_F13);
      break;
    case 'B':
      sendMacroChar(KEY_F14);
      break;
    case 'C':
      sendMacroChar(KEY_F15);
      break;
    case 'D':
      sendMacroChar(KEY_F16);
      break;
  }
  Keyboard.releaseAll(); // this releases the buttons
}
