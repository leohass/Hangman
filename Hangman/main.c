#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int maxMistakes = 7;
const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

char player1[] = "";
//char player2[];
char solution[] = "JULIAN"; //set solution for testing
char hangmanPrint[] = "";

int start; //GetTickCount(int)

int tries;
char triedLetters[26] = "";
char correctLetters[] = "";

int alphabetMask[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int mistakes;
int success = 0;


void reset_game()
{
    start = 0;
    tries = 0;
    mistakes = 0;
    success = 0;

    for(int u = 0; u < strlen(alphabet); u++)
        {
            alphabetMask[u] = 0;
        }
}

int main()
{
    reset_game();

    int length = strlen(solution);
    int solutionMask[length];
    for (int i = 0; i < length; i++) {
        solutionMask[i] = 0;
    }

    while (mistakes <= maxMistakes && success == 0)
    {
        //hier input einbauen
        char validInput;
        printf("Mistakes: %i\n", mistakes);
        fflush(stdout);
        printf("Guess: ");
        fflush(stdout);
        scanf(" %c", &validInput);

        tries++;

        for(int j = 0; j < 26; j++)
        {
            if (alphabet[j] == validInput)
            {
                alphabetMask[j] = 1;
            }
        }

        for(int m = 0; m < strlen(alphabet); m++)
        {
            if (alphabetMask[m] == 1)
            {
                printf("%c", alphabet[m]);
                printf(" ");
            }
        }
        printf("\n");

        int mistakeMade = 1;

        for(int k = 0; k < length; k++)
        {
            if (solution[k] == validInput)
            {
                solutionMask[k] = 1;
                mistakeMade = 0;
            }
        }

        if (mistakeMade == 1)
        {
            mistakes++;
        }

        success = 1;
        for(int l = 0; l < length; l++)
        {
            if (solutionMask[l] == 0)
            {
                success = 0;
            }
        }

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
