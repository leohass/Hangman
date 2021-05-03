#include<stdio.h>
#include<string.h>

void print_solution(int solutionMask[],char solution[])
{
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

void print_tried_letters(int alphabetMask[], int alphabetMaskLength, char alphabet[])
{
    printf("\nTried letters: ");
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

void handle_guess(int *tries,
                  char alphabet[],
                  int alphabetMask[],
                  char validInput[],
                  int solutionMask[],
                  char solution[],
                  int *mistakes)
{
    ++(*tries);
    for(int j = 0; j < 26; j++)
    {
        if (alphabet[j] == validInput[0])
        {
            alphabetMask[j] = 1;
        }
    }

    int mistakeMade = 1;

    for(int k = 0; k < strlen(solution); k++)
    {
        if (solution[k] == validInput[0])
        {
            solutionMask[k] = 1;
            mistakeMade = 0;
        }
    }

    if (mistakeMade == 1)
    {
        ++(*mistakes);
        printTriesLeft(mistakes);
    }
}

int check_success(int solutionMask[], int solutionLength)
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
