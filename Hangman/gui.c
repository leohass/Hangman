#include<stdio.h>


void printGameStart()
{
    char welcome[3][255] =
    {
        " +-++-++-++-++-++-++-+ +-++-+ +-++-++-++-++-++-++-+ ",
        " |W||e||l||c||o||m||e| |T||o| |H||a||n||g||m||a||n| ",
        " +-++-++-++-++-++-++-+ +-++-+ +-++-++-++-++-++-++-+ "
    };

    char rules[4][255] =
    {
        "The rules are simple",
        " 1. You have 7 tries",
        " 2. Only use uppercase letters of the alphabet",
        " 3. Lose"
    };

    for(int i = 0; i < 3; i ++)
    {
        printf("%s \n", welcome[i]);
    }

    for(int i = 0; i < 4; i++ )
    {
        printf("%s \n", rules[i]);
        printf("\n");

    }

}

void getUserInput(char *input[],int typeOf)
{

    switch(typeOf)
    {
    case 0:
        printf("Please enter a letter:");
        fflush(stdin);
        scanf("%s", input);

        break;
    case 1:
        printf("Please enter your name:");
        fflush(stdin);
        scanf("%s", input);
        break;
    }
}

int inputValidation(char input[])
{

    if(strlen(input) == 1)
    {
        if((input[0] >= 'a' && input[0] <= 'z') || (input[0] >= 'A' && input[0] <= 'Z'))
        {
            return 1;
        }
        printf("input must be alphabet \n");
        return 0;
    }

    printf("please enter only one character \n");
    return 0;
}

void printTriesLeft(int mistakes)
{

    if(mistakes == 1)
    {
        printf("\033[0;31m");
        printf("so close, you have 6 tries left \n");
        printf("\n");
        printf("\033[0m");
    }
    if(mistakes == 2)
    {
        printf("\033[0;31m");
        printf("even a blind hen sometimes finds a grain of corn, apparently you not, you have 5 tries left \n");
        printf("\n");
        printf("\033[0m");
    }
    if(mistakes == 3)
    {
        printf("\033[0;31m");
        printf("better luck next time, you have 4 tries left \n");
        printf("\n");
        printf("\033[0m");
    }
    if(mistakes == 4)
    {
        printf("\033[0;31m");
        printf("i am running out of jokes, you have 3 tries left \n");
        printf("\n");
        printf("\033[0m");
    }
    if(mistakes == 5)
    {
        printf("\033[0;31m");
        printf("amazon has a great margin on English dictionary's, maybe you should look into that, you have 2 tries left  \n");
        printf("\n");
        printf("\033[0m");
    }
    if(mistakes == 6)
    {
        printf("\033[0;31m");
        printf("you never give up do you well this is your last try \n");
        printf("\n");
        printf("\033[0m");
    }
    if(mistakes == 7)
    {
        printf("\033[0;31m");
        printf("did you juts really lose a game designed for children? \n");
        printf("\n");
        printf("\033[0m");
    }
}
void printHangman(int mistakes )
{
    char hangman[8][255] = {" \
  +---+ \n \
      | \n \
      | \n \
      | \n \
      | \n \
      | \n \
=========", " \
  +---+ \n \
  |   | \n \
      | \n \
      | \n \
      | \n \
      | \n \
=========", " \
  +---+ \n \
  |   | \n \
  O   | \n \
      | \n \
      | \n \
      | \n \
=========", " \
  +---+ \n \
  |   | \n \
  O   | \n \
  |   | \n \
      | \n \
      | \n \
=========", " \
  +---+ \n \
  |   | \n \
  O   | \n \
 /|   | \n \
      | \n \
      | \n \
=========", " \
  +---+ \n \
  |   | \n \
  O   | \n \
 /|\\  | \n \
      | \n \
      | \n \
=========", " \
  +---+ \n \
  |   | \n \
  O   | \n \
 /|\\  | \n \
 /    | \n \
      | \n \
=========", " \
  +---+ \n \
  |   | \n \
  O   | \n \
 /|\\  | \n \
 / \\  | \n \
      | \n \
========="
                           };
    printf("%s \n", hangman[mistakes]);
}

void clearScreen()
{
    system("@cls||clear");
}
