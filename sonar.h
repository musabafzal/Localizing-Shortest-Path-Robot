#include <NewPing.h>

#define SONAR_NUM     6 // Number of sensors.
#define MAX_DISTANCE 201 // Maximum distance (in inch) to ping.
#define PING_INTERVAL 33 // Milliseconds between sensor pings (29ms is about the min to avoid cross-sensor echo).

unsigned long pingTimer[SONAR_NUM]; // Holds the times when the next ping should happen for each sensor.
unsigned int in[SONAR_NUM];         // Where the ping distances are stored.
uint8_t currentSensor = 0;          // Keeps track of which sensor is active.


NewPing sonar[SONAR_NUM] = {     // Sensor object array.
  NewPing(23, 22, MAX_DISTANCE), //L1 0
  NewPing(25, 24, MAX_DISTANCE), //L2 1
  NewPing(27, 26, MAX_DISTANCE), //F 2
  NewPing(29, 28, MAX_DISTANCE), //R2 3
  NewPing(31, 30, MAX_DISTANCE), //R1 4
  NewPing(33, 32, MAX_DISTANCE)  //B 5
};

void oneSensorCycle() { // Sensor ping cycle complete, do something with the results.
  // The following code would be replaced with your code that does something with the ping results.  
  for (uint8_t i = 0; i < SONAR_NUM; i++) {
    Serial.print(i);
    Serial.print("=");
    Serial.print(in[i]);
    Serial.print("inch  ");
  }
  Serial.println();
}
void storeSonarReadings()
{

  for (int i = 0; i < 6; i++)
  {
    delay(33);
      in[i] = 0;
    unsigned int  uS = sonar[i].ping_median() / US_ROUNDTRIP_IN;
    in[i] = uS;
    if(in[i]==0)
      in[i]=79;
    if(in[i]>79)
      in[i]=79;  
  }

}
void storeSonarReadingsForLocalize()
{

  for (int i = 0; i < 6; i++)
  {
    delay(33);
      in[i] = 0;
    unsigned int  uS = sonar[i].ping_median() / US_ROUNDTRIP_IN;
    in[i] = uS;
    if(in[i]==0)
      in[i]=79;
    if(in[i]>79)
      in[i]=79;  
  }

  getSharpReadings();

  if(in[2]>8){
    in[2]=sharp[0];
  }
  if(in[1]>8){
    in[1]=sharp[1];
  }

}
void storeSonarReadingsForWallAlign()
{

  for (int i = 0; i < 6; i++)
  {
    delay(33);
    in[i] = 0;
    unsigned int  uS = sonar[i].ping() / US_ROUNDTRIP_CM;
    in[i] = uS;
        if(in[i]==0)
      in[i]=79;
    if(in[i]>79)
      in[i]=79;  
  }

}


