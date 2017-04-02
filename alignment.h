void wallAlign(){
    //L1 0
    //L2 1
    //F  2
    //R2 3
    //R1 4
    //B  5
  storeSonarReadingsForWallAlign();
  //oneSensorCycle();
  if(in[5]<45||in[3]<65){
  if(in[5]<in[3]){
    while(1){
      storeSonarReadingsForWallAlign();
  //    oneSensorCycle();
    if(in[0]==in[5]){  
         break;
    }else if(in[5]>in[0]){      
       analogWrite(rightForward,45);
       analogWrite(leftBackward,45);
                analogWrite(leftForward,0);
            analogWrite(rightBackward,0); 
    }
    else if(in[5]<in[0]){
       analogWrite(leftForward,45);
       analogWrite(rightBackward,45);   
                 analogWrite(rightForward,0);
            analogWrite(leftBackward,0); 
    }  
    }
  }
  else if(in[5]>=in[3]){
    while(1){
      storeSonarReadingsForWallAlign();
  //    oneSensorCycle();
    if(in[3]==in[4]){
    
        break; 
    }else if(in[3]>in[4]){
       analogWrite(leftForward,45);
       analogWrite(rightBackward,45);
                 analogWrite(rightForward,0);
            analogWrite(leftBackward,0);
    }
    else if(in[3]<in[4]){
       analogWrite(rightForward,45);
       analogWrite(leftBackward,45);
                  analogWrite(leftForward,0);
            analogWrite(rightBackward,0);  
    }  
  }
  
  }
          analogWrite(rightForward,0);
            analogWrite(leftBackward,0);
            analogWrite(leftForward,0);
            analogWrite(rightBackward,0);  
  }
}

void perfectWallAlign(){
  do{
    wallAlign();
    delay(45);
    storeSonarReadingsForWallAlign();
  }while(in[3]!=in[4]);
}
/*int countalign=0;
void wallAlignMagneto(){
  while(1){
  int magnetoInt=getMagnetoReadings();
  Serial.println(magnetoInt);
    
  if(magnetoInt>318){
       analogWrite(rightForward,45);
       analogWrite(leftBackward,45);
       analogWrite(leftForward,0);
            analogWrite(rightBackward,0);
  }
  else if(magnetoInt<318){ 
    analogWrite(leftForward,45);
    analogWrite(rightBackward,45);
      analogWrite(rightForward,0);
            analogWrite(leftBackward,0);
  }else{
          countalign++;
             
  }

  if(countalign>45){
    break;
  }
  }
  analogWrite(rightForward,0);
            analogWrite(leftBackward,0);
            analogWrite(leftForward,0);
            analogWrite(rightBackward,0);
       
}*/
/*void alignInBetween(){
    //L1 0
    //L2 1
    //F  2
    //R2 3
    //R1 4
    //B  5

  int saveLeft;
  int saveRight;
  storeSonarReadingsForWallAlign();
  //oneSensorCycle();
  
  saveRight=in[4];
  Serial.println(in[4]);
      turnRight(1);
  while(1){
    storeSonarReadingsForWallAlign();
    oneSensorCycle();
  if(in[2]==saveRight){
      
      break;
  }else if(in[2]>saveRight){
          analogWrite(rightForward,45);
      analogWrite(leftForward,45);

  }else if(in[2]<saveRight){
      analogWrite(rightBackward,45);
      analogWrite(leftBackward,45);
  }
  }

          analogWrite(rightForward,0);
            analogWrite(leftBackward,0);
            analogWrite(leftForward,0);
            analogWrite(rightBackward,0);
}*/
