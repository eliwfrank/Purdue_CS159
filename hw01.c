/*****+---****---*--***-*-*-----*-*---**-*-***--****************************
*
*  Homework #:01
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified.  Neither have I provided access to my code 
*  to another. The effort I am submitting is my own original work.
*
*  Program Description: 
*
*  This program takes inputs for the dimensions of a vineyard, the space 
*  needed for the posts that terminate each row or column of vines, and the 
*  distance between each set of vines. It will then output the area of the 
*  field, and the number of new vines that could be planted per row and column.
*
******+---****---*--***-*-*-----*-*---**-*-***--***************************/
#include<stdio.h>

int main(void)
{
  // Local Declarations
  int rows; //User input for the number of rows
  int columns; //User input for the number of columns
  int space; //User input for the spaced needed for each terminal post
  int distance; //User input for the distance between vines
  int area; //Function of the number of rows and columns
  int vinesRow; //Number of vines per row when arranged in columns
  int vinesColumn; //Number of vines per column when arranged in rows

  //The following code chunk accepts inputs from the user to process
  printf("Enter the field dimensions [row columns] -> ");
  scanf("%d %d", &rows, &columns);
  printf("Enter the space needed for each terminal post -> ");
  scanf("%d", &space);
  printf("Enter the distance between vines -> ");
  scanf("%d", &distance);

  //The following chunk calculates previously uninitialized variables
  area = rows * columns;
  vinesRow = ((columns - (space * 2)) + distance) / (distance + 1);
  vinesColumn = ((rows - (space * 2)) + distance) / (distance + 1);

  //This chunk prints the outputs to the function
  printf("\nArea of field %d by %d: %d\n", rows, columns, area);
  printf("Total vines per row: %d [total %d]\n", vinesRow, vinesRow * rows);
  printf("Total vines per column: %d [total %d]\n", vinesColumn, vinesColumn * columns);

  return(0);
}
