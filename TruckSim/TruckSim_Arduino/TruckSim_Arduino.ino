#include <debounce.h>
#include <Keyboard.h>

enum gpioAssignments{
  GPIO_BUTTON_1 = 2,
  GPIO_BUTTON_2,
  GPIO_BUTTON_3,
  GPIO_BUTTON_4,
  GPIO_BUTTON_5,
  GPIO_BUTTON_6,
  GPIO_BUTTON_7, // Indicator 1
  GPIO_BUTTON_8  // Indicator 2
};


enum idAssignments{
  ID_BUTTON_1 = 1,
  ID_BUTTON_2,
  ID_BUTTON_3,
  ID_BUTTON_4,
  ID_BUTTON_5,
  ID_BUTTON_6,
  ID_INDICATOR_1,
  ID_INDICATOR_2
};


bool buttonStates[] = {false, false, false, false, false, false};

static void buttonHandler(uint8_t btnId, uint8_t btnState) {
  if (btnState == BTN_PRESSED) {
    Serial.println((String)"Pushed button " + btnId);
    buttonStates[btnId-1] = true;
    // See https://www.arduino.cc/reference/en/language/functions/usb/keyboard/keyboardmodifiers/
    switch (btnId){
      case ID_BUTTON_1:
        Keyboard.press('i');
      break;
      case ID_BUTTON_2:
        Keyboard.press(',');
      break;
      case ID_BUTTON_3:
        Keyboard.press('.');
      break;
      case ID_BUTTON_4:
        Keyboard.press('/');
      break;
      case ID_BUTTON_5:
        Keyboard.press('`');
      break;
      case ID_BUTTON_6:
      
      break;
      case ID_INDICATOR_1:
        Keyboard.press('[');
      break;
      case ID_INDICATOR_2:
        Keyboard.press(']');
      break;
    }
  } else {
    // btnState == BTN_OPEN.
    Serial.println((String)"Released button " + btnId);
    buttonStates[btnId-1] = false;
    switch (btnId){
      case ID_BUTTON_1:
        Keyboard.release('i');
      break;
      case ID_BUTTON_2:
        Keyboard.release(',');
      break;
      case ID_BUTTON_3:
        Keyboard.release('.');
      break;
      case ID_BUTTON_4:
        Keyboard.release('/');
      break;
      case ID_BUTTON_5:
        Keyboard.release('`');
      break;
      case ID_BUTTON_6:
      
      break;
      case ID_INDICATOR_1:
        Keyboard.release('[');
      break;
      case ID_INDICATOR_2:
        Keyboard.release(']');
      break;
    }
  }
}


static Button buttonOne(ID_BUTTON_1, buttonHandler);
static Button buttonTwo(ID_BUTTON_2, buttonHandler);
static Button buttonThree(ID_BUTTON_3, buttonHandler);
static Button buttonFour(ID_BUTTON_4, buttonHandler);
static Button buttonFive(ID_BUTTON_5, buttonHandler);
static Button buttonSix(ID_BUTTON_6, buttonHandler);
static Button indicatorOne(ID_INDICATOR_1, buttonHandler);
static Button indicatorTwo(ID_INDICATOR_2, buttonHandler);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Keyboard.begin();
  pinMode(GPIO_BUTTON_1, INPUT_PULLUP);
  pinMode(GPIO_BUTTON_2, INPUT_PULLUP);
  pinMode(GPIO_BUTTON_3, INPUT_PULLUP);
  pinMode(GPIO_BUTTON_4, INPUT_PULLUP);
  pinMode(GPIO_BUTTON_5, INPUT_PULLUP);
  pinMode(GPIO_BUTTON_6, INPUT_PULLUP);
  pinMode(GPIO_BUTTON_7, INPUT_PULLUP);
  pinMode(GPIO_BUTTON_8, INPUT_PULLUP);
}


static void pollButtons() {
  // update() will call buttonHandler() if PIN transitions to a new state and stays there
  // for multiple reads over 25+ ms.
  buttonOne.update(digitalRead(GPIO_BUTTON_1));
  buttonTwo.update(digitalRead(GPIO_BUTTON_2));
  buttonThree.update(digitalRead(GPIO_BUTTON_3));
  buttonFour.update(digitalRead(GPIO_BUTTON_4));
  buttonFive.update(digitalRead(GPIO_BUTTON_5));
  buttonSix.update(digitalRead(GPIO_BUTTON_6));
  indicatorOne.update(digitalRead(GPIO_BUTTON_7));
  indicatorTwo.update(digitalRead(GPIO_BUTTON_8));
}


void loop() {
  // put your main code here, to run repeatedly:
  pollButtons(); // Poll your buttons every loop.
  delay(10); // Loop iterations should run fairly quickly, 10's of ms, not 100's.
}
