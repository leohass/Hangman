#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_system.h"
#include "gui.h"

const int maxMistakes = 7;
const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

char player1[];
//char player2[];
char solution[5] = "HALLO"; //set solution for testing
char hangmanPrint[] = "";

int start; //GetTickCount(int)

int tries;
char triedLetters[26] = "";
char correctLetters[] = "";

char input[];

int alphabetMask[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int mistakes;
int success = 0;

int solutionLength;


void reset_game()
{
    start = 0;
    tries = 0;
    mistakes = 0;
    success = 0;
    solutionLength = 0;

    for(int u = 0; u < strlen(alphabet); u++)
        {
            alphabetMask[u] = 0;
        }
}

void print_solution(int solutionMask[],char solution[])
{
    for (int i = 0; i < solutionLength; i++) {
        if (solutionMask[i] == 1)
        {
            printf("%c ", solution[i]);
        }
        else
        {
            printf("_ ");
        }
    }
    printf("\n");
}

void print_tried_letters(int alphabetMask[])
{
    printf("\nTried letters: ");
    for(int m = 0; m < strlen(alphabet); m++)
    {
        if (alphabetMask[m] == 1)
        {
            printf("%c", alphabet[m]);
            printf(" ");
        }
    }
    printf("\n");
}

void handle_try(char validInput[], int solutionMask[])
{
    tries++;

    for(int j = 0; j < 26; j++)
    {
        if (alphabet[j] == validInput[0])
        {
            alphabetMask[j] = 1;
        }
    }

    int mistakeMade = 1;

    for(int k = 0; k < solutionLength; k++)
    {
        if (solution[k] == validInput[0])
        {
            solutionMask[k] = 1;
            mistakeMade = 0;
        }
    }

    if (mistakeMade == 1)
    {
        mistakes++;
        printTriesLeft(mistakes);
    }
}

int check_success(int solutionMask[])
{
    int isSuccess = 1;
    for(int l = 0; l < solutionLength; l++)
    {
        if (solutionMask[l] == 0)
        {
            isSuccess = 0;
        }
    }

    return isSuccess;
}

int main()
{
    reset_game();

    printGameStart();

    getUserInput(&player1,1);

    solutionLength = strlen(solution);

    int solutionMask[solutionLength];

    for (int i = 0; i < solutionLength; i++) {
        solutionMask[i] = 0;
    }

    while (mistakes < maxMistakes && success == 0)
    {


        //hier input einbauen
        printHangman(mistakes);
        print_solution(solutionMask, solution);
        print_tried_letters(alphabetMask);
        printf("\n");

        do{
            getUserInput(&input,0);
        }while(!inputValidation(input));

        clearScreen();

        printGameStart();

        handle_try(input, solutionMask);
        success = check_success(solutionMask);


    }

    if (success == 1) {
        printf("\nWin!");
    }
    else
    {
        printf("\nLose :(");
    }


    return 0;
}
