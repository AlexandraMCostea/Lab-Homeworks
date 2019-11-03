const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;
const int redIn = 0; 
const int greenIn = 1; 
const int blueIn = 2; 
int redVal; 
int greenVal; 
int blueVal; 

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(redIn, INPUT);
  pinMode(greenIn, INPUT);
  pinMode(blueIn,INPUT);
  Serial.begin(9600);
}

void loop() { 
redVal = analogRead(redIn); 
greenVal = analogRead(greenIn); 
blueVal = analogRead(blueIn); 
redVal = map(redVal, 0, 1023, 0, 255); 
greenVal = map(greenVal, 0, 1023, 0, 255); 
blueVal = map(blueVal, 0, 1023, 0, 255); 
setColor(redVal, greenVal, blueVal);
}

void setColor(int redVal, int greenVal, int blueVal){
analogWrite(redPin, redVal); 
analogWrite(greenPin, greenVal); 
analogWrite(bluePin, blueVal); 
}
