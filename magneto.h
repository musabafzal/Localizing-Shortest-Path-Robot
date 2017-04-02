#include <Wire.h>
#include <HMC5883L.h>

HMC5883L compass;


float getMagnetoReadings() {
  Vector norm = compass.readNormalize();

  // Calculate heading
  float heading = atan2(norm.YAxis, norm.XAxis);

  // Set declination angle on your location and fix heading
  // You can find your declination on: http://magnetic-declination.com/
  // (+) Positive or (-) for negative
  // For Bytom / Poland declination angle is 4'26E (positive)
  // Formula: (deg + (min / 60.0)) / (180 / M_PI);
  float declinationAngle = (-158.85 + (26.0 / 60.0)) / (180 / M_PI);
  heading += declinationAngle;

  // Correct for heading < 0deg and heading > 360deg
  if (heading < 0)
  {
    heading += 2 * PI;
  }

  if (heading > 2 * PI)
  {
    heading -= 2 * PI;
  }

  // Convert to degrees
  int headingDegrees = heading * 180 / M_PI;


  //return headingDegrees;

  if (headingDegrees >= 0 && headingDegrees < 13 || headingDegrees >= 350 && headingDegrees < 360)
    return 0; //North

  else if (headingDegrees >= 85 && headingDegrees <= 95)
    return 1;//East

   
  else if (headingDegrees >= 170 && headingDegrees <= 190)
    return 2;//South

   
  else if (headingDegrees >= 260 && headingDegrees <= 280)
    return 3;//West

}
