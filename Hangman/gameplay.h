#ifndef GAMEPLAY_H_INCLUDED
#define GAMEPLAY_H_INCLUDED

/*
 * Outputs the Solution with correct guessed letters
 * and underscores for unguessed letters.
 */
void print_solution(int solutionMask[],char solution[]);

/*
 * Outputs all already guessed letters in alphabetical order.
 */
void print_tried_letters(int alphabetMask[], int alphabetMaskLength, char alphabet[]);

/*
 * Handles a valid guess of an user
 * The function increments the tries, marks the guess as a tried letter via the alphabetMask,
 * validates the guess, if it is part of the solution and increments the mistakes if not.
 */
 void handle_guess(int* tries,
                   char alphabet[],
                   int alphabetMask[],
                   char validInput[],
                   int solutionMask[],
                   char solution[],
                   int* mistakes);

/*
 * checks for a successfully completion of the game.
 * returns 1 , if the game is successfully completed.
 * return 0 otherwise.
 */
int check_success(int solutionMask[], int solutionLength);

#endif // GAMEPLAY_H_INCLUDED
