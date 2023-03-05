/*****+----*-*--**--***-*-*-*---*-*----*-*-***--****************************
*
*  Lab #:04
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work.
*
*  Program Description: This program takes a 12 digit ID number and the current
*  year and outputs a 4 digit student ID, the program the student is enrolled
*  in, the student's start and graduation year, and their graduation status.
*
******+----*-*--**--***-*-*-*---*-*----*-*-***--***************************/
#include<stdio.h>

long long getID(void); //function to get 12 digit ID input from user
int getYear(void); //function to get current year from user
void calcs(long long a, int b, int *short_ID, int *program, int *year_S, int *year_G, char *grad_status); //function to perform all calculations with pass by address
void Output(int short_ID, int program, int year_S, int year_G, char grad_status); //function to output all print statements.

int main(void)
{
  long long student_ID; //long data type to take the 12 digit ID number from the user
  int current_year; //takes the current year input from the user
  int short_ID; //variable to accept modified 4 digit ID value
  int program; //variable to accept program #
  int year_S; //variable to accept calculated value of start year
  int year_G; //variable to accept calculated value of grad year
  char grad_status; //character type to display binary graduation status

  student_ID = getID();
  current_year = getYear();
  calcs(student_ID, current_year, &short_ID, &program, &year_S, &year_G, &grad_status);
  Output(short_ID, program, year_S, year_G, grad_status);

  return(0);
}

/*****+----*-*--***--**-*-*-*---*-*----*-*-***--****************************
*
*  Function Information
*
*  Name of Function: getID
*
*  Function Return Type: long long
*
*  Parameters (list data type, name, and comment one per line):
*    1. void
*
*  Function Description: This function gets a 12 digit ID from the user
*
******+----*-*--***--**-*-*-*---*-*----*-*-***--***************************/
long long getID(void)
{
  long long student_ID; //long long data type to take the 12 digit ID number from user

  printf("Enter student ID -> ");
  scanf("%lld", &student_ID);

  return(student_ID);
}

/*****+----***---*---**-*-*-*---*-*----*-*-***--****************************
*
*  Function Information
*
*  Name of Function: getYear
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. void
*
*  Function Description: This function gets the current year from the user.
*
******+----***---*---**-*-*-*---*-*----*-*-***--***************************/
int getYear(void)
{
  int current_year; //variable to take the value from the user for the current year

  printf("Enter current year -> ");
  scanf("%d", &current_year);

  return(current_year);
}

/*****+-*-**-*---*---**-*-*-*---*-*----*-*-***--****************************
*
*  Function Information
*
*  Name of Function: calcs
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. long long long_ID - 12 digit ID inputted by user
*    2. int current_year - current year inputted by user
*    3. int *short_ID - pointer value for 4 digit ID calc
*    4. int *program - pointer value for program calc
*    5. int *year_S - pointer value for start year
*    6. int *year_G - pointer value for grad year
*    7. char *grad_status - pointer char value for grad status
*
*  Function Description: This function takes the inputs generated by the user
*  for the 12 digit number and the current year and uses them to calculate a
*  4 digit ID, program number, start and graduation year, and graduation status.
*
******+-*-**-*---*---**-*-*-*---*-*----*-*-***--***************************/
void calcs(long long long_ID, int current_year, int *short_ID, int *program, int *year_S, int *year_G, char *grad_status)
{
  //Chunk of code to calculate values for later output
  *short_ID = long_ID % 10000;
  *program = (long_ID / 1000000) % 100;
  *year_S = long_ID / 100000000;
  *year_G = *year_S + ((long_ID / 10000) % 100);
  *grad_status = 'N' + ((current_year / *year_G) * ('Y' - 'N'));
}

/*****+-*-**-*---*---**-*-*-*---*-*----*-*-***--****************************
*
*  Function Information
*
*  Name of Function: Output
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int short_ID - 4 digit ID number
*    2. int program - program enrolled number
*    3. int year_S - start year
*    4. int year_G - grad year
*    5. char grad_status - graduation status
*
*  Function Description: This function takes the previously calculated values
*  and outputs them in the format required by the guidelines.
*
******+-*-**-*---*---**-*-*-*---*-*----*-*-***--***************************/
void Output(int short_ID, int program, int year_S, int year_G, char grad_status)
{
  //Chunk of print statements for output in desired format
  printf("\n=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("Student ID: %10d\n", short_ID);
  printf("Program Enrolled: %4d\n", program);
  printf("Start year: %10d\n", year_S);
  printf("Graduation year: %5d\n", year_G);
  printf("Graduated: %11c\n", grad_status);
  printf("=-=-=-=-=-=-=-=-=-=-=-\n");
}