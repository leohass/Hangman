/**
*   Title: Hangman - Filesystem header
*   Date: 03.05.2021
*   Author: Wilhelm Adam
**/

#ifndef FILE_SYSTEM_H_INCLUDED
#define FILE_SYSTEM_H_INCLUDED

int get_random_solution_id();

int get_solution_length(int id);

char* get_solution_word(int id);

void save_player_highscore(char playerName[], double time, int tries);

#endif // FILE_SYSTEM_H_INCLUDED
