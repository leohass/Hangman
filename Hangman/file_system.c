#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>

const char* getfield(char* line, int num)
{
    const char* tok;
    for (tok = strtok(line, ";");
            tok && *tok;
            tok = strtok(NULL, ";\n"))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}


char* read()
{
    FILE* stream = fopen("resources/solution.csv", "r");

    srand(time(NULL));
    int number = (rand()% 5) + 1;
    char str[255];
    char line[255];

    sprintf(str, "%d", number);
    while (fgets(line, 255, stream))
    {
        char* tmp = strdup(line);
        char* solution = getfield(tmp, 2);
        // NOTE strtok clobbers tmp
        printf("%s == %s\n", str, getfield(tmp, 1));

        if (strcmp(str, getfield(tmp, 1))== 0)
        {
            printf("Solution: %s\n", solution);
            return solution;
        } else {
            free(tmp);
        }
    }
}
