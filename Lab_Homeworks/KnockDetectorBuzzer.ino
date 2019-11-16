const int activeBuzzerPin = 11;
const int passiveBuzzerPin = A0;
const int pushButtonPin = 2;

int passiveBuzzerValue = 0;
int buttonState = 0;
int buzzerTone = 1000;
int ok = 1;

const int threshold = 1;

void setup() {
  Serial.begin(9600);
  pinMode(activeBuzzerPin, OUTPUT);
  pinMode(passiveBuzzerPin, INPUT);
  pinMode(pushButtonPin, INPUT);
}

void loop() {
  passiveBuzzerValue = analogRead(passiveBuzzerPin);
  buttonState = digitalRead(pushButtonPin);
  
  if (passiveBuzzerValue != 0 && passiveBuzzerValue > threshold) {
    Serial.println(passiveBuzzerValue);
  //  delay(5000);
    tone (activeBuzzerPin, buzzerTone, 500);
    if (buttonState == 1)
      ok = 0;
    if (ok == 0){
      noTone(activeBuzzerPin);
      passiveBuzzerValue = 0;
    }
  }
  ok = 1;
}
