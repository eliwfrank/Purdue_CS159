/*****+---****--**---*--*---*---*---*-**-*-***--****************************
*
*  Lab #: 00
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work.
*
*  Program Description: The purpose of this program is to round numbers inputted by the user to the nearest tenth of a decimal place.
*
******+---****--**---*--*---*---*---*-**-*-***--***************************/
#include <stdio.h>

int main(void)
{
  float measurement; // user-provided measurement

  printf("Enter measurement -> ");
  scanf("%f", &measurement);

  printf("-=-=-=-=-=-=-=-=-=-\n");
  printf("The measurement rounded: %.1f\n", measurement); //This outputs the number rounded to the nearest tenth
  return 0;
}
