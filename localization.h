#include <math.h>
#include "theta.h"

int localize(float sensorL, float sensorR, float sensorF, float sensorB, float color){


  
  	int m=55, n=9, p=9, q=1, c, d, k;
	float color1=color; float color2=color*color;float color3=color*color*color;float color4=color*color*color*color; 
	float sum = 0;
  	float testcase[9][1]={1,sensorL,sensorR,sensorF,sensorB,color1,color2,color3,color4};
	float result[55][1]={0};
	float hthetaX[55][1]={0};
 
    for (c = 0; c < m; c++) {
      for (d = 0; d < q; d++) {
        for (k = 0; k < p; k++) {
          sum = sum + thetat[c][k]*testcase[k][d];
        }
        result[c][d] = sum;
        sum = 0;
      }
    }
 
	float negativez;
	float exponential;


    for (c = 0; c < m; c++) {
      	for (d = 0; d < q; d++){
			negativez=-1*result[c][d];	
			exponential=exp(negativez);
			hthetaX[c][d]=1/(1+exponential);			
	 	}
    }

    float maxvalue;
    int maxindex=0;
    maxvalue=hthetaX[0][0];
    for(c=0;c<m;c++){
    	if(hthetaX[c][0]>maxvalue){
    		maxvalue=hthetaX[c][0];		
    		maxindex=c;
		}		
	}
    maxindex++;
  	return maxindex;
}
