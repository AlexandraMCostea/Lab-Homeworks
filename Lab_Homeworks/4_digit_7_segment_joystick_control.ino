const int pinA = 12;
const int pinB = 8;
const int pinC = 5;
const int pinD = 3;
const int pinE = 2;
const int pinF = 11;
const int pinG = 6;
const int pinDP = 4;
const int pinD1 = 7;
const int pinD2 = 9;
const int pinD3 = 10;
const int pinD4 = 13;

const int pinSW = A2; 
const int pinX = A0; 
const int pinY = A1; 

const int segSize = 8;
const int noOfDisplays = 4;
const int noOfDigits = 10;

bool dpState = LOW;
bool swState = LOW;
bool lastSWState = LOW;

int switchValue;
int xValue = 0;
int yValue = 0;

bool joyMoved = false;

int digit = 0;
int nDisplay = 0;
int minThreshold= 400;
int maxThreshold= 600;

int segments[segSize] = { 
  pinA, pinB, pinC, pinD, pinE, pinF, pinG, pinDP
};
//
//int number[noOfDisplays] = {
//  0, 0, 0, 0
//};

int digits[noOfDisplays] = {
  pinD1, pinD2, pinD3, pinD4
};

byte digitMatrix[noOfDigits][segSize - 1] = {
// a b c d e f g
{1, 1, 1, 1, 1, 1, 0}, // 0
{0, 1, 1, 0, 0, 0, 0}, // 1
{1, 1, 0, 1, 1, 0, 1}, // 2
{1, 1, 1, 1, 0, 0, 1}, // 3
{0, 1, 1, 0, 0, 1, 1}, // 4
{1, 0, 1, 1, 0, 1, 1}, // 5
{1, 0, 1, 1, 1, 1, 1}, // 6
{1, 1, 1, 0, 0, 0, 0}, // 7
{1, 1, 1, 1, 1, 1, 1}, // 8
{1, 1, 1, 1, 0, 1, 1} // 9
};

void displayNumber(byte digit, byte decimalPoint) {
  for (int i = 0; i < segSize - 1; i++) {
    digitalWrite(segments[i], digitMatrix[digit][i]);
  }
  digitalWrite(segments[segSize - 1], decimalPoint);
}

void showDigit(int num) {
  for (int i = 0; i < noOfDisplays; i++) {
    digitalWrite(digits[i], HIGH);
  }
  digitalWrite(digits[num], LOW);
}

void setup() {
  pinMode(pinSW, INPUT_PULLUP);
  for (int i = 0; i < segSize - 1; i++) {
    pinMode(segments[i], OUTPUT);
  }
  for (int i = 0; i < noOfDisplays; i++) {
    pinMode(digits[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  swState = digitalRead(pinSW);

  if (swState == HIGH) {
    xValue = analogRead(pinX);
    showDigit(nDisplay);
    if (xValue < minThreshold && joyMoved == false) {
      if (digit > 0) {
        digit--;
        } else {
          digit = 9;
        }
        joyMoved = true;
      }
  
    if (xValue > maxThreshold && joyMoved == false) {
      if (digit < 9) {
        digit++;
      } else {
        digit = 0;
        }
      joyMoved = true;
    }
    
    if (xValue >= minThreshold && xValue <= maxThreshold) {
      joyMoved = false;
    }
  displayNumber(digit, HIGH);
  }

  if (swState == LOW) {  
    yValue = analogRead(pinY);
    if (yValue < minThreshold && joyMoved == false) {
      if (nDisplay > 0) {
        nDisplay--;
        } else {
          nDisplay = 4;
          }
        showDigit(nDisplay);
        joyMoved = true;
      }
  
    if (yValue > maxThreshold && joyMoved == false) {
      if (nDisplay > 0) {
        nDisplay--;
      } else {
        nDisplay = 4;
        }
      showDigit(nDisplay);
      joyMoved = true;
    }
  }
}  
    
