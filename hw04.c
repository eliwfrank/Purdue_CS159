/*****+-*--*-*--**--***-*---*---*-*---******-*--****************************
*
*  Homework #:4
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified.  Neither have I provided access to my code 
*  to another. The effort I am submitting is my own original work.
*
*  Program Description: This program takes inputs for a year and two dates 
*  during that year in a MM and DD format and outputs the name of the month
*  and day number and calculates the number of days between the two dates.
*
******+-*--*-*--**--***-*---*---*-*---******-*--***************************/
#include<stdio.h>
#include<stdlib.h>

int getYear(void);
int getMonth(int);
int getDay(int, int);
int calcDays(int, int);
void outMonth(int, int, int);
int calcDifference(int, int, int, int, int);
void outTotal(int, int);

int main(void)
{
  int year; //variable to store year
  int month_1; //first month input
  int day_max_1; //number of days in given month
  int day_1; //specific day in month
  int month_2; //second month input
  int day_max_2; //number of days in given month
  int day_2; //second specific day in month
  int total; //difference in days between two dates

  year = getYear();
  month_1 = getMonth(1);
  day_max_1 = calcDays(month_1, year);
  day_1 = getDay(1, day_max_1);
  month_2 = getMonth(2);
  day_max_2 = calcDays(month_2, year);
  day_2 = getDay(2, day_max_2);

  total = calcDifference(month_1, month_2, day_1, day_2, year);

  outMonth(month_1, day_1, 1);
  outMonth(month_2, day_2, 2);
  outTotal(year, total);

  return 0;
}

/*****+---*****--**--**-*---*---*-*---******-*--****************************
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
*  Function Description: This function gets the input of the year from the user.
*
******+---*****--**--**-*---*---*-*---******-*--***************************/
int getYear(void)
{
  int year; //year to be inputted by user

  printf("Enter the year -> ");
  scanf("%d", &year);

  return year;
}

/*****+----*-*---**--**-*---*---*-*---******-*--****************************
*
*  Function Information
*
*  Name of Function: getMonth
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. month_num - for first or second input
*
*  Function Description: This function gets the input for the month from the user.
*
******+----*-*---**--**-*---*---*-*---******-*--***************************/
int getMonth(int month_num)
{
  int month; //month to be inputted by user

  printf("Enter month #%d -> ", month_num);
  scanf("%d", &month);

  return month;
}

/*****+-*-**-**-**---**-*---*---*-*---******-*--****************************
*
*  Function Information
*
*  Name of Function: getDay
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int day_num - input number
*    2. int day_max - number of days in inputted month
*
*  Function Description: this function gets the day from the user.
*
******+-*-**-**-**---**-*---*---*-*---******-*--***************************/
int getDay(int day_num, int day_max)
{
  int day; //day to be inputted by user

  printf("Enter day #%d (1-%d) -> ", day_num, day_max);
  scanf("%d", &day);

  return day;
}

/*****+-*-****--**---**-*---*---*-*---******-*--****************************
*
*  Function Information
*
*  Name of Function: calcDays
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int month - inputted month
*    2. int year - inputted year
*
*  Function Description: This function calculates the number of days in a given
*  month while also accounting for leap years.
*
******+-*-****--**---**-*---*---*-*---******-*--***************************/
int calcDays(int month, int year)
{
  int days; //number of days in month

  if (month == 2)
  {
    days = 28 + ((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0)));
  }
  else
  {
    days = (31 - (month - 1) % 7 % 2);
  }

  return days;
}

/*****+----***--**---**-*---*---*-*---******-*--****************************
*
*  Function Information
*
*  Name of Function: outMonth
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int month_num - inputted month
*    2. int day - inputted day
*    3. int condition - condition for first or second output
*
*  Function Description: This function outputs the date with the name of the month
*
******+----***--**---**-*---*---*-*---******-*--***************************/
void outMonth(int month_num, int day, int condition)
{
  switch(condition) //determining whether to output first or second date
  {
    case 1 :
      printf("\nFirst date: ");
      break;
    case 2 :
      printf("\nSecond date: ");
      break;
  }

  switch(month_num) //name of month corresponding to number
  {
    case 1 :
      printf("January");
      break;
    case 2 :
      printf("February");
      break;
    case 3 :
      printf("March");
      break;
    case 4 :
      printf("April");
      break;
    case 5 :
      printf("May");
      break;
    case 6 :
      printf("June");
      break;
    case 7 :
      printf("July");
      break;
    case 8 :
      printf("August");
      break;
    case 9 :
      printf("September");
      break;
    case 10 :
      printf("October");
      break;
	case 11 :
      printf("November");
      break;
    case 12 :
      printf("December");
      break;
}
  printf(" %d", day);
}

/*****+----*-*--**---**-*---*---*-*---******-*--****************************
*
*  Function Information
*
*  Name of Function: calcDifference
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int month_1 - first month
*    2. int month_2 - second month
*    3. int days_1 - first day input
*    4. int days_2 - second day input
*    5. int year - year
*
*  Function Description: This function calculates the difference between dates 
*  in days using fall-through switch statements.
*
******+----*-*--**---**-*---*---*-*---******-*--***************************/
int calcDifference(int month_1, int month_2, int days_1, int days_2, int year)
{
  switch (month_1 - 1) //fall-through switch statement to determine number of days from Jan 1
  {
    case 11:
      days_1 += 30;
    case 10:
      days_1 += 31;
    case 9:
      days_1 += 30;
    case 8:
      days_1 += 31;
    case 7:
      days_1 += 31;
    case 6:
      days_1 += 30;
    case 5:
      days_1 += 31;
    case 4:
      days_1 += 30;
    case 3:
      days_1 += 31;
    case 2:
      days_1 += 28 + ((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0)));
    case 1:
      days_1 += 31;
  }

  switch (month_2 - 1) //fall-through switch statement to determine number of days from Jan 1
  {
    case 11:
      days_2 += 30;
    case 10:
      days_2 += 31;
    case 9:
      days_2 += 30;
    case 8:
      days_2 += 31;
    case 7:
      days_2 += 31;
    case 6:
      days_2 += 30;
    case 5:
      days_2 += 31;
    case 4:
      days_2 += 30;
    case 3:
      days_2 += 31;
    case 2:
      days_2 += 28 + ((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0)));
    case 1:
      days_2 += 31;
  }

  return abs(days_2 - days_1); //calculating difference of both numbers
}

/*****+---**-*---*---**-*---*---*-*---******-*--****************************
*
*  Function Information
*
*  Name of Function: outTotal
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int year - same year inputted by user
*    2. int total - total calculated by calcDifference function
*
*  Function Description: This function outputs the total number of days between
*  the two dates in the given year.
*
******+---**-*---*---**-*---*---*-*---******-*--***************************/
void outTotal(int year, int total)
{
  printf("\nTotal number of days between given dates in %d: %d\n", year, total);
}
