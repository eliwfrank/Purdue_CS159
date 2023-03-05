/*****+-*-*****--**-**----------*------*-*-***--****************************
*
*  Lab #:05
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work.
*
*  Program Description: This program takes inputs for the surface rates of 
*  deceleration, velocity of the car in mph, and driver reaction time and 
*  calculates and outputs the velocity of the car in m/s, stopping distance, 
*  reaction distance, and total distance, all in meters.
*
******+-*-*****--**-**----------*------*-*-***--***************************/
#include<stdio.h>
#include<math.h>
#define CONVERSION 0.44704

float getDecel(int num);
float getVel(void);
float getReaction(void);
float velCalc(float velocity);
float stopping_distance(float velocity, float decel);
float reaction_distance(float velocity, float reaction);
float total_distance(float stopping_distance, float reaction_distance);
void output_one(float velocity, float reaction, float decel_one, float decel_two);
void output_two(float stopping_one, float stopping_two, float reaction, float total_one, float total_two);

int main(void)
{
  float decel_one; //variable for first deceleration value
  float decel_two; //variable for second deceleration value
  float velocity; //variable for velocity
  float reaction; //variable for reaction time
  float stopping_one; //variable for first stopping distance
  float stopping_two; //variable for second stopping distance
  float react_distance; //variable for reaction distance
  float total_one; //variable for first total distance
  float total_two; //variable for second total distance

  decel_one = getDecel(1);
  decel_two = getDecel(2);
  velocity = getVel();
  reaction = getReaction();
  velocity = velCalc(velocity);
  stopping_one = stopping_distance(velocity, decel_one);
  stopping_two = stopping_distance(velocity, decel_two);
  react_distance = reaction_distance(velocity, reaction);
  total_one = total_distance(stopping_one, react_distance);
  total_two = total_distance(stopping_two, react_distance);

  output_one(velocity, reaction, decel_one, decel_two);
  output_two(stopping_one, stopping_two, react_distance, total_one, total_two);

  return 0;
}

/*****+----***--**--**------*---*-*-*-******-*--****************************
*
*  Function Information
*
*  Name of Function: getDecel
*
*  Function Return Type: float
*
*  Parameters (list data type, name, and comment one per line):
*    1. int num - surface number (1 or 2)
*
*  Function Description: This function gets the user input for deceleration.
*
******+----***--**--**------*---*-*-*-******-*--***************************/
float getDecel(int num)
{
  float decel; //variable to return inputted deceleration value

  printf("Enter deceleration rate of surface #%d (m/s^2) -> ", num);
  scanf("%f", &decel);

  return decel;
}

/*****+---**-*--**--**------*---*-*-*-******-*--****************************
*
*  Function Information
*
*  Name of Function: getVel
*
*  Function Return Type: float
*
*  Parameters (list data type, name, and comment one per line):
*    1. void
*
*  Function Description: This function gets the velocity for the user.
*
******+---**-*--**--**------*---*-*-*-******-*--***************************/
float getVel(void)
{
  float velocity; //variable to return inputted velocity value

  printf("Enter velocity of car (mph) -> ");
  scanf("%f", &velocity);

  return velocity;
}

/*****+-*--*-**--*--**------*---*-*-*-******-*--****************************
*
*  Function Information
*
*  Name of Function: getReaction
*
*  Function Return Type: float
*
*  Parameters (list data type, name, and comment one per line):
*    1. void
*
*  Function Description: This function gets the reaction time from the user.
*
******+-*--*-**--*--**------*---*-*-*-******-*--***************************/
float getReaction(void)
{
  float reaction; //variable to return inputted reaction time

  printf("Enter reaction time to engage brake (s) -> ");
  scanf("%f", &reaction);

  return reaction;
}

/*****+---*****-***--*------*---*-*-*-******-*--****************************
*
*  Function Information
*
*  Name of Function: velCalc
*
*  Function Return Type: float
*
*  Parameters (list data type, name, and comment one per line):
*    1. float velocity
*
*  Function Description: This function converts the velocity from mph to m/s.
*
******+---*****-***--*------*---*-*-*-******-*--***************************/
float velCalc(float velocity)
{
  return velocity * CONVERSION;
}

/*****+----****-***--*------*---*-*-*-******-*--****************************
*
*  Function Information
*
*  Name of Function: stopping_distance
*
*  Function Return Type: float
*
*  Parameters (list data type, name, and comment one per line):
*    1. float velocity - value calculated by velCalc function
*    2. float decel - inputted deceleration value
*
*  Function Description: This function calculates the stopping distance.
*
******+----****-***--*------*---*-*-*-******-*--***************************/
float stopping_distance(float velocity, float decel)
{
  float stopping_distance; //variable to return stopping distance

  stopping_distance = (velocity * velocity) / (2.0 * decel);

  return stopping_distance;
}

/*****+-*--*-**-***--*------*---*-*-*-******-*--****************************
*
*  Function Information
*
*  Name of Function: reaction_distance
*
*  Function Return Type: float
*
*  Parameters (list data type, name, and comment one per line):
*    1. float velocity - calculated velocity value
*    2. float reaction - reaction time
*
*  Function Description: This function calculates the reaction distance.
*
******+-*--*-**-***--*------*---*-*-*-******-*--***************************/
float reaction_distance(float velocity, float reaction)
{
  return velocity * reaction;
}

/*****+-*--***--***--*------*---*-*-*-******-*--****************************
*
*  Function Information
*
*  Name of Function: total_distance
*
*  Function Return Type: float
*
*  Parameters (list data type, name, and comment one per line):
*    1. float stopping_distance - calculated stopping distance value
*    2. float reaction_distance - calculated reaction distance value
*
*  Function Description: This function calculates the total distance.
*
******+-*--***--***--*------*---*-*-*-******-*--***************************/
float total_distance(float stopping_distance, float reaction_distance)
{
  return stopping_distance + reaction_distance;
}

/*****+-*--*-*--***--*------*---*-*-*-******-*--****************************
*
*  Function Information
*
*  Name of Function: output_one
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. float velocity - velocity value
*    2. float reaction - reaction time
*    3. float decel_one - first deceleration value
*    4. float decel_two - second deceleration value
*
*  Function Description: This function produces the first set of outputs.
*
******+-*--*-*--***--*------*---*-*-*-******-*--***************************/
void output_one(float velocity, float reaction, float decel_one, float decel_two)
{
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("Velocity of car -- %8.1f m/s\n", velocity);
  printf("Reaction time -- %10.1f s\n", reaction);
  printf("Deceleration rates -- %5.1f m/s^2 %5.1f m/s^2\n", decel_one, decel_two);
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
}

/*****+-*--****--**--*------*---*-*-*-******-*--****************************
*
*  Function Information
*
*  Name of Function: output_two
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. float stopping_one - first stopping distance
*    2. float stopping_two - second stopping distance
*    3. float reaction - calculated reaction distance
*    4. float total_one - first total distance
*    5. float total_two - second total distance
*
*  Function Description: This function displays the second set of outputs.
*
******+-*--****--**--*------*---*-*-*-******-*--***************************/
void output_two(float stopping_one, float stopping_two, float reaction, float total_one, float total_two)
{
  printf("Stopping distance: %8.1f m %9.1f m\n", stopping_one, stopping_two);
  printf("Reaction distance: %20.1f m\n", reaction);
  printf("Total distance: %11.1f m %9.1f m\n", total_one, total_two);
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
}
