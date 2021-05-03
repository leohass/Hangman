/**
*   Title: Hangman - Gameplay header
*   Date: 03.05.2021
*   Author: Julian Timmer
**/

#ifndef GAMEPLAY_H_INCLUDED
#define GAMEPLAY_H_INCLUDED

void print_solution(int solutionMask[],char solution[]);

void print_tried_letters(int alphabetMask[], int alphabetMaskLength, char alphabet[]);

void handle_guess(int* tries,
                   char alphabet[],
                   int alphabetLength,
                   int alphabetMask[],
                   char validInput[],
                   int solutionMask[],
                   char solution[],
                   int* mistakes);

int check_success(int solutionMask[], int solutionLength);

#endif // GAMEPLAY_H_INCLUDED
