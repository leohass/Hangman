#ifndef GUI_H_INCLUDED
#define GUI_H_INCLUDED

/*
 * Outputs the Game Start Dialog
 */
void print_game_start();

/*
 * Validates if input is alpha and only one char
 * Returns 1 on success
 * Returns 0 in fail, prints out respective error message
 */
int input_validation(char input[]);

/*
 * Requires mistakes as parameter
 * prints out fails and tries left
 */
void print_tries_left(int mistakes);

/*
 * Requires mistakes as parameter
 * Prints out current Hangman Ascii
 */
void print_hangman(int mistakes);

 /*
  *Writes user input to pointer,
  *Expects type of input
  *Type 0 is a user guess
  *Type 1 is a username
  */
void get_user_input(size_t ccount,char (*input)[ccount],int typeOf);

/*
 * Clears the console screen
 */
void clear_screen();



#endif // GUI_H_INCLUDED
