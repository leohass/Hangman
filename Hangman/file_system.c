#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include <time.h>

struct solution
{
    int id;
    char word[255];
};

struct solution records[1000];

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
        int got = fscanf(file, "%d;%s", &records[count].id, &records[count].word);
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
  * @param double timeChar, the time
  * @param double tries, the tries
  *
**/
void save_player_highscore(char name[], double time, int tries)
{
    FILE* file = fopen("resources/playerHighscore.csv", "a+");

    char simi[] = ";";
    char endline[] = "\n";

    char timeChar[sizeof(time)];
    sprintf(timeChar,"%f",time);

    char triesChar[sizeof(tries)];
    sprintf(triesChar,"%d",tries);


    fwrite(name,1,strlen(name), file);
    fwrite(simi,1,strlen(simi), file);

    fwrite(timeChar,1,strlen(timeChar), file);
    fwrite(simi,1,strlen(simi), file);

    fwrite(triesChar,1,strlen(triesChar), file);
    fwrite(endline,1,strlen(endline), file);

    fclose(file);
}
