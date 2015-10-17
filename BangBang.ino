/*
Bang Bang input

*/

const int pinGlovebox = A1;
const int pinGun = 2;
const int pinPapers = A0;
const int pinRadio = 3;

int previousStateGlovebox = HIGH;
int previousStateGun = HIGH;
int previousStatePapers = HIGH;
int previousStateRadio = HIGH;

const int keyGlovebox = (int) 'g';
const int keyGun = (int) 's';
const int keyPapers = (int) 'p';
const int keyRadio = (int) 'r';

void setup() {
  Serial.begin(9600);
  while (!Serial)
  {
    // do nothing
  };
  pinMode(pinGlovebox, INPUT);
  pinMode(pinGun, INPUT);
  pinMode(pinPapers, INPUT);
//  pinMode(pinRadio, INPUT);

  Keyboard.begin();
}

void loop() {
  // check glovebox -- ANALOG
  int stateGlovebox = previousStateGlovebox;
  int valueGlovebox = analogRead(pinGlovebox);
  Serial.println("glovebox: ");
  Serial.println(valueGlovebox);

  if (valueGlovebox > 500) {
    stateGlovebox = HIGH;
  } else {
    stateGlovebox = LOW;
  }
  if ((stateGlovebox != previousStateGlovebox)) {
    if (stateGlovebox == HIGH) {
      Keyboard.press(keyGlovebox);
      previousStateGlovebox = HIGH;
    } else {
      Keyboard.release(keyGlovebox);
      previousStateGlovebox = LOW;
    }
  }

  // check papers -- ANALOG
  int statePapers = previousStatePapers;
  int valuePapers = analogRead(pinPapers);
//  Serial.println("papers: ");
//  Serial.println(valuePapers);
  if (valuePapers > 500) {
    statePapers = HIGH;
  } else {
    statePapers = LOW;
  }
  if ((statePapers != previousStatePapers)) {
    if (statePapers == HIGH) {
      Keyboard.press(keyPapers);
      previousStatePapers = HIGH;
    } else {
      Keyboard.release(keyPapers);
      previousStatePapers = LOW;
    }
  }

//  // check gun
//  int stateGun = digitalRead(pinGun);
//  if ((stateGun != previousStateGun)) {
//    if (stateGun == HIGH) {
//      Keyboard.press(keyGun);
//      previousStateGun = HIGH;
//      Serial.println("gun pressed ");
//    } else {
//      Keyboard.release(keyGun);
//      previousStateGun = LOW;
//      Serial.println("gun released ");
//    }
//  }

//  // check radio
//  int stateRadio = digitalRead(pinRadio);
//  if ((stateRadio != previousStateRadio)) {
//    if (stateRadio == HIGH) {
//      Keyboard.press(keyRadio);
//      previousStateRadio = HIGH;
//    } else {
//      Keyboard.release(keyRadio);
//      previousStateRadio = LOW;
//    }
//  }
  
  delay(33);
}
