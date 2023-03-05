/*****+--*--******-**----**-**-*-*-*-**--*-***--****************************
*
*  Lab #:02
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work.
*
*  Program Description: User will input the time in hours and minute for a 
*  travel round trip and distance in miles. The program will then calculate 
*  the one way travel time and average speed both in miles per hour and meter 
*  per second.
*
******+--*--******-**----**-**-*-*-*-**--*-***--***************************/
#include <stdio.h>
#define CONVERSION 1609.344 

int main(void)
{
  int hours; //require the user to enter value of hours
  int minutes; //require the user to enter the value of minutes
  double distance; //require the user to enter the value of distance
  double oneWayTime; //calculated the time for one way
  double averageSpeed; //calculated the average speed

  //Chunk of code to accept inputs from user
  printf("Enter time of round trip [hours minutes] -> ");
  scanf("%d %d", &hours, &minutes);
  printf("Enter one-way distance (miles) -> ");
  scanf("%lf", &distance);

  //Calculations
  oneWayTime = ( hours + minutes / 60.0 ) / 2 ;
  averageSpeed = distance / oneWayTime ;

  //First set of outputs 
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
  printf("\nOne Way Time:%12.3lf hours", oneWayTime);
  printf("\nAverage Speed:%11.3lf mph", averageSpeed);
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");

  //Conversion Calculations
  oneWayTime = oneWayTime * 60 * 60 ;
  averageSpeed = CONVERSION * averageSpeed / 3600 ;

  //Second set of outputs
  printf("\nOne Way Time: %-12.3lfseconds", oneWayTime);
  printf("\nAverage Speed: %-11.3lfm/s", averageSpeed);
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

  return 0;
}
