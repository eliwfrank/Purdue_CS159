/*****+-*-**-**-***--**-----*---*-----**-*-***--****************************
*
*  Homework #:02
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified.  Neither have I provided access to my code 
*  to another. The effort I am submitting is my own original work.
*
*  Program Description:
*
*  This program takes inputs with a 10-digit student ID number and the current
*  year and calculates the year the student started, when they graduate, and
*  whether or not they've already graduated.
******+-*-**-**-***--**-----*---*-----**-*-***--***************************/
#include<stdio.h>

int main(void)
{
  long long int student_id; // Input by user with the 10-digit ID number
  int current_year; // Input by user with the current year
  int start_year; // Value for the year the student started calculated from ID
  int tenure; // Value for how long the student will stay at school from last 2 digits
  char grad_status; // Char value Y or N for whether student has graduated

  //User inputs for ID number and current year
  printf("Enter student ID -> ");
  scanf("%10lld", &student_id);
  printf("Enter current year -> ");
  scanf("%d", &current_year);

  //Calculations for tenure, graduation year, and graduation status
  tenure = student_id % 10;
  start_year = (student_id / 1000000) + 1989;
  grad_status = 'N' + (current_year / (start_year + tenure)) * ('Y' - 'N');

  //Outputs with calculated values
  printf("\n=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("Student ID: %010lld\n", student_id);
  printf("Start year: %10d\n", start_year);
  printf("Graduation year: %5d\n", (start_year + tenure));
  printf("Graduated: %11c\n", grad_status);
  printf("=-=-=-=-=-=-=-=-=-=-=-\n");

  return (0);
}
