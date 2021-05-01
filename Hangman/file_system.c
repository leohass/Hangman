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
    FILE* file = fopen("resources/solution.csv", "r");

    size_t count = 0;
    for (; count < sizeof(records)/sizeof(records[0]); ++count)
    {
        int got = fscanf(file, "%d;%s", &records[count].id, &records[count].word);
        if (got != 2) break; // wrong number of tokens - maybe end of file
    }
    srand(time(NULL));
    int number = (rand()% 7);
    printf("number %i\n",number);
    fclose(file);
    return records[number].id;
}

void savePlayerHighscore(char name[], int pointsInt)
{
    FILE* file = fopen("resources/playerName.csv", "a+");

    char simi[] = ";";
    char endline[] = "\n";

    char points[sizeof(pointsInt)];
    sprintf(points,"%d",pointsInt);

    fwrite(name,1,strlen(name), file);
    fwrite(simi,1,strlen(simi), file);
    fwrite(points,1,strlen(points), file);
    fwrite(endline,1,strlen(endline), file);

    fclose(file);
}
