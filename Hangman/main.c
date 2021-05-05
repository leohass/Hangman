#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_system.h"
#include "gui.h"
#include "gameplay.h"
#include <time.h>
#include <ctype.h>

const int maxMistakes = 7;
const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int alphabetLength = 26;

int alphabetMask[26]; //used for validating guessed letters
int tries;

char player1[] = "";
char hangmanPrint[] = "";

int start; //GetTickCount(int)

char input[] = "";

int mistakes = 0; //used as boolean
int success = 0; //used as boolean

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

    int id = get_random_solution_id();

    char solution[get_solution_length(id)];

    strcpy(solution, get_solution_word(id));

    int i = 0;
    while(solution[i])
    {
        solution[i] = (toupper(solution[i]));
        i++;
    }

    print_game_start();

    get_user_input(strlen(player1),&player1,1);

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
        print_hangman(mistakes);
        print_solution(solutionMask, solution);
        print_tried_letters(alphabetMask, alphabetLength, alphabet);
        printf("\n");

        do
        {
            get_user_input(strlen(player1),&input,0);
        }
        while(!input_validation(input));

        clear_screen();

        print_game_start();

        handle_guess(&tries, alphabet, alphabetLength, alphabetMask, input, solutionMask, solution, &mistakes);
        success = check_success(solutionMask, solutionLength);

        clock_t stamp = clock();
        double timeStamp = (double)(stamp - begin);
        printf("Time: %f seconds\n", timeStamp / CLOCKS_PER_SEC);

        print_tries_left(mistakes);
        printf("Tries: %i\n", tries);

    }
    clock_t end = clock();
    double time_spent = (double)(end - begin);
    if (success == 1)
    {
        printf("\nWin - the solution is: %s",(char*)solution);
        printf("\nYour time was: %f seconds!", time_spent / CLOCKS_PER_SEC);
    }
    else
    {
        printf("\nLose - the solution is: %s", (char*)solution);
        printf("\nYour time was: %f seconds!", time_spent / CLOCKS_PER_SEC);
    }

    save_player_highscore(player1,time_spent / CLOCKS_PER_SEC, tries);

    return 0;
}
