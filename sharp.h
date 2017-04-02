#include <SharpIR.h>

#define irf A6
#define irb A7
#define model 20150

SharpIR sharpF(irf, 25, 95,model);
SharpIR sharpB(irb, 25, 95,model);

int sharp[2];

void getSharpReadings(){
    int dis1=sharpF.distance();
    int dis2=sharpB.distance();

    if(dis1<20||dis1>150)
      dis1=201;

    
    if(dis2<20||dis2>150)
      dis2 =201;
      
      sharp[0]=dis1/2.54;
      sharp[1]=dis2/2.54;

}

