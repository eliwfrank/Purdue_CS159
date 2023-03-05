/*****+**-***-***-***-----*-**-*-*-****-****-*--****************************
*
*  Lab #: 06
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work.
*
*  Program Description:
*  
*  Calculate a student's score, grade, and GPA from the given ID number and
*  designated score digit locations.
*
******+**-***-***-***-----*-**-*-*-****-****-*--***************************/
#include <stdio.h>
#include <math.h>

#define MINA 90
#define MINB 80
#define MINC 70
#define MIND 56

int getId();
int getDigit(int num);
int calcDigit(int studentId, int digit);
int calcScore(int digit_result_one, int digit_result_two);
char calcGrade(int score);
float calcGpa(int score);
char calcPostfix(int score);
void output(int score, char grade, char postfix, float GPA);

int main(void)
{
  int studentId; // student ID inputted by user
  int digit1; // digit one of score location inputted by user
  int digit2; // digit two of score location inputted by user
  int digit_result_one; // first digit of score
  int digit_result_two; // second digit of score
  int score; // student's score
  char grade; // student's letter grade
  char postfix; // plus or minus part of letter grade
  float gpa; // student's GPA

  studentId = getId();
  digit1 = getDigit(1);
  digit2 = getDigit(2);
  digit_result_one = calcDigit(studentId, digit1);
  digit_result_two = calcDigit(studentId, digit2);
  score = calcScore(digit_result_one, digit_result_two);
  grade = calcGrade(score);
  gpa = calcGpa(score);
  postfix = calcPostfix(score);
  output(score, grade, postfix, gpa);

  return(0);
}

/*****+**--**--**-***-----*-**-*-*-****-****-*--****************************
*
*  Function Information
*
*  Name of Function: getId
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1.
*    2.
*    3.
*
*  Function Description: Retrieve the student ID.
*
******+**--**--**-***-----*-**-*-*-****-****-*--***************************/
int getId()
{
  int id; // student ID

  printf("Enter student ID number -> ");
  scanf("%d", &id);

  return id;
}

/*****+*---**--**-***-----*-**-*-*-****-****-*--****************************
*
*  Function Information
*
*  Name of Function: getDigit
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int num // number of digit to retrieve
*    2.
*    3.
*
*  Function Description: Retrieve the digit locations in the student ID to
*                        calculate the score.
*
******+*---**--**-***-----*-**-*-*-****-****-*--***************************/
int getDigit(int num)
{
  int digit; // digit of score location
  if (num == 1)
  {
    printf("Enter the first digit of the score -> ");
    scanf("%d", &digit);
  }
  else
  {
    printf("Enter the second digit of the score -> ");
    scanf("%d", &digit);
  }

  return digit;
}

/*****+*---**--**-***-----*-**-*-*-****-****-*--****************************
*
*  Function Information
*
*  Name of Function: calcDigit
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int studentId // student ID
*    2. int digit // digit of score location
*    3.
*
*  Function Description: Calculate the location of an individual digit in
*                        the student ID.
*
******+*---**--**-***-----*-**-*-*-****-****-*--***************************/
int calcDigit(int studentId, int digit)
{
  int result; // digit of score

  result =  (studentId / pow(10, 7 - digit));

  return (result % 10);
}

/*****+*---**--**-***-----*-**-*-*-****-****-*--****************************
*
*  Function Information
*
*  Name of Function: calcScore
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int digit_result_one // first digit of score
*    2. int digit_result_two // second digit of score
*    3.
*
*  Function Description: Calculate the student's score.
*
******+*---**--**-***-----*-**-*-*-****-****-*--***************************/
int calcScore(int digit_result_one, int digit_result_two)
{
  int score; // student's score

  score = (digit_result_one * 10 + digit_result_two);

  if (score == 00)
  {
    score = 100;
  }
  return score;
}

/*****+*---**--**-***-----*-**-*-*-****-****-*--****************************
*
*  Function Information
*
*  Name of Function: calcGrade
*
*  Function Return Type: char
*
*  Parameters (list data type, name, and comment one per line):
*    1. int score // student's score
*    2.
*    3.
*
*  Function Description: Calculate the student's letter grade.
*
******+*---**--**-***-----*-**-*-*-****-****-*--***************************/
char calcGrade(int score)
{
  char grade; // student's letter grade

  if (score >= MINA)
  {
    grade = 'A';
  }
  else if (score >= MINB)
  {
    grade = 'B';
  }
  else if (score >= MINC)
  {
    grade = 'C';
  }
  else if (score >= MIND)
  {
    grade = 'D';
  }
  else
  {
    grade = 'F';
  }
  return grade;
}

/*****+**-**---**-***-----*-**-*-*-****-****-*--****************************
*
*  Function Information
*
*  Name of Function: calcGpa
*
*  Function Return Type: float
*
*  Parameters (list data type, name, and comment one per line):
*    1. int score // student's score
*    2.
*    3.
*
*  Function Description: Calculate the student's GPA.
*
******+**-**---**-***-----*-**-*-*-****-****-*--***************************/
float calcGpa(int score)
{
  float gpa; // student's GPA

  gpa = ((score - 55) / 10.0);

  if (gpa <= 0.0)
  {
    gpa = 0.0;
  }
  return gpa;
}

/*****+**-**---**-***-----*-**-*-*-****-****-*--****************************
*
*  Function Information
*
*  Name of Function: calcPostfix
*
*  Function Return Type: char
*
*  Parameters (list data type, name, and comment one per line):
*    1. int score // student's score
*    2.
*    3.
*
*  Function Description: Calculate whether the student earned a plus or
*                        minus letter grade.
*
******+**-**---**-***-----*-**-*-*-****-****-*--***************************/
char calcPostfix(int score)
{
  int short_score; // first two digits of student's score
  char postfix; // plus or minus part of letter grade

  short_score = score % 10;

  if (score == 100)
  {
    postfix = '+';
  }
  else if (score < 56)
  {
    postfix = ' ';
  }
  else if (score <= 59 && score >= 56)
  {
    postfix = '-';
  }
  else if (score >= 59 && score <= 66)
  {
    postfix = ' ';
  }
  else if (short_score < 3)
  {
    postfix = '-';
  }
  else if (short_score < 7)
  {
    postfix = ' ';
  }
  else if (short_score <= 9)
  {
    postfix = '+';
  }
  return postfix;
}

/*****+**-**---**-***-----*-**-*-*-****-****-*--****************************
*
*  Function Information
*
*  Name of Function: output
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int score // student's score
*    2. char grade // student's letter grade
*    3. char postfix // student's plus or minus of letter grade
*    4. float GPA // student's GPA
*
*  Function Description: Print the student's score, grade, and GPA
*
******+**-**---**-***-----*-**-*-*-****-****-*--***************************/
void output(int score, char grade, char postfix, float GPA)
{
  printf("\n-=-=-=-=-=-=-=-=-=-");
  printf("\nStudent score: %4d", score);
  printf("\nStudent grade: [%c%c]", grade, postfix);
  printf("\nStudent GPA: %6.1f", GPA);
  printf("\n-=-=-=-=-=-=-=-=-=-\n");
}
