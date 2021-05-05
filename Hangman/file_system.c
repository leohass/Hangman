#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>

struct solution
{
    int id;
    char word[255];
};

struct highscore
{
    char name[255];
    double time;
    int tries;
};

struct solution records[1000];

struct highscore higscoreList[1000];

/**
 * returns the length of the solution word
 *
 * @param int id, the word you are looking for
 * @return int, the length of the word
**/
int get_solution_length(int id)
{
    for(int i = 0; i < sizeof(records); i++)
    {
        if(records[i].id == id)
        {
            return strlen(records[i].word);
        }
    }
}
/**
  * is running over all the records to find a match in the record
  * where the id is the given id
  *
  * strcpy(str, getSolutionWord(id)); you need to use to get the word into
  * a char array
  *
  * @param int id, from the word you are looking
  * @return the word as a char*
**/
char* get_solution_word(int id)
{
    for(int i = 0; i < sizeof(records); i++)
    {
        if(records[i].id == id)
        {
            return records[i].word;
        }
    }
}

/**
  * reading the solution file and saves every found solution into the solution
  * struct
  *
  * @return int, a random id which can be used to get the word out of the struct
**/
int get_random_solution_id()
{
    FILE* file = fopen("resources/solution.csv", "r");

    size_t count = 0;
    for (; count < sizeof(records)/sizeof(records[0]); ++count)
    {
        int got = fscanf(file, "%d;%s", &records[count].id, (char*) &records[count].word);
        if (got != 2) break; // wrong number of tokens - maybe end of file
    }
    srand(time(NULL));
    int amountSolutions = 0;
    while(true)
    {
        if (records[amountSolutions].id != NULL)
        {
            amountSolutions++;
        }
        else
        {
            break;
        }
    }
    int number = (rand()% amountSolutions);
    fclose(file);
    return records[number].id;
}
/**
  * saves the PlayerName and his time into the file,
  *
  *
  * @param char name[], the playerName
  * @param double time, the time
  * @param int tries, the tries
  *
**/
void save_player_highscore(char name[], double time, int tries)
{
    FILE* file = fopen("resources/playerHighscore.csv", "a+");

    fprintf(file,"%s;%f;%i\n",name, time, tries);

    fclose(file);
}

void print_highscore_list()
{
    FILE* file = fopen("resources/playerHighscore.csv", "r");

    size_t count = 0;
    for (; count < sizeof(records)/sizeof(records[0]); ++count)
    {
        int got = fscanf(file, "%s;%f;%i", (char*) &higscoreList[count].name, (double*) &higscoreList[count].time, (int*) &higscoreList[count].tries);
        if (got != 2) break; // wrong number of tokens - maybe end of file
    }
}
