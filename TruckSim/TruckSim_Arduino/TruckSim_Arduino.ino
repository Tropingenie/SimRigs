#include <debounce.h>

enum pin_names{
  BUTTON_1 = 2,
  BUTTON_2,
  BUTTON_3,
  BUTTON_4,
  BUTTON_5,
  BUTTON_6
};


static void buttonHandler(uint8_t btnId, uint8_t btnState) {
  if (btnState == BTN_PRESSED) {
    Serial.println((String)"Pushed button " + btnId);
  } else {
    // btnState == BTN_OPEN.
    Serial.println((String)"Released button " + btnId);
  }
}


static Button buttonOne(1, buttonHandler);
static Button buttonTwo(2, buttonHandler);
static Button buttonThree(3, buttonHandler);
static Button buttonFour(4, buttonHandler);
static Button buttonFive(5, buttonHandler);
static Button buttonSix(6, buttonHandler);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(BUTTON_1, INPUT_PULLUP);
  pinMode(BUTTON_2, INPUT_PULLUP);
  pinMode(BUTTON_3, INPUT_PULLUP);
  pinMode(BUTTON_4, INPUT_PULLUP);
  pinMode(BUTTON_5, INPUT_PULLUP);
  pinMode(BUTTON_6, INPUT_PULLUP);
}


static void pollButtons() {
  // update() will call buttonHandler() if PIN transitions to a new state and stays there
  // for multiple reads over 25+ ms.
  buttonOne.update(digitalRead(BUTTON_1));
  buttonTwo.update(digitalRead(BUTTON_2));
  buttonThree.update(digitalRead(BUTTON_3));
  buttonFour.update(digitalRead(BUTTON_4));
  buttonFive.update(digitalRead(BUTTON_5));
  buttonSix.update(digitalRead(BUTTON_6));
}


void loop() {
  // put your main code here, to run repeatedly:
  pollButtons(); // Poll your buttons every loop.
  delay(10); // Loop iterations should run fairly quickly, 10's of ms, not 100's.
}
