unsigned long countright = 0;
unsigned long countleft = 0;

int rightForward = 8;
int rightBackward = 9;
int leftForward = 10;
int leftBackward = 11;

void leftencoder() {
  countleft++;
}
void rightencoder() {
  countright++;
}
#include "sharp.h"
#include "gyro.h"
#include "readsdcard.h"
#include "localization.h"
#include "graph.h"
#include "magneto.h"
#include "sonar.h"
#include "adjustment.h"
#include "color.h"
#include "alignment.h"
#include "movement.h"
#include "pickanddrop.h"

void setup() {
  int currPos;
  int localizedPos;
  //sensor initialization
  int error;
  uint8_t c;
  Wire.begin();
  myservo.attach(7);

/*
  Serial.println("Initialize HMC5883L");
  while (!compass.begin())
  {
    Serial.println("Could not find a valid HMC5883L sensor, check wiring!");
    delay(500);
  }

 // Set measurement range
  compass.setRange(HMC5883L_RANGE_1_3GA);

  // Set measurement mode
  compass.setMeasurementMode(HMC5883L_CONTINOUS);

  // Set data rate
  compass.setDataRate(HMC5883L_DATARATE_30HZ);

  // Set number of samples averaged
  compass.setSamples(HMC5883L_SAMPLES_8);

  // Set calibration offset. See HMC5883L_calibration.ino
  compass.setOffset(103, 184);

  */
  error = MPU6050_read (MPU6050_WHO_AM_I, &c, 1);
  Serial.begin(115200);

  error = MPU6050_read (MPU6050_PWR_MGMT_2, &c, 1);

  MPU6050_write_reg (MPU6050_PWR_MGMT_1, 0);
  //Initialize the angles
  calibrate_sensors();

  //sensor initialization end

  //encoder interrupt initialization
  pinMode(2, INPUT);
  attachInterrupt(digitalPinToInterrupt(2), leftencoder, CHANGE);
  attachInterrupt(digitalPinToInterrupt(3), rightencoder, CHANGE);
  //encoder interrupt initialization end

  pinMode(53, OUTPUT); //for sdcard reader
  pinMode(49, OUTPUT);//for localize LED
myservo.write(180);
  //for servo
  //sonarSetup();
   //read sdcard data
 readSDData();
 printSDData();

  colorSetup();
   scien1Orien = oppositeSide(scien1Orien);
  scien2Orien = oppositeSide(scien2Orien);
  safe1Orien = oppositeSide(safe1Orien);
  safe2Orien = oppositeSide(safe2Orien);
  
  localizedPos=localizeUsingReadings();
//Serial.println(localize(in[0], in[4], in[2], in[1], -1));
   Serial.println(localizedPos);

 
   currPos=localizedPos-1;

    initializeNodeNames();
  readData();

  deleteScienSafeNodes(scien1X, scien1Y, scien1Orien);
  deleteScienSafeNodes(scien2X, scien2Y, scien2Orien);
  deleteScienSafeNodes(safe1X, safe1Y, safe1Orien);
  deleteScienSafeNodes(safe2X, safe2Y, safe2Orien);


  int endNode;
  calcEndNode(scien1X, scien1Y, scien1Orien, endNode);

  
//  Serial.println(endNode);
  changeGraphOrientation(currOrientation);
  traversePath(currPos, endNode);
  movePath();
  currPos = endNode;
  
  //  Serial.println(currOrientation);
  //  Serial.println(scien1Orien);
  alignOrienWithScienSafe(scien1Orien);
  
  //moveForward(1);
  //lineTrack();
  pickUpScientist();
 // Serial.println(currOrientation);
  //currPos=endNode;
moveBackward(1);
adjust();
  calcEndNode(safe1X, safe1Y, safe1Orien, endNode);
  changeGraphOrientation(currOrientation);
  traversePath(currPos, endNode);
  //Serial.println(endNode);
  movePath();
  currPos = endNode;
  alignOrienWithScienSafe(safe1Orien);

   dropScientist();

  calcEndNode(scien2X, scien2Y, scien2Orien, endNode);
  changeGraphOrientation(currOrientation);
  traversePath(currPos, endNode);
  movePath();
  currPos = endNode;
  alignOrienWithScienSafe(scien2Orien);

   pickUpScientist();
moveBackward(1);
adjust();
  calcEndNode(safe2X, safe2Y, safe2Orien, endNode);
  changeGraphOrientation(currOrientation);
  traversePath(currPos, endNode);
  movePath();
  currPos = endNode;
  alignOrienWithScienSafe(safe2Orien);

    dropScientist();


  /**/
//  wallAlign();
 // myservo.write(150);
  //turnLeft(1);
 // turnRight(2);
  //moveForward(4);
  // Serial.println(endNode);

  // turnLeft(1);
  //turnRight(1);  turnRight(1);  turnRight(1);  turnRight(1);
  //  sonarSetup();

  //  pinMode(A8, INPUT);
  // Serial.println(localize(in[0],in[3],in[2],in[5],1));
  //moveForward(1);

  //  movePath();
  //             analogWrite(rightForward,200);
  //           analogWrite(leftBackward,100);
  //     analogWrite(leftForward,150);
  //       analogWrite(rightBackward,150);

  //lineTrack();
  //pickUpScientist();
  //wallAlign();
  //wallAlignMagneto();
 // turnRight(1);
  //adjust();
  //moveHandUp();
  //moveHandDown();
 // moveForward(3);
//  Serial.println(countleft);
 /*countleft=0;
 while(countleft>1600){
  analogWrite(2
 }*/
 /*delay(500);
*/
//driveStraightDistance(7000, 150, 'f');
//wallAlign();
}
void loop() {



//  getColor();
 // debug_color();
  //Serial.println(countleft);
 //  storeSonarReadingsForLocalize();
  // Serial.println(getHeading());
  //Serial.println(getColor());
  //delay(200);
  //wallAlignMagneto();
 // storeSonarReadingsForWallAlign();
  //oneSensorCycle();
  //Serial.print("lel");
 // printLineSensorsReadings();
  //delay(500);
//  storeSonarReadings();
 // oneSensorCycle();
  
 //Serial.println(getColor());
//Serial.println(minColor());
//debug_color();
//Serial.println(localize(in[0], in[4], in[2], in[1], 1));
//getSharpReadings();
//delay(200);
}
