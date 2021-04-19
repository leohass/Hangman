#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>

struct my_record {
    int id;
    char word[255];
};

struct my_record records[100];

int getSolutionLength(int id)
{
    for(int i = 0; i < sizeof(records); i++)
    {
        if(records[i].id == id){
            return strlen(records[i].word);
        }
    }
}

char* getSolutionWord(int id)
{
   for(int i = 0; i < sizeof(records); i++)
    {
        if(records[i].id == id){
            printf("function: %s\n", records[i].word);
            return records[i].word;
        }
    }
}


int getRandomSolutionId()
{
    FILE* my_file = fopen("resources/solution.csv", "r");

    size_t count = 0;
    for (; count < sizeof(records)/sizeof(records[0]); ++count)
    {
        int got = fscanf(my_file, "%d;%s", &records[count].id, &records[count].word);
        if (got != 2) break; // wrong number of tokens - maybe end of file
    }
    srand(time(NULL));
    int number = (rand()% 5);
    return records[number].id;
}
