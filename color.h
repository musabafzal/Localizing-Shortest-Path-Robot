#define S0 40
#define S1 41
#define S2 42
#define S3 43
#define sensorOut 44
int RGB[3];
void colorSetup() {

  //Serial.begin(9600);
  //Color Sensor Init
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  // Setting frequency-scaling to 100%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, HIGH);


}

void color()
{
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  RGB[0] = 0;
  RGB[0] = pulseIn(sensorOut, LOW);
//   RGB[0] = map(RGB[0], 0,420,255,0);

  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  RGB[1] = 0;
  RGB[1] = pulseIn(sensorOut, LOW);
  //  RGB[1] = map(RGB[1], 0,420,255,0);


  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  RGB[2] = 0;
  RGB[2]  = pulseIn(sensorOut, LOW);
  // RGB[1] = map(RGB[2], 0,420,255,0);
}
int minColor(){
 // color();
  int minFilter=RGB[0];
  if(RGB[1]<minFilter){
     minFilter=RGB[1];
  }
  if(RGB[2]<minFilter){
    minFilter=RGB[2];
  }

  if(minFilter==RGB[0]){
    return 0;
  }else if(minFilter==RGB[1]){
    return 1;
  }else if(minFilter==RGB[2]){
    return 2;
  }
}


int getColor()
{
	color();
	
  if ((RGB[0] >= 83 && RGB[0] <= 103) && (RGB[1] >= 60 && RGB[1] <= 80) && (RGB[2] >= 25 && RGB[2] <= 45)){
   Serial.println("2");
    return 2;
  }
  else if ((RGB[0] >=20  && RGB[0] <= 40) && (RGB[1] >= 22 && RGB[1] <= 42) && (RGB[2] >= 12  && RGB[2] <= 32)){
   Serial.println("1");
    return 1;
  }
  else if ((RGB[0] >= 19 && RGB[0] <= 39) && (RGB[1] >= 32 && RGB[1] <= 52) && (RGB[2] >= 37 && RGB[2] <= 57)){
    Serial.println("3");
    return 3;
  }
  else if ((RGB[0] >= 34 && RGB[0] <= 54) && (RGB[1] >= 94 && RGB[1] <= 114) && (RGB[2] >= 59 && RGB[2] <= 79)){
    Serial.println("4");
    return 4;
  }
  else if ((RGB[0] >= 32 && RGB[0] <= 52) && (RGB[1] >= 31 && RGB[1] <= 51) && (RGB[2] >= 32 && RGB[2] <= 52)){
    Serial.println("5");
    return 5;
  }
  else{
    Serial.println("-1");
    return -1;
  }
}
/*int getColor()
{
  color();
  
  if (minColor()==0&&(RGB[1]-RGB[0]>100)&&(RGB[2]-RGB[0]>100))
    return 2;
  else if (minColor()==2&&(RGB[1]-RGB[2]>100)&&(RGB[0]-RGB[2]>100))
    return 4;
  else if ((RGB[0] >= 49 && RGB[0] <= 149) && (RGB[1] >= 44 && RGB[1] <= 144) && (RGB[2] >= 107 && RGB[2] <= 127))
    return 3;
  else if ((RGB[0] >= 56 && RGB[0] <= 156) && (RGB[1] >= 352 && RGB[1] <= 452) && (RGB[2] >= 230 && RGB[2] <= 330))
    return 2;
  else if ((RGB[0] >= 240 && RGB[0] <= 347) && (RGB[1] >= 140 && RGB[1] <= 240) && (RGB[2] >= 34 && RGB[2] <= 134))
    return 1;
  else
    return - 1;

}*/
void debug_color()
{

    Serial.print("Red:");
    Serial.print(RGB[0]);
    Serial.println(" ");
    Serial.print("Green:");
    Serial.print(RGB[1]);
    Serial.println(" ");
    Serial.print("Blue:");
    Serial.print(RGB[2]);
    Serial.println(" ");
   // Serial.println(getColor());
   // Serial.println(" ");
}



