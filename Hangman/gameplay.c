/**
*   Title: Hangman - Gameplay libraray
*   Date: 03.05.2021
*   Author: Julian Timmer
**/

#include<stdio.h>
#include<string.h>
#include "gui.h"
/**
 * Outputs the Solution with correct guessed letters
 * and underscores for unguessed letters.
 *
 * @param int array solutionMask[]
 * @param char array solution[]
**/
void print_solution(int solutionMask[],char solution[])
{
    //uses the solution mask and prints out a character at the index of solution
    //each time the mask has a value of 1 (true) at this index and an underscore otherwise
    for (int i = 0; i < strlen(solution); i++)
    {
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

/**
 * Outputs all already guessed letters in alphabetical order.
 *
 * @param int array alphabetMask[]
 * @param int alphabetLength
 * @param char array alphabet[]
**/
void print_tried_letters(int alphabetMask[], int alphabetMaskLength, char alphabet[])
{
    printf("\nTried letters: ");

    //uses the alphabet mask and prints out a character at the index of alphabet
    //each time the mask has a value of 1 (true) at this index.
    //Because the alphabet array is sorted, the output is sorted too
    for(int m = 0; m < alphabetMaskLength; m++)
    {
        if (alphabetMask[m] == 1)
        {
            printf("%c", alphabet[m]);
            printf(" ");
        }
    }

    printf("\n");
}

/**
 * Handles a valid guess of an user
 * The function increments the tries, marks the guess as a tried letter via the alphabetMask,
 * validates the guess, if it is part of the solution and increments the mistakes if not.
 *
 * @param int* tries
 * @param char array alphabet[]
 * @param int array alphabetMask[]
 * @param char array validInput[]
 * @param int array solutionMask[]
 * @param char array solution[]
 * @param int* mistakes
**/
void handle_guess(int *tries,
                  char alphabet[],
                  int alphabetLength,
                  int alphabetMask[],
                  char validInput[],
                  int solutionMask[],
                  char solution[],
                  int *mistakes)
{
    ++(*tries); //count up input(guess) of the user throughout a game

    //the guessed letter is marked as 1 (true) in the alphabetMask
    for(int j = 0; j < alphabetLength; j++)
    {
        if (alphabet[j] == validInput[0])
        {
            alphabetMask[j] = 1;
        }
    }

    int mistakeMade = 1; // initialize the guess as wrong

    //the guessed letter is marked with 1 (true) on every occurrence in the solution
    for(int k = 0; k < strlen(solution); k++)
    {
        if (solution[k] == validInput[0])
        {
            solutionMask[k] = 1;
            mistakeMade = 0; //guess is correct, so initial accusing of wrong guess is set back
        }
    }

    // count up mistakes, if guess is wrong
    if (mistakeMade == 1)
    {
        ++(*mistakes);
        print_tries_left(*mistakes);
    }
}

/**
 * checks for a successfully completion of the game.
 * returns 1 , if the game is successfully completed.
 * return 0 otherwise.
 *
 * @param int array solutionMask
 * @param int solutionLength
**/
int check_success(int solutionMask[], int solutionLength)
{
    int isSuccess = 1; // initialize success as true

    // loops through the solutionMask
    for(int l = 0; l < solutionLength; l++)
    {
        //solution mask has not every value on 1 (true)
        if (solutionMask[l] == 0)
        {
            isSuccess = 0; //set success to 0 (false)
        }
    }

    return isSuccess;
}
