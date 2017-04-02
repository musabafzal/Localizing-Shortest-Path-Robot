#include <ArduinoJson.h>
#include <SPI.h>
#include <SD.h>

 
File myFile;


char scien1Orien;
float scien1X;
float scien1Y;
char scien2Orien;
float scien2X;
float scien2Y;

float safe1X;
float safe1Y;
char safe1Orien;
float safe2X;
float safe2Y;
char safe2Orien;

const char* temp1;const char* temp2;const char* temp3;const char* temp4;

StaticJsonBuffer<500> jsonBuffer;


void printSDData(){

     Serial.println(scien1X);
     Serial.println(scien1Y);
     Serial.println(scien1Orien);
     Serial.println(scien2X);
     Serial.println(scien2Y);
     Serial.println(scien2Orien);
     Serial.println("");
     Serial.println(safe1X);
     Serial.println(safe1Y);
     Serial.println(safe1Orien);
     Serial.println(safe2X);
     Serial.println(safe2Y);
     Serial.println(safe2Orien);

}

void readSDData(){
  int lengthfile=0,i=0;
 while(!SD.begin(53)) {
    Serial.println("initialization failed!");
    
  }
  
  // open the file for reading:
  myFile = SD.open("NERC001.EXT");
  
  if (myFile) {
     lengthfile=myFile.size();
    lengthfile++;
    char *json =new char[lengthfile];
  
    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      json[i]=myFile.read();
        i++;
    }
           myFile.close();


        JsonObject& data = jsonBuffer.parseObject(json);
        scien1X =data["scientists"][0]["x"];
        scien1Y =data["scientists"][0]["y"];
        temp1=data["scientists"][0]["orientation"];
        scien1Orien=temp1[0];
        scien2X =data["scientists"][1]["x"];
        scien2Y =data["scientists"][1]["y"];
        temp2=data["scientists"][1]["orientation"];
        scien2Orien=temp2[0];
    
        safe1X =data["safezones"][0]["x"];
        safe1Y =data["safezones"][0]["y"];
        temp3=data["safezones"][0]["orientation"];    
        safe1Orien=temp3[0];
        safe2X =data["safezones"][1]["x"];
        safe2Y =data["safezones"][1]["y"];
        temp4=data["safezones"][1]["orientation"];   
        safe2Orien=temp4[0];
     }   
     
     else {
    // if the file didn't open, print an error:
    Serial.println("error opening file");
  } 

}
