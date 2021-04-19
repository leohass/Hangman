#ifndef FILE_SYSTEM_H_INCLUDED
#define FILE_SYSTEM_H_INCLUDED

/*
Returns a random id from the csv
*/
int getRandomSolutionId();

/*
Returns the length of the word which has that id
*/
int getSolutionLength(int id);
/*
Returns the word you need as an char pointer you need to call it like that
    strcpy(str, getSolutionWord(id));

    str is where you want it to go
*/
char* getSolutionWord(int id);
#endif // FILE_SYSTEM_H_INCLUDED
