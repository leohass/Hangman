#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_system.h"
#include "gui.h"
#include "gameplay.h"
#include <time.h>

const int maxMistakes = 7;
const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int alphabetLength = 26;

int alphabetMask[26];
int tries;

char player1[];
//char player2[];
char solution[5] = "HALLO"; //set solution for testing
char hangmanPrint[] = "";

int start; //GetTickCount(int)

char input[];

int mistakes = 0;
int success = 0;

void reset_game()
{
    start = 0;
    tries = 0;
    mistakes = 0;
    success = 0;

    for(int u = 0; u < alphabetLength; u++)
    {
        alphabetMask[u] = 0;
    }
}

int main()
{
    reset_game();

    printGameStart();

    getUserInput(&player1,1);

    clock_t begin = clock();

    // initialize solutionMask from length of solution
    int solutionLength = strlen(solution);
    int solutionMask[solutionLength];
    for (int i = 0; i < solutionLength; i++)
    {
        solutionMask[i] = 0;
    }

    while (mistakes < maxMistakes && success == 0)
    {
        //hier input einbauen
        printHangman(mistakes);
        print_solution(solutionMask, solution);
        print_tried_letters(alphabetMask, alphabetLength, alphabet);
        printf("\n");

        do
        {
            getUserInput(&input,0);
        }
        while(!inputValidation(input));

        clearScreen();

        printGameStart();

        handle_guess(&tries, alphabet, alphabetMask, input, solutionMask, solution, &mistakes);
        success = check_success(solutionMask, solutionLength);

        printf("Mistakes: %i\n", mistakes);
        printf("Tries: %i\n", tries);


    }
    clock_t end = clock();
    double time_spent = (double)(end - begin);
    if (success == 1)
    {
        printf("\nWin - Time %f !", time_spent / CLOCKS_PER_SEC);
    }
    else
    {
        printf("\nLose - Time %f !", time_spent / CLOCKS_PER_SEC);
    }


    return 0;
}
