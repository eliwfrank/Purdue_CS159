/*****+----*-**--**-***-*---*-*---*---**-*-***--****************************
*
*  Lab #:01
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work.
*
*  Program Description:
*
*  This program will take inputs for the diameter and height of a cylindrical
*  cake in inches and provide calculated outputs for the cake volume, cake 
*  surface area, and the volume and dimensions of a box that will fit the cake
*  with a half inch tolerance on each side and a one inch tolerance on top.
*
******+----*-**--**-***-*---*-*---*---**-*-***--***************************/
#include<stdio.h>
#define PI 3.14159

int main(void)
{
  float diameterCake; //Cake diameter(in): initialized by user input
  float heightCake; //Cake height(in): initialized by user input
  float radiusCake; //1/2 of the Cake diameter, makes calculating outputs easier
  float volumeCake; //Cake volume(in^3)
  float surfaceArea; //Cake surface area(in^2)
  float widthBox; //width and length of box(in): calculated from diameterCake
  float heightBox; //height of box(in): calculated from heightCake
  float volumeBox; //volume of box(in^3): calculated from widthBox and heightBox

  //This chunk of code accepts user inputs for cake diameter and height
  printf("Enter the cake diameter -> ");
  scanf("%f", &diameterCake);
  printf("Enter the cake height -> ");
  scanf("%f", &heightCake);

  //This chunk of code calculates uninitialized variables
  radiusCake = (diameterCake / 2);
  volumeCake = PI * radiusCake * radiusCake * heightCake;
  surfaceArea = (2 * PI * radiusCake * radiusCake) + (2 * PI * radiusCake * heightCake);
  widthBox = diameterCake + 0.5;
  heightBox = heightCake + 1;
  volumeBox = widthBox * widthBox * heightBox;

  //This chunk of code outputs the calculated values
  printf("\nCake volume: %.2f\n", volumeCake);
  printf("Cake surface area: %.2f\n", surfaceArea);
  printf("Box dimensions needed: %.1f, %.1f, %.1f\n", widthBox, widthBox, heightBox);
  printf("Box volume: %.2f\n", volumeBox);
  return(0);
}
