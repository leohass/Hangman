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
 * Requires mistakes as parameter
 * prints out fails and tries left
 */
void printTriesLeft(int mistakes);

/*
 * Requires mistakes as parameter
 * Prints out current Hangman Ascii
 */
void printHangman(int mistakes);

 /*
  *Writes user input to pointer,
  *Expects type of input
  *Type 0 is a user guess
  *Type 1 is a username
  */
void getUserInput(char *input[],int typeOf);


/*
 * Clears the console screen
 */
void clearScreen();



#endif // GUI_H_INCLUDED
