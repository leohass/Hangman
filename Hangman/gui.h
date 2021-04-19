#ifndef GUI_H_INCLUDED
#define GUI_H_INCLUDED

/*
 * Outputs the Game Start Dialog
 */
void printGameStart();

/*
 * Validates if input is alpha and only one char
 * Returns 1 on success
 * Returns 0 in fail, prints out respective error message
 */
int inputValidation(char input[]);

/*
 * Requires Fails as parameter
 * Prints out current Hangman Ascii
 * prints out fails and tries left
 */
void printStatus(int i);

/*
 * Clears the console screen
 */
void clearScreen();



#endif // GUI_H_INCLUDED