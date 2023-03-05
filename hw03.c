/*****+---**-**-**---*--*-----*--------*-*-***--****************************
*
*  Homework #:03
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified.  Neither have I provided access to my code 
*  to another. The effort I am submitting is my own original work.
*
*  Program Description: This program takes various inputs with a 4 digit ID
*  number, program number, start and graduation year, and digit locations 
*  for a specific section of the calculated ID, then calculated a 12 digits 
*  ID and the portion of the DI that falls within the digit locations
*
******+---**-**-**---*--*-----*--------*-*-***--***************************/
#include<stdio.h>
#include<math.h>

int getID(void);
int getProgram(void);
int getYear(char);
int getLocation(int);
long long calcID(int, int, int, int);
long long calcDigits(long long, int, int);
void output(long long, long long, int, int);

int main(void)
{
  int short_ID; //variable for 4 digit ID number
  int program; //variable to store program number
  int year_S; //variable for start year
  int year_G; //variable for graduation year
  int location_one; //variable for first digit location
  int location_two; //variable for second digit location
  long long student_ID; //long long data type for 12 digit ID
  long long digits; //long long data type for digits

  short_ID = getID();
  program = getProgram();
  year_S = getYear('S');
  year_G = getYear('G');
  location_one = getLocation(1);
  location_two = getLocation(2);
  student_ID = calcID(short_ID, program, year_S, year_G);
  digits = calcDigits(student_ID, location_one, location_two);

  output(student_ID, digits, location_one, location_two);

  return 0;
}

/*****+-*-**-*--**---*--*-----*--------*-*-***--****************************
*
*  Function Information
*
*  Name of Function: getID
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. void
*
*  Function Description: This function gets the user input for the 4 digit ID.
*
******+-*-**-*--**---*--*-----*--------*-*-***--***************************/
int getID(void)
{
  int short_ID; //creating variable to store 4 digit ID

  printf("Enter student ID -> ");
  scanf("%d", &short_ID);

  return short_ID;
}

/*****+---**-*--**---*--*-----*--------*-*-***--****************************
*
*  Function Information
*
*  Name of Function: getProgram
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. void
*
*  Function Description: This function get the user input for the program number.
*
******+---**-*--**---*--*-----*--------*-*-***--***************************/
int getProgram(void)
{
  int program; //variable for program number

  printf("Enter program # -> ");
  scanf("%d", &program);

  return program;
}

/*****+-*-*****--*---*--*-----*--------*-*-***--****************************
*
*  Function Information
*
*  Name of Function: getYear
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. char a - character value for 'S' or 'G'
*
*  Function Description: This function gets the input for start and grad years.
*
******+-*-*****--*---*--*-----*--------*-*-***--***************************/
int getYear(char a)
{
  int year; //variable to return year input

  printf("Enter year (%c) -> ", a);
  scanf("%d", &year);

  return year;
}

/*****+---*****--*---*--*-----*--------*-*-***--****************************
*
*  Function Information
*
*  Name of Function: getLocation
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int a - number value for which location is being inputted
*
*  Function Description: This function gets the digit locations from the user.
*
******+---*****--*---*--*-----*--------*-*-***--***************************/
int getLocation(int a)
{
  int location; //variable to return digit locations

  printf("Enter location #%d -> ", a);
  scanf("%d", &location);

  return location;
}

/*****+-*-**-*---*--***-------*--------*-*-***--****************************
*
*  Function Information
*
*  Name of Function: calcID
*
*  Function Return Type: long long
*
*  Parameters (list data type, name, and comment one per line):
*    1. int short_ID - 4 digit ID
*    2. int program - program number
*    3. int year_S - start year
*    4. int year_G - graduation year
*
*  Function Description: This function takes the 4 inputs from the user and
*  uses them to calculate 12 digit ID number.
*
******+-*-**-*---*--***-------*--------*-*-***--***************************/
long long calcID(int short_ID, int program, int year_S, int year_G)
{
  long long student_ID; //long long data type for the 12 digit calculated ID

  student_ID = ((long long)year_S * 100000000) + (program * 1000000) + ((year_G - year_S) * 10000) + short_ID;

  return student_ID;
}

/*****+---****--***--**-------*--------*-*-***--****************************
*
*  Function Information
*
*  Name of Function: calcDigits
*
*  Function Return Type: long long
*
*  Parameters (list data type, name, and comment one per line):
*    1. long long student_ID - 12 digit ID previously calculated
*    2. int location_one - digit location 1
*    3. int location_two - digit location 2
*
*  Function Description: This function calculates the number between the two
*  digit location using the modulus and division operators and power function
*  from the math library
*
******+---****--***--**-------*--------*-*-***--***************************/
long long calcDigits(long long student_ID, int location_one, int location_two)
{
  long long digits; //long long data type to return digits value

  digits = (student_ID / (long long)pow(10, location_one - 1)) % (long long)pow(10, (location_two - location_one + 1));

  return digits;
}

/*****+---****--**---**-------*--------*-*-***--****************************
*
*  Function Information
*
*  Name of Function: output
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. long long student_ID - 12 digit calculated ID
*    2. long long digits - returned value from calcDigits function
*    3. int location_one - digits location 1
*    4. int location_two - digits location 2
*
*  Function Description: This function takes the two calculated values and the
*  location values and displays them in the desired format.
*
******+---****--**---**-------*--------*-*-***--***************************/
void output(long long student_ID, long long digits, int location_one, int location_two)
{
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("Student ID: %19lld\n", student_ID);
  printf("Digits (%-2d to %2d): %12lld\n", location_one, location_two, digits);
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
}

