/*****+-*--*-*---*---*--*-*-*---*---*--*-*-***--****************************
*
*  Lab #:03
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work.
*
*  Program Description: This program takes inputs for the time of a round 
*  trip in hours and minutes, the one way distance and its units, and outputs
*  the one way time in hours with the average speed in the selected unit and
*  the one way time in seconds with the alternative unit (either m/s or mph).
*
******+-*--*-*---*---*--*-*-*---*---*--*-*-***--***************************/

#include <stdio.h>
#define CONVERSION 1609.344 

int main(void)
{
  int hours; //require the user to enter value of hours
  int minutes; //require the user to enter the value of minutes
  double distance; //require the user to enter the value of distance
  double oneWayTime; //calculated the time for one way
  double averageSpeed; //calculated the average speed
  int input; //input units from the user
  int zero_one; //altered input value for calculations
  char one = 'm'; //char value for the base units output
  char two = '/'; //char value for the base units output
  char three = 's'; //char value for the base units output
  double speed1; //variable for the output of speed in the selected units
  double speed2; //variable for the output of speed in the converted unit

  //User input and variable initialization
  printf("Enter time of round trip [hours minutes] -> ");
  scanf("%d %d", &hours, &minutes);
  printf("Enter distance units (1) meters (2) miles -> ");
  scanf("%d", &input);
  printf("Enter one-way distance -> ");
  scanf("%lf", &distance);

  //Calculations
  oneWayTime = (hours + minutes / 60.0) / 2;
  zero_one = input - 1;
  averageSpeed = distance / oneWayTime;
  speed1 = (averageSpeed * zero_one) + ((averageSpeed / 3600) * (1 - zero_one));

  //First set of outputs
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
  printf("\nOne Way Time:%11.1lf hours", oneWayTime );
  printf("\nAverage Speed:%10.3lf %c%c%c\n", speed1, one, (two + 65 * ((input - 1))), (three - 11 * (input - 1)));
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");

  //Conversion Calculations
  oneWayTime = oneWayTime * 3600;
  speed2 = (averageSpeed * (input % 2) / CONVERSION) + ((averageSpeed * CONVERSION / 3600) * (input - 1));

  //Second set of outputs
  printf("\nOne Way Time: %9.1lf seconds", oneWayTime);
  printf("\nAverage Speed: %8.3lf %c%c%c\n", speed2, one, (two + 65 * ((input - 2) * -1)), (three - 11 * ((input - 2) * -1)));
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

  return 0;
}
