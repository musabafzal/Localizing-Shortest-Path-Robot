#include <Servo.h>

Servo myservo;
int lineSensors[6]={0};
int countlinetrack; 



int boundP(int n, int l,int h){
  if(n<l){
      return l;
  }else{
    if(n>h){
      return h;
      }
    else{
      return n;
      }
   }
  }
void alignOrienWithScienSafe(char orienScien){
  orienScien= oppositeSide(orienScien);
  if(currOrientation=='N'){
    if(orienScien=='N'){
      
    }else if(orienScien=='E'){
        turnRight(1);
    }else if(orienScien=='W'){
      turnLeft(1);
    }else if(orienScien=='S'){
        turnRight(2);
    }
  }else if(currOrientation=='E'){
    if(orienScien=='N'){
      turnLeft(1);
    }else if(orienScien=='E'){
        
    }else if(orienScien=='W'){
      turnRight(2);
    }else if(orienScien=='S'){
        turnRight(1);
    }
  }else if(currOrientation=='W'){
    if(orienScien=='N'){
      turnRight(1);
    }else if(orienScien=='E'){
        turnRight(2);
    }else if(orienScien=='W'){
    
    }else if(orienScien=='S'){
        turnLeft(1);
    }
  }else if(currOrientation=='S'){
    if(orienScien=='N'){
      turnRight(2);
    }else if(orienScien=='E'){
        turnLeft(1);
    }else if(orienScien=='W'){
      turnRight(1);
    }else if(orienScien=='S'){
        
    }
  }
}
void getReadingsFromLineSensors(){
  
    lineSensors[0]=analogRead(A0);
    lineSensors[1]=analogRead(A12);
    lineSensors[2]=analogRead(A13);
    lineSensors[3]=analogRead(A14);
    lineSensors[4]=analogRead(A15);
    lineSensors[5]=analogRead(A5);

    if(lineSensors[0]>800){
      lineSensors[0]=1;
    }else if(lineSensors[0]<800){
      lineSensors[0]=0;
    }
    if(lineSensors[1]<=800){
      lineSensors[1]=1;
    }else if(lineSensors[1]>800){
      lineSensors[1]=0;
    }
    if(lineSensors[2]<=800){
      lineSensors[2]=1;
    }else if(lineSensors[2]>800){
      lineSensors[2]=0;
    }
    if(lineSensors[3]<=800){
      lineSensors[3]=1;
    }else if(lineSensors[3]>800){
      lineSensors[3]=0;
    }
    if(lineSensors[4]<=830){
      lineSensors[4]=1;
    }else if(lineSensors[4]>830){
      lineSensors[4]=0;
    }
    if(lineSensors[5]<=800){
      lineSensors[5]=1;
    }else if(lineSensors[5]>800){
      lineSensors[5]=0;
    }
    if(lineSensors[6]>0){
      lineSensors[6]=1;
    }else if(lineSensors[6]<0){
      lineSensors[6]=0;
    }
}
void printLineSensorsReadings(){
  getReadingsFromLineSensors();
 /*   lineSensors[0]=analogRead(A0);
    lineSensors[1]=analogRead(A12);
    lineSensors[2]=analogRead(A13);
    lineSensors[3]=analogRead(A14);
    lineSensors[4]=analogRead(A15);
    lineSensors[5]=analogRead(A5);*/
    Serial.println();

    Serial.println(lineSensors[0]);
    Serial.println(lineSensors[1]);
    Serial.println(lineSensors[2]);
    Serial.println(lineSensors[3]);
    Serial.println(lineSensors[4]);
    Serial.println(lineSensors[5]);
    Serial.println();
    
}
void lineTrack(){
  countlinetrack++;
    while(1){      
          getReadingsFromLineSensors();
          if(lineSensors[1]==1&&lineSensors[2]==1&&lineSensors[3]==1&&lineSensors[4]==1){
             analogWrite(rightForward,0);
             analogWrite(leftForward,0);
             break;
          }
          else if(lineSensors[2]==1&&lineSensors[3]==1){
             analogWrite(rightForward,50);
             analogWrite(leftForward,50);
          }
          else if(lineSensors[1]==1||lineSensors[2]==1||(lineSensors[1]==1&&lineSensors[2]==1)){
             analogWrite(rightForward,100);
             analogWrite(leftForward,0);
          }
          else if(lineSensors[3]==1||lineSensors[4]==1||(lineSensors[3]==1&&lineSensors[4]==1)){
             analogWrite(rightForward,0);
             analogWrite(leftForward,100);
          }/*else if(lineSensors[1]==0&&lineSensors[2]==0&&lineSensors[3]==0&&lineSensors[4]==0){
              int countturnlinetrack=0;
              do{
                countturnlinetrack++;
                if(countturnlinetrack==1)
                    
                getReadingsFromLineSensors();
                turnRight(3);
              }while(lineSensors[1]==0||lineSensors[2]==0||lineSensors[3]==0||lineSensors[4]==0);
            
          }*/
         

    }
    
  
}
void moveHandUp(){
 for (int pos = 0; pos <= 150; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}
void moveHandDown(){
 for (int pos = 150; pos >= 0; pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}
void pickUpScientist(){
          moveHandDown();
          lineTrack();     
          moveHandUp();
              scientistBackward=0;
    scientistForward=0;
    adjust();
         // setLowerPWM(70);
}
void dropScientist(){
    driveStraightDistance(100, 150, 'f');
    moveHandDown();
    driveStraightDistance(100, 150, 'b');
    moveHandUp();
        scientistBackward=0;
    scientistForward=1;
//    setLowerPWM(70);
}

