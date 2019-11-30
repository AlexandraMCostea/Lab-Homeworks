#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int V0_PIN = 9;

const int pinSW = 10; 
const int pinX = A0;
const int pinY = A1;

bool switchValue = LOW;
int xValue = 0;
int yValue = 0;

bool joyMoved = false;

int minThreshold= 400;
int maxThreshold= 600;

int startingLevelValue = 0;
int select = 0;
long startTime = 0;
int menu = 0;
int level = 0;
int score = 0;
int highscore = 0;

void setup() {
  Serial.begin(9600);
  pinMode(pinSW, INPUT_PULLUP); 
  pinMode(V0_PIN, OUTPUT); 
  analogWrite(V0_PIN, 90);
  
  lcd.begin(16,2);
  lcd.clear();
}

void loop() {
  xValue = analogRead(pinX);

  if (xValue > maxThreshold && joyMoved == false){
      select++;
      if (select > 2) 
        select = 0;
      joyMoved == true;      
        Serial.println(select);
     
  }
  
  if (xValue < minThreshold && joyMoved == false){
      select--;
      if (select < 0) 
        select = 2;
      joyMoved == true; 
        Serial.println(select);

  }
  
  if (xValue >= minThreshold && xValue <= maxThreshold) {
    joyMoved = false;
  }  

if (menu == 0){
    if (select == 0){
      lcd.setCursor(0, 0);
      lcd.print(">Start          ");
      lcd.setCursor(0, 1);
      lcd.print("HighScore       ");    
    }
  
    if (select == 1){
      lcd.setCursor(0, 0);
      lcd.print("Start           ");
      lcd.setCursor(0, 1);    
      lcd.print(">HighScore      ");
    }
    
    if (select == 2){
      lcd.setCursor(0, 0);
      lcd.print(">Settings       ");    
      lcd.setCursor(0, 1);
      lcd.print("Start           ");
    }
}

yValue = analogRead(pinY);
  
if (yValue < minThreshold && joyMoved == false){
  menu = 1;  
  if (select == 0){
    lcd.setCursor(0, 0);
    lcd.print("                ");
    lcd.setCursor(0, 0);
    lcd.print("Lives 3");
    lcd.setCursor(8, 0);
    lcd.print("Level "); 
    lcd.setCursor(15, 0);
    lcd.print("0"); 
    lcd.setCursor(0,1);
    lcd.print("Score           ");
    lcd.setCursor(8,1);
    lcd.print("0");  
    
    startTime = millis();
    while(millis() - startTime < 10000){
      if (millis() - startTime % 2 == 0){
        level++;
        lcd.setCursor(8, 0);
        lcd.print("Level "); 
        lcd.setCursor(15, 0);
        lcd.print(level); 
        lcd.setCursor(0,1);
        lcd.print("Score        ");
        lcd.setCursor(8,1);
        score = level * 3;
        Serial.println(level);
        lcd.print(score);
      }
    }
    
    if (millis() - startTime == 10000){
      lcd.setCursor(0, 0);
      lcd.print("Congrats!       ");
      lcd.setCursor(0, 1);
      lcd.print("                ");
      if (yValue > maxThreshold && joyMoved == false){ 
         menu = 0;
      }
    }
  }

  if (select == 1){
    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(0, 0);
    lcd.print("Highscore:        ");
    lcd.setCursor(11, 0);
    lcd.print(highscore); 
    if (score > highscore){
      highscore = score;
      lcd.setCursor(0, 0);
      lcd.print("highscore:      ");
      lcd.setCursor(11, 0);
      lcd.print(highscore); 
    }
    if (yValue > maxThreshold && joyMoved == false){ 
        menu = 0;
    }
  }

  if (select == 2){
    lcd.setCursor(0, 1);
    lcd.print("                ");
    startingLevelValue = 0;
    lcd.setCursor(0, 0);
    lcd.print("Select Level:   ");
    lcd.setCursor(15, 0);
    lcd.print(startingLevelValue); 
    
    if (xValue > maxThreshold && joyMoved == false){
      startingLevelValue++;
      joyMoved = true;
    }
    if (xValue > maxThreshold && joyMoved == false){
      if (startingLevelValue > 0)
         startingLevelValue--;
      joyMoved = true;
    }
    if (xValue < maxThreshold && xValue > minThreshold){
       joyMoved = false;
    }    
    if (yValue > maxThreshold && joyMoved == false){           
        lcd.setCursor(15, 0);
        lcd.print(startingLevelValue);
        delay(2000); 
        level = startingLevelValue;
        menu = 0;
    }    
  }
}

if (yValue > maxThreshold && joyMoved == false){ 
   menu = 0;
}

if (yValue >= minThreshold && xValue <= maxThreshold) {
  joyMoved = false;
}  
}
