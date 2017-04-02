 int scientistBackward=0;
int scientistForward=0;
 int  realTimePos=0;
char currOrientation = 'N';

 void moveBackwardInch(int diff){
  countleft=0;
  while(1){
  if(countleft<=110*diff)
  {
    analogWrite(rightBackward,50);
    analogWrite(leftBackward,50);
  }else{
    break;
  }
  }
   analogWrite(rightBackward,0);
    analogWrite(leftBackward,0);
 analogWrite(rightForward,0);
    analogWrite(leftForward,0);

}
void moveForwardInch(int diff){
    countleft=0;
  while(1){
  if(countleft<=110*diff)
  {
    analogWrite(rightForward,50);
    analogWrite(leftForward,50);
  }else{

    break;
  }
  }
   analogWrite(rightBackward,0);
    analogWrite(leftBackward,0);
 analogWrite(rightForward,0);
    analogWrite(leftForward,0);
}

void adjust(){
int sensorDifference;
  storeSonarReadings();
 // oneSensorCycle();
if(in[2]<79||in[1]<79)
{
  if((in[2]<in[1]||scientistBackward==1)&&(scientistForward!=1))
  {
    if(in[2]<9)
    {
     if (in[2]<3)
     {sensorDifference=3-in[2];
      moveBackwardInch(sensorDifference);
     }
     else if(in[2]>3)
     {sensorDifference=in[2]-3;
      moveForwardInch(sensorDifference);
     }
    }
    else if(in[2]>9&&in[2]<27)
    {
      
     if (in[2]<21)
     {sensorDifference=21-in[2];
      moveBackwardInch(sensorDifference);
     }
     else if(in[2]>21)
     {sensorDifference=in[2]-21;
      moveForwardInch(sensorDifference);
     }
    }
    else if(in[2]>27&&in[2]<45)
    {
      
     if (in[2]<39)
     {sensorDifference=39-in[2];
      moveBackwardInch(sensorDifference);
     }
     else if(in[2]>39)
     {sensorDifference=in[2]-39;
      moveForwardInch(sensorDifference);
     }
    }
    else if(in[2]>45&&in[2]<63)
    {
      
     if (in[2]<57)
     {sensorDifference=57-in[2];
      moveBackwardInch(sensorDifference);
     }
     else if(in[2]>57)
     {sensorDifference=in[2]-57;
      moveForwardInch(sensorDifference);
     }
    }
    else if(in[2]>63&&in[2]<79)
    {
      
     if (in[2]<75)
     {sensorDifference=75-in[2];
      moveBackwardInch(sensorDifference);
     }
     else if(in[2]>75)
     {sensorDifference=in[2]-75;
      moveForwardInch(sensorDifference);
     }
    }
  }
  else if(((in[1]<in[2])||scientistForward==1)&&(scientistBackward!=1))
  {if(in[1]<9)
    {
     if (in[1]>3)
     {sensorDifference=in[1]-3;
      moveBackwardInch(sensorDifference);
     }
     else if(in[1]<3)
     {sensorDifference=3-in[1];
      moveForwardInch(sensorDifference);
     }
    }
    else if(in[1]>9&&in[1]<27)
    {
      
     if (in[1]>21)
     {sensorDifference=in[1]-21;
      moveBackwardInch(sensorDifference);
     }
     else if(in[1]<21)
     {sensorDifference=21-in[1];
      moveForwardInch(sensorDifference);
     }
    }
    else if(in[1]>27&&in[1]<45)
    {
      
     if (in[1]>39)
     {sensorDifference=in[1]-39;
      moveBackwardInch(sensorDifference);
     }
     else if(in[1]<39)
     {sensorDifference=39-in[1];
      moveForwardInch(sensorDifference);
     }
    }
    else if(in[1]>45&&in[1]<63)
    {
      
     if (in[1]>57)
     {sensorDifference=in[1]-57;
      moveBackwardInch(sensorDifference);
     }
     else if(in[1]<57)
     {sensorDifference=57-in[1];
      moveForwardInch(sensorDifference);
     }
    }
    else if(in[1]>63&&in[1]<79)
    {
      
     if (in[1]>75)
     {sensorDifference=in[1]-75;
      moveBackwardInch(sensorDifference);
     }
     else if(in[1]<75)
     {sensorDifference=75-in[1];
      moveForwardInch(sensorDifference);
     }
    }
  }

}
}


int adjustMovement(){ 

int nodeName_adjust=realTimePos;
int scientist1node=determineNodeName(scien1X,scien1Y);
int scientist2node=determineNodeName(scien2X,scien2Y);
char scientist1orientation_adjust=scien1Orien;
char scientist2orientation_adjust=scien2Orien;
char orientation_adjust=currOrientation;



  // put your setup code here, to run once:
if(nodeName_adjust==3)
  
    {if(orientation_adjust=='W')
    {if(((scientist1node==(nodeName_adjust+1))&&(scientist1orientation_adjust=='E'))||(((scientist2node==(nodeName_adjust+1)))&&(scientist2orientation_adjust=='E')))
      {scientistBackward=1;}
      else if(((scientist1node==(nodeName_adjust-1))&&(scientist1orientation_adjust=='W'))||(((scientist2node==(nodeName_adjust-1)))&&(scientist2orientation_adjust=='W')))
      {scientistForward=1;}
    }
  else if(orientation_adjust=='E')
    {if(((scientist1node==(nodeName_adjust+1))&&(scientist1orientation_adjust=='E'))||(((scientist2node==(nodeName_adjust+1)))&&(scientist2orientation_adjust=='E')))
      {scientistForward=1;}
      else if(((scientist1node==(nodeName_adjust-1))&&(scientist1orientation_adjust=='W'))||(((scientist2node==(nodeName_adjust-1)))&&(scientist2orientation_adjust=='W')))
      {scientistBackward=1;}
    }
  }
else if(nodeName_adjust==5)
  {if(orientation_adjust=='N')
    {if(((scientist1node==(nodeName_adjust-5))&&(scientist1orientation_adjust=='S'))||((scientist2node==(nodeName_adjust-5))&&(scientist2orientation_adjust=='S')))
      {scientistBackward=1;}
    else if(((scientist1node==(nodeName_adjust+5))&&(scientist1orientation_adjust=='N'))||((scientist2node==(nodeName_adjust+5))&&(scientist2orientation_adjust=='N')))
      {scientistForward=1;}
    }
  else if(orientation_adjust=='S')
    {if(((scientist1node==(nodeName_adjust-5))&&(scientist1orientation_adjust=='S'))||((scientist2node==(nodeName_adjust-5))&&(scientist2orientation_adjust=='S')))
      {scientistForward=1;}
    else if(((scientist1node==(nodeName_adjust+5))&&(scientist1orientation_adjust=='N'))||((scientist2node==(nodeName_adjust+5))&&(scientist2orientation_adjust=='N')))
      {scientistBackward=1;}
    }
         } 
else if(nodeName_adjust==6)
  {if(orientation_adjust=='N')
    {if(((scientist1node==(nodeName_adjust+5))&&(scientist1orientation_adjust=='N'))||((scientist2node==(nodeName_adjust+5))&&(scientist2orientation_adjust=='N')))
      {scientistForward=1;}
    else if(((scientist1node==(nodeName_adjust-5))&&(scientist1orientation_adjust=='S'))||((scientist2node==(nodeName_adjust-5))&&(scientist2orientation_adjust=='S')))
      {scientistBackward=1;}
    }
  else if(orientation_adjust=='S')
    {if(((scientist1node==(nodeName_adjust+5))&&(scientist1orientation_adjust=='N'))||((scientist2node==(nodeName_adjust+5))&&(scientist2orientation_adjust=='N')))
      {scientistForward=1;}
    else if(((scientist1node==(nodeName_adjust-5))&&(scientist1orientation_adjust=='S'))||((scientist2node==(nodeName_adjust-5))&&(scientist2orientation_adjust=='S')))
      {scientistBackward=1;}
    }
  else if(orientation_adjust=='W')
    {if(((scientist1node==(nodeName_adjust-1))&&(scientist1orientation_adjust=='W'))||((scientist2node==(nodeName_adjust-1))&&(scientist2orientation_adjust=='W')))
      {scientistForward=1;}
    }
  else if(orientation_adjust=='E')
    {if(((scientist1node==(nodeName_adjust-1))&&(scientist1orientation_adjust=='W'))||((scientist2node==(nodeName_adjust-1))&&(scientist2orientation_adjust=='W')))
      {scientistBackward=1;}
    }
  }
else if(nodeName_adjust==7)
  {if(orientation_adjust=='N')
    {if(((scientist1node==(nodeName_adjust+5))&&(scientist1orientation_adjust=='N'))||((scientist2node==(nodeName_adjust+5))&&(scientist2orientation_adjust=='N')))
      {scientistForward=1;}
    else if(((scientist1node==(nodeName_adjust-5))&&(scientist1orientation_adjust=='S'))||((scientist2node==(nodeName_adjust-5))&&(scientist2orientation_adjust=='S')))
      {scientistBackward=1;}
    }
  else if(orientation_adjust=='S')
    {if(((scientist1node==(nodeName_adjust+5))&&(scientist1orientation_adjust=='N'))||((scientist2node==(nodeName_adjust+5))&&(scientist2orientation_adjust=='N')))
      {scientistBackward=1;}
    else if(((scientist1node==(nodeName_adjust-5))&&(scientist1orientation_adjust=='S'))||((scientist2node==(nodeName_adjust-5))&&(scientist2orientation_adjust=='S')))
      {scientistForward=1;}
    }
  else if(orientation_adjust=='W')
    {if((((scientist1node==(nodeName_adjust-1))||(scientist1node==(nodeName_adjust-2)))&&(scientist1orientation_adjust=='W'))||(((scientist2node==(nodeName_adjust-1))||(scientist2node==(nodeName_adjust-2)))&&(scientist2orientation_adjust=='W')))
      {scientistForward=1;}
    else if((((scientist1node==(nodeName_adjust+1))||(scientist1node==(nodeName_adjust+2)))&&(scientist1orientation_adjust=='E'))||(((scientist2node==(nodeName_adjust+1))||(scientist2node==(nodeName_adjust+2)))&&(scientist2orientation_adjust=='E')))
      {scientistBackward=1;}
    }
  else if(orientation_adjust=='E')
    {if((((scientist1node==(nodeName_adjust-1))||(scientist1node==(nodeName_adjust-2)))&&(scientist1orientation_adjust=='W'))||(((scientist2node==(nodeName_adjust-1))||(scientist2node==(nodeName_adjust-2)))&&(scientist2orientation_adjust=='W')))
      {scientistBackward=1;}
    else if((((scientist1node==(nodeName_adjust+1))||(scientist1node==(nodeName_adjust+2)))&&(scientist1orientation_adjust=='E'))||(((scientist2node==(nodeName_adjust+1))||(scientist2node==(nodeName_adjust+2)))&&(scientist2orientation_adjust=='E')))
      {scientistForward=1;}
    }
  }
else if(nodeName_adjust==8)
  {if(orientation_adjust=='N')
    {if(((scientist1node==(nodeName_adjust-5))&&(scientist1orientation_adjust=='S'))||((scientist2node==(nodeName_adjust-5))&&(scientist2orientation_adjust=='S')))
      {scientistBackward=1;}
    }
  else if(orientation_adjust=='S')
    {if(((scientist1node==(nodeName_adjust-5))&&(scientist1orientation_adjust=='S'))||((scientist2node==(nodeName_adjust-5))&&(scientist2orientation_adjust=='S')))
      {scientistForward=1;}
    }
  else if(orientation_adjust=='W')
    {if((((scientist1node==(nodeName_adjust+1)))&&(scientist1orientation_adjust=='E'))||(((scientist2node==(nodeName_adjust+1)))&&(scientist2orientation_adjust=='E')))
      {scientistBackward=1;}
    }
  else if(orientation_adjust=='E')
    {if((((scientist1node==(nodeName_adjust+1)))&&(scientist1orientation_adjust=='E'))||(((scientist2node==(nodeName_adjust+1)))&&(scientist2orientation_adjust=='E')))
      {scientistForward=1;}
    }
  }
else if(nodeName_adjust==9)
  {if(orientation_adjust=='N')
    {if(((scientist1node==(nodeName_adjust+5))&&(scientist1orientation_adjust=='N'))||((scientist2node==(nodeName_adjust+5))&&(scientist2orientation_adjust=='N')))
      {scientistForward=1;}
    else if(((scientist1node==(nodeName_adjust-5))&&(scientist1orientation_adjust=='S'))||((scientist2node==(nodeName_adjust-5))&&(scientist2orientation_adjust=='S')))
      {scientistBackward=1;}
    }
  else if(orientation_adjust=='S')
    {if(((scientist1node==(nodeName_adjust+5))&&(scientist1orientation_adjust=='N'))||((scientist2node==(nodeName_adjust+5))&&(scientist2orientation_adjust=='N')))
      {scientistBackward=1;}
    else if(((scientist1node==(nodeName_adjust-5))&&(scientist1orientation_adjust=='S'))||((scientist2node==(nodeName_adjust-5))&&(scientist2orientation_adjust=='S')))
      {scientistForward=1;}
    }
  }
else if(nodeName_adjust==10)
  {if(orientation_adjust=='N')
    {if((((scientist1node==(nodeName_adjust-5))||(scientist1node==(nodeName_adjust-10)))&&(scientist1orientation_adjust=='S'))||(((scientist2node==(nodeName_adjust-5))||(scientist2node==(nodeName_adjust-10)))&&(scientist2orientation_adjust=='S')))
      {scientistBackward=1;}
    }
  else if(orientation_adjust=='S')
    {if((((scientist1node==(nodeName_adjust-5))||(scientist1node==(nodeName_adjust-10)))&&(scientist1orientation_adjust=='S'))||(((scientist2node==(nodeName_adjust-5))||(scientist2node==(nodeName_adjust-10)))&&(scientist2orientation_adjust=='S')))
      {scientistForward=1;}
    }
  }
else if(nodeName_adjust==13)
  {if(orientation_adjust=='N')
    {if((((scientist1node==(nodeName_adjust-5))||(scientist1node==(nodeName_adjust-10)))&&(scientist1orientation_adjust=='S'))||(((scientist2node==(nodeName_adjust-5))||(scientist2node==(nodeName_adjust-10)))&&(scientist2orientation_adjust=='S')))
      {scientistBackward=1;}
    }
  else if(orientation_adjust=='S')
    {if((((scientist1node==(nodeName_adjust-5))||(scientist1node==(nodeName_adjust-10)))&&(scientist1orientation_adjust=='S'))||(((scientist2node==(nodeName_adjust-5))||(scientist2node==(nodeName_adjust-10)))&&(scientist2orientation_adjust=='S')))
      {scientistForward=1;}
    }
  else if(orientation_adjust=='W')
    {if((((scientist1node==(nodeName_adjust-1)))&&(scientist1orientation_adjust=='W'))||(((scientist2node==(nodeName_adjust-1)))&&(scientist2orientation_adjust=='W')))
      {scientistForward=1;}
    else if((((scientist1node==(nodeName_adjust+1)))&&(scientist1orientation_adjust=='E'))||(((scientist2node==(nodeName_adjust+1)))&&(scientist2orientation_adjust=='E')))
      {scientistBackward=1;}
    }
  else if(orientation_adjust=='E')
    {if((((scientist1node==(nodeName_adjust-1)))&&(scientist1orientation_adjust=='W'))||(((scientist2node==(nodeName_adjust-1)))&&(scientist2orientation_adjust=='W')))
      {scientistBackward=1;}
    else if((((scientist1node==(nodeName_adjust+1)))&&(scientist1orientation_adjust=='E'))||(((scientist2node==(nodeName_adjust+1)))&&(scientist2orientation_adjust=='E')))
      {scientistForward=1;}
    }
  }
else if(nodeName_adjust==15)
  {if(orientation_adjust=='N')
    {if((((scientist1node==(nodeName_adjust-5))||(scientist1node==(nodeName_adjust-10))||(scientist1node==(nodeName_adjust-15))&&(scientist1orientation_adjust=='S'))||(scientist2node==(nodeName_adjust-5))||(scientist2node==(nodeName_adjust-10))||(scientist1node==(nodeName_adjust-15))&&(scientist2orientation_adjust=='S')))
      {scientistBackward=1;}
    else if(((scientist1node==(nodeName_adjust+10))&&(scientist1orientation_adjust=='S'))||((scientist2node==(nodeName_adjust+10))&&(scientist2orientation_adjust=='S')))
      {scientistForward=1;}
    
    }
  else if(orientation_adjust=='S')
    {if((((scientist1node==(nodeName_adjust-5))||(scientist1node==(nodeName_adjust-10))||(scientist1node==(nodeName_adjust-15))&&(scientist1orientation_adjust=='S'))||(scientist2node==(nodeName_adjust-5))||(scientist2node==(nodeName_adjust-10))||(scientist1node==(nodeName_adjust-15))&&(scientist2orientation_adjust=='S')))
      {scientistForward=1;}
    else if(((scientist1node==(nodeName_adjust+10))&&(scientist1orientation_adjust=='S'))||((scientist2node==(nodeName_adjust+10))&&(scientist2orientation_adjust=='S')))
      {scientistBackward=1;}
    }
  }
else if(nodeName_adjust==17)
   {if(orientation_adjust=='W')
    {if((((scientist1node==(nodeName_adjust+2)))&&(scientist1orientation_adjust=='E'))||(((scientist2node==(nodeName_adjust+2)))&&(scientist2orientation_adjust=='E')))
      {scientistBackward=1;}
    }
  else if(orientation_adjust=='E')
    {if((((scientist1node==(nodeName_adjust+2)))&&(scientist1orientation_adjust=='E'))||(((scientist2node==(nodeName_adjust+2)))&&(scientist2orientation_adjust=='E')))
      {scientistForward=1;}
    }
  }
else if(nodeName_adjust==18)
  {if(orientation_adjust=='N')
    {if((((scientist1node==(nodeName_adjust-10))||(scientist1node==(nodeName_adjust-15))||(scientist1node==(nodeName_adjust-15))&&(scientist1orientation_adjust=='S'))||(scientist2node==(nodeName_adjust-15))||(scientist2node==(nodeName_adjust-10))||(scientist1node==(nodeName_adjust-15))&&(scientist2orientation_adjust=='S')))
      {scientistBackward=1;}
    }
  else if(orientation_adjust=='S')
    {if((((scientist1node==(nodeName_adjust-15))||(scientist1node==(nodeName_adjust-10))||(scientist1node==(nodeName_adjust-15)))&&(scientist1orientation_adjust=='S'))||(((scientist2node==(nodeName_adjust-15))||(scientist2node==(nodeName_adjust-10))||(scientist1node==(nodeName_adjust-15)))&&(scientist2orientation_adjust=='S')))
      {scientistForward=1;}
    }
  else if(orientation_adjust=='W')
    {if((((scientist1node==(nodeName_adjust+1)))&&(scientist1orientation_adjust=='E'))||(((scientist2node==(nodeName_adjust+1)))&&(scientist2orientation_adjust=='E')))
      {scientistBackward=1;}
    }
  else if(orientation_adjust=='E')
    {if((((scientist1node==(nodeName_adjust+1)))&&(scientist1orientation_adjust=='E'))||(((scientist2node==(nodeName_adjust+1)))&&(scientist2orientation_adjust=='E')))
      {scientistForward=1;}
    }
  }
else if(nodeName_adjust==20)
  {if(orientation_adjust=='N')
    {if((((scientist1node==(nodeName_adjust-10))||(scientist1node==(nodeName_adjust-15))||(scientist1node==(nodeName_adjust-20))&&(scientist1orientation_adjust=='S'))||(scientist2node==(nodeName_adjust-15))||(scientist2node==(nodeName_adjust-10))||(scientist2node==(nodeName_adjust-20))&&(scientist2orientation_adjust=='S')))
      {scientistBackward=1;}
    else if((((scientist1node==(nodeName_adjust+5))||(scientist1node==(nodeName_adjust+20)))&&(scientist1orientation_adjust=='N'))||(((scientist2node==(nodeName_adjust+5))||(scientist2node==(nodeName_adjust+20)))&&(scientist2orientation_adjust=='N')))
      {scientistForward=1;}
    }
  else if(orientation_adjust=='S')
    {if((((scientist1node==(nodeName_adjust-15))||(scientist1node==(nodeName_adjust-10))||(scientist1node==(nodeName_adjust-20)))&&(scientist1orientation_adjust=='S'))||(((scientist2node==(nodeName_adjust-15))||(scientist2node==(nodeName_adjust-10))||(scientist2node==(nodeName_adjust-20)))&&(scientist2orientation_adjust=='S')))
      {scientistForward=1;}
    else if((((scientist1node==(nodeName_adjust+5))||(scientist1node==(nodeName_adjust+20)))&&(scientist1orientation_adjust=='N'))||(((scientist2node==(nodeName_adjust+5))||(scientist2node==(nodeName_adjust+20)))&&(scientist2orientation_adjust=='N')))
      {scientistBackward=1;}
    }
  }
else if(nodeName_adjust==21)
  { if(orientation_adjust=='W')
    {if((((scientist1node==(nodeName_adjust+1)))&&(scientist1orientation_adjust=='E'))||(((scientist2node==(nodeName_adjust+1)))&&(scientist2orientation_adjust=='E')))
      {scientistBackward=1;}
    }
  else if(orientation_adjust=='E')
    {if((((scientist1node==(nodeName_adjust+1)))&&(scientist1orientation_adjust=='E'))||(((scientist2node==(nodeName_adjust+1)))&&(scientist2orientation_adjust=='E')))
      {scientistForward=1;}
    }
  }
else if(nodeName_adjust==23)
  {if(orientation_adjust=='N')
    {if((((scientist1node==(nodeName_adjust-15))||(scientist1node==(nodeName_adjust-20))&&(scientist1orientation_adjust=='S'))||(scientist2node==(nodeName_adjust-15))||(scientist2node==(nodeName_adjust-20))&&(scientist2orientation_adjust=='S')))
      {scientistBackward=1;}
    else if((((scientist1node==(nodeName_adjust+10))||(scientist1node==(nodeName_adjust+20)))&&(scientist1orientation_adjust=='N'))||(((scientist2node==(nodeName_adjust+10))||(scientist2node==(nodeName_adjust+20)))&&(scientist2orientation_adjust=='N')))
      {scientistForward=1;}
    }
  else if(orientation_adjust=='S')
    {if((((scientist1node==(nodeName_adjust-15))||(scientist1node==(nodeName_adjust-20)))&&(scientist1orientation_adjust=='S'))||(((scientist2node==(nodeName_adjust-15))||(scientist2node==(nodeName_adjust-20)))&&(scientist2orientation_adjust=='S')))
      {scientistForward=1;}
    else if((((scientist1node==(nodeName_adjust+10)))&&(scientist1orientation_adjust=='N'))||(((scientist2node==(nodeName_adjust+10)))&&(scientist2orientation_adjust=='N')))
      {scientistBackward=1;}
    }
  }
else if(nodeName_adjust==25)
  {if(orientation_adjust=='N')
    {if((((scientist1node==(nodeName_adjust-15))||(scientist1node==(nodeName_adjust-20))&&(scientist1orientation_adjust=='S'))||(scientist2node==(nodeName_adjust-15))||(scientist2node==(nodeName_adjust-20))&&(scientist2orientation_adjust=='S')))
      {scientistBackward=1;}
    else if((((scientist1node==(nodeName_adjust+15))||(scientist1node==(nodeName_adjust+20)))&&(scientist1orientation_adjust=='N'))||(((scientist2node==(nodeName_adjust+15))||(scientist2node==(nodeName_adjust+20)))&&(scientist2orientation_adjust=='N')))
      {scientistForward=1;}
    }
  else if(orientation_adjust=='S')
    {if((((scientist1node==(nodeName_adjust-15))||(scientist1node==(nodeName_adjust-20)))&&(scientist1orientation_adjust=='S'))||(((scientist2node==(nodeName_adjust-15))||(scientist2node==(nodeName_adjust-20)))&&(scientist2orientation_adjust=='S')))
      {scientistForward=1;}
    else if((((scientist1node==(nodeName_adjust+15))||(scientist1node==(nodeName_adjust+20)))&&(scientist1orientation_adjust=='N'))||(((scientist2node==(nodeName_adjust+15))||(scientist2node==(nodeName_adjust+20)))&&(scientist2orientation_adjust=='N')))
      {scientistBackward=1;}
    }
  }
else if(nodeName_adjust==26)
  {if(orientation_adjust=='N')
    {if(((scientist1node==(nodeName_adjust+5))&&(scientist1orientation_adjust=='N'))||((scientist2node==(nodeName_adjust+5))&&(scientist2orientation_adjust=='N')))
      {scientistForward=1;}
    else if(((scientist1node==(nodeName_adjust-5))&&(scientist1orientation_adjust=='S'))||((scientist2node==(nodeName_adjust-5))&&(scientist2orientation_adjust=='S')))
      {scientistBackward=1;}
    }
  else if(orientation_adjust=='S')
    {if(((scientist1node==(nodeName_adjust+5))&&(scientist1orientation_adjust=='N'))||((scientist2node==(nodeName_adjust+5))&&(scientist2orientation_adjust=='N')))
      {scientistBackward=1;}
    else if(((scientist1node==(nodeName_adjust-5))&&(scientist1orientation_adjust=='S'))||((scientist2node==(nodeName_adjust-5))&&(scientist2orientation_adjust=='S')))
      {scientistForward=1;}
    }
  else if(orientation_adjust=='W')
    {if((((scientist1node==(nodeName_adjust-1)))&&(scientist1orientation_adjust=='W'))||(((scientist2node==(nodeName_adjust-1)))&&(scientist2orientation_adjust=='W')))
      {scientistForward=1;}
    else if((((scientist1node==(nodeName_adjust+1)))&&(scientist1orientation_adjust=='E'))||(((scientist2node==(nodeName_adjust+1)))&&(scientist2orientation_adjust=='E')))
      {scientistBackward=1;}
    }
  else if(orientation_adjust=='E')
    {if((((scientist1node==(nodeName_adjust-1)))&&(scientist1orientation_adjust=='W'))||(((scientist2node==(nodeName_adjust-1)))&&(scientist2orientation_adjust=='W')))
      {scientistBackward=1;}
    else if((((scientist1node==(nodeName_adjust+1)))&&(scientist1orientation_adjust=='E'))||(((scientist2node==(nodeName_adjust+1)))&&(scientist2orientation_adjust=='E')))
      {scientistForward=1;}
    }
  }
else if(nodeName_adjust==27)
  {if(orientation_adjust=='N')
    {if(((scientist1node==(nodeName_adjust+5))&&(scientist1orientation_adjust=='N'))||((scientist2node==(nodeName_adjust+5))&&(scientist2orientation_adjust=='N')))
      {scientistForward=1;}
    else if(((scientist1node==(nodeName_adjust-5))&&(scientist1orientation_adjust=='S'))||((scientist2node==(nodeName_adjust-5))&&(scientist2orientation_adjust=='S')))
      {scientistBackward=1;}
    }
  else if(orientation_adjust=='S')
    {if(((scientist1node==(nodeName_adjust+5))&&(scientist1orientation_adjust=='N'))||((scientist2node==(nodeName_adjust+5))&&(scientist2orientation_adjust=='N')))
      {scientistBackward=1;}
    else if(((scientist1node==(nodeName_adjust-5))&&(scientist1orientation_adjust=='S'))||((scientist2node==(nodeName_adjust-5))&&(scientist2orientation_adjust=='S')))
      {scientistForward=1;}
    }
  }
else if(nodeName_adjust==30)
  {if(orientation_adjust=='N')
    {if(((scientist1node==(nodeName_adjust-5))||(scientist1node==(nodeName_adjust-20))&&(scientist1orientation_adjust=='S'))||((scientist2node==(nodeName_adjust-5))||(scientist2node==(nodeName_adjust-20))&&(scientist2orientation_adjust=='S')))
      {scientistBackward=1;}
    else if((((scientist1node==(nodeName_adjust+10))||(scientist1node==(nodeName_adjust+15))||(scientist1node==(nodeName_adjust+20)))&&(scientist1orientation_adjust=='N'))||(((scientist2node==(nodeName_adjust+15))||(scientist2node==(nodeName_adjust+10))||(scientist2node==(nodeName_adjust+20)))&&(scientist2orientation_adjust=='N')))
      {scientistForward=1;}
    }
  else if(orientation_adjust=='S')
    {if((((scientist1node==(nodeName_adjust-5))||(scientist1node==(nodeName_adjust-20)))&&(scientist1orientation_adjust=='S'))||(((scientist2node==(nodeName_adjust-10))||(scientist2node==(nodeName_adjust-20)))&&(scientist2orientation_adjust=='S')))
      {scientistForward=1;}
    else if(((((scientist1node==(nodeName_adjust+15))||scientist1node==(nodeName_adjust+10))||(scientist1node==(nodeName_adjust+20)))&&(scientist1orientation_adjust=='N'))||((((scientist2node==(nodeName_adjust+15))||scientist2node==(nodeName_adjust+10))||(scientist2node==(nodeName_adjust+20)))&&(scientist2orientation_adjust=='N')))
      {scientistBackward=1;}
    }
  }
else if(nodeName_adjust==31)
  { if(orientation_adjust=='W')
    {if((((scientist1node==(nodeName_adjust+1)))&&(scientist1orientation_adjust=='E'))||(((scientist2node==(nodeName_adjust+1)))&&(scientist2orientation_adjust=='E')))
      {scientistBackward=1;}
    }
  else if(orientation_adjust=='E')
    {if((((scientist1node==(nodeName_adjust+1)))&&(scientist1orientation_adjust=='E'))||(((scientist2node==(nodeName_adjust+1)))&&(scientist2orientation_adjust=='E')))
      {scientistForward=1;}
    }
  }
else if(nodeName_adjust==33)
  {if(orientation_adjust=='N')
    {if((((scientist1node==(nodeName_adjust+15))||(scientist1node==(nodeName_adjust+20))&&(scientist1orientation_adjust=='N'))||(scientist2node==(nodeName_adjust+15))||(scientist2node==(nodeName_adjust+20))&&(scientist2orientation_adjust=='N')))
      {scientistForward=1;}
    else if((((scientist1node==(nodeName_adjust-10)))&&(scientist1orientation_adjust=='S'))||(((scientist2node==(nodeName_adjust-10)))&&(scientist2orientation_adjust=='S')))
      {scientistBackward=1;}
    }
  else if(orientation_adjust=='S')
    {if((((scientist1node==(nodeName_adjust+15))||(scientist1node==(nodeName_adjust+20)))&&(scientist1orientation_adjust=='N'))||(((scientist2node==(nodeName_adjust+15))||(scientist2node==(nodeName_adjust+20)))&&(scientist2orientation_adjust=='N')))
      {scientistBackward=1;}
    else if((((scientist1node==(nodeName_adjust-10)))&&(scientist1orientation_adjust=='S'))||(((scientist2node==(nodeName_adjust-10)))&&(scientist2orientation_adjust=='S')))
      {scientistForward=1;}
    }
  }
else if(nodeName_adjust==35)
  {if(orientation_adjust=='N')
    {if((((scientist1node==(nodeName_adjust+5))||(scientist1node==(nodeName_adjust+10))||(scientist1node==(nodeName_adjust+15))&&(scientist1orientation_adjust=='N'))||(scientist2node==(nodeName_adjust+5))||(scientist2node==(nodeName_adjust+10))||(scientist1node==(nodeName_adjust+15))&&(scientist2orientation_adjust=='N')))
      {scientistForward=1;}
    }
  else if(orientation_adjust=='S')
    {if((((scientist1node==(nodeName_adjust+5))||(scientist1node==(nodeName_adjust+10))||(scientist1node==(nodeName_adjust+15))&&(scientist1orientation_adjust=='N'))||(scientist2node==(nodeName_adjust+5))||(scientist2node==(nodeName_adjust+10))||(scientist1node==(nodeName_adjust+15))&&(scientist2orientation_adjust=='N')))
      {scientistBackward=1;}
    }
  }
else if(nodeName_adjust==37)
  {if(orientation_adjust=='W')
    {if((((scientist1node==(nodeName_adjust+2)))&&(scientist1orientation_adjust=='E'))||(((scientist2node==(nodeName_adjust+2)))&&(scientist2orientation_adjust=='E')))
      {scientistBackward=1;}
    }
  else if(orientation_adjust=='E')
    {if((((scientist1node==(nodeName_adjust+2)))&&(scientist1orientation_adjust=='E'))||(((scientist2node==(nodeName_adjust+2)))&&(scientist2orientation_adjust=='E')))
      {scientistForward=1;}
    }
  }
else if(nodeName_adjust==38)
  {if(orientation_adjust=='N')
    {if((((scientist1node==(nodeName_adjust+10))||(scientist1node==(nodeName_adjust+15))||(scientist1node==(nodeName_adjust+15))&&(scientist1orientation_adjust=='N'))||(scientist2node==(nodeName_adjust+15))||(scientist2node==(nodeName_adjust+10))||(scientist1node==(nodeName_adjust+15))&&(scientist2orientation_adjust=='N')))
      {scientistForward=1;}
    }
  else if(orientation_adjust=='S')
    {if((((scientist1node==(nodeName_adjust+10))||(scientist1node==(nodeName_adjust+15))||(scientist1node==(nodeName_adjust+15))&&(scientist1orientation_adjust=='N'))||(scientist2node==(nodeName_adjust+15))||(scientist2node==(nodeName_adjust+10))||(scientist1node==(nodeName_adjust+15))&&(scientist2orientation_adjust=='N')))
      {scientistBackward=1;}
    }
  else if(orientation_adjust=='W')
    {if((((scientist1node==(nodeName_adjust+1)))&&(scientist1orientation_adjust=='E'))||(((scientist2node==(nodeName_adjust+1)))&&(scientist2orientation_adjust=='E')))
      {scientistBackward=1;}
    }
  else if(orientation_adjust=='E')
    {if((((scientist1node==(nodeName_adjust+1)))&&(scientist1orientation_adjust=='E'))||(((scientist2node==(nodeName_adjust+1)))&&(scientist2orientation_adjust=='E')))
      {scientistForward=1;}
    }
  }
else if(nodeName_adjust==40)
  {if(orientation_adjust=='N')
    {if((((scientist1node==(nodeName_adjust+5))||(scientist1node==(nodeName_adjust+10)))&&(scientist1orientation_adjust=='N'))||(((scientist2node==(nodeName_adjust+5))||(scientist2node==(nodeName_adjust+10)))&&(scientist2orientation_adjust=='N')))
      {scientistForward=1;}
    }
  else if(orientation_adjust=='S')
    {if((((scientist1node==(nodeName_adjust+5))||(scientist1node==(nodeName_adjust+10)))&&(scientist1orientation_adjust=='N'))||(((scientist2node==(nodeName_adjust+5))||(scientist2node==(nodeName_adjust+10)))&&(scientist2orientation_adjust=='N')))
      {scientistBackward=1;}
    }
  }
else if(nodeName_adjust==43)
  {if(orientation_adjust=='N')
    {if((((scientist1node==(nodeName_adjust+5))||(scientist1node==(nodeName_adjust+10)))&&(scientist1orientation_adjust=='N'))||(((scientist2node==(nodeName_adjust+5))||(scientist2node==(nodeName_adjust+10)))&&(scientist2orientation_adjust=='N')))
      {scientistForward=1;}
    }
  else if(orientation_adjust=='S')
    {if(((scientist1node==(nodeName_adjust+5))||((scientist1node==(nodeName_adjust+10))&&(scientist1orientation_adjust=='N')))||(((scientist2node==(nodeName_adjust+5))||(scientist2node==(nodeName_adjust+10))&&(scientist2orientation_adjust=='N'))))
      {scientistForward=1;}
    }
  else if(orientation_adjust=='W')
    {if((((scientist1node==(nodeName_adjust-1)))&&(scientist1orientation_adjust=='W'))||(((scientist2node==(nodeName_adjust-1)))&&(scientist2orientation_adjust=='W')))
      {scientistForward=1;}
    else if((((scientist1node==(nodeName_adjust+1)))&&(scientist1orientation_adjust=='E'))||(((scientist2node==(nodeName_adjust+1)))&&(scientist2orientation_adjust=='E')))
      {scientistBackward=1;}
    }
  else if(orientation_adjust=='E')
    {if((((scientist1node==(nodeName_adjust-1)))&&(scientist1orientation_adjust=='W'))||(((scientist2node==(nodeName_adjust-1)))&&(scientist2orientation_adjust=='W')))
      {scientistBackward=1;}
    else if((((scientist1node==(nodeName_adjust+1)))&&(scientist1orientation_adjust=='E'))||(((scientist2node==(nodeName_adjust+1)))&&(scientist2orientation_adjust=='E')))
      {scientistForward=1;}
    }
  }
else if(nodeName_adjust==45)
  {if(orientation_adjust=='N')
    {if(((scientist1node==(nodeName_adjust+5))&&(scientist1orientation_adjust=='N'))||((scientist2node==(nodeName_adjust+5))&&(scientist2orientation_adjust=='N')))
      {scientistForward=1;}
    }
  else if(orientation_adjust=='S')
    {if(((scientist1node==(nodeName_adjust+5))&&(scientist1orientation_adjust=='N'))||((scientist2node==(nodeName_adjust+5))&&(scientist2orientation_adjust=='N')))
      {scientistBackward=1;}
    }
         } 
else if(nodeName_adjust==46)
  {if(orientation_adjust=='N')
    {if(((scientist1node==(nodeName_adjust+5))&&(scientist1orientation_adjust=='N'))||((scientist2node==(nodeName_adjust+5))&&(scientist2orientation_adjust=='N')))
      {scientistForward=1;}
    else if(((scientist1node==(nodeName_adjust-5))&&(scientist1orientation_adjust=='S'))||((scientist2node==(nodeName_adjust-5))&&(scientist2orientation_adjust=='S')))
      {scientistBackward=1;}
    }
  else if(orientation_adjust=='S')
    {if(((scientist1node==(nodeName_adjust+5))&&(scientist1orientation_adjust=='N'))||((scientist2node==(nodeName_adjust+5))&&(scientist2orientation_adjust=='N')))
      {scientistForward=1;}
    else if(((scientist1node==(nodeName_adjust-5))&&(scientist1orientation_adjust=='S'))||((scientist2node==(nodeName_adjust-5))&&(scientist2orientation_adjust=='S')))
      {scientistBackward=1;}
    }
  else if(orientation_adjust=='W')
    {if(((scientist1node==(nodeName_adjust-1))&&(scientist1orientation_adjust=='W'))||((scientist2node==(nodeName_adjust-1))&&(scientist2orientation_adjust=='W')))
      {scientistForward=1;}
    }
  else if(orientation_adjust=='E')
    {if(((scientist1node==(nodeName_adjust-1))&&(scientist1orientation_adjust=='W'))||((scientist2node==(nodeName_adjust-1))&&(scientist2orientation_adjust=='W')))
      {scientistBackward=1;}
    }
  }
else if(nodeName_adjust==47)
  {if(orientation_adjust=='N')
    {if(((scientist1node==(nodeName_adjust+5))&&(scientist1orientation_adjust=='N'))||((scientist2node==(nodeName_adjust+5))&&(scientist2orientation_adjust=='N')))
      {scientistForward=1;}
    else if(((scientist1node==(nodeName_adjust-5))&&(scientist1orientation_adjust=='S'))||((scientist2node==(nodeName_adjust-5))&&(scientist2orientation_adjust=='S')))
      {scientistBackward=1;}
    }
  else if(orientation_adjust=='S')
    {if(((scientist1node==(nodeName_adjust+5))&&(scientist1orientation_adjust=='N'))||((scientist2node==(nodeName_adjust+5))&&(scientist2orientation_adjust=='N')))
      {scientistBackward=1;}
    else if(((scientist1node==(nodeName_adjust-5))&&(scientist1orientation_adjust=='S'))||((scientist2node==(nodeName_adjust-5))&&(scientist2orientation_adjust=='S')))
      {scientistForward=1;}
    }
  else if(orientation_adjust=='W')
    {if((((scientist1node==(nodeName_adjust-1))||(scientist1node==(nodeName_adjust-2)))&&(scientist1orientation_adjust=='W'))||(((scientist2node==(nodeName_adjust-1))||(scientist2node==(nodeName_adjust-2)))&&(scientist2orientation_adjust=='W')))
      {scientistForward=1;}
    else if((((scientist1node==(nodeName_adjust+1))||(scientist1node==(nodeName_adjust+2)))&&(scientist1orientation_adjust=='E'))||(((scientist2node==(nodeName_adjust+1))||(scientist2node==(nodeName_adjust+2)))&&(scientist2orientation_adjust=='E')))
      {scientistBackward=1;}
    }
  else if(orientation_adjust=='E')
    {if((((scientist1node==(nodeName_adjust-1))||(scientist1node==(nodeName_adjust-2)))&&(scientist1orientation_adjust=='W'))||(((scientist2node==(nodeName_adjust-1))||(scientist2node==(nodeName_adjust-2)))&&(scientist2orientation_adjust=='W')))
      {scientistBackward=1;}
    else if((((scientist1node==(nodeName_adjust+1))||(scientist1node==(nodeName_adjust+2)))&&(scientist1orientation_adjust=='E'))||(((scientist2node==(nodeName_adjust+1))||(scientist2node==(nodeName_adjust+2)))&&(scientist2orientation_adjust=='E')))
      {scientistForward=1;}
    }
  }

else if(nodeName_adjust==48)
  {if(orientation_adjust=='N')
    {if(((scientist1node==(nodeName_adjust+5))&&(scientist1orientation_adjust=='N'))||((scientist2node==(nodeName_adjust+5))&&(scientist2orientation_adjust=='N')))
      {scientistForward=1;}
    }
  else if(orientation_adjust=='S')
    {if(((scientist1node==(nodeName_adjust+5))&&(scientist1orientation_adjust=='N'))||((scientist2node==(nodeName_adjust+5))&&(scientist2orientation_adjust=='N')))
      {scientistBackward=1;}
    }
  else if(orientation_adjust=='W')
    {if((((scientist1node==(nodeName_adjust+1)))&&(scientist1orientation_adjust=='E'))||(((scientist2node==(nodeName_adjust+1)))&&(scientist2orientation_adjust=='E')))
      {scientistBackward=1;}
    }
  else if(orientation_adjust=='E')
    {if((((scientist1node==(nodeName_adjust+1)))&&(scientist1orientation_adjust=='E'))||(((scientist2node==(nodeName_adjust+1)))&&(scientist2orientation_adjust=='E')))
      {scientistForward=1;}
    }
  }
else if(nodeName_adjust==49)
  {if(orientation_adjust=='N')
    {if(((scientist1node==(nodeName_adjust+5))&&(scientist1orientation_adjust=='N'))||(scientist2node==(nodeName_adjust+5))&&(scientist2orientation_adjust=='N'))
      {scientistForward=1;}
    else if(((scientist1node==(nodeName_adjust-5))&&(scientist1orientation_adjust=='S'))||(scientist2node==(nodeName_adjust-5))&&(scientist2orientation_adjust=='S'))
      {scientistBackward=1;}
    }
  else if(orientation_adjust=='S')
    {if(((scientist1node==(nodeName_adjust+5))&&(scientist1orientation_adjust=='N'))||((scientist2node==(nodeName_adjust+5))&&(scientist2orientation_adjust=='N')))
      {scientistBackward=1;}
    else if(((scientist1node==(nodeName_adjust-5))&&(scientist1orientation_adjust=='S'))||((scientist2node==(nodeName_adjust-5))&&(scientist2orientation_adjust=='S')))
      {scientistForward=1;}
    }
  }
else if(nodeName_adjust==53)
  
        {if(orientation_adjust=='W')
    {if(((scientist1node==(nodeName_adjust+1))&&(scientist1orientation_adjust=='E'))||(((scientist2node==(nodeName_adjust+1)))&&(scientist2orientation_adjust=='E')))
      {scientistBackward=1;}
      else if(((scientist1node==(nodeName_adjust-1))&&(scientist1orientation_adjust=='W'))||(((scientist2node==(nodeName_adjust-1)))&&(scientist2orientation_adjust=='W')))
      {scientistForward=1;}
    }
  else if(orientation_adjust=='E')
    {if(((scientist1node==(nodeName_adjust+1))&&(scientist1orientation_adjust=='E'))||(((scientist2node==(nodeName_adjust+1)))&&(scientist2orientation_adjust=='E')))
      {scientistForward=1;}
      else if(((scientist1node==(nodeName_adjust-1))&&(scientist1orientation_adjust=='W'))||(((scientist2node==(nodeName_adjust-1)))&&(scientist2orientation_adjust=='W')))
      {scientistBackward=1;}
    }
  }
Serial.println(scientistForward);
Serial.println(scientistBackward);
}



