/*****+---*****-***--*----*-*-*-*-----******-*--****************************
*
*  Lab #:07
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work.
*
*  Program Description: This program prompts the user for a seed and uses it 
*  to generate a pseudo-blackjack program that draws 3 cards if the sum of the
*  first two is less than 16 and selects the value of aces to be either 1 or 11.
*  The program displays the card number/face and the suit and displays the final
*  total.
*
******+---*****-***--*----*-*-*-*-----******-*--***************************/
#include <stdio.h>
#include <stdlib.h>

int getSeed(void);
int calcNum(int);
int calcCard(int);
int calcTotal(int, int);
int faceCards(int);
void output(int, int, int, int, int, int, int, int);
void outCard(int, int, int);
void outTotal(int);

int main(void)
{
  int seed; //value for seed from user
  int full_value_one; //first generated value before % 52
  int value_one; //value one after modulus
  int full_value_two; //second generated value before % 52
  int value_two; //value two after modulus
  int full_value_three; //third generated value before % 52
  int value_three; //value three after modulus
  int total1; //first total
  int total2; //second total
  int total3; //third total

  seed = getSeed();
  srand(seed);

  full_value_one = calcNum(rand());
  value_one = calcCard(full_value_one);
  full_value_two = calcNum(rand());
  value_two = calcCard(full_value_two);
  full_value_three = calcNum(rand());
  value_three = calcCard(full_value_three);

  total1 = calcTotal(0, value_one);
  total2 = calcTotal(total1, value_two);
  total3 = calcTotal(total2, value_three);

  output(value_one, full_value_one, value_two, full_value_two, value_three, full_value_three, total2, total3);

  return 0;
}

/*****+----****-***--*----*-*-*-*-----******-*--****************************
*
*  Function Information
*
*  Name of Function: getSeed
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. void
*
*  Function Description: This function gets a seed from a user.
*
******+----****-***--*----*-*-*-*-----******-*--***************************/
int getSeed(void)
{
  int seed; //seed for user input

  printf("Enter a seed -> ");
  scanf("%d", &seed);

  return seed;
}

/*****+-*--*-*---**--*----*-*-*-*-----******-*--****************************
*
*  Function Information
*
*  Name of Function: calcNum
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int value //value calculated by rand function
*
*  Function Description: This function mods the random value by 52 for a range
*  conducive to playing cards. It then returns the value.
*
******+-*--*-*---**--*----*-*-*-*-----******-*--***************************/
int calcNum(int value)
{
  return value % 52;
}

/*****+---*****-**---*----*-*-*-*-----******-*--****************************
*
*  Function Information
*
*  Name of Function: calcCard
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int value // previously modded value
*
*  Function Description: This function converts all cards to be between 1 and 13
*  regardless of the suit.
*
******+---*****-**---*----*-*-*-*-----******-*--***************************/
int calcCard(int value)
{
  if (value >= 39)
  {
    value -= 38;
  }
  else if (value >= 26 && value <= 38)
  {
    value -= 25;
  }
  else if (value >= 13 && value <= 25)
  {
    value -= 12;
  }
  else if (value <= 12)
  {
    value += 1;
  }

  return value;
}

/*****+----***--**---*----*-*-*-*-----******-*--****************************
*
*  Function Information
*
*  Name of Function: output
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int value_one //first card value
*    2. int full_value_one //first full card value for calculating suit
*    3. int value_two //second card value
*    4. int full_value_two //second full card value for calculating suit
*    5. int value_three //third card value
*    6. int full_value_three //third full care value for calculating suit
*    7. int total2 //second calculated total
*    8. int total3 //third calculated total
*
*  Function Description: This function calls other output functions conditionally
*  to output the correct values.
*
******+----***--**---*----*-*-*-*-----******-*--***************************/
void output(int value_one, int full_value_one, int value_two, int full_value_two, int value_three, int full_value_three, int total2, int total3)
{
  outCard(1, value_one, full_value_one);
  outCard(2, value_two, full_value_two);

  if (total2 < 15)
  {
    outCard(3, value_three, full_value_three);
    outTotal(total3);
  }
  else
  {
    outTotal(total2);
  }
}

/*****+---**-**--*---*----*-*-*-*-----******-*--****************************
*
*  Function Information
*
*  Name of Function: outCard
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int condition //condition for first, second, or third card
*    2. int value //value to output
*    3. int full_value //full value used to determine suit
*
*  Function Description: This function outputs the cards with their values and
*  suits.
*
******+---**-**--*---*----*-*-*-*-----******-*--***************************/
void outCard(int condition, int value, int full_value)
{
  if (condition == 1)
  {
    printf("\nFirst Card: ");
  }
  else if (condition == 2)
  {
    printf("Second Card: ");
  }
  else if (condition == 3)
  {
    printf("Third Card: ");
  }

  if (value > 1 && value < 10)
  {
    printf("%d of ", value);
  }
  else
  {
    switch(value)
    {
      case 1 :
        printf("Ace of ");
        break;
      case 11 :
        printf("Jack of ");
        break;
      case 12 :
        printf("Queen of ");
        break;
      case 13 :
        printf("King of ");
        break;
     }
  }

  if (full_value <= 12)
  {
    printf("Clubs\n");
  }
  else if (full_value >= 13 && full_value <= 25)
  {
    printf("Hearts\n");
  }
  else if (full_value >= 26 && full_value <= 38)
  {
    printf("Diamonds\n");
  }
  else if (full_value >= 39)
  {
    printf("Spades\n");
  }
}

/*****+----*-**--*---*----*-*-*-*-----******-*--****************************
*
*  Function Information
*
*  Name of Function: calcTotal
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int x //first value to add
*    2. int y //second value to add
*
*  Function Description: This function calculates the total and modifies it
*  accordingly if there are aces.
*
******+----*-**--*---*----*-*-*-*-----******-*--***************************/
int calcTotal(int x, int y)
{
  int total; //total to return

  y = faceCards(y);

  if (x + y > 21)
  {
    total = x + y - 10;
  }
  else
  {
    total = x + y;
  }

  return total;
}

/*****+----***---*---*----*-*-*-*-----******-*--****************************
*
*  Function Information
*
*  Name of Function: faceCards
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int val //modded value to modify
*
*  Function Description: This function modifies the values if they are face cards.
*
******+----***---*---*----*-*-*-*-----******-*--***************************/
int faceCards(int val)
{
  if (val > 10)
  {
    val = 10;
  }
  else if (val == 1)
  {
    val = 11;
  }

  return val;
}

/*****+-*-**-*---*---*----*-*-*-*-----******-*--****************************
*
*  Function Information
*
*  Name of Function:outTotal
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int total //value to be outputted
*
*  Function Description: This function outputs the total.
*
******+-*-**-*---*---*----*-*-*-*-----******-*--***************************/
void outTotal(int total)
{
  printf("The total card value is: %d\n", total);
}
