#include "Mouse.h"
#include "Keyboard.h"

int clip1 = 9;
int clip2 = 8;
int dirDown = 7;
int dirUp = 6;
int dirLeft = 5;
int dirRight = 4;

int previousClip1State = HIGH; 

//Arcade stick move speed
int range = 10;     

unsigned long timePress = 0;
unsigned long timePressLimit = 0;
// unsigned long timePress1 = 0;
// unsigned long timePressLimit1 = 0;
int clicks1 = 0;
int clicks2 = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(dirDown, INPUT);
  pinMode(dirUp, INPUT);
  pinMode(dirLeft, INPUT);
  pinMode(dirRight, INPUT);
  pinMode(clip1, INPUT);
  pinMode(clip2, INPUT);

  Mouse.begin();
  Keyboard.begin();
  Serial.begin(9600);
}

void loop() {
  // read the buttons:

  int upState = digitalRead(dirUp);

  int downState = digitalRead(dirDown);

  int rightState = digitalRead(dirRight);

  int leftState = digitalRead(dirLeft);

  int clip1State = digitalRead(clip1);

  int clip2State = digitalRead(clip2);


  // // put your main code here, to run repeatedly:
  // if(digitalRead(dirDown) == LOW){
  //   Serial.println("Direction: Down");
  
  // }
  // else if(digitalRead(dirUp) == LOW){
  //   Serial.println("Direction: Up");
  // }
  // else if(digitalRead(dirLeft) == LOW){
  //   Serial.println("Direction: Left");
  // }
  // else if(digitalRead(dirRight) == LOW){
  //   Serial.println("Direction: Right");
  // }
  // else{
  //   Serial.println("Stop");
  // }
  // calculate the movement distance based on the button states:

  int  xDistance = (leftState - rightState) * range ;

  int  yDistance = (upState - downState) * range;

  // if X or Y is non-zero, move:
  if ((xDistance != 0) || (yDistance != 0)) {

    Mouse.move(xDistance, yDistance, 0);

  }
  delay(10);

  

  // //clip1
  // if (clip1State == HIGH){
  //   delay(200);
  //   Serial.println("Button Pressed");
    
  //   if (clicks1 == 0) {
  //   timePress1 = millis();
  //   timePressLimit1 = timePress + 1000;    
  //   clicks1 = 1;
  //   }

  //   else if (clicks1 == 1 && millis() < timePressLimit1){
  //     Serial.println("Button Pressed twice");
     
  //   Keyboard.press('z');
  //   delay(50);
  //   Keyboard.release('z');
  //   delay(1000);
  //  //set variables back to 0
  //     timePress1 = 0;
  //     timePressLimit1 = 0;
  //     clicks1 = 0;      
  //   }
  // }


  // 1
  if (clip1State == HIGH){
    delay(200);
    Serial.println("Button Pressed");
    Keyboard.press('z');
    delay(50);
    Keyboard.release('z');
    delay(1000);
    if (clicks1 == 0) {
    timePress = millis();
    timePressLimit = timePress + 2000;    
    clicks1 = 1;
    }

    else if (clicks1 == 1 && millis() < timePressLimit){
      Serial.println("Button Pressed twice");
     
   
   //set variables back to 0
      timePress = 0;
      timePressLimit = 0;
      clicks1 = 0;      
    }
  }




  //clip2
  if (clip2State == HIGH){
    delay(200);
    Serial.println("Button Pressed");
    Keyboard.press('x');
    delay(50);
    Keyboard.release('x');
    delay(1000);


    if (clicks2 == 0) {
    timePress = millis();
    timePressLimit = timePress + 2000;    
    clicks2 = 1;
    }

    else if (clicks2 == 1 && millis() < timePressLimit){
      Serial.println("Button Pressed twice");
     
    
   //set variables back to 0
      timePress = 0;
      timePressLimit = 0;
      clicks2 = 0;      
    }
  }
 }
