#include <I2Cdev.h>

float g_turnTarget = 0.0;
bool  g_turnEnabled = false;
float g_turnTolerance = 0;    //needs to be tuned
float g_turnKp = 2.22;             //needs to be tuned
float g_driveTarget = 0.0;
bool  g_driveEnabled = false;
float g_driveTolerance = 0;


//PID
int countturn=0;
int countmove=0;
int lowerPWM=70;

void setLowerPWM(int n){
  lowerPWM=n;
}


int bound(int n, int l, int h) {
  if (n < l) {
    return l;
  } else {
    if (n > h) {
      return h;
    }
    else {
      return n;
    }
  }
}

void SetTurnTarget(float angle)         //This is saying unreferenced function
{
  g_turnTarget = angle;
  g_turnEnabled = true;
}
void SetDriveTarget(float clicks) {
  g_driveTarget = clicks;
  g_driveEnabled = true;
}
void moveRightMotor(int tP) {
  if (tP >= 0) {
    //        tP=tP*255;
    //   tP=tP/50;
    analogWrite(rightForward, tP);
  }
  else {
    tP = tP * -1;
    //       tP=tP*255;
    // tP=tP/50;
    analogWrite(rightBackward, tP);
  }
  //  Serial.println(tP);
}
void moveLeftMotor(int tP) {
  if (tP >= 0) {
    //   tP=tP*255;
    // tP=tP/50;
    analogWrite(leftForward, tP);
  }
  else {
    tP = tP * -1;
    // tP=tP*255;
    //  tP=tP/50;
    analogWrite(leftBackward, tP);
  }
  //   Serial.println(tP);

}

void TurnTask(char a)
{
  if (g_turnEnabled)
  {
    //     Serial.println(countleft);
    //   Serial.println(getHeading());
    float error = g_turnTarget - getHeading();
    //  Serial.println(error);
    if (error >= g_turnTolerance)
    {

      int turnPower = bound((int)(g_turnKp * error), 60, 150);
      //Serial.println(turnPower);
      if (a == 'r') {
        moveLeftMotor(turnPower);
        moveRightMotor(-turnPower);
      }
      else if (a == 'l') {
        moveLeftMotor(-turnPower);
        moveRightMotor(turnPower);
      }
    }
    else
    {
      analogWrite(rightForward, 0);
      analogWrite(leftBackward, 0);
      analogWrite(leftForward, 0);
      analogWrite(rightBackward, 0);
      g_turnEnabled = false;
    }
  }
  delay(5);
}

void DriveTask(float g_driveKp, char dir)
{
  if (g_driveEnabled)
  {
    //      Serial.println(countleft);
    float error = g_driveTarget - countleft;
    if (error >= g_driveTolerance)
    {

      int turnPower = bound((int)(g_driveKp * error), 150, 150);
      //     Serial.println(turnPower);
      if (dir == 'f') {
        moveLeftMotor(turnPower);
        moveRightMotor(turnPower);
      } else if (dir == 'b') {
        moveLeftMotor(-turnPower);
        moveRightMotor(-turnPower);
      }
    }
    else
    {
      analogWrite(rightForward, 0);
      analogWrite(leftBackward, 0);
      analogWrite(leftForward, 0);
      analogWrite(rightBackward, 0);
      g_driveEnabled = false;
    }
  }
}





void driveStraightDistance(int tickGoal, int masterPower, char dir)
{

  //This will count up the total encoder ticks despite the fact that the encoders are constantly reset.
  int totalTicks = 0;
  int slavePower;
  //Initialise slavePower as masterPower - 5 so we don't get huge error for the first few iterations. The
  //-5 value is based off a rough guess of how much the motors are different, which prevents the robot from
  //veering off course at the start of the function.

   slavePower = masterPower-35;
  
  int error = 0;
 
  float kp = 0.5;
 
  countleft = 0;
  countright = 0;
 
  //Monitor 'totalTicks', instead of the values of the encoders which are constantly reset.
  while(abs(totalTicks) < tickGoal)
  {
    //Proportional algorithm to keep the robot going straight.
    if(dir=='f'){
    moveLeftMotor(slavePower);
    moveRightMotor(masterPower);
    }else if(dir=='b'){
    moveLeftMotor(-slavePower);
    moveRightMotor(-masterPower);
    }
// Serial.println(masterPower);
 //Serial.println(slavePower);
    error = countleft - countright;
//Serial.println(error);
    slavePower -= error * kp;
  /*      if(slavePower<100)
        slavePower=100;*/
 // Serial.println(slavePower);
    totalTicks+= countleft;


    countleft = 0;
    countright = 0;
 
    delay(100);
 
    //Add this iteration's encoder values to totalTicks.

  }
    analogWrite(leftForward, 0);
    analogWrite(rightForward, 0);
    analogWrite(leftBackward, 0);
    analogWrite(rightBackward, 0);
   
}
void moveBackward(int distcount) {
     if(currOrientation=='N'){
      realTimePos=realTimePos-5*distcount;
   }else if(currOrientation=='E'){
      realTimePos=realTimePos-1*distcount;
   }else if(currOrientation=='S'){
      realTimePos=realTimePos+5*distcount;
   }else if(currOrientation=='W'){
      realTimePos=realTimePos+1*distcount;
   }
 
  char direction0 = 'b';
  delay(100);
  if (distcount == 1) {
    driveStraightDistance(1075, 150, direction0);
  }
   // wallAlign();
    adjustMovement();
    adjust();
        scientistBackward=0;
    scientistForward=0;

}
void moveForward(int distcount) {
  char direction0 = 'f';
  countmove++;
 // Serial.print("countmove: ");
 // Serial.println(countmove);

   if(currOrientation=='N'){
      realTimePos=realTimePos+5*distcount;
   }else if(currOrientation=='E'){
      realTimePos=realTimePos+1*distcount;
   }else if(currOrientation=='S'){
      realTimePos=realTimePos-5*distcount;
   }else if(currOrientation=='W'){
      realTimePos=realTimePos-1*distcount;
   }
  
  float Kp = 0;
  int fedCount = 0;
  delay(100);
  if (distcount == 1) {
    driveStraightDistance(1075, 150, direction0);
  } else if (distcount == 2) {
    driveStraightDistance(2850, 150, direction0);
  } else if (distcount == 3) {
    driveStraightDistance(4850, 150, direction0);
   
  } else if (distcount == 4) {
    driveStraightDistance(7100, 150, direction0);
    
  } else if (distcount == 5) {
    driveStraightDistance(3150, 150, direction0);;
    delay(500);
    driveStraightDistance(3150, 150, direction0);;
    delay(500);
    driveStraightDistance(1240, 150, direction0);;
  } else if (distcount == 6) {
    driveStraightDistance(3150, 150, direction0);;
    delay(500);
    driveStraightDistance(3150, 150, direction0);;
    delay(500);
    driveStraightDistance(3150, 150, direction0);;
  } else if (distcount == 7) {
    driveStraightDistance(3150, 150, direction0);;
    delay(500);
    driveStraightDistance(3150, 150, direction0);;
    delay(500);
    driveStraightDistance(3150, 150, direction0);;
    delay(500);
    driveStraightDistance(1240, 150, direction0);
  } else if (distcount == 8) {
    driveStraightDistance(3150, 150, direction0);;
    delay(500);
    driveStraightDistance(3150, 150, direction0);;
    delay(500);
    driveStraightDistance(3150, 150, direction0);;
    delay(500);
    driveStraightDistance(3150, 150, direction0);;
  } else if (distcount == 9) {
    driveStraightDistance(3150, 150, direction0);;
    delay(500);
    driveStraightDistance(3150, 150, direction0);;
    delay(500);
    driveStraightDistance(3150, 150, direction0);;
    delay(500);
    driveStraightDistance(3150, 150, direction0);;
    delay(500);
    driveStraightDistance(1240, 150, direction0);
  } else if (distcount == 10) {
    driveStraightDistance(3150, 150, direction0);;
    delay(500);
    driveStraightDistance(3150, 150, direction0);;
    delay(500);
    driveStraightDistance(3150, 150, direction0);;
    delay(500);
    driveStraightDistance(3150, 150, direction0);;
    delay(500);
    driveStraightDistance(3150, 150, direction0);;
  }

  wallAlign();
//  if(countmove==1||countmove==2||countmove==3);
//  else
    adjustMovement();
    adjust();
    Serial.println(realTimePos);
        scientistBackward=0;
    scientistForward=0;

}
void turnLeft(int angcount) {
  int angle;
  char dir = 'l';
//  adjust();
  
  delay(100);
  if (angcount == 1) {

    if (currOrientation == 'N') {
      currOrientation = 'W';
    }
    else if (currOrientation == 'W') {
      currOrientation = 'S';
    }
    else if (currOrientation == 'E') {
      currOrientation = 'N';
    }
    else if (currOrientation == 'S') {
      currOrientation = 'E';
    }
    angle = 87;
  } else if (angcount == 2) {
    if (currOrientation == 'N') {
      currOrientation = 'S';
    }
    else if (currOrientation == 'E') {
      currOrientation = 'W';
    }
    else if (currOrientation == 'W') {
      currOrientation = 'E';
    }
    else if (currOrientation == 'S') {
      currOrientation = 'N';
    }

    angle = 175;
  }else if (angcount == 3){
    angle = 45;
  }

  SetTurnTarget(angle);
  set_last_read_angle_data(millis(), 0, 0, 0, 0, 0, 0);
  while (g_turnEnabled)
    TurnTask(dir);
  delay(100);
wallAlign();
  adjust();

}
void turnRight(int angcount) {
  // Serial.println(angcount);
  countturn++;
//  Serial.print("countturn: ");
//  Serial.println(countturn);
  
  int angle;
  char dir = 'r';
 // if(countturn!=2)
  //  adjust();
  delay(100);
  
  if (angcount == 1) {
    if (currOrientation == 'N') {
      currOrientation = 'E';
    }
    else if (currOrientation == 'E') {
      currOrientation = 'S';
    }
    else if (currOrientation == 'W') {
      currOrientation = 'N';
    }
    else if (currOrientation == 'S') {
      currOrientation = 'W';
    }
    angle = 87;
  } else if (angcount == 2) {
    if (currOrientation == 'N') {
      currOrientation = 'S';
    }
    else if (currOrientation == 'E') {
      currOrientation = 'W';
    }
    else if (currOrientation == 'W') {
      currOrientation = 'E';
    }
    else if (currOrientation == 'S') {
      currOrientation = 'N';
    }
    angle = 175;
  } else if (angcount == 3){
    angle = 45;
  }
  SetTurnTarget(angle);
  set_last_read_angle_data(millis(), 0, 0, 0, 0, 0, 0);
  while (g_turnEnabled)
    TurnTask(dir);
  delay(100);
  wallAlign();
  adjust();

}
void movePath() {
  queue *tmp;
  while (true) {
    tmp = dequeue();
    if (tmp == NULL)
      break;
    else if (tmp->dir == 'F') {
      moveForward(tmp->count);
    }
    else if (tmp->dir == 'R') {
      turnRight(tmp->count);
    }
    else if (tmp->dir == 'L') {
      turnLeft(tmp->count);
    }
  }
}

int localizeUsingReadings() {
  //L1 0
  //L2 1
  //F  2
  //R2 3
  //R1 4
  //B  5
 digitalWrite(49,LOW);
 
  int countf = 0;
  int countb = 0;
  int countl = 0;
  int countr = 0;
  int confirmPos = 0;
  int foundPos = 0;
  int prevfoundPos = 0;
  int addf = 0;
  int addb = 0;
  int addl = 0;
  int addr = 0;
  do {
    if (countf == 1 && countb == 1 && countl == 1 && countr == 1) {
      countf = 0;
      countb = 0;
      countr = 0;
      countl = 0;
    }
    delay(500);
    storeSonarReadingsForLocalize();
    oneSensorCycle();
    prevfoundPos = localize(in[0], in[4], in[2], in[1], 1);
    Serial.println(prevfoundPos);
    // delay(500);
    if (in[2] >= 18 && countf == 0) {
      countf++;
      addf = 0;
      while (in[2] >= 18) {
        addf = addf+5;
        moveForward(1);
        delay(500);
        storeSonarReadingsForLocalize();
        oneSensorCycle();
        foundPos = localize(in[0], in[4], in[2], in[1], 1);
        Serial.println(foundPos);
        if (foundPos == prevfoundPos + addf||foundPos == prevfoundPos + 5) {
          confirmPos = 1;
          break;
          break;
        }
      }
    } else if (in[1] >= 18 && countb == 0) {
      countb++;
      addb = 0;
      while (in[1] >= 18) {
        addb = addb+5;
        moveBackward(1);
        delay(500);
        storeSonarReadingsForLocalize();
        oneSensorCycle();
        foundPos = localize(in[0], in[4], in[2],in[1], 1);
        Serial.println(foundPos);
        if (foundPos == prevfoundPos - addb||foundPos == prevfoundPos -5) {
          confirmPos = 1;
          break;
          break;
        }
      }
    } else if (in[0] >= 18 && countl == 0) {
      countl++;
      addl = 0;
      while (in[0] >= 18) {
        addl = addl+1;
        turnLeft(1);
        moveForward(1);
        turnRight(1);
        delay(500);
        storeSonarReadingsForLocalize();
        oneSensorCycle();
        foundPos = localize(in[0], in[4], in[2], in[1],1);
        Serial.println(foundPos);
        if (foundPos == prevfoundPos - addl||foundPos == prevfoundPos -1) {
          confirmPos = 1;
          break;
          break;
        }
      }
    } else if (in[4] >= 18 && countr == 0) {
      countr++;
      addr = 0;
      while (in[4] >= 18) {
        addr = addr+1;
        turnRight(1);
        moveForward(1);
        turnLeft(1);
        delay(500);
        storeSonarReadingsForLocalize();
        oneSensorCycle();
        foundPos = localize(in[0], in[4], in[2],in[1], 1);
        Serial.println(foundPos);
        if (foundPos == prevfoundPos + addr||foundPos == prevfoundPos + 1) {
          confirmPos = 1;
          break;
          break;
        }
      }
    }
  } while (confirmPos != 1);


  digitalWrite(49,HIGH);
  return foundPos;
}
