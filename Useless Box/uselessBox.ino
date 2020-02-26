#include <Servo.h> 
Servo doorServo;
Servo handServo;

int switchPin = 2;               //set switch on pin 2

int pos = 0;
int selectedMove = 0;             //move selector
int Testmove = 0;                 //test mode: set to move number to test only one selected move 
                                  //(set to Zero to run normally i.e: roundrobbin on amm moves)
const int debounce = 100;
unsigned long lastTimeDebounce = 0;  


bool switchValue = LOW;
bool lastSwitchValue = LOW;
bool switchState = LOW;


void setup()
{
  Serial.begin(9600);
  pinMode(switchPin, INPUT);
  doorServo.attach(9);           //set door servo on Pin 9 pwm
  handServo.attach(10);          //set hand servo on Pin 10 pwm
  doorServo.write(80);           //set door to hiding position 
  handServo.write(0);            //set hand to hiding position
}


void loop()
{
if (Testmove != 0) {
selectedMove = Testmove;
}
  //debounce, not needed
  //can be done by hardware too
//  switchValue = digitalRead(switch_pin);
//
//  if ( switchValue != lastSwitchValue){
//    lastTimeDebounce = millis();
//  }
//  
//  if ((millis() - lastTimeDebounce) > debounce){ 
//     if (switchValue != switchState){
//         switchState = switchValue;
//     }
//    }
    
  if (digitalRead(switchPin) == LOW)  {    
    if (selectedMove > 9) { selectedMove = 0; } //when all moves are played, repeat the moves from beginning     
    if (selectedMove == 0) { moveOne(); }
    else if (selectedMove == 1) { moveOne(); }   
    else if (selectedMove == 2) { moveTwo(); }
    else if (selectedMove == 3) { moveThree(); }
    else if (selectedMove == 4) { moveFour(); }
    else if (selectedMove == 5) { moveFive(); }
    else if (selectedMove == 6) { moveSix(); }
    else if (selectedMove == 7) { moveOne(); }
    else if (selectedMove == 8) { moveSeven(); }
    else if (selectedMove == 9) { moveEight(); }
     
    if (Testmove == 0) {
      selectedMove++;         //swith to next move if not in test mode
    }
  }
}



// Library of moves

   void moveOne(){    
      for(pos = 80; pos < 155; pos += 3){                                   
        doorServo.write(pos);              
        delay(15);                       
      }
 
      for(pos = 0; pos < 129; pos += 4) {                                   
        handServo.write(pos);               
        delay(15);                       
      }  
      
      for(pos = 129; pos>=0; pos-=4){                                
        handServo.write(pos);               
        delay(15);                        
      } 

      for(pos = 155; pos>=80; pos-=3){                                
        doorServo.write(pos);              
        delay(15);                      
      } 
   } 
     
    void moveTwo(){
      for(pos = 80; pos < 155; pos += 3){                                   
        doorServo.write(pos);              
        delay(15);                       
      }
     
      delay(800); 
      
      for(pos = 0; pos < 100; pos += 4){                                   
        handServo.write(pos);               
        delay(15);                       
      }
     
      delay(1000); 
      for(pos = 100; pos < 129; pos += 4){                                   
        handServo.write(pos);               
        delay(15);                       
      }    
      
      for(pos = 129; pos>=0; pos-=5){                                
        handServo.write(pos);               
        delay(15);                        
      } 
        
      for(pos = 155; pos>=80; pos-=3){                                
        doorServo.write(pos);              
        delay(15);                    
      } 
    }
  
  
   void moveThree(){

    for(pos = 80; pos < 125; pos += 3){                                   
      doorServo.write(pos);              
      delay(15);                       
    }
  
    for(pos = 125; pos>=80; pos-=5){                                
      doorServo.write(pos);              
      delay(15);                      
    } 

    for(pos = 80; pos < 110; pos += 3){                                   
      doorServo.write(pos);              
      delay(15);                       
    }
  
    for(pos = 110; pos>=80; pos-=15){                                
      doorServo.write(pos);              
      delay(15);                      
    } 
    
    delay(700);

    for(pos = 80; pos < 125; pos += 3){                                   
      doorServo.write(pos);              
      delay(15);                       
    }
    
    delay(700);
    
    for(pos = 125; pos>=80; pos-=5){                                
      doorServo.write(pos);              
      delay(15);                      
    } 

    for(pos = 80; pos < 155; pos += 8){                                   
      doorServo.write(pos);              
      delay(15);                       
    }
   
    for(pos = 0; pos < 129; pos += 3){                                   
      handServo.write(pos);               
      delay(15);                       
    }  

    for(pos = 129; pos>=0; pos-=3){                                
      handServo.write(pos);               
      delay(15);                        
    } 
      
    for(pos = 155; pos>=80; pos-=15){                                
      doorServo.write(pos);              
      delay(15);                      
    }    
  }   


 void moveFour(){
    for(pos = 80; pos < 155; pos += 1){                                   
      doorServo.write(pos);              
      delay(30);                       
    }
   
    for(pos = 0; pos < 129; pos += 1){                                   
      handServo.write(pos);               
      delay(30);                       
    }  

    for(pos = 129; pos>=0; pos-=1){                                
      handServo.write(pos);               
      delay(30);                        
    } 
      
    for(pos = 155; pos>=125; pos-=1){                                
      doorServo.write(pos);              
      delay(30);                      
    }
    
    delay(100);
    
    for(pos = 125; pos>=80; pos-=4){                                
      doorServo.write(pos);              
      delay(15);                      
    }     
 }
 
 void moveFive() {
    for(pos = 80; pos < 155; pos += 3){                                   
      doorServo.write(pos);              
      delay(15);                       
    }
     
    for(pos = 0; pos < 70; pos += 1){                                   
      handServo.write(pos);               
      delay(15);                       
    }
    
    delay(800);
    
    for(pos = 155; pos>=130; pos-=3){                                
      doorServo.write(pos);              
      delay(15); 
    }
    
    for(pos = 130; pos < 155; pos+=3){                                
      doorServo.write(pos);              
      delay(15); 
    } 

    for(pos = 155; pos>=130; pos-=3){                                
      doorServo.write(pos);              
      delay(15); 
    }   
 
    for(pos = 130; pos < 155; pos+=3){                                
      doorServo.write(pos);              
      delay(15); 
    } 
     
    handServo.write(40);
    
    delay(1000);
      
    for(pos = 40; pos < 129; pos += 4){                                   
      handServo.write(pos);               
      delay(15);                       
    } 
    
    for(pos = 129; pos>=0; pos-=4){                                
      handServo.write(pos);               
      delay(15);                        
    } 
     
    for(pos = 120; pos>=80; pos -= 1){                                   
      doorServo.write(pos);              
      delay(15);                       
    }   
} 

void moveSix(){
    for(pos = 80; pos < 155; pos += 3){                                   
      doorServo.write(pos);              
      delay(15);                       
    }
   
    for(pos = 0; pos < 127; pos += 4){                                   
      handServo.write(pos);               
      delay(15);                       
    }

    for(pos = 155; pos>=130; pos-=3){                                
      doorServo.write(pos);              
      delay(15);                      
    }  
     
    delay(2000);
    
    for(pos = 130; pos < 155; pos += 3){                                   
      doorServo.write(pos);              
      delay(15);                       
    }
    
    for(pos = 155; pos>=140; pos-=3){                                
      doorServo.write(pos);              
      delay(15);
    }
    
    for(pos = 140; pos < 155; pos += 3){                                   
      doorServo.write(pos);              
      delay(15);                       
    }
    
    delay(500);

    for(pos = 127; pos>=0; pos-=4){                                
      handServo.write(pos);               
      delay(15);                        
    } 
      
    for(pos = 155; pos>=80; pos-=3){                                
      doorServo.write(pos);              
      delay(15);                      
    } 
}
   
void moveSeven(){
    for(pos = 80; pos < 155; pos += 3){                                   
      doorServo.write(pos);              
      delay(15);                       
    }
   
    for(pos = 0; pos < 80; pos += 4){                                   
      handServo.write(pos);               
      delay(15);                       
    }
    
    for(pos = 80; pos < 129; pos += 1){                                   
      handServo.write(pos);               
      delay(30);                       
    }  
    
    delay(300);
    
    for(pos = 129; pos>=0; pos-=4){                                
      handServo.write(pos);               
      delay(10);                        
    } 
      
    for(pos = 155; pos>=80; pos-=3){                                
      doorServo.write(pos);              
      delay(15);                      
    } 
  
}

void moveEight(){    
    for(pos = 80; pos < 130; pos += 1){                                   
      doorServo.write(pos);              
      delay(30);                       
    }
    
    delay(2000);
    
    for(pos = 0; pos < 40; pos += 1){                                   
      handServo.write(pos);               
      delay(30);                       
    }  
        
    delay(500);
    
    for(pos = 130; pos < 155; pos += 4){                                   
      doorServo.write(pos);              
      delay(15);                       
    }
    
    delay(100);
    
    for(pos = 40; pos < 90; pos += 4){                                   
      handServo.write(pos);                
      delay(15);                       
    }  
    
    delay(500);

    for(pos = 90; pos>=70; pos-=4){                                
      handServo.write(pos);               
      delay(15);                        
    }
    
    delay(100);
    
    for(pos = 70; pos < 90; pos += 4){                                   
      handServo.write(pos);               
      delay(15);                       
    }
    
    delay(100);
    
    for(pos = 90; pos>=70; pos-=4){                                
      handServo.write(pos);               
      delay(15);                        
    }
    
    delay(100);
       
    for(pos = 70; pos < 129; pos += 4){                                   
      handServo.write(pos);               
      delay(15);                       
    }
    
    for(pos = 129; pos>=0; pos-=4){                                
      handServo.write(pos);               
      delay(15);                        
    }    

    for(pos = 155; pos>=80; pos-=3){                                
      doorServo.write(pos);              
      delay(15);                      
    } 
   } 
   
